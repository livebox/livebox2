/*
   Unix SMB/Netbios implementation.
   Version 3.0
   client RAP calls
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
Call a remote api on an arbitrary pipe.  takes param, data and setup buffers.
****************************************************************************/
BOOL cli_api_pipe(struct cli_state *cli, const char *pipe_name,
		  uint16 *setup, uint32 setup_count, uint32 max_setup_count,
		  char *params, uint32 param_count, uint32 max_param_count,
		  char *data, uint32 data_count, uint32 max_data_count,
		  char **rparam, uint32 *rparam_count,
		  char **rdata, uint32 *rdata_count)
{
  cli_send_trans(cli, SMBtrans, 
                 pipe_name, 
                 0,0,                         /* fid, flags */
                 setup, setup_count, max_setup_count,
                 params, param_count, max_param_count,
                 data, data_count, max_data_count);

  return (cli_receive_trans(cli, SMBtrans, 
                            rparam, (unsigned int *)rparam_count,
                            rdata, (unsigned int *)rdata_count));
}

/****************************************************************************
call a remote api
****************************************************************************/
BOOL cli_api(struct cli_state *cli,
	     char *param, int prcnt, int mprcnt,
	     char *data, int drcnt, int mdrcnt,
	     char **rparam, unsigned int *rprcnt,
	     char **rdata, unsigned int *rdrcnt)
{
DEBUG(1,("function ommited\n"));
/* function omited*/
}


/****************************************************************************
perform a NetWkstaUserLogon
****************************************************************************/
BOOL cli_NetWkstaUserLogon(struct cli_state *cli,char *user, char *workstation)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
call a NetShareEnum - try and browse available connections on a host
****************************************************************************/
int cli_RNetShareEnum(struct cli_state *cli, void (*fn)(const char *, uint32, const char *, void *), void *state)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/****************************************************************************
call a NetServerEnum for the specified workgroup and servertype mask.  This
function then calls the specified callback function for each name returned.

The callback function takes 4 arguments: the machine name, the server type,
the comment and a state pointer.
****************************************************************************/
BOOL cli_NetServerEnum(struct cli_state *cli, char *workgroup, uint32 stype,
		       void (*fn)(const char *, uint32, const char *, void *),
		       void *state)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}



/****************************************************************************
Send a SamOEMChangePassword command
****************************************************************************/
BOOL cli_oem_change_password(struct cli_state *cli, const char *user, const char *new_password,
			     const char *old_password)
{
DEBUG(1,("function ommited\n"));
/* function omited*/
}


/****************************************************************************
send a qpathinfo call
****************************************************************************/
BOOL cli_qpathinfo(struct cli_state *cli, const char *fname,
		   time_t *c_time, time_t *a_time, time_t *m_time,
		   size_t *size, uint16 *mode)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
send a qpathinfo call with the SMB_QUERY_FILE_ALL_INFO info level
****************************************************************************/
BOOL cli_qpathinfo2(struct cli_state *cli, const char *fname,
		    time_t *c_time, time_t *a_time, time_t *m_time,
		    time_t *w_time, size_t *size, uint16 *mode,
		    SMB_INO_T *ino)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/****************************************************************************
send a qfileinfo call
****************************************************************************/
BOOL cli_qfileinfo(struct cli_state *cli, int fnum,
		   uint16 *mode, size_t *size,
		   time_t *c_time, time_t *a_time, time_t *m_time,
		   time_t *w_time, SMB_INO_T *ino)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
send a qfileinfo call
****************************************************************************/
BOOL cli_qfileinfo_test(struct cli_state *cli, int fnum, int level, char *outdata)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Send a qpathinfo SMB_QUERY_FILE_ALT_NAME_INFO call.
****************************************************************************/

NTSTATUS cli_qpathinfo_alt_name(struct cli_state *cli, const char *fname, fstring alt_name)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}
