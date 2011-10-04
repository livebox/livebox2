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
 e
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#include "includes.h"

/****************************************************************************
 A temporary TALLOC context for things like unistrs, that is valid for
 the life of a complete RPC call.
****************************************************************************/

static TALLOC_CTX *current_rpc_talloc = NULL;

TALLOC_CTX *get_current_rpc_talloc(void)
{
    return current_rpc_talloc;
}

void set_current_rpc_talloc( TALLOC_CTX *ctx)
{
	current_rpc_talloc = ctx;
}

static TALLOC_CTX *main_loop_talloc = NULL;

/*******************************************************************
free up temporary memory - called from the main loop
********************************************************************/

void main_loop_talloc_free(void)
{
    if (!main_loop_talloc)
	return;
    talloc_destroy(main_loop_talloc);
    main_loop_talloc = NULL;
}

/*******************************************************************
 Get a talloc context that is freed in the main loop...
********************************************************************/

TALLOC_CTX *main_loop_talloc_get(void)
{
    if (!main_loop_talloc) {
	main_loop_talloc = talloc_init();
	if (!main_loop_talloc)
	    smb_panic("main_loop_talloc: malloc fail\n");
    }

    return main_loop_talloc;
}

/*******************************************************************
 Try and get a talloc context. Get the rpc one if possible, else
 get the main loop one. The main loop one is more dangerous as it
 goes away between packets, the rpc one will stay around for as long
 as a current RPC lasts.
********************************************************************/

TALLOC_CTX *get_talloc_ctx(void)
{
	TALLOC_CTX *tc = get_current_rpc_talloc();

	if (tc)
		return tc;
	return main_loop_talloc_get();
}

/*******************************************************************
 Reads or writes a UTIME type.
********************************************************************/

