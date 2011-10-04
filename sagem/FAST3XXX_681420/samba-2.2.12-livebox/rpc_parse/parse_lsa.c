/*
 *  Unix SMB/CIFS implementation.
 *  RPC Pipe client / server routines
 *  Copyright (C) Andrew Tridgell              1992-1997,
 *  Copyright (C) Luke Kenneth Casson Leighton 1996-1997,
 *  Copyright (C) Paul Ashton                       1997.
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

static BOOL lsa_io_trans_names(const char *desc, LSA_TRANS_NAME_ENUM *trn, prs_struct *ps, int depth);

/*******************************************************************
 Inits a LSA_TRANS_NAME structure.
********************************************************************/

void init_lsa_trans_name(LSA_TRANS_NAME *trn, UNISTR2 *uni_name,
			 uint16 sid_name_use, const char *name, uint32 idx)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a LSA_TRANS_NAME structure.
********************************************************************/

static BOOL lsa_io_trans_name(const char *desc, LSA_TRANS_NAME *trn, prs_struct *ps,
			      int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a DOM_R_REF structure.
********************************************************************/

static BOOL lsa_io_dom_r_ref(const char *desc, DOM_R_REF *r_r, prs_struct *ps,
			     int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits an LSA_SEC_QOS structure.
********************************************************************/

void init_lsa_sec_qos(LSA_SEC_QOS *qos, uint16 imp_lev, uint8 ctxt, uint8 eff)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_SEC_QOS structure.
********************************************************************/

static BOOL lsa_io_sec_qos(const char *desc,  LSA_SEC_QOS *qos, prs_struct *ps,
			   int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits an LSA_OBJ_ATTR structure.
********************************************************************/

void init_lsa_obj_attr(LSA_OBJ_ATTR *attr, uint32 attributes, LSA_SEC_QOS *qos)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_OBJ_ATTR structure.
********************************************************************/

static BOOL lsa_io_obj_attr(const char *desc, LSA_OBJ_ATTR *attr, prs_struct *ps,
			    int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
 Inits an LSA_Q_OPEN_POL structure.
********************************************************************/

void init_q_open_pol(LSA_Q_OPEN_POL *r_q, uint16 system_name,
		     uint32 attributes, uint32 desired_access,
		     LSA_SEC_QOS *qos)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_Q_OPEN_POL structure.
********************************************************************/

BOOL lsa_io_q_open_pol(const char *desc, LSA_Q_OPEN_POL *r_q, prs_struct *ps,
		       int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_R_OPEN_POL structure.
********************************************************************/

BOOL lsa_io_r_open_pol(const char *desc, LSA_R_OPEN_POL *r_p, prs_struct *ps,
		       int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits an LSA_Q_OPEN_POL2 structure.
********************************************************************/

void init_q_open_pol2(LSA_Q_OPEN_POL2 *r_q, const char *server_name,
			uint32 attributes, uint32 desired_access,
			LSA_SEC_QOS *qos)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_Q_OPEN_POL2 structure.
********************************************************************/

BOOL lsa_io_q_open_pol2(const char *desc, LSA_Q_OPEN_POL2 *r_q, prs_struct *ps,
			int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_R_OPEN_POL2 structure.
********************************************************************/

BOOL lsa_io_r_open_pol2(const char *desc, LSA_R_OPEN_POL2 *r_p, prs_struct *ps,
			int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
makes an LSA_Q_QUERY_SEC_OBJ structure.
********************************************************************/

void init_q_query_sec_obj(LSA_Q_QUERY_SEC_OBJ *q_q, const POLICY_HND *hnd,
			  uint32 sec_info)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_Q_QUERY_SEC_OBJ structure.
********************************************************************/

BOOL lsa_io_q_query_sec_obj(const char *desc, LSA_Q_QUERY_SEC_OBJ *q_q,
			    prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a LSA_R_QUERY_SEC_OBJ structure.
********************************************************************/

BOOL lsa_io_r_query_sec_obj(const char *desc, LSA_R_QUERY_SEC_OBJ *r_u,
			    prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits an LSA_Q_QUERY_INFO structure.
********************************************************************/

void init_q_query(LSA_Q_QUERY_INFO *q_q, POLICY_HND *hnd, uint16 info_class)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_Q_QUERY_INFO structure.
********************************************************************/

BOOL lsa_io_q_query(const char *desc, LSA_Q_QUERY_INFO *q_q, prs_struct *ps,
		    int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
makes an LSA_Q_ENUM_TRUST_DOM structure.
********************************************************************/
BOOL init_q_enum_trust_dom(LSA_Q_ENUM_TRUST_DOM * q_e, POLICY_HND *pol,
			   uint32 enum_context, uint32 preferred_len)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_Q_ENUM_TRUST_DOM structure.
********************************************************************/

BOOL lsa_io_q_enum_trust_dom(const char *desc, LSA_Q_ENUM_TRUST_DOM *q_e,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits an LSA_R_ENUM_TRUST_DOM structure.
********************************************************************/

void init_r_enum_trust_dom(TALLOC_CTX *ctx, LSA_R_ENUM_TRUST_DOM *r_e, uint32 enum_context,
			   const char *domain_name, DOM_SID *domain_sid,
			   NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_R_ENUM_TRUST_DOM structure.
********************************************************************/

BOOL lsa_io_r_enum_trust_dom(const char *desc, LSA_R_ENUM_TRUST_DOM *r_e,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a dom query structure.
********************************************************************/

static BOOL lsa_io_dom_query(const char *desc, DOM_QUERY *d_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL lsa_io_dom_query_2(const char *desc, DOM_QUERY_2 *d_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a dom query structure.
********************************************************************/

static BOOL lsa_io_dom_query_3(const char *desc, DOM_QUERY_3 *d_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a dom query structure.
********************************************************************/

BOOL lsa_io_dom_query_5(const char *desc, DOM_QUERY_5 *d_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a dom query structure.
********************************************************************/

static BOOL lsa_io_dom_query_6(const char *desc, DOM_QUERY_6 *d_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_R_QUERY_INFO structure.
********************************************************************/

BOOL lsa_io_r_query(const char *desc, LSA_R_QUERY_INFO *r_q, prs_struct *ps,
		    int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a LSA_SID_ENUM structure.
********************************************************************/

void init_lsa_sid_enum(TALLOC_CTX *mem_ctx, LSA_SID_ENUM *sen,
		       int num_entries, DOM_SID *sids)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a LSA_SID_ENUM structure.
********************************************************************/

static BOOL lsa_io_sid_enum(const char *desc, LSA_SID_ENUM *sen, prs_struct *ps,
			    int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits an LSA_R_ENUM_TRUST_DOM structure.
********************************************************************/

void init_q_lookup_sids(TALLOC_CTX *mem_ctx, LSA_Q_LOOKUP_SIDS *q_l,
			POLICY_HND *hnd, int num_sids, DOM_SID *sids,
			uint16 level)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a LSA_Q_LOOKUP_SIDS structure.
********************************************************************/

BOOL lsa_io_q_lookup_sids(const char *desc, LSA_Q_LOOKUP_SIDS *q_s, prs_struct *ps,
			  int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL lsa_io_trans_names(const char *desc, LSA_TRANS_NAME_ENUM *trn,
		prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL lsa_io_r_lookup_sids(const char *desc, LSA_R_LOOKUP_SIDS *r_s,
			  prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
makes a structure.
********************************************************************/

void init_q_lookup_names(TALLOC_CTX *mem_ctx, LSA_Q_LOOKUP_NAMES *q_l,
			 POLICY_HND *hnd, int num_names, const char **names)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL lsa_io_q_lookup_names(const char *desc, LSA_Q_LOOKUP_NAMES *q_r,
			   prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL lsa_io_r_lookup_names(const char *desc, LSA_R_LOOKUP_NAMES *r_r,
			   prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
 Inits an LSA_Q_CLOSE structure.
********************************************************************/

void init_lsa_q_close(LSA_Q_CLOSE *q_c, POLICY_HND *hnd)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_Q_CLOSE structure.
********************************************************************/

BOOL lsa_io_q_close(const char *desc, LSA_Q_CLOSE *q_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_R_CLOSE structure.
********************************************************************/

BOOL lsa_io_r_close(const char *desc,  LSA_R_CLOSE *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_Q_OPEN_SECRET structure.
********************************************************************/

BOOL lsa_io_q_open_secret(const char *desc, LSA_Q_OPEN_SECRET *q_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_R_OPEN_SECRET structure.
********************************************************************/

BOOL lsa_io_r_open_secret(const char *desc, LSA_R_OPEN_SECRET *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits an LSA_Q_ENUM_PRIVS structure.
********************************************************************/

void init_q_enum_privs(LSA_Q_ENUM_PRIVS *q_q, POLICY_HND *hnd, uint32 enum_context, uint32 pref_max_length)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
BOOL lsa_io_q_enum_privs(const char *desc, LSA_Q_ENUM_PRIVS *q_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
static BOOL lsa_io_priv_entries(const char *desc, LSA_PRIV_ENTRY *entries, uint32 count, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits an LSA_R_ENUM_PRIVS structure.
********************************************************************/

void init_lsa_r_enum_privs(LSA_R_ENUM_PRIVS *r_u, uint32 enum_context,
			  uint32 count, LSA_PRIV_ENTRY *entries)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
BOOL lsa_io_r_enum_privs(const char *desc, LSA_R_ENUM_PRIVS *r_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

void init_lsa_priv_get_dispname(LSA_Q_PRIV_GET_DISPNAME *trn, POLICY_HND *hnd, const char *name, uint16 lang_id, uint16 lang_id_sys)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
BOOL lsa_io_q_priv_get_dispname(const char *desc, LSA_Q_PRIV_GET_DISPNAME *q_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
BOOL lsa_io_r_priv_get_dispname(const char *desc, LSA_R_PRIV_GET_DISPNAME *r_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

void init_lsa_q_enum_accounts(LSA_Q_ENUM_ACCOUNTS *trn, POLICY_HND *hnd, uint32 enum_context, uint32 pref_max_length)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
BOOL lsa_io_q_enum_accounts(const char *desc, LSA_Q_ENUM_ACCOUNTS *q_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits an LSA_R_ENUM_PRIVS structure.
********************************************************************/

void init_lsa_r_enum_accounts(LSA_R_ENUM_ACCOUNTS *r_u, uint32 enum_context)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
BOOL lsa_io_r_enum_accounts(const char *desc, LSA_R_ENUM_ACCOUNTS *r_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
 Reads or writes an LSA_Q_UNK_GET_CONNUSER structure.
********************************************************************/

BOOL lsa_io_q_unk_get_connuser(const char *desc, LSA_Q_UNK_GET_CONNUSER *q_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_R_UNK_GET_CONNUSER structure.
********************************************************************/

BOOL lsa_io_r_unk_get_connuser(const char *desc, LSA_R_UNK_GET_CONNUSER *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

void init_lsa_q_open_account(LSA_Q_OPENACCOUNT *trn, POLICY_HND *hnd, DOM_SID *sid, uint32 desired_access)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_Q_OPENACCOUNT structure.
********************************************************************/

BOOL lsa_io_q_open_account(const char *desc, LSA_Q_OPENACCOUNT *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_R_OPENACCOUNT structure.
********************************************************************/

BOOL lsa_io_r_open_account(const char *desc, LSA_R_OPENACCOUNT  *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


void init_lsa_q_enum_privsaccount(LSA_Q_ENUMPRIVSACCOUNT *trn, POLICY_HND *hnd)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/

}

/*******************************************************************
 Reads or writes an LSA_Q_ENUMPRIVSACCOUNT structure.
********************************************************************/

BOOL lsa_io_q_enum_privsaccount(const char *desc, LSA_Q_ENUMPRIVSACCOUNT *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LUID structure.
********************************************************************/

BOOL lsa_io_luid(const char *desc, LUID *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LUID_ATTR structure.
********************************************************************/

BOOL lsa_io_luid_attr(const char *desc, LUID_ATTR *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an PRIVILEGE_SET structure.
********************************************************************/

BOOL lsa_io_privilege_set(const char *desc, PRIVILEGE_SET *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

void init_lsa_r_enum_privsaccount(LSA_R_ENUMPRIVSACCOUNT *r_u, LUID_ATTR *set, uint32 count, uint32 control)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_R_ENUMPRIVSACCOUNT structure.
********************************************************************/

BOOL lsa_io_r_enum_privsaccount(const char *desc, LSA_R_ENUMPRIVSACCOUNT *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}



/*******************************************************************
 Reads or writes an  LSA_Q_GETSYSTEMACCOUNTstructure.
********************************************************************/

BOOL lsa_io_q_getsystemaccount(const char *desc, LSA_Q_GETSYSTEMACCOUNT  *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an  LSA_R_GETSYSTEMACCOUNTstructure.
********************************************************************/

BOOL lsa_io_r_getsystemaccount(const char *desc, LSA_R_GETSYSTEMACCOUNT  *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
 Reads or writes an LSA_Q_SETSYSTEMACCOUNT structure.
********************************************************************/

BOOL lsa_io_q_setsystemaccount(const char *desc, LSA_Q_SETSYSTEMACCOUNT  *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_R_SETSYSTEMACCOUNT structure.
********************************************************************/

BOOL lsa_io_r_setsystemaccount(const char *desc, LSA_R_SETSYSTEMACCOUNT  *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


void init_lsa_q_lookupprivvalue(LSA_Q_LOOKUPPRIVVALUE *trn, POLICY_HND *hnd, const char *name)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_Q_LOOKUPPRIVVALUE  structure.
********************************************************************/

BOOL lsa_io_q_lookupprivvalue(const char *desc, LSA_Q_LOOKUPPRIVVALUE  *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an  LSA_R_LOOKUPPRIVVALUE structure.
********************************************************************/

BOOL lsa_io_r_lookupprivvalue(const char *desc, LSA_R_LOOKUPPRIVVALUE  *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
 Reads or writes an LSA_Q_ADDPRIVS structure.
********************************************************************/

BOOL lsa_io_q_addprivs(const char *desc, LSA_Q_ADDPRIVS *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_R_ADDPRIVS structure.
********************************************************************/

BOOL lsa_io_r_addprivs(const char *desc, LSA_R_ADDPRIVS *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_Q_REMOVEPRIVS structure.
********************************************************************/

BOOL lsa_io_q_removeprivs(const char *desc, LSA_Q_REMOVEPRIVS *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an LSA_R_REMOVEPRIVS structure.
********************************************************************/

BOOL lsa_io_r_removeprivs(const char *desc, LSA_R_REMOVEPRIVS *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

BOOL policy_handle_is_valid(const POLICY_HND *hnd)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}
