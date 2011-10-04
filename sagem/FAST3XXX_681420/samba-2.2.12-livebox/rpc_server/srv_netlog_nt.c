/*
 *  Unix SMB/Netbios implementation.
 *  Version 1.9.
 *  RPC Pipe client / server routines
 *  Copyright (C) Andrew Tridgell              1992-1997,
 *  Copyright (C) Luke Kenneth Casson Leighton 1996-1997,
 *  Copyright (C) Paul Ashton                       1997.
 *  Copyright (C) Jeremy Allison               1998-2001.
 *  Copyirht  (C) Andrew Bartlett                   2001.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/* This is the implementation of the netlogon pipe. */

#include "includes.h"

extern BOOL sam_logon_in_ssb;
extern pstring samlogon_user;
extern pstring global_myname;
extern DOM_SID global_sam_sid;

/*************************************************************************
 init_net_r_req_chal:
 *************************************************************************/

static void init_net_r_req_chal(NET_R_REQ_CHAL *r_c,
				DOM_CHAL *srv_chal, NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 error messages cropping up when using nltest.exe...
 *************************************************************************/

#define ERROR_NO_SUCH_DOMAIN   0x54b
#define ERROR_NO_LOGON_SERVERS 0x51f

/*************************************************************************
 net_reply_logon_ctrl:
 *************************************************************************/

/* Some flag values reverse engineered from NLTEST.EXE */

#define LOGON_CTRL_IN_SYNC          0x00
#define LOGON_CTRL_REPL_NEEDED      0x01
#define LOGON_CTRL_REPL_IN_PROGRESS 0x02

NTSTATUS _net_logon_ctrl(pipes_struct *p, NET_Q_LOGON_CTRL *q_u,
		       NET_R_LOGON_CTRL *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 net_reply_logon_ctrl2:
 *************************************************************************/

NTSTATUS _net_logon_ctrl2(pipes_struct *p, NET_Q_LOGON_CTRL2 *q_u, NET_R_LOGON_CTRL2 *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 net_reply_trust_dom_list:
 *************************************************************************/

NTSTATUS _net_trust_dom_list(pipes_struct *p, NET_Q_TRUST_DOM_LIST *q_u, NET_R_TRUST_DOM_LIST *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***********************************************************************************
 init_net_r_srv_pwset:
 ***********************************************************************************/

static void init_net_r_srv_pwset(NET_R_SRV_PWSET *r_s,
			     DOM_CRED *srv_cred, NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/******************************************************************
 gets a machine password entry.  checks access rights of the host.
 ******************************************************************/

static BOOL get_md4pw(char *md4pw, char *mach_acct)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 _net_req_chal
 *************************************************************************/

NTSTATUS _net_req_chal(pipes_struct *p, NET_Q_REQ_CHAL *q_u, NET_R_REQ_CHAL *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 init_net_r_auth:
 *************************************************************************/

static void init_net_r_auth(NET_R_AUTH *r_a, DOM_CHAL *resp_cred, NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 _net_auth
 *************************************************************************/

NTSTATUS _net_auth(pipes_struct *p, NET_Q_AUTH *q_u, NET_R_AUTH *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 init_net_r_auth_2:
 *************************************************************************/

static void init_net_r_auth_2(NET_R_AUTH_2 *r_a,
			      DOM_CHAL *resp_cred, NEG_FLAGS *flgs, NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 _net_auth_2
 *************************************************************************/

NTSTATUS _net_auth_2(pipes_struct *p, NET_Q_AUTH_2 *q_u, NET_R_AUTH_2 *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 _net_srv_pwset
 *************************************************************************/

NTSTATUS _net_srv_pwset(pipes_struct *p, NET_Q_SRV_PWSET *q_u, NET_R_SRV_PWSET *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}


/*************************************************************************
 _net_sam_logoff:
 *************************************************************************/

NTSTATUS _net_sam_logoff(pipes_struct *p, NET_Q_SAM_LOGOFF *q_u, NET_R_SAM_LOGOFF *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 net_login_interactive:
 *************************************************************************/

static NTSTATUS net_login_interactive(NET_ID_INFO_1 *id1, SAM_ACCOUNT *sampass, pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 _net_login_network:
 *************************************************************************/

static NTSTATUS net_login_network(NET_ID_INFO_2 *id2, SAM_ACCOUNT *sampass)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 _net_sam_logon
 *************************************************************************/

NTSTATUS _net_sam_logon(pipes_struct *p, NET_Q_SAM_LOGON *q_u, NET_R_SAM_LOGON *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}
