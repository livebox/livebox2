/*
 *  Unix SMB/Netbios implementation.
 *  Version 1.9.
 *  RPC Pipe client / server routines
 *  Copyright (C) Andrew Tridgell              1992-2000,
 *  Copyright (C) Luke Kenneth Casson Leighton 1996-2000,
 *  Copyright (C) Paul Ashton                  1997-2000,
 *  Copyright (C) Elrond                            2000,
 *  Copyright (C) Jeremy Allison                    2001
 *  Copyright (C) Jean Fran�ois Micouleau      1998-2001.
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
#include "rpc_parse.h"
#include "nterr.h"

/*******************************************************************
inits a SAMR_Q_CLOSE_HND structure.
********************************************************************/

void init_samr_q_close_hnd(SAMR_Q_CLOSE_HND * q_c, POLICY_HND *hnd)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_close_hnd(const char *desc, SAMR_Q_CLOSE_HND * q_u,
			 prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_close_hnd(const char *desc, SAMR_R_CLOSE_HND * r_u,
			 prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_LOOKUP_DOMAIN structure.
********************************************************************/

void init_samr_q_lookup_domain(SAMR_Q_LOOKUP_DOMAIN * q_u,
			       POLICY_HND *pol, const char *dom_name)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
BOOL samr_io_q_lookup_domain(const char *desc, SAMR_Q_LOOKUP_DOMAIN * q_u,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_LOOKUP_DOMAIN structure.
********************************************************************/

void init_samr_r_lookup_domain(SAMR_R_LOOKUP_DOMAIN * r_u,
			       DOM_SID *dom_sid, NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_lookup_domain(const char *desc, SAMR_R_LOOKUP_DOMAIN * r_u,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

void init_samr_q_unknown_2d(SAMR_Q_UNKNOWN_2D * q_u, POLICY_HND *dom_pol, DOM_SID *sid)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_unknown_2d(const char *desc, SAMR_Q_UNKNOWN_2D * q_u,
			  prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_unknown_2d(const char *desc, SAMR_R_UNKNOWN_2D * r_u,
			  prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

void init_samr_q_open_domain(SAMR_Q_OPEN_DOMAIN * q_u,
			     POLICY_HND *pol, uint32 flags,
			     const DOM_SID *sid)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_open_domain(const char *desc, SAMR_Q_OPEN_DOMAIN * q_u,
			   prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_open_domain(const char *desc, SAMR_R_OPEN_DOMAIN * r_u,
			   prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

void init_samr_q_get_usrdom_pwinfo(SAMR_Q_GET_USRDOM_PWINFO * q_u,
				   POLICY_HND *user_pol)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_get_usrdom_pwinfo(const char *desc, SAMR_Q_GET_USRDOM_PWINFO * q_u,
				 prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Init.
********************************************************************/

void init_samr_r_get_usrdom_pwinfo(SAMR_R_GET_USRDOM_PWINFO *r_u, NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_get_usrdom_pwinfo(const char *desc, SAMR_R_GET_USRDOM_PWINFO * r_u,
				 prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

void init_samr_q_query_sec_obj(SAMR_Q_QUERY_SEC_OBJ * q_u,
			       POLICY_HND *user_pol, uint32 sec_info)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_query_sec_obj(const char *desc, SAMR_Q_QUERY_SEC_OBJ * q_u,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

void init_samr_q_query_dom_info(SAMR_Q_QUERY_DOMAIN_INFO * q_u,
				POLICY_HND *domain_pol, uint16 switch_value)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_query_dom_info(const char *desc, SAMR_Q_QUERY_DOMAIN_INFO * q_u,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
inits a structure.
********************************************************************/

void init_unk_info3(SAM_UNK_INFO_3 *u_3, NTTIME nt_logout)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL sam_io_unk_info3(const char *desc, SAM_UNK_INFO_3 * u_3,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a structure.
********************************************************************/

void init_unk_info6(SAM_UNK_INFO_6 * u_6)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL sam_io_unk_info6(const char *desc, SAM_UNK_INFO_6 * u_6,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a structure.
********************************************************************/

void init_unk_info7(SAM_UNK_INFO_7 * u_7)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL sam_io_unk_info7(const char *desc, SAM_UNK_INFO_7 * u_7,
			     prs_struct *ps, int depth)
{
	if (u_7 == NULL)
		return False;

	prs_debug(ps, depth, desc, "sam_io_unk_info7");
	depth++;

	if(!prs_uint16("unknown_0", ps, depth, &u_7->unknown_0)) /* 0x0003 */
		return False;

	return True;
}

/*******************************************************************
inits a structure.
********************************************************************/

void init_unk_info12(SAM_UNK_INFO_12 * u_12, NTTIME nt_lock_duration, NTTIME nt_reset_time, uint16 lockout)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL sam_io_unk_info12(const char *desc, SAM_UNK_INFO_12 * u_12,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a structure.
********************************************************************/
void init_unk_info5(SAM_UNK_INFO_5 * u_5,const char *server)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL sam_io_unk_info5(const char *desc, SAM_UNK_INFO_5 * u_5,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a structure.
********************************************************************/
void init_unk_info2(SAM_UNK_INFO_2 * u_2,
			const char *domain, const char *server,
			uint32 seq_num, uint32 num_users, uint32 num_groups, uint32 num_alias)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL sam_io_unk_info2(const char *desc, SAM_UNK_INFO_2 * u_2,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a structure.
********************************************************************/

void init_unk_info1(SAM_UNK_INFO_1 *u_1, uint16 min_pass_len, uint16 pass_hist,
		    uint32 flag, NTTIME nt_expire, NTTIME nt_min_age)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/

}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL sam_io_unk_info1(const char *desc, SAM_UNK_INFO_1 * u_1,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_QUERY_DOMAIN_INFO structure.
********************************************************************/

void init_samr_r_query_dom_info(SAMR_R_QUERY_DOMAIN_INFO * r_u,
				uint16 switch_value, SAM_UNK_CTR * ctr,
				NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_query_dom_info(const char *desc, SAMR_R_QUERY_DOMAIN_INFO * r_u,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a SAMR_R_QUERY_SEC_OBJ structure.
********************************************************************/

BOOL samr_io_r_query_sec_obj(const char *desc, SAMR_R_QUERY_SEC_OBJ * r_u,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a SAM_STR1 structure.
********************************************************************/

static BOOL sam_io_sam_str1(const char *desc, SAM_STR1 * sam, uint32 acct_buf,
			    uint32 name_buf, uint32 desc_buf,
			    prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAM_ENTRY1 structure.
********************************************************************/

static void init_sam_entry1(SAM_ENTRY1 * sam, uint32 user_idx,
			    uint32 len_sam_name, uint32 len_sam_full,
			    uint32 len_sam_desc, uint32 rid_user,
			    uint16 acb_info)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a SAM_ENTRY1 structure.
********************************************************************/

static BOOL sam_io_sam_entry1(const char *desc, SAM_ENTRY1 * sam,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a SAM_STR2 structure.
********************************************************************/

static BOOL sam_io_sam_str2(const char *desc, SAM_STR2 * sam, uint32 acct_buf,
			    uint32 desc_buf, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAM_ENTRY2 structure.
********************************************************************/
static void init_sam_entry2(SAM_ENTRY2 * sam, uint32 user_idx,
			    uint32 len_sam_name, uint32 len_sam_desc,
			    uint32 rid_user, uint16 acb_info)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a SAM_ENTRY2 structure.
********************************************************************/

static BOOL sam_io_sam_entry2(const char *desc, SAM_ENTRY2 * sam,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a SAM_STR3 structure.
********************************************************************/

static BOOL sam_io_sam_str3(const char *desc, SAM_STR3 * sam, uint32 acct_buf,
			    uint32 desc_buf, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAM_ENTRY3 structure.
********************************************************************/

static void init_sam_entry3(SAM_ENTRY3 * sam, uint32 grp_idx,
			    uint32 len_grp_name, uint32 len_grp_desc,
			    uint32 rid_grp)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a SAM_ENTRY3 structure.
********************************************************************/

static BOOL sam_io_sam_entry3(const char *desc, SAM_ENTRY3 * sam,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAM_ENTRY4 structure.
********************************************************************/

static void init_sam_entry4(SAM_ENTRY4 * sam, uint32 user_idx,
			    uint32 len_acct_name)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a SAM_ENTRY4 structure.
********************************************************************/

static BOOL sam_io_sam_entry4(const char *desc, SAM_ENTRY4 * sam,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAM_ENTRY5 structure.
********************************************************************/

static void init_sam_entry5(SAM_ENTRY5 * sam, uint32 grp_idx,
			    uint32 len_grp_name)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a SAM_ENTRY5 structure.
********************************************************************/

static BOOL sam_io_sam_entry5(const char *desc, SAM_ENTRY5 * sam,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAM_ENTRY structure.
********************************************************************/

void init_sam_entry(SAM_ENTRY * sam, uint32 len_sam_name, uint32 rid)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a SAM_ENTRY structure.
********************************************************************/

static BOOL sam_io_sam_entry(const char *desc, SAM_ENTRY * sam,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_ENUM_DOM_USERS structure.
********************************************************************/

void init_samr_q_enum_dom_users(SAMR_Q_ENUM_DOM_USERS * q_e, POLICY_HND *pol,
				uint32 start_idx,
				uint16 acb_mask, uint16 unk_1, uint32 size)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_enum_dom_users(const char *desc, SAMR_Q_ENUM_DOM_USERS * q_e,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
inits a SAMR_R_ENUM_DOM_USERS structure.
********************************************************************/

void init_samr_r_enum_dom_users(SAMR_R_ENUM_DOM_USERS * r_u,
				uint32 next_idx, uint32 num_sam_entries)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_enum_dom_users(const char *desc, SAMR_R_ENUM_DOM_USERS * r_u,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_QUERY_DISPINFO structure.
********************************************************************/

void init_samr_q_query_dispinfo(SAMR_Q_QUERY_DISPINFO * q_e, POLICY_HND *pol,
				uint16 switch_level, uint32 start_idx,
				uint32 max_entries, uint32 max_size)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_query_dispinfo(const char *desc, SAMR_Q_QUERY_DISPINFO * q_e,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAM_DISPINFO_1 structure.
********************************************************************/

NTSTATUS init_sam_dispinfo_1(TALLOC_CTX *ctx, SAM_DISPINFO_1 *sam, uint32 num_entries,
			 uint32 start_idx, DISP_USER_INFO *disp_user_info)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL sam_io_sam_dispinfo_1(const char *desc, SAM_DISPINFO_1 * sam,
				  uint32 num_entries,
				  prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAM_DISPINFO_2 structure.
********************************************************************/

NTSTATUS init_sam_dispinfo_2(TALLOC_CTX *ctx, SAM_DISPINFO_2 *sam, uint32 num_entries,
			 uint32 start_idx, DISP_USER_INFO *disp_user_info)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL sam_io_sam_dispinfo_2(const char *desc, SAM_DISPINFO_2 * sam,
				  uint32 num_entries,
				  prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAM_DISPINFO_3 structure.
********************************************************************/

NTSTATUS init_sam_dispinfo_3(TALLOC_CTX *ctx, SAM_DISPINFO_3 *sam, uint32 num_entries,
			 uint32 start_idx, DISP_GROUP_INFO *disp_group_info)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL sam_io_sam_dispinfo_3(const char *desc, SAM_DISPINFO_3 * sam,
				  uint32 num_entries,
				  prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAM_DISPINFO_4 structure.
********************************************************************/

NTSTATUS init_sam_dispinfo_4(TALLOC_CTX *ctx, SAM_DISPINFO_4 *sam, uint32 num_entries,
			 uint32 start_idx, DISP_USER_INFO *disp_user_info)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL sam_io_sam_dispinfo_4(const char *desc, SAM_DISPINFO_4 * sam,
				  uint32 num_entries,
				  prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAM_DISPINFO_5 structure.
********************************************************************/

NTSTATUS init_sam_dispinfo_5(TALLOC_CTX *ctx, SAM_DISPINFO_5 *sam, uint32 num_entries,
			 uint32 start_idx, DISP_GROUP_INFO *disp_group_info)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL sam_io_sam_dispinfo_5(const char *desc, SAM_DISPINFO_5 * sam,
				  uint32 num_entries,
				  prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_QUERY_DISPINFO structure.
********************************************************************/

void init_samr_r_query_dispinfo(SAMR_R_QUERY_DISPINFO * r_u,
				uint32 num_entries, uint32 total_size, uint32 data_size,
				uint16 switch_level, SAM_DISPINFO_CTR * ctr,
				NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_query_dispinfo(const char *desc, SAMR_R_QUERY_DISPINFO * r_u,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_OPEN_GROUP structure.
********************************************************************/

void init_samr_q_open_group(SAMR_Q_OPEN_GROUP * q_c,
			    POLICY_HND *hnd,
			    uint32 access_mask, uint32 rid)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_open_group(const char *desc, SAMR_Q_OPEN_GROUP * q_u,
			  prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_open_group(const char *desc, SAMR_R_OPEN_GROUP * r_u,
			  prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a GROUP_INFO1 structure.
********************************************************************/

void init_samr_group_info1(GROUP_INFO1 * gr1,
			   const char *acct_name, const char *acct_desc,
			   uint32 num_members)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_group_info1(const char *desc, GROUP_INFO1 * gr1,
			 prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a GROUP_INFO3 structure.
********************************************************************/

void init_samr_group_info3(GROUP_INFO3 *gr3)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_group_info3(const char *desc, GROUP_INFO3 *gr3, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a GROUP_INFO4 structure.
********************************************************************/

void init_samr_group_info4(GROUP_INFO4 * gr4, const char *acct_desc)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_group_info4(const char *desc, GROUP_INFO4 * gr4,
			 prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL samr_group_info_ctr(const char *desc, GROUP_INFO_CTR **ctr,
				prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_CREATE_DOM_GROUP structure.
********************************************************************/

void init_samr_q_create_dom_group(SAMR_Q_CREATE_DOM_GROUP * q_e,
				  POLICY_HND *pol, const char *acct_desc,
				  uint32 access_mask)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_create_dom_group(const char *desc, SAMR_Q_CREATE_DOM_GROUP * q_e,
				prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_create_dom_group(const char *desc, SAMR_R_CREATE_DOM_GROUP * r_u,
				prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_DELETE_DOM_GROUP structure.
********************************************************************/

void init_samr_q_delete_dom_group(SAMR_Q_DELETE_DOM_GROUP * q_c,
				  POLICY_HND *hnd)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_delete_dom_group(const char *desc, SAMR_Q_DELETE_DOM_GROUP * q_u,
				prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_delete_dom_group(const char *desc, SAMR_R_DELETE_DOM_GROUP * r_u,
				prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_DEL_GROUPMEM structure.
********************************************************************/

void init_samr_q_del_groupmem(SAMR_Q_DEL_GROUPMEM * q_e,
			      POLICY_HND *pol, uint32 rid)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_del_groupmem(const char *desc, SAMR_Q_DEL_GROUPMEM * q_e,
			    prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_DEL_GROUPMEM structure.
********************************************************************/

void init_samr_r_del_groupmem(SAMR_R_DEL_GROUPMEM * r_u, POLICY_HND *pol,
			      NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_del_groupmem(const char *desc, SAMR_R_DEL_GROUPMEM * r_u,
			    prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_ADD_GROUPMEM structure.
********************************************************************/

void init_samr_q_add_groupmem(SAMR_Q_ADD_GROUPMEM * q_e,
			      POLICY_HND *pol, uint32 rid)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_add_groupmem(const char *desc, SAMR_Q_ADD_GROUPMEM * q_e,
			    prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_ADD_GROUPMEM structure.
********************************************************************/

void init_samr_r_add_groupmem(SAMR_R_ADD_GROUPMEM * r_u, POLICY_HND *pol,
			      NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_add_groupmem(const char *desc, SAMR_R_ADD_GROUPMEM * r_u,
			    prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_SET_GROUPINFO structure.
********************************************************************/

void init_samr_q_set_groupinfo(SAMR_Q_SET_GROUPINFO * q_e,
			       POLICY_HND *pol, GROUP_INFO_CTR * ctr)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_set_groupinfo(const char *desc, SAMR_Q_SET_GROUPINFO * q_e,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_SET_GROUPINFO structure.
********************************************************************/

void init_samr_r_set_groupinfo(SAMR_R_SET_GROUPINFO * r_u, NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_set_groupinfo(const char *desc, SAMR_R_SET_GROUPINFO * r_u,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_QUERY_GROUPINFO structure.
********************************************************************/

void init_samr_q_query_groupinfo(SAMR_Q_QUERY_GROUPINFO * q_e,
				 POLICY_HND *pol, uint16 switch_level)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_query_groupinfo(const char *desc, SAMR_Q_QUERY_GROUPINFO * q_e,
			       prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_QUERY_GROUPINFO structure.
********************************************************************/

void init_samr_r_query_groupinfo(SAMR_R_QUERY_GROUPINFO * r_u,
				 GROUP_INFO_CTR * ctr, NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_query_groupinfo(const char *desc, SAMR_R_QUERY_GROUPINFO * r_u,
			       prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_QUERY_GROUPMEM structure.
********************************************************************/

void init_samr_q_query_groupmem(SAMR_Q_QUERY_GROUPMEM * q_c, POLICY_HND *hnd)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_query_groupmem(const char *desc, SAMR_Q_QUERY_GROUPMEM * q_u,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_QUERY_GROUPMEM structure.
********************************************************************/

void init_samr_r_query_groupmem(SAMR_R_QUERY_GROUPMEM * r_u,
				uint32 num_entries, uint32 *rid,
				uint32 *attr, NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_query_groupmem(const char *desc, SAMR_R_QUERY_GROUPMEM * r_u,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_QUERY_USERGROUPS structure.
********************************************************************/

void init_samr_q_query_usergroups(SAMR_Q_QUERY_USERGROUPS * q_u,
				  POLICY_HND *hnd)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_query_usergroups(const char *desc, SAMR_Q_QUERY_USERGROUPS * q_u,
				prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_QUERY_USERGROUPS structure.
********************************************************************/

void init_samr_r_query_usergroups(SAMR_R_QUERY_USERGROUPS * r_u,
				  uint32 num_gids, DOM_GID * gid,
				  NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_gids(const char *desc, uint32 *num_gids, DOM_GID ** gid,
		  prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_query_usergroups(const char *desc, SAMR_R_QUERY_USERGROUPS * r_u,
				prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_ENUM_DOMAINS structure.
********************************************************************/

void init_samr_q_enum_domains(SAMR_Q_ENUM_DOMAINS * q_e,
			      POLICY_HND *pol,
			      uint32 start_idx, uint32 size)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_enum_domains(const char *desc, SAMR_Q_ENUM_DOMAINS * q_e,
			    prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_ENUM_DOMAINS structure.
********************************************************************/

void init_samr_r_enum_domains(SAMR_R_ENUM_DOMAINS * r_u,
			      uint32 next_idx, uint32 num_sam_entries)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_enum_domains(const char *desc, SAMR_R_ENUM_DOMAINS * r_u,
			    prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_ENUM_DOM_GROUPS structure.
********************************************************************/

void init_samr_q_enum_dom_groups(SAMR_Q_ENUM_DOM_GROUPS * q_e,
				 POLICY_HND *pol,
				 uint32 start_idx, uint32 size)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_enum_dom_groups(const char *desc, SAMR_Q_ENUM_DOM_GROUPS * q_e,
			       prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_ENUM_DOM_GROUPS structure.
********************************************************************/

void init_samr_r_enum_dom_groups(SAMR_R_ENUM_DOM_GROUPS * r_u,
				 uint32 next_idx, uint32 num_sam_entries)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_enum_dom_groups(const char *desc, SAMR_R_ENUM_DOM_GROUPS * r_u,
			       prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_ENUM_DOM_ALIASES structure.
********************************************************************/

void init_samr_q_enum_dom_aliases(SAMR_Q_ENUM_DOM_ALIASES * q_e,
				  POLICY_HND *pol, uint32 start_idx,
				  uint32 size)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_enum_dom_aliases(const char *desc, SAMR_Q_ENUM_DOM_ALIASES * q_e,
				prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_ENUM_DOM_ALIASES structure.
********************************************************************/

void init_samr_r_enum_dom_aliases(SAMR_R_ENUM_DOM_ALIASES *r_u, uint32 next_idx, uint32 num_sam_entries)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_enum_dom_aliases(const char *desc, SAMR_R_ENUM_DOM_ALIASES * r_u,
				prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a ALIAS_INFO1 structure.
********************************************************************/

void init_samr_alias_info1(ALIAS_INFO1 * al1, const char *acct_name, uint32 num_member, const char *acct_desc)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_alias_info1(const char *desc, ALIAS_INFO1 * al1,
			 prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a ALIAS_INFO3 structure.
********************************************************************/

void init_samr_alias_info3(ALIAS_INFO3 * al3, const char *acct_desc)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_alias_info3(const char *desc, ALIAS_INFO3 * al3,
			 prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_alias_info_ctr(const char *desc, ALIAS_INFO_CTR * ctr,
			 prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_QUERY_ALIASINFO structure.
********************************************************************/

void init_samr_q_query_aliasinfo(SAMR_Q_QUERY_ALIASINFO * q_e,
				 POLICY_HND *pol, uint16 switch_level)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_query_aliasinfo(const char *desc, SAMR_Q_QUERY_ALIASINFO * q_e,
			       prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_QUERY_ALIASINFO structure.
********************************************************************/

void init_samr_r_query_aliasinfo(SAMR_R_QUERY_ALIASINFO * r_u,
				 ALIAS_INFO_CTR * ctr, NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_query_aliasinfo(const char *desc, SAMR_R_QUERY_ALIASINFO * r_u,
			       prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_SET_ALIASINFO structure.
********************************************************************/

void init_samr_q_set_aliasinfo(SAMR_Q_SET_ALIASINFO * q_u,
			       POLICY_HND *hnd, ALIAS_INFO_CTR * ctr)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_set_aliasinfo(const char *desc, SAMR_Q_SET_ALIASINFO * q_u,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_set_aliasinfo(const char *desc, SAMR_R_SET_ALIASINFO * r_u,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_QUERY_USERALIASES structure.
********************************************************************/

void init_samr_q_query_useraliases(SAMR_Q_QUERY_USERALIASES * q_u,
				   POLICY_HND *hnd,
				   uint32 num_sids,
				   uint32 *ptr_sid, DOM_SID2 * sid)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a SAMR_Q_QUERY_USERALIASES structure.
********************************************************************/

BOOL samr_io_q_query_useraliases(const char *desc, SAMR_Q_QUERY_USERALIASES * q_u,
				 prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_QUERY_USERALIASES structure.
********************************************************************/

void init_samr_r_query_useraliases(SAMR_R_QUERY_USERALIASES * r_u,
				   uint32 num_rids, uint32 *rid,
				   NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_rids(const char *desc, uint32 *num_rids, uint32 **rid,
		  prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_query_useraliases(const char *desc, SAMR_R_QUERY_USERALIASES * r_u,
				 prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_OPEN_ALIAS structure.
********************************************************************/

void init_samr_q_open_alias(SAMR_Q_OPEN_ALIAS * q_u, POLICY_HND *pol,
			    uint32 access_mask, uint32 rid)
{
	DEBUG(5, ("init_samr_q_open_alias\n"));

	q_u->dom_pol = *pol;
	q_u->access_mask = access_mask;
	q_u->rid_alias = rid;
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_open_alias(const char *desc, SAMR_Q_OPEN_ALIAS * q_u,
			  prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_open_alias(const char *desc, SAMR_R_OPEN_ALIAS * r_u,
			  prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_LOOKUP_RIDS structure.
********************************************************************/

void init_samr_q_lookup_rids(TALLOC_CTX *ctx, SAMR_Q_LOOKUP_RIDS * q_u,
			     POLICY_HND *pol, uint32 flags,
			     uint32 num_rids, uint32 *rid)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_lookup_rids(const char *desc, SAMR_Q_LOOKUP_RIDS * q_u,
			   prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_LOOKUP_RIDS structure.
********************************************************************/

void init_samr_r_lookup_rids(SAMR_R_LOOKUP_RIDS * r_u,
			     uint32 num_names, UNIHDR * hdr_name,
			     UNISTR2 *uni_name, uint32 *type)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_lookup_rids(const char *desc, SAMR_R_LOOKUP_RIDS * r_u,
			   prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_OPEN_ALIAS structure.
********************************************************************/

void init_samr_q_delete_alias(SAMR_Q_DELETE_DOM_ALIAS * q_u, POLICY_HND *hnd)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_delete_alias(const char *desc, SAMR_Q_DELETE_DOM_ALIAS * q_u,
			    prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_delete_alias(const char *desc, SAMR_R_DELETE_DOM_ALIAS * r_u,
			    prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_CREATE_DOM_ALIAS structure.
********************************************************************/

void init_samr_q_create_dom_alias(SAMR_Q_CREATE_DOM_ALIAS * q_u,
				  POLICY_HND *hnd, const char *acct_desc)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_create_dom_alias(const char *desc, SAMR_Q_CREATE_DOM_ALIAS * q_u,
				prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_create_dom_alias(const char *desc, SAMR_R_CREATE_DOM_ALIAS * r_u,
				prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_ADD_ALIASMEM structure.
********************************************************************/

void init_samr_q_add_aliasmem(SAMR_Q_ADD_ALIASMEM * q_u, POLICY_HND *hnd,
			      DOM_SID *sid)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_add_aliasmem(const char *desc, SAMR_Q_ADD_ALIASMEM * q_u,
			    prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_add_aliasmem(const char *desc, SAMR_R_ADD_ALIASMEM * r_u,
			    prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_DEL_ALIASMEM structure.
********************************************************************/

void init_samr_q_del_aliasmem(SAMR_Q_DEL_ALIASMEM * q_u, POLICY_HND *hnd,
			      DOM_SID *sid)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_del_aliasmem(const char *desc, SAMR_Q_DEL_ALIASMEM * q_u,
			    prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_del_aliasmem(const char *desc, SAMR_R_DEL_ALIASMEM * r_u,
			    prs_struct *ps, int depth)
{ DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_DELETE_DOM_ALIAS structure.
********************************************************************/

void init_samr_q_delete_dom_alias(SAMR_Q_DELETE_DOM_ALIAS * q_c,
				  POLICY_HND *hnd)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_delete_dom_alias(const char *desc, SAMR_Q_DELETE_DOM_ALIAS * q_u,
				prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_DELETE_DOM_ALIAS structure.
********************************************************************/

void init_samr_r_delete_dom_alias(SAMR_R_DELETE_DOM_ALIAS * r_u,
				  NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_delete_dom_alias(const char *desc, SAMR_R_DELETE_DOM_ALIAS * r_u,
				prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_QUERY_ALIASMEM structure.
********************************************************************/

void init_samr_q_query_aliasmem(SAMR_Q_QUERY_ALIASMEM * q_c,
				POLICY_HND *hnd)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_query_aliasmem(const char *desc, SAMR_Q_QUERY_ALIASMEM * q_u,
			      prs_struct *ps, int depth)
{DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_QUERY_ALIASMEM structure.
********************************************************************/

void init_samr_r_query_aliasmem(SAMR_R_QUERY_ALIASMEM * r_u,
				uint32 num_sids, DOM_SID2 * sid,
				NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_query_aliasmem(const char *desc, SAMR_R_QUERY_ALIASMEM * r_u,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_LOOKUP_NAMES structure.
********************************************************************/

NTSTATUS init_samr_q_lookup_names(TALLOC_CTX *ctx, SAMR_Q_LOOKUP_NAMES * q_u,
			      POLICY_HND *pol, uint32 flags,
			      uint32 num_names, const char **name)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_lookup_names(const char *desc, SAMR_Q_LOOKUP_NAMES * q_u,
			    prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_LOOKUP_NAMES structure.
********************************************************************/

NTSTATUS init_samr_r_lookup_names(TALLOC_CTX *ctx, SAMR_R_LOOKUP_NAMES * r_u,
			      uint32 num_rids,
			      uint32 *rid, uint32 *type,
			      NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_lookup_names(const char *desc, SAMR_R_LOOKUP_NAMES * r_u,
			    prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_DELETE_DOM_USER structure.
********************************************************************/

void init_samr_q_delete_dom_user(SAMR_Q_DELETE_DOM_USER * q_c,
				 POLICY_HND *hnd)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_delete_dom_user(const char *desc, SAMR_Q_DELETE_DOM_USER * q_u,
			       prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_delete_dom_user(const char *desc, SAMR_R_DELETE_DOM_USER * r_u,
			       prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

void init_samr_q_open_user(SAMR_Q_OPEN_USER * q_u,
			   POLICY_HND *pol,
			   uint32 access_mask, uint32 rid)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_open_user(const char *desc, SAMR_Q_OPEN_USER * q_u,
			 prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_open_user(const char *desc, SAMR_R_OPEN_USER * r_u,
			 prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
reads or writes a structure.
********************************************************************/

void init_samr_q_create_user(SAMR_Q_CREATE_USER * q_u,
			     POLICY_HND *pol,
			     const char *name,
			     uint32 acb_info, uint32 access_mask)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_create_user(const char *desc, SAMR_Q_CREATE_USER * q_u,
			   prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_create_user(const char *desc, SAMR_R_CREATE_USER * r_u,
			   prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_QUERY_USERINFO structure.
********************************************************************/

void init_samr_q_query_userinfo(SAMR_Q_QUERY_USERINFO * q_u,
				POLICY_HND *hnd, uint16 switch_value)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_query_userinfo(const char *desc, SAMR_Q_QUERY_USERINFO * q_u,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a LOGON_HRS structure.
********************************************************************/

static BOOL sam_io_logon_hrs(const char *desc, LOGON_HRS * hrs,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAM_USER_INFO_12 structure.
********************************************************************/

void init_sam_user_info12(SAM_USER_INFO_12 * usr,
			  const uint8 lm_pwd[16], const uint8 nt_pwd[16])
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL sam_io_user_info12(const char *desc, SAM_USER_INFO_12 * u,
			prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAM_USER_INFO_10 structure.
********************************************************************/

void init_sam_user_info10(SAM_USER_INFO_10 * usr, uint32 acb_info)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL sam_io_user_info10(const char *desc, SAM_USER_INFO_10 * usr,
			prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAM_USER_INFO_11 structure.
********************************************************************/

void init_sam_user_info11(SAM_USER_INFO_11 * usr,
			  NTTIME * expiry,
			  const char *mach_acct,
			  uint32 rid_user, uint32 rid_group, uint16 acct_ctrl)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL sam_io_user_info11(const char *desc, SAM_USER_INFO_11 * usr,
			prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*************************************************************************
 init_sam_user_infoa

 unknown_3 = 0x09f8 27fa
 unknown_5 = 0x0001 0000
 unknown_6 = 0x0000 04ec

 *************************************************************************/

void init_sam_user_info24(SAM_USER_INFO_24 * usr, char newpass[516], uint16 pw_len)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL sam_io_user_info24(const char *desc, SAM_USER_INFO_24 * usr,
			       prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*************************************************************************
 init_sam_user_info23

 unknown_3 = 0x09f8 27fa
 unknown_5 = 0x0001 0000
 unknown_6 = 0x0000 04ec

 *************************************************************************/

void init_sam_user_info23W(SAM_USER_INFO_23 * usr, NTTIME * logon_time,	/* all zeros */
			NTTIME * logoff_time,	/* all zeros */
			NTTIME * kickoff_time,	/* all zeros */
			NTTIME * pass_last_set_time,	/* all zeros */
			NTTIME * pass_can_change_time,	/* all zeros */
			NTTIME * pass_must_change_time,	/* all zeros */
			UNISTR2 *user_name,
			UNISTR2 *full_name,
			UNISTR2 *home_dir,
			UNISTR2 *dir_drive,
			UNISTR2 *log_scr,
			UNISTR2 *prof_path,
			UNISTR2 *desc,
			UNISTR2 *wkstas,
			UNISTR2 *unk_str,
			UNISTR2 *mung_dial,
			uint32 user_rid,	/* 0x0000 0000 */
			uint32 group_rid,
			uint32 acb_info,
			uint32 unknown_3,
			uint16 logon_divs,
			LOGON_HRS * hrs,
			uint32 unknown_5,
			char newpass[516], uint32 unknown_6)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*************************************************************************
 init_sam_user_info23

 unknown_3 = 0x09f8 27fa
 unknown_5 = 0x0001 0000
 unknown_6 = 0x0000 04ec

 *************************************************************************/

void init_sam_user_info23A(SAM_USER_INFO_23 * usr, NTTIME * logon_time,	/* all zeros */
			   NTTIME * logoff_time,	/* all zeros */
			   NTTIME * kickoff_time,	/* all zeros */
			   NTTIME * pass_last_set_time,	/* all zeros */
			   NTTIME * pass_can_change_time,	/* all zeros */
			   NTTIME * pass_must_change_time,	/* all zeros */
			   const char *user_name,	/* NULL */
			   const char *full_name,
			   const char *home_dir, const char *dir_drive, const char *log_scr,
			   const char *prof_path, const char *desc, const char *wkstas,
			   const char *unk_str, const char *mung_dial, uint32 user_rid,	/* 0x0000 0000 */
			   uint32 group_rid, uint32 acb_info,
			   uint32 unknown_3, uint16 logon_divs,
			   LOGON_HRS * hrs, uint32 unknown_5,
			   char newpass[516], uint32 unknown_6)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL sam_io_user_info23(const char *desc, SAM_USER_INFO_23 * usr,
			       prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 reads or writes a structure.
 NB. This structure is *definately* incorrect. It's my best guess
 currently for W2K SP2. The password field is encrypted in a different
 way than normal... And there are definately other problems. JRA.
********************************************************************/

static BOOL sam_io_user_info25(const char *desc, SAM_USER_INFO_25 * usr, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*************************************************************************
 init_sam_user_info21W

 unknown_3 = 0x00ff ffff
 unknown_5 = 0x0002 0000
 unknown_6 = 0x0000 04ec

 *************************************************************************/

void init_sam_user_info21W(SAM_USER_INFO_21 * usr,
			   NTTIME * logon_time,
			   NTTIME * logoff_time,
			   NTTIME * kickoff_time,
			   NTTIME * pass_last_set_time,
			   NTTIME * pass_can_change_time,
			   NTTIME * pass_must_change_time,
			   UNISTR2 *user_name,
			   UNISTR2 *full_name,
			   UNISTR2 *home_dir,
			   UNISTR2 *dir_drive,
			   UNISTR2 *log_scr,
			   UNISTR2 *prof_path,
			   UNISTR2 *desc,
			   UNISTR2 *wkstas,
			   UNISTR2 *unk_str,
			   UNISTR2 *mung_dial,
			   uchar lm_pwd[16],
			   uchar nt_pwd[16],
			   uint32 user_rid,
			   uint32 group_rid,
			   uint32 acb_info,
			   uint32 unknown_3,
			   uint16 logon_divs,
			   LOGON_HRS * hrs,
			   uint32 unknown_5, uint32 unknown_6)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*************************************************************************
 init_sam_user_info21

 unknown_3 = 0x00ff ffff
 unknown_5 = 0x0002 0000
 unknown_6 = 0x0000 04ec

 *************************************************************************/

void init_sam_user_info21A(SAM_USER_INFO_21 *usr, SAM_ACCOUNT *pw)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL sam_io_user_info21(const char *desc, SAM_USER_INFO_21 * usr,
			prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

void init_sam_user_info20A(SAM_USER_INFO_20 *usr, SAM_ACCOUNT *pw)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/

}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL sam_io_user_info20(const char *desc, SAM_USER_INFO_20 *usr,
			prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAM_USERINFO_CTR structure.
********************************************************************/

NTSTATUS make_samr_userinfo_ctr_usr21(TALLOC_CTX *ctx, SAM_USERINFO_CTR * ctr,
				    uint16 switch_value,
				    SAM_USER_INFO_21 * usr)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAM_USERINFO_CTR structure.
********************************************************************/

void init_samr_userinfo_ctr(SAM_USERINFO_CTR * ctr, uchar * sess_key,
			    uint16 switch_value, void *info)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL samr_io_userinfo_ctr(const char *desc, SAM_USERINFO_CTR **ppctr,
				 prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_QUERY_USERINFO structure.
********************************************************************/

void init_samr_r_query_userinfo(SAMR_R_QUERY_USERINFO * r_u,
				SAM_USERINFO_CTR * ctr, NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_query_userinfo(const char *desc, SAMR_R_QUERY_USERINFO * r_u,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_SET_USERINFO structure.
********************************************************************/

void init_samr_q_set_userinfo(SAMR_Q_SET_USERINFO * q_u,
			      POLICY_HND *hnd,  unsigned char sess_key[16],
			      uint16 switch_value, void *info)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_set_userinfo(const char *desc, SAMR_Q_SET_USERINFO * q_u,
			    prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_SET_USERINFO structure.
********************************************************************/

void init_samr_r_set_userinfo(SAMR_R_SET_USERINFO * r_u, NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_set_userinfo(const char *desc, SAMR_R_SET_USERINFO * r_u,
			    prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_SET_USERINFO2 structure.
********************************************************************/

void init_samr_q_set_userinfo2(SAMR_Q_SET_USERINFO2 * q_u,
			       POLICY_HND *hnd, unsigned char sess_key[16],
			       uint16 switch_value, SAM_USERINFO_CTR * ctr)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_set_userinfo2(const char *desc, SAMR_Q_SET_USERINFO2 * q_u,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_SET_USERINFO2 structure.
********************************************************************/

void init_samr_r_set_userinfo2(SAMR_R_SET_USERINFO2 * r_u, NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_set_userinfo2(const char *desc, SAMR_R_SET_USERINFO2 * r_u,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_CONNECT structure.
********************************************************************/

void init_samr_q_connect(SAMR_Q_CONNECT * q_u,
			 const char *srv_name, uint32 access_mask)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_connect(const char *desc, SAMR_Q_CONNECT * q_u,
		       prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_connect(const char *desc, SAMR_R_CONNECT * r_u,
		       prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_CONNECT_ANON structure.
********************************************************************/

void init_samr_q_connect_anon(SAMR_Q_CONNECT_ANON * q_u)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_connect_anon(const char *desc, SAMR_Q_CONNECT_ANON * q_u,
			    prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_connect_anon(const char *desc, SAMR_R_CONNECT_ANON * r_u,
			    prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_Q_GET_DOM_PWINFO structure.
********************************************************************/

void init_samr_q_get_dom_pwinfo(SAMR_Q_GET_DOM_PWINFO * q_u,
				const char *srv_name)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_get_dom_pwinfo(const char *desc, SAMR_Q_GET_DOM_PWINFO * q_u,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_get_dom_pwinfo(const char *desc, SAMR_R_GET_DOM_PWINFO * r_u,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
make a SAMR_ENC_PASSWD structure.
********************************************************************/

void init_enc_passwd(SAMR_ENC_PASSWD * pwd, char pass[512])
{
	ZERO_STRUCTP(pwd);

	if (pass == NULL) {
		pwd->ptr = 0;
	} else {
		pwd->ptr = 1;
		memcpy(pwd->pass, pass, sizeof(pwd->pass));
	}
}

/*******************************************************************
reads or writes a SAMR_ENC_PASSWD structure.
********************************************************************/

BOOL samr_io_enc_passwd(const char *desc, SAMR_ENC_PASSWD * pwd,
			prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_ENC_HASH structure.
********************************************************************/

void init_enc_hash(SAMR_ENC_HASH * hsh, uchar hash[16])
{
	ZERO_STRUCTP(hsh);

	if (hash == NULL) {
		hsh->ptr = 0;
	} else {
		hsh->ptr = 1;
		memcpy(hsh->hash, hash, sizeof(hsh->hash));
	}
}

/*******************************************************************
reads or writes a SAMR_ENC_HASH structure.
********************************************************************/

BOOL samr_io_enc_hash(const char *desc, SAMR_ENC_HASH * hsh,
		      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_GET_DOM_PWINFO structure.
********************************************************************/

void init_samr_q_chgpasswd_user(SAMR_Q_CHGPASSWD_USER * q_u,
				const char *dest_host, const char *user_name,
				char nt_newpass[516],
				uchar nt_oldhash[16],
				char lm_newpass[516],
				uchar lm_oldhash[16])
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_chgpasswd_user(const char *desc, SAMR_Q_CHGPASSWD_USER * q_u,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_CHGPASSWD_USER structure.
********************************************************************/

void init_samr_r_chgpasswd_user(SAMR_R_CHGPASSWD_USER * r_u, NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_chgpasswd_user(const char *desc, SAMR_R_CHGPASSWD_USER * r_u,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

void init_samr_q_unknown_2e(SAMR_Q_UNKNOWN_2E *q_u,
				POLICY_HND *domain_pol, uint16 switch_value)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_unknown_2e(const char *desc, SAMR_Q_UNKNOWN_2E *q_u,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_QUERY_DOMAIN_INFO structure.
********************************************************************/

void init_samr_r_samr_unknown_2e(SAMR_R_UNKNOWN_2E * r_u,
				uint16 switch_value, SAM_UNK_CTR * ctr,
				NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_samr_unknown_2e(const char *desc, SAMR_R_UNKNOWN_2E * r_u,
			      prs_struct *ps, int depth)
{DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
reads or writes a structure.
********************************************************************/

void init_samr_q_set_domain_info(SAMR_Q_SET_DOMAIN_INFO *q_u,
				POLICY_HND *domain_pol, uint16 switch_value, SAM_UNK_CTR *ctr)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_q_set_domain_info(const char *desc, SAMR_Q_SET_DOMAIN_INFO *q_u,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
inits a SAMR_R_QUERY_DOMAIN_INFO structure.
********************************************************************/

void init_samr_r_set_domain_info(SAMR_R_SET_DOMAIN_INFO * r_u, NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL samr_io_r_set_domain_info(const char *desc, SAMR_R_SET_DOMAIN_INFO * r_u,
			      prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}
