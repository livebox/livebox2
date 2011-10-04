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

/* This is the implementation of the lsa server code. */

#include "includes.h"

extern DOM_SID global_sam_sid;
extern fstring global_myworkgroup;
extern pstring global_myname;

static PRIVS privs[] = {
    {SE_PRIV_NONE, "no_privs", "No privilege"},
    {SE_PRIV_ADD_USERS, "add_users", "add users"},
    {SE_PRIV_ADD_MACHINES, "add_computers", "add computers to domain"},
    {SE_PRIV_PRINT_OPERATOR, "print_op", "printer operator"},
    {SE_PRIV_ALL, "all_privs", "all privileges"}
};

struct lsa_info {
    DOM_SID sid;
    uint32 access;
};

/*******************************************************************
 Function to free the per handle data.
 ********************************************************************/

static void free_lsa_info(void *ptr)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
Init dom_query
 ***************************************************************************/

static void init_dom_query(DOM_QUERY *d_q, char *dom_name, DOM_SID *dom_sid)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
 init_dom_ref - adds a domain if it's not already in, returns the index.
***************************************************************************/

static int init_dom_ref(DOM_R_REF *ref, char *dom_name, DOM_SID *dom_sid)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
 init_lsa_rid2s
 ***************************************************************************/

static void init_lsa_rid2s(DOM_R_REF *ref, DOM_RID2 *rid2,
				int num_entries, UNISTR2 *name,
				uint32 *mapped_count, BOOL endian)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
 init_reply_lookup_names
 ***************************************************************************/

static void init_reply_lookup_names(LSA_R_LOOKUP_NAMES *r_l,
		DOM_R_REF *ref, uint32 num_entries,
		DOM_RID2 *rid2, uint32 mapped_count)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
 Init lsa_trans_names.
 ***************************************************************************/

static void init_lsa_trans_names(TALLOC_CTX *ctx, DOM_R_REF *ref, LSA_TRANS_NAME_ENUM *trn,
				 int num_entries, DOM_SID2 *sid,
				 uint32 *mapped_count)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
 Init_reply_lookup_sids.
 ***************************************************************************/

static void init_reply_lookup_sids(LSA_R_LOOKUP_SIDS *r_l,
		DOM_R_REF *ref, LSA_TRANS_NAME_ENUM *names,
		uint32 mapped_count)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
 _lsa_open_policy2.
 ***************************************************************************/

NTSTATUS _lsa_open_policy2(pipes_struct *p, LSA_Q_OPEN_POL2 *q_u, LSA_R_OPEN_POL2 *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
 _lsa_open_policy
 ***************************************************************************/

NTSTATUS _lsa_open_policy(pipes_struct *p, LSA_Q_OPEN_POL *q_u, LSA_R_OPEN_POL *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
 _lsa_enum_trust_dom - this needs fixing to do more than return NULL ! JRA.
 ***************************************************************************/

NTSTATUS _lsa_enum_trust_dom(pipes_struct *p, LSA_Q_ENUM_TRUST_DOM *q_u, LSA_R_ENUM_TRUST_DOM *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
 _lsa_query_info. See the POLICY_INFOMATION_CLASS docs at msdn.
 ***************************************************************************/

NTSTATUS _lsa_query_info(pipes_struct *p, LSA_Q_QUERY_INFO *q_u, LSA_R_QUERY_INFO *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
 _lsa_lookup_sids
 ***************************************************************************/

NTSTATUS _lsa_lookup_sids(pipes_struct *p, LSA_Q_LOOKUP_SIDS *q_u, LSA_R_LOOKUP_SIDS *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
lsa_reply_lookup_names
 ***************************************************************************/

NTSTATUS _lsa_lookup_names(pipes_struct *p,LSA_Q_LOOKUP_NAMES *q_u, LSA_R_LOOKUP_NAMES *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
 _lsa_close. Also weird - needs to check if lsa handle is correct. JRA.
 ***************************************************************************/

NTSTATUS _lsa_close(pipes_struct *p, LSA_Q_CLOSE *q_u, LSA_R_CLOSE *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
  "No more secrets Marty...." :-).
 ***************************************************************************/

NTSTATUS _lsa_open_secret(pipes_struct *p, LSA_Q_OPEN_SECRET *q_u, LSA_R_OPEN_SECRET *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
_lsa_enum_privs.
 ***************************************************************************/

NTSTATUS _lsa_enum_privs(pipes_struct *p, LSA_Q_ENUM_PRIVS *q_u, LSA_R_ENUM_PRIVS *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************
_lsa_priv_get_dispname.
 ***************************************************************************/

NTSTATUS _lsa_priv_get_dispname(pipes_struct *p, LSA_Q_PRIV_GET_DISPNAME *q_u, LSA_R_PRIV_GET_DISPNAME *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

NTSTATUS _lsa_unk_get_connuser(pipes_struct *p, LSA_Q_UNK_GET_CONNUSER *q_u, LSA_R_UNK_GET_CONNUSER *r_u)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************

 ***************************************************************************/

NTSTATUS _lsa_open_account(pipes_struct *p, LSA_Q_OPENACCOUNT *q_u, LSA_R_OPENACCOUNT *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************************

 ***************************************************************************/

NTSTATUS _lsa_getsystemaccount(pipes_struct *p, LSA_Q_GETSYSTEMACCOUNT *q_u, LSA_R_GETSYSTEMACCOUNT *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}
