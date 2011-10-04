/****************************************************************************
 *
 * /home/gil/dev/rg.tag/pkg/l2tp/rg.c
 * 
 * Copyright (C) Jungo LTD 2004
 * 
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General 
 * Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the Free
 * Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 * MA 02111-1307, USA.
 *
 * Developed by Jungo LTD.
 * Residential Gateway Software Division
 * www.jungo.com
 * info@jungo.com
 */

#include "l2tp.h"
#include "rg_ipc.h"
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <termios.h>

#include "be_api_gpl.h"
#include "openrg_gpl.h"
#include "kos_chardev_id.h"
#include "alloc.h"

#define HANDLER_NAME "jungo"

static int rg_session_close(EventSelector *es, int id);
static int rg_session_open(EventSelector *es, int id, struct in_addr *addr,
    char *secret, int secret_len);
static int establish_session(l2tp_session *ses);
static void close_session(l2tp_session *ses, char const *reason);
static void rg_tunnel_close(l2tp_tunnel *tunnel);
static void handle_frame(l2tp_session *ses, unsigned char *buf, size_t len);
static void readable(EventSelector *es, int fd, unsigned int flags, void *data);
static int l2tp_peer_is_equal_id(l2tp_peer *peer, void *param);
static void rg_session_cont_free(l2tp_session *ses);
static int rg_send_ipc(l2tpd_msg_type_t type, EventSelector *es,
    l2tp_session *ses);
static int rg_peer_id(l2tp_peer *peer);
static void rg_sig_id(l2tp_tuid *tuid);

typedef struct {
    EventHandler *read_event;	/* Read event handler */
    int fd;			/* socket of master tty */
    int attached;		/* 1 if char device is already attached 
				   0 otherwise */
} rg_session_context_t;

typedef struct {
    int id;			/* as received in the open message */
    enum {
	PEER_ACTIVE = 0,
	PEER_WAITING_CLOSE = 1,
    } state;
} rg_peer_context_t;

typedef struct rg_ipc_send_msg_t {
    struct rg_ipc_send_msg_t *next;
    EventHandler *retry_event;	/* Retry event handler */
    l2tpd_msg_t msg;
} rg_ipc_send_msg_t;

static l2tp_call_ops my_ops = {
    establish_session,
    close_session,
    handle_frame
};

static l2tp_lac_handler my_lac_handler = {
    NULL,
    HANDLER_NAME,
    &my_ops
};

static int ipc_sock = -1;
static EventHandler *ipc_event;
static rg_ipc_send_msg_t *rg_ipc_send_msgs;

static int rg_backend_attach(int id, char *dev_name)
{
    l2tp_tunnel *tunnel;
    l2tp_peer *peer;
    l2tp_session *ses;
    void *dummy;
    rg_session_context_t *cont;

    /* search matching session */
    if (!(peer = l2tp_peer_find_by_func(l2tp_peer_is_equal_id, &id)) ||
	!peer->private)
    {
	l2tp_set_errmsg("peer for id %d not found", id);
	return -1;
    }
    
    if (!(tunnel = tunnel_find_bypeer(peer)))
    {
	l2tp_set_errmsg("tunnel for id %d not found", id);
	return -1;
    }
    
    if (!(ses = l2tp_tunnel_first_session(tunnel, &dummy)))
    {
	l2tp_set_errmsg("session for id %d not found", id);
	return -1;
    }

    cont = malloc(sizeof(rg_session_context_t));
    if (!cont)
    {
	l2tp_set_errmsg("unable to allocate session private memory");
	return -1;
    }

    ses->private = cont;
    memset(cont, 0, sizeof(rg_session_context_t));

    /* open char device and attach to it */
    if ((cont->fd = gpl_sys_rg_chrdev_open(KOS_CDT_PPPCHARDEV_BACKEND, O_RDWR))
	< 0)
    {
	l2tp_set_errmsg("Can't open ppp chardevice");
	goto Error;
    }

    if (ioctl(cont->fd, PPPBE_ATTACH, (int)dev_name) < 0)
    {
	l2tp_set_errmsg("failed attach l2tpd to device %s", dev_name);
	goto Error;
    }
    cont->attached = 1;

    cont->read_event = Event_AddHandler(ses->tunnel->es, cont->fd,
	EVENT_FLAG_READABLE, readable, ses);

    l2tp_db(DBG_CONTROL, "session %d to %s opened, fd %d",
	((rg_peer_context_t *)ses->tunnel->peer->private)->id,
       	inet_ntoa(ses->tunnel->peer->addr.sin_addr), cont->fd);
    return 0;
Error:
    rg_session_cont_free(ses);
    return -1;
}

