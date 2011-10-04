/*
 *  Unix SMB/Netbios implementation.
 *  Version 1.9.
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

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL net_io_neg_flags(const char *desc, NEG_FLAGS *neg, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a NETLOGON_INFO_3 structure.
********************************************************************/

static void init_netinfo_3(NETLOGON_INFO_3 *info, uint32 flags, uint32 logon_attempts)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a NETLOGON_INFO_3 structure.
********************************************************************/

static BOOL net_io_netinfo_3(const char *desc,  NETLOGON_INFO_3 *info, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
 Inits a NETLOGON_INFO_1 structure.
********************************************************************/

static void init_netinfo_1(NETLOGON_INFO_1 *info, uint32 flags, uint32 pdc_status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a NETLOGON_INFO_1 structure.
********************************************************************/

static BOOL net_io_netinfo_1(const char *desc, NETLOGON_INFO_1 *info, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a NETLOGON_INFO_2 structure.
********************************************************************/

static void init_netinfo_2(NETLOGON_INFO_2 *info, uint32 flags, uint32 pdc_status,
				uint32 tc_status, const char *trusted_dc_name)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a NETLOGON_INFO_2 structure.
********************************************************************/

static BOOL net_io_netinfo_2(const char *desc, NETLOGON_INFO_2 *info, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an NET_Q_LOGON_CTRL2 structure.
********************************************************************/

BOOL net_io_q_logon_ctrl2(const char *desc, NET_Q_LOGON_CTRL2 *q_l, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits an NET_Q_LOGON_CTRL2 structure.
********************************************************************/

void init_net_q_logon_ctrl2(NET_Q_LOGON_CTRL2 *q_l, const char *srv_name,
			    uint32 query_level)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits an NET_R_LOGON_CTRL2 structure.
********************************************************************/

void init_net_r_logon_ctrl2(NET_R_LOGON_CTRL2 *r_l, uint32 query_level,
			    uint32 flags, uint32 pdc_status,
			    uint32 logon_attempts, uint32 tc_status,
			    const char *trusted_domain_name)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an NET_R_LOGON_CTRL2 structure.
********************************************************************/

BOOL net_io_r_logon_ctrl2(const char *desc, NET_R_LOGON_CTRL2 *r_l, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an NET_Q_LOGON_CTRL structure.
********************************************************************/

BOOL net_io_q_logon_ctrl(const char *desc, NET_Q_LOGON_CTRL *q_l, prs_struct *ps,
			 int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits an NET_Q_LOGON_CTRL structure.
********************************************************************/

void init_net_q_logon_ctrl(NET_Q_LOGON_CTRL *q_l, const char *srv_name,
			   uint32 query_level)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits an NET_R_LOGON_CTRL structure.
********************************************************************/

void init_net_r_logon_ctrl(NET_R_LOGON_CTRL *r_l, uint32 query_level,
			   uint32 flags, uint32 pdc_status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an NET_R_LOGON_CTRL structure.
********************************************************************/

BOOL net_io_r_logon_ctrl(const char *desc, NET_R_LOGON_CTRL *r_l, prs_struct *ps,
			 int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits an NET_R_TRUST_DOM_LIST structure.
********************************************************************/

void init_r_trust_dom(NET_R_TRUST_DOM_LIST *r_t,
			uint32 num_doms, const char *dom_name)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an NET_R_TRUST_DOM_LIST structure.
********************************************************************/

BOOL net_io_r_trust_dom(const char *desc, NET_R_TRUST_DOM_LIST *r_t, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
 Reads or writes an NET_Q_TRUST_DOM_LIST structure.
********************************************************************/

BOOL net_io_q_trust_dom(const char *desc, NET_Q_TRUST_DOM_LIST *q_l, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits an NET_Q_REQ_CHAL structure.
********************************************************************/

void init_q_req_chal(NET_Q_REQ_CHAL *q_c,
				const char *logon_srv, const char *logon_clnt,
				DOM_CHAL *clnt_chal)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an NET_Q_REQ_CHAL structure.
********************************************************************/

BOOL net_io_q_req_chal(const char *desc,  NET_Q_REQ_CHAL *q_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL net_io_r_req_chal(const char *desc, NET_R_REQ_CHAL *r_c, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL net_io_q_auth(const char *desc, NET_Q_AUTH *q_a, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL net_io_r_auth(const char *desc, NET_R_AUTH *r_a, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a NET_Q_AUTH_2 struct.
********************************************************************/

void init_q_auth_2(NET_Q_AUTH_2 *q_a,
		const char *logon_srv, const char *acct_name, uint16 sec_chan, const char *comp_name,
		DOM_CHAL *clnt_chal, uint32 clnt_flgs)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL net_io_q_auth_2(const char *desc, NET_Q_AUTH_2 *q_a, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL net_io_r_auth_2(const char *desc, NET_R_AUTH_2 *r_a, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
 Inits a NET_Q_SRV_PWSET.
********************************************************************/

void init_q_srv_pwset(NET_Q_SRV_PWSET *q_s, const char *logon_srv, const char *acct_name,
		uint16 sec_chan, const char *comp_name, DOM_CRED *cred, char nt_cypher[16])
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL net_io_q_srv_pwset(const char *desc, NET_Q_SRV_PWSET *q_s, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL net_io_r_srv_pwset(const char *desc, NET_R_SRV_PWSET *r_s, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*************************************************************************
 Init DOM_SID2 array from a string containing multiple sids
 *************************************************************************/

static int init_dom_sid2s(TALLOC_CTX *ctx, const char *sids_str, DOM_SID2 **ppsids)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a NET_ID_INFO_1 structure.
********************************************************************/

void init_id_info1(NET_ID_INFO_1 *id, const char *domain_name,
				uint32 param_ctrl, uint32 log_id_low, uint32 log_id_high,
				const char *user_name, const char *wksta_name,
				const char *sess_key,
				unsigned char lm_cypher[16], unsigned char nt_cypher[16])
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an NET_ID_INFO_1 structure.
********************************************************************/

static BOOL net_io_id_info1(const char *desc,  NET_ID_INFO_1 *id, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
Inits a NET_ID_INFO_2 structure.

This is a network logon packet. The log_id parameters
are what an NT server would generate for LUID once the
user is logged on. I don't think we care about them.

Note that this has no access to the NT and LM hashed passwords,
so it forwards the challenge, and the NT and LM responses (24
bytes each) over the secure channel to the Domain controller
for it to say yea or nay. This is the preferred method of
checking for a logon as it doesn't export the password
hashes to anyone who has compromised the secure channel. JRA.
********************************************************************/

void init_id_info2(NET_ID_INFO_2 * id, const char *domain_name,
		   uint32 param_ctrl,
		   uint32 log_id_low, uint32 log_id_high,
		   const char *user_name, const char *wksta_name,
		   const uchar lm_challenge[8],
		   const uchar * lm_chal_resp, int lm_chal_resp_len,
		   const uchar * nt_chal_resp, int nt_chal_resp_len)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/

}

/*******************************************************************
 Reads or writes an NET_ID_INFO_2 structure.
********************************************************************/

static BOOL net_io_id_info2(const char *desc,  NET_ID_INFO_2 *id, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
 Inits a DOM_SAM_INFO structure.
********************************************************************/

void init_sam_info(DOM_SAM_INFO *sam,
				const char *logon_srv, const char *comp_name, DOM_CRED *clnt_cred,
				DOM_CRED *rtn_cred, uint16 logon_level,
				NET_ID_INFO_CTR *ctr)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a DOM_SAM_INFO structure.
********************************************************************/

static BOOL net_io_id_info_ctr(const char *desc, NET_ID_INFO_CTR **pp_ctr, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a DOM_SAM_INFO structure.
 ********************************************************************/

static BOOL smb_io_sam_info(const char *desc, DOM_SAM_INFO *sam, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*************************************************************************
 Init
 *************************************************************************/

void init_net_user_info3(TALLOC_CTX *ctx, NET_USER_INFO_3 *usr, SAM_ACCOUNT *sampw,
			 uint16 logon_count, uint16 bad_pw_count,
			 uint32 num_groups, DOM_GID *gids,
			 uint32 user_flgs, uchar *sess_key,
			 const char *logon_srv, const char *logon_dom,
			 DOM_SID *dom_sid, const char *other_sids)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 This code has been modified to cope with a NET_USER_INFO_2 - which is
 exactly the same as a NET_USER_INFO_3, minus the other sids parameters.
 We use validation level to determine if we're marshalling a info 2 or
 INFO_3 - be we always return an INFO_3. Based on code donated by Marc
 Jacobsen at HP. JRA.
********************************************************************/

static BOOL net_io_user_info3(const char *desc, NET_USER_INFO_3 *usr, prs_struct *ps, int depth, uint16 validation_level)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL net_io_q_sam_logon(const char *desc, NET_Q_SAM_LOGON *q_l, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL net_io_r_sam_logon(const char *desc, NET_R_SAM_LOGON *r_l, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL net_io_q_sam_logoff(const char *desc,  NET_Q_SAM_LOGOFF *q_l, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL net_io_r_sam_logoff(const char *desc, NET_R_SAM_LOGOFF *r_l, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
makes a NET_Q_SAM_SYNC structure.
********************************************************************/
BOOL init_net_q_sam_sync(NET_Q_SAM_SYNC * q_s, const char *srv_name,
			 const char *cli_name, DOM_CRED * cli_creds,
			 DOM_CRED *ret_creds, uint32 database_id)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
BOOL net_io_q_sam_sync(const char *desc, NET_Q_SAM_SYNC * q_s, prs_struct *ps,
		       int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
static BOOL net_io_sam_delta_hdr(const char *desc, SAM_DELTA_HDR * delta,
				 prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
static BOOL net_io_sam_delta_stamp(const char *desc, SAM_DELTA_STAMP *info,
				   prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
static BOOL net_io_sam_domain_info(const char *desc, SAM_DOMAIN_INFO * info,
				   prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
static BOOL net_io_sam_group_info(const char *desc, SAM_GROUP_INFO * info,
				  prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
static BOOL net_io_sam_passwd_info(const char *desc, SAM_PWD * pwd,
				   prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
makes a SAM_ACCOUNT_INFO structure.
********************************************************************/
BOOL make_sam_account_info(SAM_ACCOUNT_INFO * info,
			   const UNISTR2 *user_name,
			   const UNISTR2 *full_name,
			   uint32 user_rid, uint32 group_rid,
			   const UNISTR2 *home_dir,
			   const UNISTR2 *dir_drive,
			   const UNISTR2 *log_scr,
			   const UNISTR2 *desc,
			   uint32 acb_info,
			   const UNISTR2 *prof_path,
			   const UNISTR2 *wkstas,
			   const UNISTR2 *unk_str, const UNISTR2 *mung_dial)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
static BOOL net_io_sam_account_info(const char *desc, uint8 sess_key[16],
				    SAM_ACCOUNT_INFO * info, prs_struct *ps,
				    int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
static BOOL net_io_sam_group_mem_info(const char *desc, SAM_GROUP_MEM_INFO * info,
				      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
static BOOL net_io_sam_alias_info(const char *desc, SAM_ALIAS_INFO * info,
				  prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
static BOOL net_io_sam_alias_mem_info(const char *desc, SAM_ALIAS_MEM_INFO * info,
				      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
static BOOL net_io_sam_delta_ctr(const char *desc, uint8 sess_key[16],
				 SAM_DELTA_CTR * delta, uint16 type,
				 prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
BOOL net_io_r_sam_sync(const char *desc, uint8 sess_key[16],
		       NET_R_SAM_SYNC * r_s, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
makes a NET_Q_SAM_DELTAS structure.
********************************************************************/
BOOL init_net_q_sam_deltas(NET_Q_SAM_DELTAS *q_s, const char *srv_name,
			   const char *cli_name, DOM_CRED *cli_creds,
			   uint32 database_id, UINT64_S dom_mod_count)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
BOOL net_io_q_sam_deltas(const char *desc, NET_Q_SAM_DELTAS *q_s, prs_struct *ps,
			 int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
BOOL net_io_r_sam_deltas(const char *desc, uint8 sess_key[16],
			 NET_R_SAM_DELTAS *r_s, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}
