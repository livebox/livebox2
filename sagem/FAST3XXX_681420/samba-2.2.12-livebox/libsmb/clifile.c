/*
   Unix SMB/Netbios implementation.
   Version 3.0
   client file operations
   Copyright (C) Andrew Tridgell 1994-1998
   Copyright (C) Jeremy Allison 2001-2002

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#define NO_SYSLOG

#include "includes.h"

/****************************************************************************
 Hard/Symlink a file (UNIX extensions).
****************************************************************************/

static BOOL cli_link_internal(struct cli_state *cli, const char *fname_src, const char *fname_dst, BOOL hard_link)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Map standard UNIX permissions onto wire representations.
****************************************************************************/

uint32  unix_perms_to_wire(mode_t perms)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Symlink a file (UNIX extensions).
****************************************************************************/

BOOL cli_unix_symlink(struct cli_state *cli, const char *fname_src, const char *fname_dst)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Hard a file (UNIX extensions).
****************************************************************************/

BOOL cli_unix_hardlink(struct cli_state *cli, const char *fname_src, const char *fname_dst)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Chmod or chown a file internal (UNIX extensions).
****************************************************************************/

static BOOL cli_unix_chmod_chown_internal(struct cli_state *cli, const char *fname, uint32 mode, uint32 uid, uint32 gid)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 chmod a file (UNIX extensions).
****************************************************************************/

BOOL cli_unix_chmod(struct cli_state *cli, const char *fname, mode_t mode)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 chown a file (UNIX extensions).
****************************************************************************/

BOOL cli_unix_chown(struct cli_state *cli, const char *fname, uid_t uid, gid_t gid)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Rename a file.
****************************************************************************/

BOOL cli_rename(struct cli_state *cli, const char *fname_src, const char *fname_dst)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Delete a file.
****************************************************************************/

BOOL cli_unlink(struct cli_state *cli, const char *fname)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Create a directory.
****************************************************************************/

BOOL cli_mkdir(struct cli_state *cli, const char *dname)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Remove a directory.
****************************************************************************/

BOOL cli_rmdir(struct cli_state *cli, const char *dname)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Set or clear the delete on close flag.
****************************************************************************/

int cli_nt_delete_on_close(struct cli_state *cli, int fnum, BOOL flag)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Open a file - exposing the full horror of the NT API :-).
 Used in smbtorture.
****************************************************************************/

int cli_nt_create_full(struct cli_state *cli, const char *fname, uint32 DesiredAccess,
		 uint32 FileAttributes, uint32 ShareAccess,
		 uint32 CreateDisposition, uint32 CreateOptions)
{
	char *p;
	int len;

	memset(cli->outbuf,'\0',smb_size);
	memset(cli->inbuf,'\0',smb_size);

	set_message(cli->outbuf,24,0,True);

	SCVAL(cli->outbuf,smb_com,SMBntcreateX);
	SSVAL(cli->outbuf,smb_tid,cli->cnum);
	cli_setup_packet(cli);

	SSVAL(cli->outbuf,smb_vwv0,0xFF);
	if (cli->use_oplocks)
		SIVAL(cli->outbuf,smb_ntcreate_Flags, REQUEST_OPLOCK|REQUEST_BATCH_OPLOCK);
	else
		SIVAL(cli->outbuf,smb_ntcreate_Flags, 0);
	SIVAL(cli->outbuf,smb_ntcreate_RootDirectoryFid, 0x0);
	SIVAL(cli->outbuf,smb_ntcreate_DesiredAccess, DesiredAccess);
	SIVAL(cli->outbuf,smb_ntcreate_FileAttributes, FileAttributes);
	SIVAL(cli->outbuf,smb_ntcreate_ShareAccess, ShareAccess);
	SIVAL(cli->outbuf,smb_ntcreate_CreateDisposition, CreateDisposition);
	SIVAL(cli->outbuf,smb_ntcreate_CreateOptions, CreateOptions);
	SIVAL(cli->outbuf,smb_ntcreate_ImpersonationLevel, 0x02);

	p = smb_buf(cli->outbuf);
	/* this alignment and termination is critical for netapp filers. Don't change */
	p += clistr_align_out(cli, p, 0);
	len = clistr_push(cli, p, fname, -1, 0);
	p += len;
	SSVAL(cli->outbuf,smb_ntcreate_NameLength, len);
	/* sigh. this copes with broken netapp filer behaviour */
	p += clistr_push(cli, p, "", -1, STR_TERMINATE|STR_CONVERT);

	cli_setup_bcc(cli, p);

	cli_send_smb(cli);
	if (!cli_receive_smb(cli)) {
		return -1;
	}

	if (cli_is_error(cli)) {
		return -1;
	}

	return SVAL(cli->inbuf,smb_vwv2 + 1);
}

