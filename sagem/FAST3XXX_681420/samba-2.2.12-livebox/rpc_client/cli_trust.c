/*
 *  Unix SMB/Netbios implementation.
 *  Version 1.9.
 *  RPC Pipe client / server routines
 *  Copyright (C) Andrew Tridgell              1992-1997,
 *  Copyright (C) Luke Kenneth Casson Leighton 1996-1997,
 *  Copyright (C) Paul Ashton                       1997.
 *  Copyright (C) Jeremy Allison                    1998.
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

extern pstring global_myname;

/*********************************************************
 Change the domain password on the PDC.
**********************************************************/

static BOOL modify_trust_password( char *domain, char *remote_machine,
			  unsigned char orig_trust_passwd_hash[16],
			  unsigned char new_trust_passwd_hash[16])
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/************************************************************************
 Change the trust account password for a domain.
 The user of this function must have locked the trust password file for
 update.
************************************************************************/

BOOL change_trust_account_password( char *domain, const char *remote_machine_list)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}
