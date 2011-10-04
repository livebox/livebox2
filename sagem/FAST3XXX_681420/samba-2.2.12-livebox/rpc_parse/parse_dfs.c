/*
 *  Unix SMB/Netbios implementation.
 *  Version 1.9.
 *  MSDfs RPC Pipe client / server routines
 *  Copyright (C) Andrew Tridgell              1992-2000,
 *  Copyright (C) Luke Kenneth Casson Leighton 1996-2000,
 *  Copyright (C) Shirish Kalele               2000.
 *  Copyright (C) Jeremy Allison				2001.
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
#include "nterr.h"
#include "rpc_parse.h"

/*******************************************************************
Make a DFS_Q_DFS_QUERY structure
*******************************************************************/

void init_dfs_q_dfs_exist(DFS_Q_DFS_EXIST *q_d)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*************************************************************
 Read/write a DFS_Q_DFS_EXIST structure - dummy...
 ************************************************************/

BOOL dfs_io_q_dfs_exist(const char *desc, DFS_Q_DFS_EXIST *q_d, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}
/*************************************************************
 Read/write a DFS_R_DFS_EXIST structure
 ************************************************************/

BOOL dfs_io_r_dfs_exist(const char *desc, DFS_R_DFS_EXIST *q_d, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
Make a DFS_Q_DFS_REMOVE structure
*******************************************************************/

BOOL init_dfs_q_dfs_remove(DFS_Q_DFS_REMOVE *q_d, const char *entrypath,
			   const char *servername, const char *sharename)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
Read/write a DFS_Q_DFS_REMOVE structure
*******************************************************************/

BOOL dfs_io_q_dfs_remove(const char *desc, DFS_Q_DFS_REMOVE *q_d, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
Read/write a DFS_R_DFS_REMOVE structure
*******************************************************************/

BOOL dfs_io_r_dfs_remove(const char *desc, DFS_R_DFS_REMOVE *r_d, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
Make a DFS_Q_DFS_ADD structure
*******************************************************************/

BOOL init_dfs_q_dfs_add(DFS_Q_DFS_ADD *q_d, const char *entrypath, const char *servername,
			const char *sharename, const char *comment, uint32 flags)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/************************************************************
 Read/write a DFS_Q_DFS_ADD structure
 ************************************************************/

BOOL dfs_io_q_dfs_add(const char *desc, DFS_Q_DFS_ADD *q_d, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/************************************************************
 Read/write a DFS_R_DFS_ADD structure
 ************************************************************/

BOOL dfs_io_r_dfs_add(const char *desc, DFS_R_DFS_ADD *r_d, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

BOOL init_dfs_q_dfs_get_info(DFS_Q_DFS_GET_INFO *q_d, const char *entrypath,
			     const char *servername, const char *sharename,
			     uint32 info_level)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/************************************************************
 Read/write a DFS_Q_GET_INFO structure
 ************************************************************/

BOOL dfs_io_q_dfs_get_info(const char* desc, DFS_Q_DFS_GET_INFO* q_i, prs_struct* ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/************************************************************
 Read/write a DFS_R_GET_INFO structure
 ************************************************************/

BOOL dfs_io_r_dfs_get_info(const char* desc, DFS_R_DFS_GET_INFO* r_i, prs_struct* ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/************************************************************
 Make a DFS_Q_DFS_ENUM structure
 ************************************************************/
BOOL init_dfs_q_dfs_enum(DFS_Q_DFS_ENUM *q_d, uint32 level, DFS_INFO_CTR *ctr)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/************************************************************
 Read or write the DFS_Q_DFS_ENUM structure
 ************************************************************/

BOOL dfs_io_q_dfs_enum(const char *desc, DFS_Q_DFS_ENUM *q_d, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/************************************************************
 Read/write a DFS_INFO_CTR structure
 ************************************************************/

BOOL dfs_io_dfs_info_ctr(const char *desc, DFS_INFO_CTR* ctr, uint32 num_entries, uint32 level, prs_struct* ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/************************************************************
 Read/write a DFS_R_DFS_ENUM structure
 ************************************************************/

BOOL dfs_io_r_dfs_enum(const char *desc, DFS_R_DFS_ENUM *q_d, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

BOOL dfs_io_dfs_storage_info(const char *desc, DFS_INFO_3* info3, prs_struct *ps, int depth)
{
	int i=0;
	if(info3 == NULL)
		return False;

	prs_debug(ps, depth, desc, "smb_io_dfs_storage_info");
	depth++;

	if(UNMARSHALLING(ps)) {
		info3->storages = (DFS_STORAGE_INFO *)prs_alloc_mem(ps, info3->num_storage_infos*sizeof(DFS_STORAGE_INFO));
		if (!info3->storages)
			return False;
	}

	for(i=0;i<info3->num_storage_infos;i++) {
		if(!prs_uint32("storage_state", ps, depth, &info3->storages[i].state))
			return False;
		if(!prs_uint32("ptr_servername", ps, depth, &info3->storages[i].ptr_servername))
			return False;
		if(!prs_uint32("ptr_sharename", ps, depth, &info3->storages[i].ptr_sharename))
			return False;
	}

	for(i=0;i<info3->num_storage_infos;i++) {
		if(!smb_io_unistr2("servername", &info3->storages[i].servername, info3->storages[i].ptr_servername, ps, depth))
			return False;
		if(!prs_align(ps))
			return False;
		if(!smb_io_unistr2("sharename", &info3->storages[i].sharename, info3->storages[i].ptr_sharename, ps, depth))
			return False;
		if(!prs_align(ps))
			return False;
	}

	return True;
}
