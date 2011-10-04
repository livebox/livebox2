/*
 *  Unix SMB/Netbios implementation.
 *  Version 1.9.
 *  RPC Pipe client / server routines
 *  Copyright (C) Andrew Tridgell              1992-1997,
 *  Copyright (C) Luke Kenneth Casson Leighton 1996-1997,
 *  Copyright (C) Paul Ashton                       1997.
 *  Copyright (C) Jeremy Allison               1998-2001.
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

/* This is the interface to the netlogon pipe. */

#include "includes.h"

/*************************************************************************
 api_net_req_chal:
 *************************************************************************/

static BOOL api_net_req_chal(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 api_net_auth:
 *************************************************************************/

static BOOL api_net_auth(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 api_net_auth_2:
 *************************************************************************/

static BOOL api_net_auth_2(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 api_net_srv_pwset:
 *************************************************************************/

static BOOL api_net_srv_pwset(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 api_net_sam_logoff:
 *************************************************************************/

static BOOL api_net_sam_logoff(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 api_net_sam_logon:
 *************************************************************************/

static BOOL api_net_sam_logon(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 api_net_trust_dom_list:
 *************************************************************************/

static BOOL api_net_trust_dom_list(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 api_net_logon_ctrl2:
 *************************************************************************/

static BOOL api_net_logon_ctrl2(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 api_net_logon_ctrl:
 *************************************************************************/

static BOOL api_net_logon_ctrl(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 array of \PIPE\NETLOGON operations
 ********************************************************************/
static struct api_struct api_net_cmds [] =
{
	{ "NET_REQCHAL"       , NET_REQCHAL       , api_net_req_chal       },
	{ "NET_AUTH"          , NET_AUTH          , api_net_auth           },
	{ "NET_AUTH2"         , NET_AUTH2         , api_net_auth_2         },
	{ "NET_SRVPWSET"      , NET_SRVPWSET      , api_net_srv_pwset      },
	{ "NET_SAMLOGON"      , NET_SAMLOGON      , api_net_sam_logon      },
	{ "NET_SAMLOGOFF"     , NET_SAMLOGOFF     , api_net_sam_logoff     },
	{ "NET_LOGON_CTRL2"   , NET_LOGON_CTRL2   , api_net_logon_ctrl2    },
	{ "NET_TRUST_DOM_LIST", NET_TRUST_DOM_LIST, api_net_trust_dom_list },
	{ "NET_LOGON_CTRL"    , NET_LOGON_CTRL    , api_net_logon_ctrl     },
	{  NULL               , 0                 , NULL                   }
};

/*******************************************************************
 receives a netlogon pipe and responds.
 ********************************************************************/

BOOL api_netlog_rpc(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}