static BOOL smb_io_utime(const char *desc, UTIME *t, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an NTTIME structure.
********************************************************************/

BOOL smb_io_time(const char *desc, NTTIME *nttime, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a LOOKUP_LEVEL structure.
********************************************************************/

BOOL smb_io_lookup_level(const char *desc, LOOKUP_LEVEL *level, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Gets an enumeration handle from an ENUM_HND structure.
********************************************************************/

uint32 get_enum_hnd(ENUM_HND *enh)
{
	return (enh && enh->ptr_hnd != 0) ? enh->handle : 0;
}

/*******************************************************************
 Inits an ENUM_HND structure.
********************************************************************/

void init_enum_hnd(ENUM_HND *enh, uint32 hnd)
{
	DEBUG(5,("smb_io_enum_hnd\n"));

	enh->ptr_hnd = (hnd != 0) ? 1 : 0;
	enh->handle = hnd;
}

/*******************************************************************
 Reads or writes an ENUM_HND structure.
********************************************************************/

BOOL smb_io_enum_hnd(const char *desc, ENUM_HND *hnd, prs_struct *ps, int depth)
{
	if (hnd == NULL)
		return False;

	prs_debug(ps, depth, desc, "smb_io_enum_hnd");
	depth++;

	if(!prs_align(ps))
		return False;

	if(!prs_uint32("ptr_hnd", ps, depth, &hnd->ptr_hnd)) /* pointer */
		return False;

	if (hnd->ptr_hnd != 0) {
		if(!prs_uint32("handle ", ps, depth, &hnd->handle )) /* enum handle */
			return False;
	}

	return True;
}

/*******************************************************************
 Reads or writes a DOM_SID structure.
********************************************************************/

BOOL smb_io_dom_sid(const char *desc, DOM_SID *sid, prs_struct *ps, int depth)
{
	int i;

	if (sid == NULL)
		return False;

	prs_debug(ps, depth, desc, "smb_io_dom_sid");
	depth++;

	if(!prs_align(ps))
		return False;
	
	if(!prs_uint8 ("sid_rev_num", ps, depth, &sid->sid_rev_num))
		return False;
	if(!prs_uint8 ("num_auths  ", ps, depth, &sid->num_auths))
		return False;

	for (i = 0; i < 6; i++)
	{
		fstring tmp;
		slprintf(tmp, sizeof(tmp) - 1, "id_auth[%d] ", i);
		if(!prs_uint8 (tmp, ps, depth, &sid->id_auth[i]))
			return False;
	}

	/* oops! XXXX should really issue a warning here... */
	if (sid->num_auths > MAXSUBAUTHS)
		sid->num_auths = MAXSUBAUTHS;

	if(!prs_uint32s(False, "sub_auths ", ps, depth, sid->sub_auths, sid->num_auths))
		return False;

	return True;
}

/*******************************************************************
 Inits a DOM_SID structure.

 BIG NOTE: this function only does SIDS where the identauth is not >= 2^32
 identauth >= 2^32 can be detected because it will be specified in hex
********************************************************************/

void init_dom_sid(DOM_SID *sid, const char *str_sid)
{
	pstring domsid;
	int identauth;
	char *p;

	if (str_sid == NULL)
	{
		DEBUG(4,("netlogon domain SID: none\n"));
		sid->sid_rev_num = 0;
		sid->num_auths = 0;
		return;
	}

	pstrcpy(domsid, str_sid);

	DEBUG(4,("init_dom_sid %d SID:  %s\n", __LINE__, domsid));

	/* assume, but should check, that domsid starts "S-" */
	p = strtok(domsid+2,"-");
	sid->sid_rev_num = atoi(p);

	/* identauth in decimal should be <  2^32 */
	/* identauth in hex     should be >= 2^32 */
	identauth = atoi(strtok(0,"-"));

	DEBUG(4,("netlogon rev %d\n", sid->sid_rev_num));
	DEBUG(4,("netlogon %s ia %d\n", p, identauth));

	sid->id_auth[0] = 0;
	sid->id_auth[1] = 0;
	sid->id_auth[2] = (identauth & 0xff000000) >> 24;
	sid->id_auth[3] = (identauth & 0x00ff0000) >> 16;
	sid->id_auth[4] = (identauth & 0x0000ff00) >> 8;
	sid->id_auth[5] = (identauth & 0x000000ff);

	sid->num_auths = 0;

	while ((p = strtok(0, "-")) != NULL && sid->num_auths < MAXSUBAUTHS)
		sid->sub_auths[sid->num_auths++] = atoi(p);

	DEBUG(4,("init_dom_sid: %d SID:  %s\n", __LINE__, domsid));
}

/*******************************************************************
 Inits a DOM_SID2 structure.
********************************************************************/

void init_dom_sid2(DOM_SID2 *sid2, const DOM_SID *sid)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a DOM_SID2 structure.
********************************************************************/

BOOL smb_io_dom_sid2(const char *desc, DOM_SID2 *sid, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
creates a STRHDR structure.
********************************************************************/

void init_str_hdr(STRHDR *hdr, int max_len, int len, uint32 buffer)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a STRHDR structure.
********************************************************************/

BOOL smb_io_strhdr(const char *desc,  STRHDR *hdr, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a UNIHDR structure.
********************************************************************/

void init_uni_hdr(UNIHDR *hdr, int len)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a UNIHDR structure.
********************************************************************/

BOOL smb_io_unihdr(const char *desc, UNIHDR *hdr, prs_struct *ps, int depth)
{
	if (hdr == NULL)
		return False;

	prs_debug(ps, depth, desc, "smb_io_unihdr");
	depth++;

	if(!prs_align(ps))
		return False;
	
	if(!prs_uint16("uni_str_len", ps, depth, &hdr->uni_str_len))
		return False;
	if(!prs_uint16("uni_max_len", ps, depth, &hdr->uni_max_len))
		return False;
	if(!prs_uint32("buffer     ", ps, depth, &hdr->buffer))
		return False;

	return True;
}

/*******************************************************************
 Inits a BUFHDR structure.
********************************************************************/

void init_buf_hdr(BUFHDR *hdr, int max_len, int len)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 prs_uint16 wrapper. Call this and it sets up a pointer to where the
 uint16 should be stored, or gets the size if reading.
 ********************************************************************/

BOOL smb_io_hdrbuf_pre(const char *desc, BUFHDR *hdr, prs_struct *ps, int depth, uint32 *offset)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 smb_io_hdrbuf wrapper. Call this and it retrospectively stores the size.
 Does nothing on reading, as that is already handled by ...._pre()
 ********************************************************************/

BOOL smb_io_hdrbuf_post(const char *desc, BUFHDR *hdr, prs_struct *ps, int depth,
				uint32 ptr_hdrbuf, uint32 max_len, uint32 len)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a BUFHDR structure.
********************************************************************/

BOOL smb_io_hdrbuf(const char *desc, BUFHDR *hdr, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
creates a UNIHDR2 structure.
********************************************************************/

void init_uni_hdr2(UNIHDR2 *hdr, int len)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a UNIHDR2 structure.
********************************************************************/

BOOL smb_io_unihdr2(const char *desc, UNIHDR2 *hdr2, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a UNISTR structure.
********************************************************************/

void init_unistr(UNISTR *str, const char *buf)
{
	size_t len;

	if (buf == NULL) {
		str->buffer = NULL;
		return;
	}
		

	len = strlen(buf) + 1;

	if (len < MAX_UNISTRLEN)
		len = MAX_UNISTRLEN;
	len *= sizeof(uint16);

	str->buffer = (uint16 *)talloc_zero(get_talloc_ctx(), len);
	if (str->buffer == NULL)
		smb_panic("init_unistr: malloc fail\n");

	/* store the string (null-terminated copy) */
	dos_struni2((char *)str->buffer, buf, len);
}

/*******************************************************************
reads or writes a UNISTR structure.
XXXX NOTE: UNISTR structures NEED to be null-terminated.
********************************************************************/

BOOL smb_io_unistr(const char *desc, UNISTR *uni, prs_struct *ps, int depth)
{
	if (uni == NULL)
		return False;

	prs_debug(ps, depth, desc, "smb_io_unistr");
	depth++;

	if(!prs_unistr("unistr", ps, depth, uni))
		return False;

	return True;
}

/*******************************************************************
 Allocate the BUFFER3 memory.
********************************************************************/

static void create_buffer3(BUFFER3 *str, size_t len)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a BUFFER3 structure from a uint32
********************************************************************/

void init_buffer3_uint32(BUFFER3 *str, uint32 val)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a BUFFER3 structure.
********************************************************************/

void init_buffer3_str(BUFFER3 *str, char *buf, int len)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a BUFFER3 structure from a hex string.
********************************************************************/

void init_buffer3_hex(BUFFER3 *str, char *buf)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a BUFFER3 structure.
********************************************************************/

void init_buffer3_bytes(BUFFER3 *str, uint8 *buf, int len)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a BUFFER3 structure.
   the uni_max_len member tells you how large the buffer is.
   the uni_str_len member tells you how much of the buffer is really used.
********************************************************************/

BOOL smb_io_buffer3(const char *desc, BUFFER3 *buf3, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a BUFFER5 structure.
the buf_len member tells you how large the buffer is.
********************************************************************/
BOOL smb_io_buffer5(const char *desc, BUFFER5 *buf5, prs_struct *ps, int depth)
{
	prs_debug(ps, depth, desc, "smb_io_buffer5");
	depth++;

	if (buf5 == NULL) return False;

	if(!prs_align(ps))
		return False;
	if(!prs_uint32("buf_len", ps, depth, &buf5->buf_len))
		return False;

	if(buf5->buf_len) {
		if(!prs_buffer5(True, "buffer" , ps, depth, buf5))
			return False;
	}

	return True;
}

/*******************************************************************
 Inits a BUFFER2 structure.
********************************************************************/

void init_buffer2(BUFFER2 *str, uint8 *buf, int len)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a BUFFER2 structure.
   the uni_max_len member tells you how large the buffer is.
   the uni_str_len member tells you how much of the buffer is really used.
********************************************************************/

BOOL smb_io_buffer2(const char *desc, BUFFER2 *buf2, uint32 buffer, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
creates a UNISTR2 structure: sets up the buffer, too
********************************************************************/

void init_buf_unistr2(UNISTR2 *str, uint32 *ptr, const char *buf)
{
	if (buf != NULL) {

		*ptr = 1;
		init_unistr2(str, buf, strlen(buf)+1);

	} else {

		*ptr = 0;
		init_unistr2(str, "", 0);

	}
}

/*******************************************************************
 Copies a UNISTR2 structure.
********************************************************************/

void copy_unistr2(UNISTR2 *str, const UNISTR2 *from)
{

	/* set up string lengths. add one if string is not null-terminated */
	str->uni_max_len = from->uni_max_len;
	str->undoc       = from->undoc;
	str->uni_str_len = from->uni_str_len;

	if (from->buffer == NULL)
		return;
		
	/* the string buffer is allocated to the maximum size
	   (the the length of the source string) to prevent
	   reallocation of memory. */
	if (str->buffer == NULL) {
		size_t len = from->uni_max_len * sizeof(uint16);

		if (len < MAX_UNISTRLEN)
			len = MAX_UNISTRLEN;
		len *= sizeof(uint16);

   		str->buffer = (uint16 *)talloc_zero(get_talloc_ctx(), len);
		if ((str->buffer == NULL) && (len > 0 ))
		{
			smb_panic("copy_unistr2: talloc fail\n");
			return;
		}
	}

	/* copy the string */
	memcpy(str->buffer, from->buffer, from->uni_max_len*sizeof(uint16));
}

/*******************************************************************
 Creates a STRING2 structure.
********************************************************************/

void init_string2(STRING2 *str, const char *buf, int max_len, int str_len)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a STRING2 structure.
 XXXX NOTE: STRING2 structures need NOT be null-terminated.
   the str_str_len member tells you how long the string is;
   the str_max_len member tells you how large the buffer is.
********************************************************************/

BOOL smb_io_string2(const char *desc, STRING2 *str2, uint32 buffer, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a UNISTR2 structure. len is in bytes.
********************************************************************/

void init_unistr2(UNISTR2 *str, const char *buf, size_t len)
{
	ZERO_STRUCTP(str);

	/* set up string lengths. */
	str->uni_max_len = (uint32)len;
	str->undoc       = 0;
	str->uni_str_len = (uint32)len;

	if (len < MAX_UNISTRLEN)
		len = MAX_UNISTRLEN;
	len *= sizeof(uint16);

	str->buffer = (uint16 *)talloc_zero(get_talloc_ctx(), len);
	if ((str->buffer == NULL) && (len > 0))
	{
		smb_panic("init_unistr2: malloc fail\n");
		return;
	}

	/*
	 * don't move this test above ! The UNISTR2 must be initialized !!!
	 * jfm, 7/7/2001.
	 */
	if (buf==NULL)
		return;

	/* store the string (null-terminated 8 bit chars into 16 bit chars) */
	dos_struni2((char *)str->buffer, buf, len);
}

/*******************************************************************
 Inits a UNISTR2 structure from a UNISTR
********************************************************************/
void init_unistr2_from_unistr (UNISTR2 *to, UNISTR *from)
{

	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
 Reads or writes a UNISTR2 structure.
 XXXX NOTE: UNISTR2 structures need NOT be null-terminated.
   the uni_str_len member tells you how long the string is;
   the uni_max_len member tells you how large the buffer is.
********************************************************************/

BOOL smb_io_unistr2(const char *desc, UNISTR2 *uni2, uint32 buffer, prs_struct *ps, int depth)
{
	if (uni2 == NULL)
		return False;

	if (buffer) {

		prs_debug(ps, depth, desc, "smb_io_unistr2");
		depth++;

		if(!prs_align(ps))
			return False;

		if(!prs_uint32("uni_max_len", ps, depth, &uni2->uni_max_len))
			return False;
		if(!prs_uint32("undoc      ", ps, depth, &uni2->undoc))
			return False;
		if(!prs_uint32("uni_str_len", ps, depth, &uni2->uni_str_len))
			return False;

		/* buffer advanced by indicated length of string
		   NOT by searching for null-termination */
		if(!prs_unistr2(True, "buffer     ", ps, depth, uni2))
			return False;

	} else {

		prs_debug(ps, depth, desc, "smb_io_unistr2 - NULL");
		depth++;
		memset((char *)uni2, '\0', sizeof(*uni2));

	}

	return True;
}

/*******************************************************************
 Inits a DOM_RID2 structure.
********************************************************************/

void init_dom_rid2(DOM_RID2 *rid2, uint32 rid, uint8 type, uint32 idx)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a DOM_RID2 structure.
********************************************************************/

BOOL smb_io_dom_rid2(const char *desc, DOM_RID2 *rid2, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
creates a DOM_RID3 structure.
********************************************************************/

void init_dom_rid3(DOM_RID3 *rid3, uint32 rid, uint8 type)
{
DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a DOM_RID3 structure.
********************************************************************/

BOOL smb_io_dom_rid3(const char *desc, DOM_RID3 *rid3, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a DOM_RID4 structure.
********************************************************************/

void init_dom_rid4(DOM_RID4 *rid4, uint16 unknown, uint16 attr, uint32 rid)
{
DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a DOM_CLNT_SRV structure.
********************************************************************/

static void init_clnt_srv(DOM_CLNT_SRV *log, const char *logon_srv, const char *comp_name)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits or writes a DOM_CLNT_SRV structure.
********************************************************************/

static BOOL smb_io_clnt_srv(const char *desc, DOM_CLNT_SRV *log, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a DOM_LOG_INFO structure.
********************************************************************/

void init_log_info(DOM_LOG_INFO *log, const char *logon_srv, const char *acct_name,
		uint16 sec_chan, const char *comp_name)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a DOM_LOG_INFO structure.
********************************************************************/

BOOL smb_io_log_info(const char *desc, DOM_LOG_INFO *log, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a DOM_CHAL structure.
********************************************************************/

BOOL smb_io_chal(const char *desc, DOM_CHAL *chal, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a DOM_CRED structure.
********************************************************************/

BOOL smb_io_cred(const char *desc,  DOM_CRED *cred, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a DOM_CLNT_INFO2 structure.
********************************************************************/

void init_clnt_info2(DOM_CLNT_INFO2 *clnt,
				const char *logon_srv, const char *comp_name,
				DOM_CRED *clnt_cred)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a DOM_CLNT_INFO2 structure.
********************************************************************/

BOOL smb_io_clnt_info2(const char *desc, DOM_CLNT_INFO2 *clnt, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a DOM_CLNT_INFO structure.
********************************************************************/

void init_clnt_info(DOM_CLNT_INFO *clnt,
		const char *logon_srv, const char *acct_name,
		uint16 sec_chan, const char *comp_name,
				DOM_CRED *cred)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a DOM_CLNT_INFO structure.
********************************************************************/

BOOL smb_io_clnt_info(const char *desc,  DOM_CLNT_INFO *clnt, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits a DOM_LOGON_ID structure.
********************************************************************/

void init_logon_id(DOM_LOGON_ID *log, uint32 log_id_low, uint32 log_id_high)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a DOM_LOGON_ID structure.
********************************************************************/

BOOL smb_io_logon_id(const char *desc, DOM_LOGON_ID *log, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Inits an OWF_INFO structure.
********************************************************************/

void init_owf_info(OWF_INFO *hash, uint8 data[16])
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an OWF_INFO structure.
********************************************************************/

BOOL smb_io_owf_info(const char *desc, OWF_INFO *hash, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a DOM_GID structure.
********************************************************************/

BOOL smb_io_gid(const char *desc,  DOM_GID *gid, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes an POLICY_HND structure.
********************************************************************/

BOOL smb_io_pol_hnd(const char *desc, POLICY_HND *pol, prs_struct *ps, int depth)
{
	if (pol == NULL)
		return False;

	prs_debug(ps, depth, desc, "smb_io_pol_hnd");
	depth++;

	if(!prs_align(ps))
		return False;

	if(UNMARSHALLING(ps))
		ZERO_STRUCTP(pol);

	if (!prs_uint32("data1", ps, depth, &pol->data1))
		return False;
	if (!prs_uint32("data2", ps, depth, &pol->data2))
		return False;
	if (!prs_uint16("data3", ps, depth, &pol->data3))
		return False;
	if (!prs_uint16("data4", ps, depth, &pol->data4))
		return False;
	if(!prs_uint8s (False, "data5", ps, depth, pol->data5, sizeof(pol->data5)))
		return False;

	return True;
}

/*******************************************************************
 Create a UNISTR3.
********************************************************************/

void init_unistr3(UNISTR3 *str, const char *buf)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
 Reads or writes a UNISTR3 structure.
********************************************************************/

BOOL smb_io_unistr3(const char *desc, UNISTR3 *name, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/*******************************************************************
 Stream a uint64_struct
 ********************************************************************/
BOOL prs_uint64(const char *name, prs_struct *ps, int depth, UINT64_S *data64)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a BUFHDR2 structure.
********************************************************************/
BOOL smb_io_bufhdr2(const char *desc, BUFHDR2 *hdr, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
reads or writes a BUFFER4 structure.
********************************************************************/
BOOL smb_io_buffer4(const char *desc, BUFFER4 *buf4, uint32 buffer, prs_struct *ps, int depth)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
creates a UNIHDR structure.
********************************************************************/

BOOL make_uni_hdr(UNIHDR *hdr, int len)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*******************************************************************
creates a BUFHDR2 structure.
********************************************************************/
BOOL make_bufhdr2(BUFHDR2 *hdr, uint32 info_level, uint32 length, uint32 buffer)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}
