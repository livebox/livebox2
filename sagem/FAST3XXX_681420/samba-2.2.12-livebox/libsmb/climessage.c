/*
   Unix SMB/Netbios implementation.
   Version 3.0
   client message handling routines
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
start a message sequence
****************************************************************************/
BOOL cli_message_start(struct cli_state *cli, char *host, char *username,
			      int *grp)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/****************************************************************************
send a message
****************************************************************************/
BOOL cli_message_text(struct cli_state *cli, char *msg, int len, int grp)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
end a message
****************************************************************************/
BOOL cli_message_end(struct cli_state *cli, int grp)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