/****************************************************************************
 Open a file.
****************************************************************************/

int cli_nt_create(struct cli_state *cli, const char *fname, uint32 DesiredAccess)
{
	return cli_nt_create_full(cli, fname, DesiredAccess, 0,
				FILE_SHARE_READ|FILE_SHARE_WRITE, FILE_EXISTS_OPEN, 0x0);
}

/****************************************************************************
 Open a file
 WARNING: if you open with O_WRONLY then getattrE won't work!
****************************************************************************/

int cli_open(struct cli_state *cli, const char *fname, int flags, int share_mode)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Close a file.
****************************************************************************/

BOOL cli_close(struct cli_state *cli, int fnum)
{
	memset(cli->outbuf,'\0',smb_size);
	memset(cli->inbuf,'\0',smb_size);

	set_message(cli->outbuf,3,0,True);

	SCVAL(cli->outbuf,smb_com,SMBclose);
	SSVAL(cli->outbuf,smb_tid,cli->cnum);
	cli_setup_packet(cli);

	SSVAL(cli->outbuf,smb_vwv0,fnum);
	SIVALS(cli->outbuf,smb_vwv1,-1);

	cli_send_smb(cli);
	if (!cli_receive_smb(cli)) {
		return False;
	}

	return !cli_is_error(cli);
}

/****************************************************************************
 send a lock with a specified locktype
 this is used for testing LOCKING_ANDX_CANCEL_LOCK
****************************************************************************/
NTSTATUS cli_locktype(struct cli_state *cli, int fnum,
		      uint32 offset, uint32 len, int timeout, unsigned char locktype)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Lock a file.
****************************************************************************/

BOOL cli_lock(struct cli_state *cli, int fnum,
	      uint32 offset, uint32 len, int timeout, enum brl_type lock_type)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Unlock a file.
****************************************************************************/

BOOL cli_unlock(struct cli_state *cli, int fnum, uint32 offset, uint32 len)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Lock a file with 64 bit offsets.
****************************************************************************/

BOOL cli_lock64(struct cli_state *cli, int fnum,
		SMB_BIG_UINT offset, SMB_BIG_UINT len, int timeout, enum brl_type lock_type)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Unlock a file with 64 bit offsets.
****************************************************************************/

BOOL cli_unlock64(struct cli_state *cli, int fnum, SMB_BIG_UINT offset, SMB_BIG_UINT len)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Do a SMBgetattrE call. The size is 32 bits.
****************************************************************************/

BOOL cli_getattrE(struct cli_state *cli, int fd,
		  uint16 *attr, SMB_BIG_UINT *size,
		  time_t *c_time, time_t *a_time, time_t *m_time)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Do a SMBgetatr call
****************************************************************************/

BOOL cli_getatr(struct cli_state *cli, const char *fname,
		uint16 *attr, size_t *size, time_t *t)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Do a SMBsetatr call.
****************************************************************************/

BOOL cli_setatr(struct cli_state *cli, const char *fname, uint16 attr, time_t t)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Check for existance of a dir.
****************************************************************************/

BOOL cli_chkpath(struct cli_state *cli, const char *path)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Query disk space.
****************************************************************************/

BOOL cli_dskattr(struct cli_state *cli, int *bsize, int *total, int *avail)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Create and open a temporary file.
****************************************************************************/

int cli_ctemp(struct cli_state *cli, const char *path, char **tmp_path)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}
