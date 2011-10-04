/*
 *  Unix SMB/Netbios implementation.
 *  Version 1.9.
 *  RPC Pipe client / server routines
 *  Copyright (C) Andrew Tridgell              1992-1997,
 *  Copyright (C) Luke Kenneth Casson Leighton 1996-1997,
 *  Copyright (C) Paul Ashton                       1997.
 *  Copyright (C) Marc Jacobsen						1999.
 *  Copyright (C) Jeremy Allison               2001-2002.
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

/*
 * This is the implementation of the SAMR code.
 */

#include "includes.h"

extern fstring global_myworkgroup;
extern pstring global_myname;
extern DOM_SID global_sam_sid;
extern DOM_SID global_sid_Builtin;

extern rid_name domain_group_rids[];
extern rid_name domain_alias_rids[];
extern rid_name builtin_alias_rids[];

typedef struct _disp_info {
	BOOL user_dbloaded;
	uint32 num_user_account;
	DISP_USER_INFO *disp_user_info;
	BOOL group_dbloaded;
	uint32 num_group_account;
	DISP_GROUP_INFO *disp_group_info;
} DISP_INFO;

struct samr_info {
	/* for use by the \PIPE\samr policy */
	DOM_SID sid;
	uint32 status; /* some sort of flag.  best to record it.  comes from opnum 0x39 */
	DISP_INFO disp_info;
};

/*******************************************************************
 Create a samr_info struct.
 ********************************************************************/

static struct samr_info *get_samr_info_by_sid(DOM_SID *psid)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Function to free the per handle data.
 ********************************************************************/

static void free_samr_db(struct samr_info *info)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Function to free the per handle data.
 ********************************************************************/

static void free_samr_info(void *ptr)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Ensure password info is never given out. Paranioa... JRA.
 ********************************************************************/

static void samr_clear_passwd_fields( SAM_USER_INFO_21 *pass, int num_entries)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static void samr_clear_sam_passwd(SAM_ACCOUNT *sam_pass)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static NTSTATUS load_sampwd_entries(struct samr_info *info, uint16 acb_mask)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*
 * This is a really ugly hack to make this interface work in the 2.2.x code. JRA.
 * Return a malloced map so we can free it.
 */

static int setup_fake_group_map(GROUP_MAP **ret_map)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static NTSTATUS load_group_domain_entries(struct samr_info *info, DOM_SID *sid)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
  This next function should be replaced with something that
  dynamically returns the correct user info..... JRA.
 ********************************************************************/

static NTSTATUS get_sampwd_entries(SAM_USER_INFO_21 *pw_buf, int start_idx,
				int *total_entries, int *num_entries,
				int max_num_entries, uint16 acb_mask)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 _samr_close_hnd
 ********************************************************************/

