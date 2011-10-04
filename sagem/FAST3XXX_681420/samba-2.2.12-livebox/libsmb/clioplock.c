/*
   Unix SMB/Netbios implementation.
   Version 3.0
   SMB client oplock functions
   Copyright (C) Andrew Tridgell 2001

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
send an ack for an oplock break request
****************************************************************************/
BOOL cli_oplock_ack(struct cli_state *cli, int fnum, unsigned char level)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/****************************************************************************
set the oplock handler for a connection
****************************************************************************/
void cli_oplock_handler(struct cli_state *cli,
			BOOL (*handler)(struct cli_state *, int, unsigned char))
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}
