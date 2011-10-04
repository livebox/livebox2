/*
 *  Unix SMB/Netbios implementation.
 *  Version 1.9.
 *  RPC Pipe client / server routines
 *  Copyright (C) Andrew Tridgell              1992-1997,
 *  Copyright (C) Luke Kenneth Casson Leighton 1996-1997,
 *  Copyright (C) Paul Ashton                       1997.
 *  Copyright (C) Jeremy Allison		    1999.
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
 Inits a SH_INFO_1_STR structure
********************************************************************/

void init_srv_share_info1_str(SH_INFO_1_STR *sh1, const char *net_name, const char *remark)
{
	DEBUG(5,("init_srv_share_info1_str\n"));

	init_unistr2(&sh1->uni_netname, net_name, strlen(net_name)+1);
	init_unistr2(&sh1->uni_remark, remark, strlen(remark)+1);
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_share_info1_str(const char *desc, SH_INFO_1_STR *sh1, prs_struct *ps, int depth)
{
	if (sh1 == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_share_info1_str");
	depth++;

	if(!prs_align(ps))
		return False;
	if(!smb_io_unistr2("", &sh1->uni_netname, True, ps, depth))
		return False;

	if(!prs_align(ps))
		return False;
	if(!smb_io_unistr2("", &sh1->uni_remark, True, ps, depth))
		return False;

	return True;
}

/*******************************************************************
 makes a SH_INFO_1 structure
********************************************************************/

void init_srv_share_info1(SH_INFO_1 *sh1, const char *net_name, uint32 type, const char *remark)
{
	DEBUG(5,("init_srv_share_info1: %s %8x %s\n", net_name, type, remark));

	sh1->ptr_netname = (net_name != NULL) ? 1 : 0;
	sh1->type        = type;
	sh1->ptr_remark  = (remark != NULL) ? 1 : 0;
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_share_info1(const char *desc, SH_INFO_1 *sh1, prs_struct *ps, int depth)
{
	if (sh1 == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_share_info1");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("ptr_netname", ps, depth, &sh1->ptr_netname))
		return False;
	if(!prs_uint32("type       ", ps, depth, &sh1->type))
		return False;
	if(!prs_uint32("ptr_remark ", ps, depth, &sh1->ptr_remark))
		return False;

	return True;
}

/*******************************************************************
 Inits a SH_INFO_2_STR structure
********************************************************************/

void init_srv_share_info2_str(SH_INFO_2_STR *sh2,
				const char *net_name, const char *remark,
				const char *path, const char *passwd)
{
	DEBUG(5,("init_srv_share_info2_str\n"));

	init_unistr2(&sh2->uni_netname, net_name, strlen(net_name)+1);
	init_unistr2(&sh2->uni_remark, remark, strlen(remark)+1);
	init_unistr2(&sh2->uni_path, path, strlen(path)+1);
	init_unistr2(&sh2->uni_passwd, passwd, strlen(passwd)+1);
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_share_info2_str(const char *desc, SH_INFO_2 *sh, SH_INFO_2_STR *sh2, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Inits a SH_INFO_2 structure
********************************************************************/

void init_srv_share_info2(SH_INFO_2 *sh2,
				const char *net_name, uint32 type, const char *remark,
				uint32 perms, uint32 max_uses, uint32 num_uses,
				const char *path, const char *passwd)
{
	DEBUG(5,("init_srv_share_info2: %s %8x %s\n", net_name, type, remark));

	sh2->ptr_netname = (net_name != NULL) ? 1 : 0;
	sh2->type        = type;
	sh2->ptr_remark  = (remark != NULL) ? 1 : 0;
	sh2->perms       = perms;
	sh2->max_uses    = max_uses;
	sh2->num_uses    = num_uses;
	sh2->type        = type;
	sh2->ptr_path    = (path != NULL) ? 1 : 0;
	sh2->ptr_passwd  = (passwd != NULL) ? 1 : 0;
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_share_info2(const char *desc, SH_INFO_2 *sh2, prs_struct *ps, int depth)
{
	if (sh2 == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_share_info2");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("ptr_netname", ps, depth, &sh2->ptr_netname))
		return False;
	if(!prs_uint32("type       ", ps, depth, &sh2->type))
		return False;
	if(!prs_uint32("ptr_remark ", ps, depth, &sh2->ptr_remark))
		return False;
	if(!prs_uint32("perms      ", ps, depth, &sh2->perms))
		return False;
	if(!prs_uint32("max_uses   ", ps, depth, &sh2->max_uses))
		return False;
	if(!prs_uint32("num_uses   ", ps, depth, &sh2->num_uses))
		return False;
	if(!prs_uint32("ptr_path   ", ps, depth, &sh2->ptr_path))
		return False;
	if(!prs_uint32("ptr_passwd ", ps, depth, &sh2->ptr_passwd))
		return False;

	return True;
}

/*******************************************************************
 Inits a SH_INFO_2 structure
*******************************************************************/

void init_srv_share_info501(SH_INFO_501 *sh501, const char *net_name, uint32 type, const char *remark, uint32 csc_policy)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads of writes a structure.
*******************************************************************/

static BOOL srv_io_share_info501(const char *desc, SH_INFO_501 *sh501, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/********************************************************************
 Inits a SH_INFO_501_STR structure
********************************************************************/

void init_srv_share_info501_str(SH_INFO_501_STR *sh501, const char *net_name, const char *remark)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_share_info501_str(const char *desc, SH_INFO_501_STR *sh501, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Inits a SH_INFO_502 structure
********************************************************************/

void init_srv_share_info502(SH_INFO_502 *sh502,
				const char *net_name, uint32 type, const char *remark,
				uint32 perms, uint32 max_uses, uint32 num_uses,
				const char *path, const char *passwd, SEC_DESC *psd, size_t sd_size)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_share_info502(const char *desc, SH_INFO_502 *sh502, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Inits a SH_INFO_502_STR structure
********************************************************************/

void init_srv_share_info502_str(SH_INFO_502_STR *sh502str,
				SH_INFO_502 *ptrs,
				const char *net_name, const char *remark,
				const char *path, const char *passwd, SEC_DESC *psd, size_t sd_size)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_share_info502_str(const char *desc, SH_INFO_502_STR *sh502, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_share_info1005(const char* desc, SRV_SHARE_INFO_1005* sh1005,
				  prs_struct* ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_share_info1501(const char* desc, SRV_SHARE_INFO_1501* sh1501,
				  prs_struct* ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_srv_share_ctr(const char *desc, SRV_SHARE_INFO_CTR *ctr, prs_struct *ps, int depth)
{
	if (ctr == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_srv_share_ctr");
	depth++;

	if (UNMARSHALLING(ps)) {
		memset(ctr, '\0', sizeof(SRV_SHARE_INFO_CTR));
	}

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("info_level", ps, depth, &ctr->info_level))
		return False;

	if (ctr->info_level == 0)
		return True;

	if(!prs_uint32("switch_value", ps, depth, &ctr->switch_value))
		return False;
	if(!prs_uint32("ptr_share_info", ps, depth, &ctr->ptr_share_info))
		return False;

	if (ctr->ptr_share_info == 0)
		return True;

	if(!prs_uint32("num_entries", ps, depth, &ctr->num_entries))
		return False;
	if(!prs_uint32("ptr_entries", ps, depth, &ctr->ptr_entries))
		return False;

	if (ctr->ptr_entries == 0) {
		if (ctr->num_entries == 0)
			return True;
		else
			return False;
	}

	if(!prs_uint32("num_entries2", ps, depth, &ctr->num_entries2))
		return False;

	if (ctr->num_entries2 != ctr->num_entries)
		return False;

	switch (ctr->switch_value) {
	case 1:
	{
		SRV_SHARE_INFO_1 *info1 = ctr->share.info1;
		int num_entries = ctr->num_entries;
		int i;

		if (UNMARSHALLING(ps)) {
			if (!(info1 = (SRV_SHARE_INFO_1 *)prs_alloc_mem(ps, num_entries * sizeof(SRV_SHARE_INFO_1))))
				return False;
			ctr->share.info1 = info1;
		}

		for (i = 0; i < num_entries; i++) {
			if(!srv_io_share_info1("", &info1[i].info_1, ps, depth))
				return False;
		}

		for (i = 0; i < num_entries; i++) {
			if(!srv_io_share_info1_str("", &info1[i].info_1_str, ps, depth))
				return False;
		}

		break;
	}

	case 2:
	{
		SRV_SHARE_INFO_2 *info2 = ctr->share.info2;
		int num_entries = ctr->num_entries;
		int i;

		if (UNMARSHALLING(ps)) {
			if (!(info2 = (SRV_SHARE_INFO_2 *)prs_alloc_mem(ps,num_entries * sizeof(SRV_SHARE_INFO_2))))
				return False;
			ctr->share.info2 = info2;
		}

		for (i = 0; i < num_entries; i++) {
			if(!srv_io_share_info2("", &info2[i].info_2, ps, depth))
				return False;
		}

		for (i = 0; i < num_entries; i++) {
			if(!srv_io_share_info2_str("", &info2[i].info_2, &info2[i].info_2_str, ps, depth))
				return False;
		}

		break;
	}

	case 501:
	{
		SRV_SHARE_INFO_501 *info501 = ctr->share.info501;
		int num_entries = ctr->num_entries;
		int i;

		if (UNMARSHALLING(ps)) {
			if (!(info501 = (SRV_SHARE_INFO_501 *) prs_alloc_mem(ps, num_entries *
					sizeof (SRV_SHARE_INFO_501))))
				return False;
			ctr->share.info501 = info501;
		}

		for (i = 0; i < num_entries; i++) {
			if (!srv_io_share_info501("", &info501[i].info_501, ps, depth))
				return False;
		}

		for (i = 0; i < num_entries; i++) {
			if (!srv_io_share_info501_str("", &info501[i].info_501_str, ps, depth))
				return False;
		}

		break;
	}

	case 502:
	{
		SRV_SHARE_INFO_502 *info502 = ctr->share.info502;
		int num_entries = ctr->num_entries;
		int i;

		if (UNMARSHALLING(ps)) {
			if (!(info502 = (SRV_SHARE_INFO_502 *)prs_alloc_mem(ps,num_entries * sizeof(SRV_SHARE_INFO_502))))
				return False;
			ctr->share.info502 = info502;
		}

		for (i = 0; i < num_entries; i++) {
			if(!srv_io_share_info502("", &info502[i].info_502, ps, depth))
				return False;
		}

		for (i = 0; i < num_entries; i++) {
			info502[i].info_502_str.ptrs = &info502[i].info_502;
			if(!srv_io_share_info502_str("", &info502[i].info_502_str, ps, depth))
				return False;
		}

		break;
	}

	default:
		DEBUG(5,("%s no share info at switch_value %d\n",
			 tab_depth(depth), ctr->switch_value));
		break;
	}

	return True;
}

/*******************************************************************
 Inits a SRV_Q_NET_SHARE_ENUM structure.
********************************************************************/

void init_srv_q_net_share_enum(SRV_Q_NET_SHARE_ENUM *q_n,
				const char *srv_name, uint32 info_level,
				uint32 preferred_len, ENUM_HND *hnd)
{

	DEBUG(5,("init_q_net_share_enum\n"));

	init_buf_unistr2(&q_n->uni_srv_name, &q_n->ptr_srv_name, srv_name);

	q_n->ctr.info_level = q_n->ctr.switch_value = info_level;
	q_n->ctr.ptr_share_info = 0;
	q_n->preferred_len = preferred_len;

	memcpy(&q_n->enum_hnd, hnd, sizeof(*hnd));
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_q_net_share_enum(const char *desc, SRV_Q_NET_SHARE_ENUM *q_n, prs_struct *ps, int depth)
{
	if (q_n == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_q_net_share_enum");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("ptr_srv_name", ps, depth, &q_n->ptr_srv_name))
		return False;
	if(!smb_io_unistr2("", &q_n->uni_srv_name, True, ps, depth))
		return False;

	if(!srv_io_srv_share_ctr("share_ctr", &q_n->ctr, ps, depth))
		return False;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("preferred_len", ps, depth, &q_n->preferred_len))
		return False;

	if(!smb_io_enum_hnd("enum_hnd", &q_n->enum_hnd, ps, depth))
		return False;

	return True;
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_r_net_share_enum(const char *desc, SRV_R_NET_SHARE_ENUM *r_n, prs_struct *ps, int depth)
{
	if (r_n == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_r_net_share_enum");
	depth++;

	if(!srv_io_srv_share_ctr("share_ctr", &r_n->ctr, ps, depth))
		return False;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("total_entries", ps, depth, &r_n->total_entries))
		return False;
	if(!smb_io_enum_hnd("enum_hnd", &r_n->enum_hnd, ps, depth))
		return False;
	if(!prs_werror("status     ", ps, depth, &r_n->status))
		return False;

	return True;
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_q_net_share_get_info(const char *desc, SRV_Q_NET_SHARE_GET_INFO *q_n, prs_struct *ps, int depth)
{
	if (q_n == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_q_net_share_get_info");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("ptr_srv_name", ps, depth, &q_n->ptr_srv_name))
		return False;
	if(!smb_io_unistr2("", &q_n->uni_srv_name, True, ps, depth))
		return False;

	if(!smb_io_unistr2("", &q_n->uni_share_name, True, ps, depth))
		return False;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("info_level", ps, depth, &q_n->info_level))
		return False;

	return True;
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_srv_share_info(const char *desc, prs_struct *ps, int depth, SRV_SHARE_INFO *r_n)
{
	if (r_n == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_srv_share_info");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("switch_value ", ps, depth, &r_n->switch_value ))
		return False;

	if(!prs_uint32("ptr_share_ctr", ps, depth, &r_n->ptr_share_ctr))
		return False;

	if (r_n->ptr_share_ctr != 0) {
		switch (r_n->switch_value) {
		case 1:
			if(!srv_io_share_info1("", &r_n->share.info1.info_1, ps, depth))
				return False;

			if(!srv_io_share_info1_str("", &r_n->share.info1.info_1_str, ps, depth))
				return False;

			break;
		case 2:
			if(!srv_io_share_info2("", &r_n->share.info2.info_2, ps, depth))
				return False;

			if(!srv_io_share_info2_str("", &r_n->share.info2.info_2, &r_n->share.info2.info_2_str, ps, depth))
				return False;

			break;
		case 501:
			if (!srv_io_share_info501("", &r_n->share.info501.info_501, ps, depth))
				return False;
			if (!srv_io_share_info501_str("", &r_n->share.info501.info_501_str, ps, depth))
				return False;
			break;

		case 502:
			if(!srv_io_share_info502("", &r_n->share.info502.info_502, ps, depth))
				return False;

			/*allow access to pointers in the str part. */
			r_n->share.info502.info_502_str.ptrs = &r_n->share.info502.info_502;

			if(!srv_io_share_info502_str("", &r_n->share.info502.info_502_str, ps, depth))
				return False;
			break;
		case 1005:
			if(!srv_io_share_info1005("", &r_n->share.info1005, ps, depth))
				return False;
			break;
		case 1501:
			if (!srv_io_share_info1501("", &r_n->share.info1501, ps, depth))
				return False;
		default:
			DEBUG(5,("%s no share info at switch_value %d\n",
				 tab_depth(depth), r_n->switch_value));
			break;
		}
	}

	return True;
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_r_net_share_get_info(const char *desc, SRV_R_NET_SHARE_GET_INFO *r_n, prs_struct *ps, int depth)
{
	if (r_n == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_r_net_share_get_info");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!srv_io_srv_share_info("info  ", ps, depth, &r_n->info))
		return False;

	if(!prs_align(ps))
		return False;

	if(!prs_werror("status", ps, depth, &r_n->status))
		return False;

	return True;
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_q_net_share_set_info(const char *desc, SRV_Q_NET_SHARE_SET_INFO *q_n, prs_struct *ps, int depth)
{
	if (q_n == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_q_net_share_set_info");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("ptr_srv_name", ps, depth, &q_n->ptr_srv_name))
		return False;
	if(!smb_io_unistr2("", &q_n->uni_srv_name, True, ps, depth))
		return False;

	if(!smb_io_unistr2("", &q_n->uni_share_name, True, ps, depth))
		return False;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("info_level", ps, depth, &q_n->info_level))
		return False;

	if(!prs_align(ps))
		return False;

	if(!srv_io_srv_share_info("info  ", ps, depth, &q_n->info))
		return False;

	return True;
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_r_net_share_set_info(const char *desc, SRV_R_NET_SHARE_SET_INFO *q_n, prs_struct *ps, int depth)
{
	if (q_n == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_r_net_share_set_info");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("switch_value  ", ps, depth, &q_n->switch_value))
		return False;
	if(!prs_werror("status        ", ps, depth, &q_n->status))
		return False;

	return True;
}	

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_q_net_share_add(const char *desc, SRV_Q_NET_SHARE_ADD *q_n, prs_struct *ps, int depth)
{
	if (q_n == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_q_net_share_add");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("ptr_srv_name", ps, depth, &q_n->ptr_srv_name))
		return False;
	if(!smb_io_unistr2("", &q_n->uni_srv_name, True, ps, depth))
		return False;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("info_level", ps, depth, &q_n->info_level))
		return False;

	if(!prs_align(ps))
		return False;

	if(!srv_io_srv_share_info("info  ", ps, depth, &q_n->info))
		return False;

	return True;
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_r_net_share_add(const char *desc, SRV_R_NET_SHARE_ADD *q_n, prs_struct *ps, int depth)
{
	if (q_n == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_r_net_share_add");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("switch_value  ", ps, depth, &q_n->switch_value))
		return False;
	if(!prs_werror("status        ", ps, depth, &q_n->status))
		return False;

	return True;
}	

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_q_net_share_del(const char *desc, SRV_Q_NET_SHARE_DEL *q_n, prs_struct *ps, int depth)
{
	if (q_n == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_q_net_share_del");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("ptr_srv_name", ps, depth, &q_n->ptr_srv_name))
		return False;
	if(!smb_io_unistr2("", &q_n->uni_srv_name, True, ps, depth))
		return False;

	if(!smb_io_unistr2("", &q_n->uni_share_name, True, ps, depth))
		return False;

	return True;
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_r_net_share_del(const char *desc, SRV_R_NET_SHARE_DEL *q_n, prs_struct *ps, int depth)
{
	if (q_n == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_r_net_share_del");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!prs_werror("status        ", ps, depth, &q_n->status))
		return False;

	return True;
}	

/*******************************************************************
 Inits a SESS_INFO_0_STR structure
********************************************************************/

void init_srv_sess_info0_str(SESS_INFO_0_STR *ss0, const char *name)
{
	DEBUG(5,("init_srv_sess_info0_str\n"));

	init_unistr2(&ss0->uni_name, name, strlen(name)+1);
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_sess_info0_str(const char *desc,  SESS_INFO_0_STR *ss0, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Inits a SESS_INFO_0 structure
********************************************************************/

void init_srv_sess_info0(SESS_INFO_0 *ss0, const char *name)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_sess_info0(const char *desc, SESS_INFO_0 *ss0, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_srv_sess_info_0(const char *desc, SRV_SESS_INFO_0 *ss0, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Inits a SESS_INFO_1_STR structure
********************************************************************/

void init_srv_sess_info1_str(SESS_INFO_1_STR *ss1, const char *name, const char *user)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_sess_info1_str(const char *desc, SESS_INFO_1_STR *ss1, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Inits a SESS_INFO_1 structure
********************************************************************/

void init_srv_sess_info1(SESS_INFO_1 *ss1,
				const char *name, const char *user,
				uint32 num_opens, uint32 open_time, uint32 idle_time,
				uint32 user_flags)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

static BOOL srv_io_sess_info1(const char *desc, SESS_INFO_1 *ss1, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_srv_sess_info_1(const char *desc, SRV_SESS_INFO_1 *ss1, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_srv_sess_ctr(const char *desc, SRV_SESS_INFO_CTR **pp_ctr, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Inits a SRV_Q_NET_SESS_ENUM structure.
********************************************************************/

void init_srv_q_net_sess_enum(SRV_Q_NET_SESS_ENUM *q_n,
				const char *srv_name, const char *qual_name,
				uint32 sess_level, SRV_SESS_INFO_CTR *ctr,
				uint32 preferred_len,
				ENUM_HND *hnd)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_q_net_sess_enum(const char *desc, SRV_Q_NET_SESS_ENUM *q_n, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_r_net_sess_enum(const char *desc, SRV_R_NET_SESS_ENUM *r_n, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Inits a CONN_INFO_0 structure
********************************************************************/

void init_srv_conn_info0(CONN_INFO_0 *ss0, uint32 id)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_conn_info0(const char *desc, CONN_INFO_0 *ss0, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_srv_conn_info_0(const char *desc, SRV_CONN_INFO_0 *ss0, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Inits a CONN_INFO_1_STR structure
********************************************************************/

void init_srv_conn_info1_str(CONN_INFO_1_STR *ss1, const char *usr_name, const char *net_name)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_conn_info1_str(const char *desc, CONN_INFO_1_STR *ss1, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Inits a CONN_INFO_1 structure
********************************************************************/

void init_srv_conn_info1(CONN_INFO_1 *ss1,
				uint32 id, uint32 type,
				uint32 num_opens, uint32 num_users, uint32 open_time,
				const char *usr_name, const char *net_name)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_conn_info1(const char *desc, CONN_INFO_1 *ss1, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_srv_conn_info_1(const char *desc, SRV_CONN_INFO_1 *ss1, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_srv_conn_ctr(const char *desc, SRV_CONN_INFO_CTR **pp_ctr, prs_struct *ps, int depth)
{
	SRV_CONN_INFO_CTR *ctr = *pp_ctr;

	prs_debug(ps, depth, desc, "srv_io_srv_conn_ctr");
	depth++;

	if (UNMARSHALLING(ps)) {
		ctr = *pp_ctr = (SRV_CONN_INFO_CTR *)prs_alloc_mem(ps, sizeof(SRV_CONN_INFO_CTR));
		if (ctr == NULL)
			return False;
	}
		
	if (ctr == NULL)
		return False;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("switch_value", ps, depth, &ctr->switch_value))
		return False;
	if(!prs_uint32("ptr_conn_ctr", ps, depth, &ctr->ptr_conn_ctr))
		return False;

	if (ctr->ptr_conn_ctr != 0) {
		switch (ctr->switch_value) {
		case 0:
			if(!srv_io_srv_conn_info_0("", &ctr->conn.info0, ps, depth))
				return False;
			break;
		case 1:
			if(!srv_io_srv_conn_info_1("", &ctr->conn.info1, ps, depth))
				return False;
			break;
		default:
			DEBUG(5,("%s no connection info at switch_value %d\n",
			         tab_depth(depth), ctr->switch_value));
			break;
		}
	}

	return True;
}

/*******************************************************************
  Reads or writes a structure.
********************************************************************/

void init_srv_q_net_conn_enum(SRV_Q_NET_CONN_ENUM *q_n,
				const char *srv_name, const char *qual_name,
				uint32 conn_level, SRV_CONN_INFO_CTR *ctr,
				uint32 preferred_len,
				ENUM_HND *hnd)
{  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_q_net_conn_enum(const char *desc, SRV_Q_NET_CONN_ENUM *q_n, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_r_net_conn_enum(const char *desc,  SRV_R_NET_CONN_ENUM *r_n, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Inits a FILE_INFO_3_STR structure
********************************************************************/

void init_srv_file_info3_str(FILE_INFO_3_STR *fi3, const char *user_name, const char *path_name)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_file_info3_str(const char *desc, FILE_INFO_3_STR *sh1, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Inits a FILE_INFO_3 structure
********************************************************************/

void init_srv_file_info3(FILE_INFO_3 *fl3,
				uint32 id, uint32 perms, uint32 num_locks,
				const char *path_name, const char *user_name)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_file_info3(const char *desc, FILE_INFO_3 *fl3, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_srv_file_info_3(const char *desc, SRV_FILE_INFO_3 *fl3, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

static BOOL srv_io_srv_file_ctr(const char *desc, SRV_FILE_INFO_CTR **pp_ctr, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Inits a SRV_Q_NET_FILE_ENUM structure.
********************************************************************/

void init_srv_q_net_file_enum(SRV_Q_NET_FILE_ENUM *q_n,
				const char *srv_name, const char *qual_name,
				uint32 file_level, SRV_FILE_INFO_CTR *ctr,
				uint32 preferred_len,
				ENUM_HND *hnd)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_q_net_file_enum(const char *desc, SRV_Q_NET_FILE_ENUM *q_n, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_r_net_file_enum(const char *desc, SRV_R_NET_FILE_ENUM *r_n, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Inits a SRV_INFO_100 structure.
 ********************************************************************/

void init_srv_info_100(SRV_INFO_100 *sv100, uint32 platform_id, const char *name)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a SRV_INFO_101 structure.
 ********************************************************************/

static BOOL srv_io_info_100(const char *desc, SRV_INFO_100 *sv100, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}


/*******************************************************************
 Inits a SRV_INFO_101 structure.
 ********************************************************************/

void init_srv_info_101(SRV_INFO_101 *sv101, uint32 platform_id, const char *name,
				uint32 ver_major, uint32 ver_minor,
				uint32 srv_type, const char *comment)
{
	DEBUG(5,("init_srv_info_101\n"));

	sv101->platform_id  = platform_id;
	init_buf_unistr2(&sv101->uni_name, &sv101->ptr_name, name);
	sv101->ver_major    = ver_major;
	sv101->ver_minor    = ver_minor;
	sv101->srv_type     = srv_type;
	init_buf_unistr2(&sv101->uni_comment, &sv101->ptr_comment, comment);
}

/*******************************************************************
 Reads or writes a SRV_INFO_101 structure.
 ********************************************************************/

static BOOL srv_io_info_101(const char *desc, SRV_INFO_101 *sv101, prs_struct *ps, int depth)
{
	if (sv101 == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_info_101");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("platform_id ", ps, depth, &sv101->platform_id))
		return False;
	if(!prs_uint32("ptr_name    ", ps, depth, &sv101->ptr_name))
		return False;
	if(!prs_uint32("ver_major   ", ps, depth, &sv101->ver_major))
		return False;
	if(!prs_uint32("ver_minor   ", ps, depth, &sv101->ver_minor))
		return False;
	if(!prs_uint32("srv_type    ", ps, depth, &sv101->srv_type))
		return False;
	if(!prs_uint32("ptr_comment ", ps, depth, &sv101->ptr_comment))
		return False;

	if(!prs_align(ps))
		return False;

	if(!smb_io_unistr2("uni_name    ", &sv101->uni_name, True, ps, depth))
		return False;
	if(!smb_io_unistr2("uni_comment ", &sv101->uni_comment, True, ps, depth))
		return False;

	return True;
}

/*******************************************************************
 Inits a SRV_INFO_102 structure.
 ********************************************************************/

void init_srv_info_102(SRV_INFO_102 *sv102, uint32 platform_id, const char *name,
				const char *comment, uint32 ver_major, uint32 ver_minor,
				uint32 srv_type, uint32 users, uint32 disc, uint32 hidden,
				uint32 announce, uint32 ann_delta, uint32 licenses,
				const char *usr_path)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}


/*******************************************************************
 Reads or writes a SRV_INFO_102 structure.
 ********************************************************************/

static BOOL srv_io_info_102(const char *desc, SRV_INFO_102 *sv102, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a SRV_INFO_102 structure.
 ********************************************************************/

static BOOL srv_io_info_ctr(const char *desc, SRV_INFO_CTR *ctr, prs_struct *ps, int depth)
{
	if (ctr == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_info_ctr");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("switch_value", ps, depth, &ctr->switch_value))
		return False;
	if(!prs_uint32("ptr_srv_ctr ", ps, depth, &ctr->ptr_srv_ctr))
		return False;

	if (ctr->ptr_srv_ctr != 0 && ctr->switch_value != 0 && ctr != NULL) {
		switch (ctr->switch_value) {
		case 100:
			if(!srv_io_info_100("sv100", &ctr->srv.sv100, ps, depth))
				return False;
			break;
		case 101:
			if(!srv_io_info_101("sv101", &ctr->srv.sv101, ps, depth))
				return False;
			break;
		case 102:
			if(!srv_io_info_102("sv102", &ctr->srv.sv102, ps, depth))
				return False;
			break;
		default:
			DEBUG(5,("%s no server info at switch_value %d\n",
					 tab_depth(depth), ctr->switch_value));
			break;
		}
		if(!prs_align(ps))
			return False;
	}

	return True;
}

/*******************************************************************
 Inits a SRV_Q_NET_SRV_GET_INFO structure.
 ********************************************************************/

void init_srv_q_net_srv_get_info(SRV_Q_NET_SRV_GET_INFO *srv,
				const char *server_name, uint32 switch_value)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_q_net_srv_get_info(const char *desc, SRV_Q_NET_SRV_GET_INFO *q_n, prs_struct *ps, int depth)
{
	if (q_n == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_q_net_srv_get_info");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("ptr_srv_name  ", ps, depth, &q_n->ptr_srv_name))
		return False;
	if(!smb_io_unistr2("", &q_n->uni_srv_name, True, ps, depth))
		return False;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("switch_value  ", ps, depth, &q_n->switch_value))
		return False;

	return True;
}

/*******************************************************************
 Inits a SRV_R_NET_SRV_GET_INFO structure.
 ********************************************************************/

void init_srv_r_net_srv_get_info(SRV_R_NET_SRV_GET_INFO *srv,
				uint32 switch_value, SRV_INFO_CTR *ctr, WERROR status)
{
	DEBUG(5,("init_srv_r_net_srv_get_info\n"));

	srv->ctr = ctr;

	if (W_ERROR_IS_OK(status)) {
		srv->ctr->switch_value = switch_value;
		srv->ctr->ptr_srv_ctr  = 1;
	} else {
		srv->ctr->switch_value = 0;
		srv->ctr->ptr_srv_ctr  = 0;
	}

	srv->status = status;
}

/*******************************************************************
 Inits a SRV_R_NET_SRV_SET_INFO structure.
 ********************************************************************/

void init_srv_r_net_srv_set_info(SRV_R_NET_SRV_SET_INFO *srv,
				 uint32 switch_value, WERROR status)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_q_net_srv_set_info(const char *desc, SRV_Q_NET_SRV_SET_INFO *q_n,
			       prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
 ********************************************************************/

BOOL srv_io_r_net_srv_get_info(const char *desc, SRV_R_NET_SRV_GET_INFO *r_n, prs_struct *ps, int depth)
{
	if (r_n == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_r_net_srv_get_info");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!srv_io_info_ctr("ctr", r_n->ctr, ps, depth))
		return False;

	if(!prs_werror("status      ", ps, depth, &r_n->status))
		return False;

	return True;
}

/*******************************************************************
 Reads or writes a structure.
 ********************************************************************/

BOOL srv_io_r_net_srv_set_info(const char *desc, SRV_R_NET_SRV_SET_INFO *r_n,
			       prs_struct *ps, int depth)
{
	prs_debug(ps, depth, desc, "srv_io_r_net_srv_set_info");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("switch_value  ", ps, depth, &r_n->switch_value))
		return False;

	if(!prs_werror("status ", ps, depth, &r_n->status))
		return False;

	return True;
}

/*******************************************************************
 Reads or writes a structure.
 ********************************************************************/

BOOL srv_io_q_net_remote_tod(const char *desc, SRV_Q_NET_REMOTE_TOD *q_n, prs_struct *ps, int depth)
{
	if (q_n == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_q_net_remote_tod");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("ptr_srv_name  ", ps, depth, &q_n->ptr_srv_name))
		return False;
	if(!smb_io_unistr2("", &q_n->uni_srv_name, True, ps, depth))
		return False;

	return True;
}

/*******************************************************************
 Reads or writes a TIME_OF_DAY_INFO structure.
 ********************************************************************/

static BOOL srv_io_time_of_day_info(const char *desc, TIME_OF_DAY_INFO *tod, prs_struct *ps, int depth)
{
	if (tod == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_time_of_day_info");
	depth++;

	if(!prs_align(ps))
		return False;
	
	if(!prs_uint32("elapsedt   ", ps, depth, &tod->elapsedt))
		return False;
	if(!prs_uint32("msecs      ", ps, depth, &tod->msecs))
		return False;
	if(!prs_uint32("hours      ", ps, depth, &tod->hours))
		return False;
	if(!prs_uint32("mins       ", ps, depth, &tod->mins))
		return False;
	if(!prs_uint32("secs       ", ps, depth, &tod->secs))
		return False;
	if(!prs_uint32("hunds      ", ps, depth, &tod->hunds))
		return False;
	if(!prs_uint32("timezone   ", ps, depth, &tod->zone))
		return False;
	if(!prs_uint32("tintervals ", ps, depth, &tod->tintervals))
		return False;
	if(!prs_uint32("day        ", ps, depth, &tod->day))
		return False;
	if(!prs_uint32("month      ", ps, depth, &tod->month))
		return False;
	if(!prs_uint32("year       ", ps, depth, &tod->year))
		return False;
	if(!prs_uint32("weekday    ", ps, depth, &tod->weekday))
		return False;

	return True;
}

/*******************************************************************
 Inits a TIME_OF_DAY_INFO structure.
 ********************************************************************/

void init_time_of_day_info(TIME_OF_DAY_INFO *tod, uint32 elapsedt, uint32 msecs,
			   uint32 hours, uint32 mins, uint32 secs, uint32 hunds,
			   uint32 zone, uint32 tintervals, uint32 day,
			   uint32 month, uint32 year, uint32 weekday)
{
	DEBUG(5,("init_time_of_day_info\n"));

	tod->elapsedt	= elapsedt;
	tod->msecs	= msecs;
	tod->hours	= hours;
	tod->mins	= mins;
	tod->secs	= secs;
	tod->hunds	= hunds;
	tod->zone	= zone;
	tod->tintervals	= tintervals;
	tod->day	= day;
	tod->month	= month;
	tod->year	= year;
	tod->weekday	= weekday;
}


/*******************************************************************
 Reads or writes a structure.
 ********************************************************************/

BOOL srv_io_r_net_remote_tod(const char *desc, SRV_R_NET_REMOTE_TOD *r_n, prs_struct *ps, int depth)
{
	if (r_n == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_r_net_remote_tod");
	depth++;

	if(!prs_align(ps))
		return False;
	
	if(!prs_uint32("ptr_srv_tod ", ps, depth, &r_n->ptr_srv_tod))
		return False;

	if(!srv_io_time_of_day_info("tod", r_n->tod, ps, depth))
		return False;

	if(!prs_werror("status      ", ps, depth, &r_n->status))
		return False;

	return True;
}

/*******************************************************************
 Reads or writes a structure.
 ********************************************************************/

BOOL srv_io_q_net_disk_enum(const char *desc, SRV_Q_NET_DISK_ENUM *q_n, prs_struct *ps, int depth)
{
	if (q_n == NULL)
		return False;

	prs_debug(ps, depth, desc, "srv_io_q_net_disk_enum");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("ptr_srv_name", ps, depth, &q_n->ptr_srv_name))
		return False;

	if(!smb_io_unistr2("", &q_n->uni_srv_name, True, ps, depth))
		return False;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("level", ps, depth, &q_n->disk_enum_ctr.level))
		return False;

	if(!prs_uint32("entries_read", ps, depth, &q_n->disk_enum_ctr.entries_read))
		return False;

	if(!prs_uint32("buffer", ps, depth, &q_n->disk_enum_ctr.disk_info_ptr))
		return False;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("preferred_len", ps, depth, &q_n->preferred_len))
		return False;
	if(!smb_io_enum_hnd("enum_hnd", &q_n->enum_hnd, ps, depth))
		return False;

	return True;
}

/*******************************************************************
 Reads or writes a structure.
 ********************************************************************/

BOOL srv_io_r_net_disk_enum(const char *desc, SRV_R_NET_DISK_ENUM *r_n, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
 ********************************************************************/

BOOL srv_io_q_net_name_validate(const char *desc, SRV_Q_NET_NAME_VALIDATE *q_n, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
 ********************************************************************/

BOOL srv_io_r_net_name_validate(const char *desc, SRV_R_NET_NAME_VALIDATE *r_n, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_q_net_file_query_secdesc(const char *desc, SRV_Q_NET_FILE_QUERY_SECDESC *q_n, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_r_net_file_query_secdesc(const char *desc, SRV_R_NET_FILE_QUERY_SECDESC *r_n, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_q_net_file_set_secdesc(const char *desc, SRV_Q_NET_FILE_SET_SECDESC *q_n, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Reads or writes a structure.
********************************************************************/

BOOL srv_io_r_net_file_set_secdesc(const char *desc, SRV_R_NET_FILE_SET_SECDESC *r_n, prs_struct *ps, int depth)
{
	  DEBUG(1,("function ommited\n"));
	/* function omited*/
}
