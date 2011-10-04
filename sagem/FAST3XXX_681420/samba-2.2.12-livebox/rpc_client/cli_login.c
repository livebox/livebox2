/*
   Unix SMB/Netbios implementation.
   Version 1.9.
   NT Domain Authentication SMB / MSRPC client
   Copyright (C) Andrew Tridgell 1994-1997
   Copyright (C) Luke Kenneth Casson Leighton 1996-1997
   Copyright (C) Jeremy Allison  1999.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include "includes.h"

extern fstring global_myworkgroup;
extern pstring global_myname;

/****************************************************************************
Initialize domain session credentials.
****************************************************************************/

NTSTATUS cli_nt_setup_creds(struct cli_state *cli, unsigned char mach_pwd[16])
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Set machine password.
 ****************************************************************************/

BOOL cli_nt_srv_pwset(struct cli_state *cli, unsigned char *new_hashof_mach_pwd)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
NT login - interactive.
*NEVER* use this code. This method of doing a logon (sending the cleartext
password equivalents, protected by the session key) is inherently insecure
given the current design of the NT Domain system. JRA.
 ****************************************************************************/

NTSTATUS cli_nt_login_interactive(struct cli_state *cli, char *unix_domain, char *unix_username,
				uint32 smb_userid_low, char *unix_password,
				NET_ID_INFO_CTR *ctr, NET_USER_INFO_3 *user_info3)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
NT login - network.
*ALWAYS* use this call to validate a user as it does not expose plaintext
password equivalents over the network. JRA.
****************************************************************************/

NTSTATUS cli_nt_login_network(struct cli_state *cli, char *unix_domain, char *unix_username,
				uint32 smb_userid_low, const char lm_chal[8],
				const char *lm_chal_resp, const char *nt_chal_resp,
				NET_ID_INFO_CTR *ctr, NET_USER_INFO_3 *user_info3)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
NT Logoff.
****************************************************************************/

BOOL cli_nt_logoff(struct cli_state *cli, NET_ID_INFO_CTR *ctr)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}