/* called by l2tpd main event loop when there is something to read from ipc
 * socket */
static void rg_input(EventSelector *es, int sock, unsigned int flags,
    void *data)
{
    l2tpd_msg_t msg;
    int fd, rc = -1;
    u8 secret[MAX_SECRET_LEN];
    char *dev_name = NULL;

    /* read message */
    if ((fd = ipc_accept(sock))<0 ||
        (rc = ipc_read(fd, (u8 *)&msg, sizeof(msg))))
    {
	goto Exit;
    }

    /* handle message */
    switch (msg.type)
    {
    case L2M_CONNECT:
	if (msg.params.shared_secret_len)
	{
	    if (msg.params.shared_secret_len > MAX_SECRET_LEN ||
		(rc = ipc_read(fd, secret, msg.params.shared_secret_len)))
	    {
		goto Exit;
	    }
	}
	    
	/* open new session */
	ipc_u32_write(fd, (u32)rg_session_open(es, msg.params.id,
	    &msg.params.server_ip, secret, msg.params.shared_secret_len));
	break;
    case L2M_CLOSE:
	/* close session */
	rg_session_close(es, msg.params.id);
	break;
    case L2M_ATTACH:
	if (!(dev_name = ipc_string_read(fd)))
	    goto Exit;
	ipc_u32_write(fd, (u32)rg_backend_attach(msg.params.id, dev_name));
	break;
    default:
	break;
    }

Exit:
    if (fd>=0)
	ipc_server_close(fd, rc);
    nfree(dev_name);
}

int rg_init(EventSelector *es)
{
    l2tp_session_register_lac_handler(&my_lac_handler);

    ipc_sock = ipc_bind_listen_port(htons(RG_IPC_PORT_MT_2_L2TPD));
    if (ipc_sock < 0)
    {
	l2tp_set_errmsg("could not open ipc socket");
	return -1;
    }

    ipc_event = Event_AddHandler(es, ipc_sock, EVENT_FLAG_READABLE, rg_input,
	NULL);
    
    /* update caller that l2tpd/ipc is ready */
    rg_send_ipc(L2M_READY, es, NULL);

    return 0;
}

static int l2tp_peer_is_equal_id(l2tp_peer *peer, void *param)
{
    rg_peer_context_t *cont = peer->private;

    return cont && cont->id == *(int *)param;
}

static int rg_session_close(EventSelector *es, int id)
{
    l2tp_tunnel *tunnel;
    l2tp_peer *peer;
    rg_peer_context_t *cont;

    /* search matching session */
    peer = l2tp_peer_find_by_func(l2tp_peer_is_equal_id, &id);
    if (!peer || !peer->private)
    {
	l2tp_set_errmsg("session %d not found", id);
	return -1;
    }
    cont = peer->private;
    switch (cont->state)
    {
    case PEER_ACTIVE:
	tunnel = tunnel_find_bypeer(peer);
	peer_release(peer);
	if (!tunnel)
	{
	    l2tp_set_errmsg("no tunnel found for session %d to %s", id,
	       	inet_ntoa(peer->addr.sin_addr));
	    peer_free(peer);
	    return -1;
	}
	cont->state = PEER_WAITING_CLOSE;
	l2tp_tunnel_stop_tunnel(tunnel, "Closed by OpenRG");
	DBG(l2tp_db(DBG_FLOW, "tunnel stopped for session %d to %s", id,
	    inet_ntoa(peer->addr.sin_addr)));
	break;
    case PEER_WAITING_CLOSE:
	/* should never be reached */
	l2tp_set_errmsg("session %d to %s already closing", id, 
	    inet_ntoa(peer->addr.sin_addr));
	return -1;
    }

    return 0;
}

static void rg_peer_close(l2tp_peer *p)
{
    if (!p->private)
	return;

    free(p->private);
    p->private = NULL;
}

