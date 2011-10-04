/*
 *  Unix SMB/Netbios implementation.
 *  Version 1.9.
 *  RPC Pipe client / server routines
 *  Copyright (C) Andrew Tridgell              1992-1997,
 *  Copyright (C) Luke Kenneth Casson Leighton 1996-1997,
 *  Copyright (C) Paul Ashton                       1997.
 *  Copyright (C) Jeremy Allison                    2001.
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

/* This is the interface to the lsa server code. */

#include "includes.h"

/***************************************************************************
 api_lsa_open_policy2
 ***************************************************************************/

static BOOL api_lsa_open_policy2(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
api_lsa_open_policy
 ***************************************************************************/

static BOOL api_lsa_open_policy(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
 api_lsa_enum_trust_dom
 ***************************************************************************/

static BOOL api_lsa_enum_trust_dom(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
 api_lsa_query_info
 ***************************************************************************/

static BOOL api_lsa_query_info(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
 api_lsa_lookup_sids
 ***************************************************************************/

static BOOL api_lsa_lookup_sids(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
 api_lsa_lookup_names
 ***************************************************************************/

static BOOL api_lsa_lookup_names(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
 api_lsa_close.
 ***************************************************************************/

static BOOL api_lsa_close(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
 api_lsa_open_secret.
 ***************************************************************************/

static BOOL api_lsa_open_secret(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
 api_lsa_open_secret.
 ***************************************************************************/

static BOOL api_lsa_enum_privs(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
 api_lsa_open_secret.
 ***************************************************************************/

static BOOL api_lsa_priv_get_dispname(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

#if 0
/***************************************************************************
 api_lsa_open_secret.
 ***************************************************************************/

static BOOL api_lsa_enum_accounts(pipes_struct *p)
{
	LSA_Q_ENUM_ACCOUNTS q_u;
	LSA_R_ENUM_ACCOUNTS r_u;
	prs_struct *data = &p->in_data.data;
	prs_struct *rdata = &p->out_data.rdata;

	ZERO_STRUCT(q_u);
	ZERO_STRUCT(r_u);

	if(!lsa_io_q_enum_accounts("", &q_u, data, 0)) {
		DEBUG(0,("api_lsa_enum_accounts: failed to unmarshall LSA_Q_ENUM_ACCOUNTS.\n"));
		return False;
	}

	r_u.status = _lsa_enum_accounts(p, &q_u, &r_u);

	/* store the response in the SMB stream */
	if(!lsa_io_r_enum_accounts("", &r_u, rdata, 0)) {
		DEBUG(0,("api_lsa_enum_accounts: Failed to marshall LSA_R_ENUM_ACCOUNTS.\n"));
		return False;
	}

	return True;
}
#endif

/***************************************************************************
 api_lsa_UNK_GET_CONNUSER
 ***************************************************************************/

static BOOL api_lsa_unk_get_connuser(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
 api_lsa_open_user
 ***************************************************************************/

static BOOL api_lsa_open_account(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

#if 0
/***************************************************************************
 api_lsa_get_privs
 ***************************************************************************/

static BOOL api_lsa_enum_privsaccount(pipes_struct *p)
{
	LSA_Q_ENUMPRIVSACCOUNT q_u;
	LSA_R_ENUMPRIVSACCOUNT r_u;

	prs_struct *data = &p->in_data.data;
	prs_struct *rdata = &p->out_data.rdata;

	ZERO_STRUCT(q_u);
	ZERO_STRUCT(r_u);

	if(!lsa_io_q_enum_privsaccount("", &q_u, data, 0)) {
		DEBUG(0,("api_lsa_enum_privsaccount: failed to unmarshall LSA_Q_ENUMPRIVSACCOUNT.\n"));
		return False;
	}

	r_u.status = _lsa_enum_privsaccount(p, &q_u, &r_u);

	/* store the response in the SMB stream */
	if(!lsa_io_r_enum_privsaccount("", &r_u, rdata, 0)) {
		DEBUG(0,("api_lsa_enum_privsaccount: Failed to marshall LSA_R_ENUMPRIVSACCOUNT.\n"));
		return False;
	}

	return True;
}
#endif

/***************************************************************************
 api_lsa_getsystemaccount
 ***************************************************************************/

static BOOL api_lsa_getsystemaccount(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}


/***************************************************************************
 \PIPE\ntlsa commands
 ***************************************************************************/

static struct api_struct api_lsa_cmds[] =
{
	{ "LSA_OPENPOLICY2"     , LSA_OPENPOLICY2     , api_lsa_open_policy2   },
	{ "LSA_OPENPOLICY"      , LSA_OPENPOLICY      , api_lsa_open_policy    },
	{ "LSA_QUERYINFOPOLICY" , LSA_QUERYINFOPOLICY , api_lsa_query_info     },
	{ "LSA_ENUMTRUSTDOM"    , LSA_ENUMTRUSTDOM    , api_lsa_enum_trust_dom },
	{ "LSA_CLOSE"           , LSA_CLOSE           , api_lsa_close          },
	{ "LSA_OPENSECRET"      , LSA_OPENSECRET      , api_lsa_open_secret    },
	{ "LSA_LOOKUPSIDS"      , LSA_LOOKUPSIDS      , api_lsa_lookup_sids    },
	{ "LSA_LOOKUPNAMES"     , LSA_LOOKUPNAMES     , api_lsa_lookup_names   },
	{ "LSA_ENUM_PRIVS"      , LSA_ENUM_PRIVS      , api_lsa_enum_privs     },
	{ "LSA_PRIV_GET_DISPNAME",LSA_PRIV_GET_DISPNAME,api_lsa_priv_get_dispname},
#if 0
	{ "LSA_ENUM_ACCOUNTS"   , LSA_ENUM_ACCOUNTS   , api_lsa_enum_accounts  },
#endif
	{ "LSA_UNK_GET_CONNUSER", LSA_UNK_GET_CONNUSER, api_lsa_unk_get_connuser},
	{ "LSA_OPENACCOUNT"     , LSA_OPENACCOUNT     , api_lsa_open_account    },
#if 0
	{ "LSA_ENUMPRIVSACCOUNT", LSA_ENUMPRIVSACCOUNT, api_lsa_enum_privsaccount},
#endif
	{ "LSA_GETSYSTEMACCOUNT", LSA_GETSYSTEMACCOUNT, api_lsa_getsystemaccount},
	{ NULL                  , 0                   , NULL                   }
};

/***************************************************************************
 api_ntLsarpcTNP
 ***************************************************************************/
BOOL api_ntlsa_rpc(pipes_struct *p)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}
