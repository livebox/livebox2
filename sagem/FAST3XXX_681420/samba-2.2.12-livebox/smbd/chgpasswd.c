/*
   Unix SMB/Netbios implementation.
   Version 1.9.
   Samba utility functions
   Copyright (C) Andrew Tridgell 1992-1998

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

/* fork a child process to exec passwd and write to its
 * tty to change a users password. This is running as the
 * user who is attempting to change the password.
 */

/*
 * This code was copied/borrowed and stolen from various sources.
 * The primary source was the poppasswd.c from the authors of POPMail. This software
 * was included as a client to change passwords using the 'passwd' program
 * on the remote machine.
 *
 * This routine is called by set_user_password() in password.c only if ALLOW_PASSWORD_CHANGE
 * is defined in the compiler directives located in the Makefile.
 *
 * This code has been hacked by Bob Nance (nance@niehs.nih.gov) and Evan Patterson
 * (patters2@niehs.nih.gov) at the National Institute of Environmental Health Sciences
 * and rights to modify, distribute or incorporate this change to the CAP suite or
 * using it for any other reason are granted, so long as this disclaimer is left intact.
 */

/*
   This code was hacked considerably for inclusion in Samba, primarily
   by Andrew.Tridgell@anu.edu.au. The biggest change was the addition
   of the "password chat" option, which allows the easy runtime
   specification of the expected sequence of events to change a
   password.
   */

#include "includes.h"

extern struct passdb_ops pdb_ops;

#if ALLOW_CHANGE_PASSWORD

static int findpty(char **slave)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static int dochild(int master, char *slavedev, char *name,
		   char *passwordprogram, BOOL as_root)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static int expect(int master, char *issue, char *expected)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static void pwd_sub(char *buf)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static int talktochild(int master, const char *seq)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static BOOL chat_with_program(char *passwordprogram, char *name,
			      char *chatsequence, BOOL as_root)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}


BOOL chgpasswd(char *name, const char *oldpass, const char *newpass, BOOL as_root)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

#else /* ALLOW_CHANGE_PASSWORD */

BOOL chgpasswd(char *name, const char *oldpass, const char *newpass, BOOL as_root)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}
#endif /* ALLOW_CHANGE_PASSWORD */

/***********************************************************
 Code to check the lanman hashed password.
************************************************************/

BOOL check_lanman_password(char *user, uchar * pass1,
			   uchar * pass2, SAM_ACCOUNT **hnd)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***********************************************************
 Code to change the lanman hashed password.
 It nulls out the NT hashed password as it will
 no longer be valid.
************************************************************/

BOOL change_lanman_password(SAM_ACCOUNT *sampass, uchar * pass1,
			    uchar * pass2)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***********************************************************
 Code to check and change the OEM hashed password.
************************************************************/
BOOL pass_oem_change(char *user,
		     uchar * lmdata, uchar * lmhash,
		     uchar * ntdata, uchar * nthash)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***********************************************************
 Code to check the OEM hashed password.

 this function ignores the 516 byte nt OEM hashed password
 but does use the lm OEM password to check the nt hashed-hash.

************************************************************/

BOOL check_oem_password(char *user,
			uchar * lmdata, uchar * lmhash,
			uchar * ntdata, uchar * nthash,
			SAM_ACCOUNT **hnd, char *new_passwd,
			int new_passwd_size)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***********************************************************
 Code to change the oem password. Changes both the lanman
 and NT hashes.
 override = False, normal
 override = True, override XXXXXXXXXX'd password
************************************************************/

BOOL change_oem_password(SAM_ACCOUNT *hnd, char *new_passwd,
			 BOOL override)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***********************************************************
 Code to check a plaintext password against smbpasswd entries.
***********************************************************/

BOOL check_plaintext_password(char *user, char *old_passwd,
			      int old_passwd_size, SAM_ACCOUNT **hnd)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}