NTSTATUS _samr_close_hnd(pipes_struct *p, SAMR_Q_CLOSE_HND *q_u, SAMR_R_CLOSE_HND *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 samr_reply_open_domain
 ********************************************************************/

NTSTATUS _samr_open_domain(pipes_struct *p, SAMR_Q_OPEN_DOMAIN *q_u, SAMR_R_OPEN_DOMAIN *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static uint32 get_lsa_policy_samr_rid(struct samr_info *info)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 _samr_get_usrdom_pwinfo
 ********************************************************************/

NTSTATUS _samr_get_usrdom_pwinfo(pipes_struct *p, SAMR_Q_GET_USRDOM_PWINFO *q_u, SAMR_R_GET_USRDOM_PWINFO *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 samr_make_usr_obj_sd
 ********************************************************************/

static NTSTATUS samr_make_usr_obj_sd(TALLOC_CTX *ctx, SEC_DESC_BUF **buf, DOM_SID *usr_sid)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static BOOL get_lsa_policy_samr_sid(pipes_struct *p, POLICY_HND *pol, DOM_SID *sid)
{
	struct samr_info *info = NULL;

	/* find the policy handle.  open a policy on it. */
	if (!find_policy_by_hnd(p, pol, (void **)&info))
		return False;

	if (!info)
		return False;

	*sid = info->sid;
	return True;
}

/*******************************************************************
 _samr_query_sec_obj
 ********************************************************************/

NTSTATUS _samr_query_sec_obj(pipes_struct *p, SAMR_Q_QUERY_SEC_OBJ *q_u, SAMR_R_QUERY_SEC_OBJ *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
makes a SAM_ENTRY / UNISTR2* structure from a user list.
********************************************************************/

static void make_user_sam_entry_list(TALLOC_CTX *ctx, SAM_ENTRY **sam_pp, UNISTR2 **uni_name_pp,
		uint32 num_sam_entries, SAM_USER_INFO_21 *pass)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 samr_reply_enum_dom_users
 ********************************************************************/

NTSTATUS _samr_enum_dom_users(pipes_struct *p, SAMR_Q_ENUM_DOM_USERS *q_u, SAMR_R_ENUM_DOM_USERS *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
makes a SAM_ENTRY / UNISTR2* structure from a group list.
********************************************************************/

static void make_group_sam_entry_list(TALLOC_CTX *ctx, SAM_ENTRY **sam_pp, UNISTR2 **uni_name_pp,
		uint32 num_sam_entries, DOMAIN_GRP *grp)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Get the group entries - similar to get_sampwd_entries().
 ********************************************************************/

static NTSTATUS get_group_alias_entries(DOMAIN_GRP *d_grp, DOM_SID *sid, uint32 start_idx,
				    uint32 *p_num_entries, uint32 max_entries)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Get the group entries - similar to get_sampwd_entries().
 ********************************************************************/

static NTSTATUS get_group_domain_entries(DOMAIN_GRP *d_grp, DOM_SID *sid, uint32 start_idx,
				     uint32 *p_num_entries, uint32 max_entries)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 samr_reply_enum_dom_groups
 Only reply with one group - domain admins. This must be fixed for
 a real PDC. JRA.
 ********************************************************************/

NTSTATUS _samr_enum_dom_groups(pipes_struct *p, SAMR_Q_ENUM_DOM_GROUPS *q_u, SAMR_R_ENUM_DOM_GROUPS *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}


/*******************************************************************
 samr_reply_enum_dom_aliases
 ********************************************************************/

NTSTATUS _samr_enum_dom_aliases(pipes_struct *p, SAMR_Q_ENUM_DOM_ALIASES *q_u, SAMR_R_ENUM_DOM_ALIASES *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 samr_reply_query_dispinfo
 ********************************************************************/
NTSTATUS _samr_query_dispinfo(pipes_struct *p, SAMR_Q_QUERY_DISPINFO *q_u, SAMR_R_QUERY_DISPINFO *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/

}

/*******************************************************************
 samr_reply_query_aliasinfo
 ********************************************************************/

NTSTATUS _samr_query_aliasinfo(pipes_struct *p, SAMR_Q_QUERY_ALIASINFO *q_u, SAMR_R_QUERY_ALIASINFO *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

#if 0
/*******************************************************************
 samr_reply_lookup_ids
 ********************************************************************/

 uint32 _samr_lookup_ids(pipes_struct *p, SAMR_Q_LOOKUP_IDS *q_u, SAMR_R_LOOKUP_IDS *r_u)
{
    uint32 rid[MAX_SAM_ENTRIES];
    int num_rids = q_u->num_sids1;

    r_u->status = NT_STATUS_OK;

    DEBUG(5,("_samr_lookup_ids: %d\n", __LINE__));

    if (num_rids > MAX_SAM_ENTRIES) {
	num_rids = MAX_SAM_ENTRIES;
	DEBUG(5,("_samr_lookup_ids: truncating entries to %d\n", num_rids));
    }

#if 0
    int i;
    SMB_ASSERT_ARRAY(q_u->uni_user_name, num_rids);

    for (i = 0; i < num_rids && status == 0; i++)
    {
	struct sam_passwd *sam_pass;
	fstring user_name;


	fstrcpy(user_name, unistrn2(q_u->uni_user_name[i].buffer,
				    q_u->uni_user_name[i].uni_str_len));

	/* find the user account */
	become_root();
	sam_pass = get_smb21pwd_entry(user_name, 0);
	unbecome_root();

	if (sam_pass == NULL)
	{
	    status = 0xC0000000 | NT_STATUS_NO_SUCH_USER;
	    rid[i] = 0;
	}
	else
	{
	    rid[i] = sam_pass->user_rid;
	}
    }
#endif

    num_rids = 1;
    rid[0] = BUILTIN_ALIAS_RID_USERS;

    init_samr_r_lookup_ids(&r_u, num_rids, rid, NT_STATUS_OK);

    DEBUG(5,("_samr_lookup_ids: %d\n", __LINE__));

    return r_u->status;
}
#endif

/*******************************************************************
 _samr_lookup_names
 ********************************************************************/

NTSTATUS _samr_lookup_names(pipes_struct *p, SAMR_Q_LOOKUP_NAMES *q_u, SAMR_R_LOOKUP_NAMES *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 _samr_chgpasswd_user
 ********************************************************************/

NTSTATUS _samr_chgpasswd_user(pipes_struct *p, SAMR_Q_CHGPASSWD_USER *q_u, SAMR_R_CHGPASSWD_USER *r_u)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
makes a SAMR_R_LOOKUP_RIDS structure.
********************************************************************/

static BOOL make_samr_lookup_rids(TALLOC_CTX *ctx, uint32 num_names, fstring names[],
	    UNIHDR **pp_hdr_name, UNISTR2 **pp_uni_name)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 _samr_lookup_rids
 ********************************************************************/

NTSTATUS _samr_lookup_rids(pipes_struct *p, SAMR_Q_LOOKUP_RIDS *q_u, SAMR_R_LOOKUP_RIDS *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 _api_samr_open_user. Safe - gives out no passwd info.
 ********************************************************************/

NTSTATUS _api_samr_open_user(pipes_struct *p, SAMR_Q_OPEN_USER *q_u, SAMR_R_OPEN_USER *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 get_user_info_10. Safe. Only gives out acb bits.
 *************************************************************************/

static BOOL get_user_info_10(SAM_USER_INFO_10 *id10, uint32 user_rid)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*************************************************************************
 get_user_info_12. OK - this is the killer as it gives out password info.
 Ensure that this is only allowed on an encrypted connection with a root
 user. JRA.
 *************************************************************************/

static NTSTATUS get_user_info_12(pipes_struct *p, SAM_USER_INFO_12 * id12, uint32 user_rid)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

#if 1 /* JRA - re-enabled... JERRY - why was this removed ? */
/*************************************************************************
 get_user_info_20
 *************************************************************************/

static BOOL get_user_info_20(SAM_USER_INFO_20 *id20, uint32 user_rid)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}
#endif

/*************************************************************************
 get_user_info_21
 *************************************************************************/

static BOOL get_user_info_21(SAM_USER_INFO_21 *id21, uint32 user_rid)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 _samr_query_userinfo
 ********************************************************************/

NTSTATUS _samr_query_userinfo(pipes_struct *p, SAMR_Q_QUERY_USERINFO *q_u, SAMR_R_QUERY_USERINFO *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 samr_reply_query_usergroups
 ********************************************************************/

NTSTATUS _samr_query_usergroups(pipes_struct *p, SAMR_Q_QUERY_USERGROUPS *q_u, SAMR_R_QUERY_USERGROUPS *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 _samr_query_dom_info
 ********************************************************************/

NTSTATUS _samr_query_dom_info(pipes_struct *p, SAMR_Q_QUERY_DOMAIN_INFO *q_u, SAMR_R_QUERY_DOMAIN_INFO *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 _api_samr_create_user
 Create an account, can be either a normal user or a machine.
 This funcion will need to be updated for bdc/domain trusts.
 ********************************************************************/

NTSTATUS _api_samr_create_user(pipes_struct *p, SAMR_Q_CREATE_USER *q_u, SAMR_R_CREATE_USER *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 samr_reply_connect_anon
 ********************************************************************/

NTSTATUS _samr_connect_anon(pipes_struct *p, SAMR_Q_CONNECT_ANON *q_u, SAMR_R_CONNECT_ANON *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 samr_reply_connect
 ********************************************************************/

NTSTATUS _samr_connect(pipes_struct *p, SAMR_Q_CONNECT *q_u, SAMR_R_CONNECT *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/**********************************************************************
 api_samr_lookup_domain
 **********************************************************************/

NTSTATUS _samr_lookup_domain(pipes_struct *p, SAMR_Q_LOOKUP_DOMAIN *q_u, SAMR_R_LOOKUP_DOMAIN *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/******************************************************************
makes a SAMR_R_ENUM_DOMAINS structure.
********************************************************************/

static BOOL make_enum_domains(TALLOC_CTX *ctx, SAM_ENTRY **pp_sam,
			UNISTR2 **pp_uni_name, uint32 num_sam_entries, fstring doms[])
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/**********************************************************************
 api_samr_enum_domains
 **********************************************************************/

NTSTATUS _samr_enum_domains(pipes_struct *p, SAMR_Q_ENUM_DOMAINS *q_u, SAMR_R_ENUM_DOMAINS *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 api_samr_open_alias
 ********************************************************************/

NTSTATUS _api_samr_open_alias(pipes_struct *p, SAMR_Q_OPEN_ALIAS *q_u, SAMR_R_OPEN_ALIAS *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 set_user_info_10
 ********************************************************************/

static BOOL set_user_info_10(const SAM_USER_INFO_10 *id10, uint32 rid)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 set_user_info_12
 ********************************************************************/

static BOOL set_user_info_12(SAM_USER_INFO_12 *id12, uint32 rid)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 set_user_info_21
 ********************************************************************/

static BOOL set_user_info_21(SAM_USER_INFO_21 *id21, uint32 rid)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 set_user_info_23
 ********************************************************************/

static BOOL set_user_info_23(SAM_USER_INFO_23 *id23, uint32 rid)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 set_user_info_pw
 ********************************************************************/

static BOOL set_user_info_pw(char *pass, uint32 rid)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 samr_reply_set_userinfo
 ********************************************************************/

NTSTATUS _samr_set_userinfo(pipes_struct *p, SAMR_Q_SET_USERINFO *q_u, SAMR_R_SET_USERINFO *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 samr_reply_set_userinfo2
 ********************************************************************/

NTSTATUS _samr_set_userinfo2(pipes_struct *p, SAMR_Q_SET_USERINFO2 *q_u, SAMR_R_SET_USERINFO2 *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*********************************************************************
 _samr_query_aliasmem
*********************************************************************/

NTSTATUS _samr_query_useraliases(pipes_struct *p, SAMR_Q_QUERY_USERALIASES *q_u, SAMR_R_QUERY_USERALIASES *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/

}

/*********************************************************************
 _samr_query_aliasmem
*********************************************************************/

NTSTATUS _samr_query_aliasmem(pipes_struct *p, SAMR_Q_QUERY_ALIASMEM *q_u, SAMR_R_QUERY_ALIASMEM *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*********************************************************************
 _samr_query_groupmem
*********************************************************************/

NTSTATUS _samr_query_groupmem(pipes_struct *p, SAMR_Q_QUERY_GROUPMEM *q_u, SAMR_R_QUERY_GROUPMEM *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*********************************************************************
 _samr_add_aliasmem
*********************************************************************/

NTSTATUS _samr_add_aliasmem(pipes_struct *p, SAMR_Q_ADD_ALIASMEM *q_u, SAMR_R_ADD_ALIASMEM *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*********************************************************************
 _samr_del_aliasmem
*********************************************************************/

NTSTATUS _samr_del_aliasmem(pipes_struct *p, SAMR_Q_DEL_ALIASMEM *q_u, SAMR_R_DEL_ALIASMEM *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*********************************************************************
 _samr_add_groupmem
*********************************************************************/

NTSTATUS _samr_add_groupmem(pipes_struct *p, SAMR_Q_ADD_GROUPMEM *q_u, SAMR_R_ADD_GROUPMEM *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*********************************************************************
 _samr_del_groupmem
*********************************************************************/

NTSTATUS _samr_del_groupmem(pipes_struct *p, SAMR_Q_DEL_GROUPMEM *q_u, SAMR_R_DEL_GROUPMEM *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*********************************************************************
 _samr_delete_dom_user
*********************************************************************/

NTSTATUS _samr_delete_dom_user(pipes_struct *p, SAMR_Q_DELETE_DOM_USER *q_u, SAMR_R_DELETE_DOM_USER *r_u )
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*********************************************************************
 _samr_delete_dom_group
*********************************************************************/

NTSTATUS _samr_delete_dom_group(pipes_struct *p, SAMR_Q_DELETE_DOM_GROUP *q_u, SAMR_R_DELETE_DOM_GROUP *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*********************************************************************
 _samr_delete_dom_alias
*********************************************************************/

NTSTATUS _samr_delete_dom_alias(pipes_struct *p, SAMR_Q_DELETE_DOM_ALIAS *q_u, SAMR_R_DELETE_DOM_ALIAS *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*********************************************************************
 _samr_create_dom_group
*********************************************************************/

NTSTATUS _samr_create_dom_group(pipes_struct *p, SAMR_Q_CREATE_DOM_GROUP *q_u, SAMR_R_CREATE_DOM_GROUP *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*********************************************************************
 _samr_create_dom_alias
*********************************************************************/

NTSTATUS _samr_create_dom_alias(pipes_struct *p, SAMR_Q_CREATE_DOM_ALIAS *q_u, SAMR_R_CREATE_DOM_ALIAS *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*********************************************************************
 _samr_query_groupinfo
*********************************************************************/

NTSTATUS _samr_query_groupinfo(pipes_struct *p, SAMR_Q_QUERY_GROUPINFO *q_u, SAMR_R_QUERY_GROUPINFO *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*********************************************************************
 _samr_set_groupinfo
*********************************************************************/

NTSTATUS _samr_set_groupinfo(pipes_struct *p, SAMR_Q_SET_GROUPINFO *q_u, SAMR_R_SET_GROUPINFO *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*********************************************************************
 _samr_get_dom_pwinfo
*********************************************************************/

NTSTATUS _samr_get_dom_pwinfo(pipes_struct *p, SAMR_Q_GET_DOM_PWINFO *q_u, SAMR_R_GET_DOM_PWINFO *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*********************************************************************
 _samr_open_group
*********************************************************************/

NTSTATUS _samr_open_group(pipes_struct *p, SAMR_Q_OPEN_GROUP *q_u, SAMR_R_OPEN_GROUP *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*********************************************************************
 _samr_unknown_2d
*********************************************************************/

NTSTATUS _samr_unknown_2d(pipes_struct *p, SAMR_Q_UNKNOWN_2D *q_u, SAMR_R_UNKNOWN_2D *r_u)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}
