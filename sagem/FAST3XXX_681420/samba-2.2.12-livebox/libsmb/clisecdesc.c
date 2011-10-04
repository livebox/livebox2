/*
   Unix SMB/Netbios implementation.
   Version 3.0
   client security descriptor functions
   Copyright (C) Andrew Tridgell 2000

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

#include "includes.h"

/****************************************************************************
  query the security descriptor for a open file
 ****************************************************************************/
SEC_DESC *cli_query_secdesc(struct cli_state *cli, int fnum,
			    TALLOC_CTX *mem_ctx)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
  set the security descriptor for a open file
 ****************************************************************************/
BOOL cli_set_secdesc(struct cli_state *cli, int fnum, SEC_DESC *sd)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}