static int rg_session_open(EventSelector *es, int id, struct in_addr *addr,
    char *secret, int secret_len)
{
    l2tp_peer *p;
    rg_peer_context_t *cont;
    l2tp_session *ses;

    l2tp_db(DBG_CONTROL, "opening session %d to %s", id, inet_ntoa(*addr));

    cont = malloc(sizeof(*cont));
    if (!cont)
    {
	l2tp_set_errmsg("could not allocate peer context for session %d to %s", 
	    id, inet_ntoa(*addr));
	return -1;
    }
    memset(cont, 0, sizeof(*cont));
    cont->state = PEER_ACTIVE;
    cont->id = id;

    p = l2tp_peer_insert_and_fill(HANDLER_NAME, addr, L2TP_PORT, secret,
	secret_len, cont, rg_peer_close, rg_peer_id, rg_sig_id);
    if (!p)
    {
	l2tp_set_errmsg("could not create peer for session %d to %s", id,
	    inet_ntoa(*addr));
	free(cont);
	return  -1;
    }

    ses = l2tp_session_call_lns(p, "foobar", es, NULL);
    if (!ses)
    {
	l2tp_set_errmsg("could not call peer of session %d to %s", id,
	    inet_ntoa(p->addr.sin_addr));
	peer_release(p);
	peer_free(p);
	return -1;
    }
    ses->tunnel->close = rg_tunnel_close;

    return 0;
}

static void rg_ipc_send_msg_free(EventSelector *es,
    rg_ipc_send_msg_t *rg_ipc_send_msg)
{
    rg_ipc_send_msg_t **cur;

    if (rg_ipc_send_msg->retry_event)
	Event_DelHandler(es, rg_ipc_send_msg->retry_event);

    /* remove from list */
    for (cur = &rg_ipc_send_msgs; *cur && *cur != rg_ipc_send_msg;
	cur = &(*cur)->next);
    if (*cur)
	*cur = rg_ipc_send_msg->next;

    free(rg_ipc_send_msg);
}


static void rg_send_ipc_try(EventSelector *es, int fd_dummy,
    unsigned int flags_dummy, void *data)
{
    rg_ipc_send_msg_t *rg_ipc_send_msg = data;
    int rc = -1, fd;

    if ((fd = ipc_connect(htons(RG_IPC_PORT_L2TPD_2_MT)))<0 ||
	(rc = ipc_write(fd, (u8 *)&rg_ipc_send_msg->msg,
       	sizeof(rg_ipc_send_msg->msg))))
    {
	struct timeval t;

	/* schedule retry 0.1 seconds from now */
	t.tv_sec = 0;
	t.tv_usec = 100000;
	rg_ipc_send_msg->retry_event =
	    Event_AddTimerHandler(es, t, rg_send_ipc_try, rg_ipc_send_msg);

	return;
    }
    if (fd >= 0)
	ipc_client_close(fd, rc);

    rg_ipc_send_msg_free(es, rg_ipc_send_msg);
}

static int rg_send_ipc(l2tpd_msg_type_t type, EventSelector *es,
    l2tp_session *ses)
{
    rg_ipc_send_msg_t *rg_ipc_send_msg = zalloc(sizeof(rg_ipc_send_msg_t));

    if (!rg_ipc_send_msg)
	return -1;

    rg_ipc_send_msg->msg.type = type;
    if (ses)
    {
	l2tp_peer *peer = ses->tunnel->peer;
	rg_peer_context_t *cont = peer->private;

	rg_ipc_send_msg->msg.params.id = cont->id;
	rg_ipc_send_msg->msg.params.server_ip = peer->addr.sin_addr;
	rg_ipc_send_msg->msg.params.shared_secret_len = peer->secret_len;
    }

    /* add to list */
    rg_ipc_send_msg->next = rg_ipc_send_msgs;
    rg_ipc_send_msgs = rg_ipc_send_msg;

    rg_send_ipc_try(es, 0, 0, rg_ipc_send_msg);

    return 0;
}

static void rg_session_cont_free(l2tp_session *ses)
{
    rg_session_context_t *cont = ses->private;

    if (!cont)
	return;

    if (cont->read_event)
	Event_DelHandler(ses->tunnel->es, cont->read_event);
    if (cont->attached)
	ioctl(cont->fd, PPPBE_DETACH, NULL); 
    if (cont->fd >= 0)
	close(cont->fd);
    free(cont);
    ses->private = NULL;
}

