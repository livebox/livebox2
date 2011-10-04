/*
 *  Unix SMB/Netbios implementation.
 *  Version 1.9.
 *  RPC Pipe client / server routines
 *  Copyright (C) Andrew Tridgell              1992-1997,
 *  Copyright (C) Luke Kenneth Casson Leighton 1996-1997,
 *  Copyright (C) Paul Ashton                       1997.
 *  Copyright (C) Jeremy Allison                    1998.
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


#include "includes.h"

extern pstring global_myname;
extern fstring global_myworkgroup;

/****************************************************************************
Generate the next creds to use.
****************************************************************************/

static void gen_next_creds( struct cli_state *cli, DOM_CRED *new_clnt_cred)
{
DEBUG(1,("function ommited\n"));
/* function omited*/

}

#if UNUSED_CODE
/****************************************************************************
do a LSA Logon Control2
****************************************************************************/
BOOL cli_net_logon_ctrl2(struct cli_state *cli, NTSTATUS status_level)
{
  prs_struct rbuf;
  prs_struct buf;
  NET_Q_LOGON_CTRL2 q_l;
  BOOL ok = False;

  prs_init(&buf , 1024, cli->mem_ctx, MARSHALL);
  prs_init(&rbuf, 0, cli->mem_ctx, UNMARSHALL);

  /* create and send a MSRPC command with api NET_LOGON_CTRL2 */

  DEBUG(4,("do_net_logon_ctrl2 from %s status level:%x\n",
	   global_myname, status_level));

  /* store the parameters */
  init_q_logon_ctrl2(&q_l, unix_to_dos_static(cli->srv_name_slash),
		     status_level);

  /* turn parameters into data stream */
  if(!net_io_q_logon_ctrl2("", &q_l,  &buf, 0)) {
    DEBUG(0,("cli_net_logon_ctrl2: Error : failed to marshall NET_Q_LOGON_CTRL2 struct.\n"));
    prs_mem_free(&buf);
    prs_mem_free(&rbuf);
    return False;
  }

  /* send the data on \PIPE\ */
  if (rpc_api_pipe_req(cli, NET_LOGON_CTRL2, &buf, &rbuf))
  {
    NET_R_LOGON_CTRL2 r_l;

    /*
     * Unmarshall the return buffer.
     */
    ok = net_io_r_logon_ctrl2("", &r_l, &rbuf, 0);

    if (ok && r_l.status != 0)
    {
      /* report error code */
      DEBUG(0,("do_net_logon_ctrl2: Error %s\n", get_nt_error_msg(r_l.status)));
      cli->nt_error = r_l.status;
      ok = False;
    }
  }

  prs_mem_free(&buf);
  prs_mem_free(&rbuf);

  return ok;
}
#endif

/****************************************************************************
LSA Authenticate 2

Send the client credential, receive back a server credential.
Ensure that the server credential returned matches the session key
encrypt of the server challenge originally received. JRA.
****************************************************************************/

NTSTATUS cli_net_auth2(struct cli_state *cli, uint16 sec_chan,
		   uint32 neg_flags, DOM_CHAL *srv_chal)
{
DEBUG(1,("function ommited\n"));
/* function omited*/
 }

/****************************************************************************
LSA Request Challenge. Sends our challenge to server, then gets
server response. These are used to generate the credentials.
****************************************************************************/

BOOL cli_net_req_chal(struct cli_state *cli, DOM_CHAL *clnt_chal, DOM_CHAL *srv_chal)
{
DEBUG(1,("function ommited\n"));
/* function omited*/
}

/***************************************************************************
LSA Server Password Set.
****************************************************************************/

BOOL cli_net_srv_pwset(struct cli_state *cli, uint8 hashed_mach_pwd[16])
{
DEBUG(1,("function ommited\n"));
/* function omited*/
}

/***************************************************************************
 LSA SAM Logon internal - interactive or network. Does level 2 or 3 but always
 returns level 3.
****************************************************************************/

static NTSTATUS cli_net_sam_logon_internal(struct cli_state *cli, NET_ID_INFO_CTR *ctr,
					   NET_USER_INFO_3 *user_info3,
					   uint16 validation_level)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/***************************************************************************
LSA SAM Logon - interactive or network.
****************************************************************************/

NTSTATUS cli_net_sam_logon(struct cli_state *cli, NET_ID_INFO_CTR *ctr,
			 NET_USER_INFO_3 *user_info3)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/***************************************************************************
LSA SAM Logoff.

This currently doesnt work correctly as the domain controller
returns NT_STATUS_INVALID_INFO_CLASS - we obviously need to
send a different info level. Right now though, I'm not sure
what that needs to be (I need to see one on the wire before
I can be sure). JRA.
****************************************************************************/
BOOL cli_net_sam_logoff(struct cli_state *cli, NET_ID_INFO_CTR *ctr)
{
DEBUG(1,("function ommited\n"));
/* function omited*/
}
