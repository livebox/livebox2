/* 
   Unix SMB/Netbios implementation.
   Version 3.0
   client print routines
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

/*****************************************************************************
 Convert a character pointer in a cli_call_api() response to a form we can use.
 This function contains code to prevent core dumps if the server returns 
 invalid data.
*****************************************************************************/
static const char *fix_char_ptr(unsigned int datap, unsigned int converter, 
			  char *rdata, int rdrcnt)
{
	DEBUG(1,("function ommited/n"));
/* function omited*/
}


/****************************************************************************
call fn() on each entry in a print queue
****************************************************************************/
int cli_print_queue(struct cli_state *cli, 
		    void (*fn)(struct print_job_info *))
{
	DEBUG(1,("function ommited/n"));
/* function omited*/
}

/****************************************************************************
  cancel a print job
  ****************************************************************************/
int cli_printjob_del(struct cli_state *cli, int job)
{
	DEBUG(1,("function ommited/n"));
/* function omited*/
}


