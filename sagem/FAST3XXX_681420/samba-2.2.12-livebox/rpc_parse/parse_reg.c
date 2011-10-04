/*
 *  Unix SMB/Netbios implementation.
 *  Version 1.9.
 *  RPC Pipe client / server routines
 *  Copyright (C) Andrew Tridgell              1992-1997,
 *  Copyright (C) Luke Kenneth Casson Leighton 1996-1997,
 *  Copyright (C) Paul Ashton                       1997.
 *  Copyright (C) Marc Jacobsen                     1999.
 *  Copyright (C) Simo Sorce                        2000.
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
 Inits a structure.
********************************************************************/

void init_reg_q_open_hkcr(REG_Q_OPEN_HKCR *q_o,
				uint16 unknown_0, uint32 level)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_q_open_hkcr(const char *desc,  REG_Q_OPEN_HKCR *r_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_r_open_hkcr(const char *desc,  REG_R_OPEN_HKCR *r_r, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a structure.
********************************************************************/

void init_reg_q_open_hklm(REG_Q_OPEN_HKLM * q_o,
			  uint16 unknown_0, uint32 access_mask)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/

}

/*******************************************************************
reads or writes a structure.
********************************************************************/
BOOL reg_io_q_open_hklm(const char *desc, REG_Q_OPEN_HKLM * r_q, prs_struct *ps,
			int depth)
{
	if (r_q == NULL)
		return False;

	prs_debug(ps, depth, desc, "reg_io_q_open_hklm");
	depth++;

	if (!prs_align(ps))
		return False;

	if (!prs_uint32("ptr      ", ps, depth, &(r_q->ptr)))
		return False;
	if (r_q->ptr != 0)
	{
		if (!prs_uint16("unknown_0", ps, depth, &(r_q->unknown_0)))
		return False;
		if (!prs_uint16("unknown_1", ps, depth, &(r_q->unknown_1)))
		return False;
		if (!prs_uint32("access_mask", ps, depth, &(r_q->access_mask)))
		return False;
	}

	return True;
}


/*******************************************************************
reads or writes a structure.
********************************************************************/
BOOL reg_io_r_open_hklm(const char *desc, REG_R_OPEN_HKLM * r_r, prs_struct *ps,
			int depth)
{
	if (r_r == NULL)
		return False;

	prs_debug(ps, depth, desc, "reg_io_r_open_hklm");
	depth++;

	if (!prs_align(ps))
		return False;

	if (!smb_io_pol_hnd("", &r_r->pol, ps, depth))
		return False;

	if (!prs_ntstatus("status", ps, depth, &r_r->status))
		return False;

	return True;
}


/*******************************************************************
 Inits a structure.
********************************************************************/

void init_reg_q_flush_key(REG_Q_FLUSH_KEY *q_u, POLICY_HND *pol)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_q_flush_key(const char *desc,  REG_Q_FLUSH_KEY *r_q, prs_struct *ps, int depth)
{
	if (r_q == NULL)
		return False;

	prs_debug(ps, depth, desc, "reg_io_q_flush_key");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!smb_io_pol_hnd("", &r_q->pol, ps, depth))
		return False;

	return True;
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_r_flush_key(const char *desc,  REG_R_FLUSH_KEY *r_r, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes SEC_DESC_BUF and SEC_DATA structures.
********************************************************************/

static BOOL reg_io_hdrbuf_sec(uint32 ptr, uint32 *ptr3, BUFHDR *hdr_sec, SEC_DESC_BUF *data, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a structure.
********************************************************************/

void init_reg_q_create_key(REG_Q_CREATE_KEY *q_c, POLICY_HND *hnd,
				const char *name, const char *class, SEC_ACCESS *sam_access,
				SEC_DESC_BUF *sec_buf)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_q_create_key(const char *desc,  REG_Q_CREATE_KEY *r_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_r_create_key(const char *desc,  REG_R_CREATE_KEY *r_r, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
 Inits a structure.
********************************************************************/

void init_reg_q_delete_val(REG_Q_DELETE_VALUE *q_c, POLICY_HND *hnd,
				const char *name)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_q_delete_val(const char *desc,  REG_Q_DELETE_VALUE *r_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_r_delete_val(const char *desc,  REG_R_DELETE_VALUE *r_r, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a structure.
********************************************************************/

void init_reg_q_delete_key(REG_Q_DELETE_KEY *q_c, POLICY_HND *hnd,
				const char *name)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_q_delete_key(const char *desc,  REG_Q_DELETE_KEY *r_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_r_delete_key(const char *desc,  REG_R_DELETE_KEY *r_r, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a structure.
********************************************************************/

void init_reg_q_query_key(REG_Q_QUERY_KEY *q_o, POLICY_HND *hnd,
				uint32 max_class_len)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_q_query_key(const char *desc,  REG_Q_QUERY_KEY *r_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_r_query_key(const char *desc,  REG_R_QUERY_KEY *r_r, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a structure.
********************************************************************/

void init_reg_q_unk_1a(REG_Q_UNK_1A *q_o, POLICY_HND *hnd)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_q_unk_1a(const char *desc,  REG_Q_UNK_1A *r_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_r_unk_1a(const char *desc,  REG_R_UNK_1A *r_r, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a structure.
********************************************************************/

void init_reg_q_open_hku(REG_Q_OPEN_HKU *q_o,
				uint16 unknown_0, uint32 level)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_q_open_hku(const char *desc,  REG_Q_OPEN_HKU *r_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_r_open_hku(const char *desc,  REG_R_OPEN_HKU *r_r, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits an REG_Q_CLOSE structure.
********************************************************************/

void init_reg_q_close(REG_Q_CLOSE *q_c, POLICY_HND *hnd)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_q_close(const char *desc,  REG_Q_CLOSE *q_u, prs_struct *ps, int depth)
{
	if (q_u == NULL)
		return False;

	prs_debug(ps, depth, desc, "reg_io_q_unknown_1");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!smb_io_pol_hnd("", &q_u->pol, ps, depth))
		return False;
	if(!prs_align(ps))
		return False;

	return True;
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_r_close(const char *desc,  REG_R_CLOSE *r_u, prs_struct *ps, int depth)
{
	if (r_u == NULL)
		return False;

	prs_debug(ps, depth, desc, "reg_io_r_unknown_1");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!smb_io_pol_hnd("", &r_u->pol, ps, depth))
		return False;
	if(!prs_align(ps))
		return False;

	if(!prs_ntstatus("status", ps, depth, &r_u->status))
		return False;

	return True;
}

/*******************************************************************
makes a structure.
********************************************************************/

void init_reg_q_set_key_sec(REG_Q_SET_KEY_SEC *q_i, POLICY_HND *pol, SEC_DESC_BUF *sec_desc_buf)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_q_set_key_sec(const char *desc,  REG_Q_SET_KEY_SEC *r_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_r_set_key_sec(const char *desc, REG_R_SET_KEY_SEC *r_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
makes a structure.
********************************************************************/

void init_reg_q_get_key_sec(REG_Q_GET_KEY_SEC *q_i, POLICY_HND *pol,
				uint32 sec_buf_size, SEC_DESC_BUF *psdb)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_q_get_key_sec(const char *desc,  REG_Q_GET_KEY_SEC *r_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

#if 0
/*******************************************************************
makes a structure.
********************************************************************/
 void init_reg_r_get_key_sec(REG_R_GET_KEY_SEC *r_i, POLICY_HND *pol,
				uint32 buf_len, uint8 *buf,
				NTSTATUS status)
{
	r_i->ptr = 1;
	init_buf_hdr(&r_i->hdr_sec, buf_len, buf_len);
	init_sec_desc_buf(r_i->data, buf_len, 1);

	r_i->status = status; /* 0x0000 0000 or 0x0000 007a */
}
#endif

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_r_get_key_sec(const char *desc,  REG_R_GET_KEY_SEC *r_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
makes a structure.
********************************************************************/

BOOL init_reg_q_info(REG_Q_INFO *q_i, POLICY_HND *pol, char* val_name)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_q_info(const char *desc,  REG_Q_INFO *r_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a structure.
********************************************************************/

BOOL init_reg_r_info(uint32 include_keyval, REG_R_INFO *r_r,
		     BUFFER2* buf, uint32 type, NTSTATUS status)
{
DEBUG(1,("function ommited\n"));
/* function omited*/

}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_r_info(const char *desc, REG_R_INFO *r_r, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
makes a structure.
********************************************************************/

void init_reg_q_enum_val(REG_Q_ENUM_VALUE *q_i, POLICY_HND *pol,
				uint32 val_idx, uint32 max_val_len,
				uint32 max_buf_len)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_q_enum_val(const char *desc,  REG_Q_ENUM_VALUE *q_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_r_enum_val(const char *desc,  REG_R_ENUM_VALUE *r_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
makes a structure.
********************************************************************/

void init_reg_q_create_val(REG_Q_CREATE_VALUE *q_i, POLICY_HND *pol,
				const char *val_name, uint32 type,
				BUFFER3 *val)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_q_create_val(const char *desc,  REG_Q_CREATE_VALUE *q_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_r_create_val(const char *desc,  REG_R_CREATE_VALUE *r_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
makes a structure.
********************************************************************/

void init_reg_q_enum_key(REG_Q_ENUM_KEY *q_i, POLICY_HND *pol, uint32 key_idx)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_q_enum_key(const char *desc,  REG_Q_ENUM_KEY *q_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_r_enum_key(const char *desc,  REG_R_ENUM_KEY *r_q, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
makes a structure.
********************************************************************/

void init_reg_q_open_entry(REG_Q_OPEN_ENTRY *r_q, POLICY_HND *pol,
				const char *key_name, uint32 unk)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_q_open_entry(const char *desc,  REG_Q_OPEN_ENTRY *r_q, prs_struct *ps, int depth)
{
	if (r_q == NULL)
		return False;

	prs_debug(ps, depth, desc, "reg_io_q_entry");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!smb_io_pol_hnd("", &r_q->pol, ps, depth))
		return False;
	if(!smb_io_unihdr ("", &r_q->hdr_name, ps, depth))
		return False;
	if(!smb_io_unistr2("", &r_q->uni_name, r_q->hdr_name.buffer, ps, depth))
		return False;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("unknown_0", ps, depth, &r_q->unknown_0))
		return False;
	if(!prs_uint32("unknown_1", ps, depth, &r_q->unknown_1))
		return False;

	return True;
}

/*******************************************************************
 Inits a structure.
********************************************************************/

void init_reg_r_open_entry(REG_R_OPEN_ENTRY *r_r,
			   POLICY_HND *pol, NTSTATUS status)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/

BOOL reg_io_r_open_entry(const char *desc,  REG_R_OPEN_ENTRY *r_r, prs_struct *ps, int depth)
{
	if (r_r == NULL)
		return False;

	prs_debug(ps, depth, desc, "reg_io_r_open_entry");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!smb_io_pol_hnd("", &r_r->pol, ps, depth))
		return False;

	if(!prs_ntstatus("status", ps, depth, &r_r->status))
		return False;

	return True;
}

/*******************************************************************
Inits a structure.
********************************************************************/
void init_reg_q_shutdown(REG_Q_SHUTDOWN * q_s,
			 const char *msg, uint32 timeout, uint16 flags)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/

}

/*******************************************************************
reads or writes a structure.
********************************************************************/
BOOL reg_io_q_shutdown(const char *desc, REG_Q_SHUTDOWN * q_s, prs_struct *ps,
		       int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
BOOL reg_io_r_shutdown(const char *desc, REG_R_SHUTDOWN * r_s, prs_struct *ps,
		       int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
Inits a structure.
********************************************************************/
void init_reg_q_abort_shutdown(REG_Q_ABORT_SHUTDOWN * q_s)
{

	q_s->ptr_server = 0;

}

/*******************************************************************
reads or writes a structure.
********************************************************************/
BOOL reg_io_q_abort_shutdown(const char *desc, REG_Q_ABORT_SHUTDOWN * q_s,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a structure.
********************************************************************/
BOOL reg_io_r_abort_shutdown(const char *desc, REG_R_ABORT_SHUTDOWN * r_s,
			     prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}
