/*
   Unix SMB/Netbios implementation.
   Version 3.0
   client directory list routines
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
interpret a long filename structure - this is mostly guesses at the moment
The length of the structure is returned
The structure of a long filename depends on the info level. 260 is used
by NT and 2 is used by OS/2
****************************************************************************/
static int interpret_long_filename(struct cli_state *cli,
				   int level,char *p,file_info *finfo)
{
DEBUG(1,("function ommited\n"));
/* function omited*/
}


/****************************************************************************
  do a directory listing, calling fn on each file found
  ****************************************************************************/
int cli_list_new(struct cli_state *cli,const char *Mask,uint16 attribute,
		 void (*fn)(file_info *, const char *, void *), void *state)
{
DEBUG(1,("function ommited\n"));
/* function omited*/
}



/****************************************************************************
interpret a short filename structure
The length of the structure is returned
****************************************************************************/
static int interpret_short_filename(struct cli_state *cli, char *p,file_info *finfo)
{
DEBUG(1,("function ommited\n"));
/* function omited*/
}


/****************************************************************************
  do a directory listing, calling fn on each file found
  this uses the old SMBsearch interface. It is needed for testing Samba,
  but should otherwise not be used
  ****************************************************************************/

int cli_list_old(struct cli_state *cli,const char *Mask,uint16 attribute,
		 void (*fn)(file_info *, const char *, void *), void *state)
{
DEBUG(1,("function ommited\n"));
/* function omited*/
}


/****************************************************************************
  do a directory listing, calling fn on each file found
  this auto-switches between old and new style
  ****************************************************************************/
int cli_list(struct cli_state *cli,const char *Mask,uint16 attribute,
	     void (*fn)(file_info *, const char *, void *), void *state)
{
DEBUG(1,("function ommited\n"));
/* function omited*/
}
