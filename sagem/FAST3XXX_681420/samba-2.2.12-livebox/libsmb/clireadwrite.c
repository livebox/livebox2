/*
   Unix SMB/Netbios implementation.
   Version 3.0
   client file read/write routines
   Copyright (C) Andrew Tridgell 1994-1998

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
Issue a single SMBread and don't wait for a reply.
****************************************************************************/

static BOOL cli_issue_read(struct cli_state *cli, int fnum, off_t offset,
			   size_t size, int i)
{
	BOOL bigoffset = False;

	memset(cli->outbuf,'\0',smb_size);
	memset(cli->inbuf,'\0',smb_size);

	if ((SMB_BIG_UINT)offset >> 32) 
		bigoffset = True;

	set_message(cli->outbuf,bigoffset ? 12 : 10,0,True);
		
	SCVAL(cli->outbuf,smb_com,SMBreadX);
	SSVAL(cli->outbuf,smb_tid,cli->cnum);
	cli_setup_packet(cli);

	SCVAL(cli->outbuf,smb_vwv0,0xFF);
	SSVAL(cli->outbuf,smb_vwv2,fnum);
	SIVAL(cli->outbuf,smb_vwv3,offset);
	SSVAL(cli->outbuf,smb_vwv5,size);
	SSVAL(cli->outbuf,smb_vwv6,size);
	SSVAL(cli->outbuf,smb_mid,cli->mid + i);

#ifdef LARGE_SMB_OFF_T
        /*
	 * We only want to do the following if we understand large offsets
	 * otherwise the compiler is likely to get upset with us
	 */
	if (bigoffset)
		SIVAL(cli->outbuf,smb_vwv10,(offset>>32) & 0xffffffff);

#endif /* LARGE_SMB_OFF_T */

	return cli_send_smb(cli);
}

/****************************************************************************
Issue a single SMBreadraw and don't wait for a reply.
****************************************************************************/

static BOOL cli_issue_readraw(struct cli_state *cli, int fnum, off_t offset,
			   size_t size, int i)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
  Read size bytes at offset offset using SMBreadX.
****************************************************************************/

ssize_t cli_read(struct cli_state *cli, int fnum, char *buf, off_t offset, size_t size)
{
	char *p;
	int size2;
	int readsize;
	ssize_t total = 0;

	if (size == 0) 
		return 0;

	/*
	 * Set readsize to the maximum size we can handle in one readX,
	 * rounded down to a multiple of 1024.
	 */

	readsize = (cli->max_xmit - (smb_size+32)) & ~1023;

	while (total < size) {
		readsize = MIN(readsize, size-total);

		/* Issue a read and receive a reply */

		if (!cli_issue_read(cli, fnum, offset, readsize, 0))
			return -1;

		if (!cli_receive_smb(cli))
			return -1;

		/* Check for error.  Make sure to check for DOS and NT
                   errors. */

                if (cli_is_error(cli)) {
                        NTSTATUS status = NT_STATUS_OK;
                        uint8 eclass = 0;
			uint32 ecode = 0;

                        if (cli_is_nt_error(cli))
                                status = cli_nt_error(cli);
                        else
                                cli_dos_error(cli, &eclass, &ecode);

                        if ((eclass == ERRDOS && ecode == ERRmoredata) ||
                            NT_STATUS_V(status) == NT_STATUS_V(STATUS_MORE_ENTRIES))
                                return -1;
		}

		size2 = SVAL(cli->inbuf, smb_vwv5);

		if (size2 > readsize) {
			DEBUG(5,("server returned more than we wanted!\n"));
			return -1;
		} else if (size2 < 0) {
			DEBUG(5,("read return < 0!\n"));
			return -1;
		}

		/* Copy data into buffer */

		p = smb_base(cli->inbuf) + SVAL(cli->inbuf,smb_vwv6);
		memcpy(buf + total, p, size2);

		total += size2;
		offset += size2;

		/*
		 * If the server returned less than we asked for we're at EOF.
		 */

		if (size2 < readsize)
			break;
	}

	return total;
}

/****************************************************************************
 Tester for the readraw call.
****************************************************************************/

ssize_t cli_readraw(struct cli_state *cli, int fnum, char *buf, off_t offset, size_t size)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
issue a single SMBwrite and don't wait for a reply
****************************************************************************/

static BOOL cli_issue_write(struct cli_state *cli, int fnum, off_t offset, uint16 mode, char *buf,
			    size_t size, int i)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
  write to a file
  write_mode: 0x0001 disallow write cacheing
	      0x0002 return bytes remaining
	      0x0004 use raw named pipe protocol
	      0x0008 start of message mode named pipe protocol
****************************************************************************/

ssize_t cli_write(struct cli_state *cli,
		  int fnum, uint16 write_mode,
		  char *buf, off_t offset, size_t size)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
  write to a file using a SMBwrite and not bypassing 0 byte writes
****************************************************************************/

ssize_t cli_smbwrite(struct cli_state *cli,
		     int fnum, char *buf, off_t offset, size_t size1)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}