static int establish_session(l2tp_session *ses)
{
    /* update caller that session is open */
    return rg_send_ipc(L2M_CONNECT, ses->tunnel->es, ses);
}

/* close_session() is called just before ses is freed */
static void close_session(l2tp_session *ses, char const *reason)
{
    l2tp_db(DBG_CONTROL, "session %d to %s closed. reason %s",
	((rg_peer_context_t *)ses->tunnel->peer->private)->id,
       	inet_ntoa(ses->tunnel->peer->addr.sin_addr), reason ? reason : "-");

    if (ses->private)
	rg_session_cont_free(ses);
}

/* rg_tunnel_close() is called just before tunnel is freed */
static void rg_tunnel_close(l2tp_tunnel *tunnel)
{
    rg_peer_context_t *cont = tunnel->peer->private;

    DBG(l2tp_db(DBG_TUNNEL, "tunnel of session %d to %s closed",
	((rg_peer_context_t *)tunnel->peer->private)->id,
       	inet_ntoa(tunnel->peer->addr.sin_addr)));

    switch (cont->state)
    {
    case PEER_ACTIVE:
	peer_release(tunnel->peer);
	/* fall through */
    case PEER_WAITING_CLOSE:
	/* peer already released, either here or in rg_session_close() */
	peer_free(tunnel->peer);
	break;
    }
}

/* deliver the peer device id corresponding */
static int rg_peer_id(l2tp_peer *peer)
{
return(((rg_peer_context_t *)peer->private)->id);
}

/* signal to the main task a shutdown message at peer device */
static void rg_sig_id(l2tp_tuid * tuid)
{
rg_ipc_send_msg_t *rg_ipc_send_msg;

/* not a real id ? */
if (tuid->id < 0) return;

rg_ipc_send_msg = zalloc(sizeof(rg_ipc_send_msg_t));

/* no memory ? */
if (!rg_ipc_send_msg) return ;

rg_ipc_send_msg->msg.type = L2M_CLOSE;
rg_ipc_send_msg->msg.params.id = tuid->id;

/* add to list */
rg_ipc_send_msg->next = rg_ipc_send_msgs;
rg_ipc_send_msgs = rg_ipc_send_msg;

/* send the message */
rg_send_ipc_try(tuid->es, 0, 0, rg_ipc_send_msg);	
}

static void handle_frame(l2tp_session *ses, unsigned char *buf, size_t len)
{
    int n;
    rg_session_context_t *cont = ses->private;

    /* chardev was not attached yet */
    if (!cont)
	return;
    
    /* TODO: Add error checking */
    n = write(cont->fd, buf, len);

    DBG(l2tp_db(DBG_XMIT_RCV,
	"handle_frame() sent to pppd %d octets of %d (%d-%s):\n",
	n, len, errno, strerror(errno)));
    DBG(l2tp_db(DBG_XMIT_RCV_DUMP, "orig: %s\n", dump(buf, len)));
}

static void readable(EventSelector *es, int fd, unsigned int flags, void *data)
{
    unsigned char buf[MAX_PACKET_LEN+EXTRA_HEADER_ROOM];
    int n;
    l2tp_session *ses = (l2tp_session *)data;
    rg_session_context_t *cont;
    int iters = 5;

    /* It seems to be better to read in a loop than to go
     * back to select loop.  However, don't loop forever, or
     * we could have a DoS potential */
    while (iters--)
    {
	n = read(fd, buf + EXTRA_HEADER_ROOM, MAX_PACKET_LEN);

	if (n < 0)
	{
	    if (errno != EIO)
		continue;
	    return;
	}

	DBG(l2tp_db(DBG_XMIT_RCV, 
	    "readable() got from pppd %d octets (%d-%s)\n",
	    n, errno, strerror(errno)));
	DBG(l2tp_db(DBG_XMIT_RCV_DUMP, "readable(): %s\n", dump(buf, n)));
	errno = 0;

	/* TODO: Check this.... */
	if (n <= 2)
	    return;

	if (!ses)
	    continue;

	cont = ses->private;

	l2tp_dgram_send_ppp_frame(ses, buf+EXTRA_HEADER_ROOM, n); 
    }
}

