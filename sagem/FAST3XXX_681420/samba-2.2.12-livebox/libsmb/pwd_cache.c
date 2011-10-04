/*
   Unix SMB/Netbios implementation.
   Version 1.9.
   Password cacheing.  obfuscation is planned
   Copyright (C) Luke Kenneth Casson Leighton 1996-1998

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
 Initialises a password structure.
****************************************************************************/

void pwd_init(struct pwd_info *pwd)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Returns NULL password flag.
****************************************************************************/

BOOL pwd_is_nullpwd(const struct pwd_info *pwd)
{
DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Compares two passwords.  hmm, not as trivial as expected.  hmm.
****************************************************************************/

BOOL pwd_compare(struct pwd_info *pwd1, struct pwd_info *pwd2)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Reads a password.
****************************************************************************/

void pwd_read(struct pwd_info *pwd, char *passwd_report, BOOL do_encrypt)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Stores a cleartext password.
****************************************************************************/

void pwd_set_nullpwd(struct pwd_info *pwd)
{
DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Stores a cleartext password.
 ****************************************************************************/

void pwd_set_cleartext(struct pwd_info *pwd, const char *clr)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Gets a cleartext password.
****************************************************************************/

void pwd_get_cleartext(struct pwd_info *pwd, char *clr)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Stores lm and nt hashed passwords.
****************************************************************************/

void pwd_set_lm_nt_16(struct pwd_info *pwd, uchar lm_pwd[16], uchar nt_pwd[16])
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Gets lm and nt hashed passwords.
****************************************************************************/

void pwd_get_lm_nt_16(struct pwd_info *pwd, uchar lm_pwd[16], uchar nt_pwd[16])
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Makes lm and nt hashed passwords.
****************************************************************************/

void pwd_make_lm_nt_16(struct pwd_info *pwd, char *clr)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Makes lm and nt OWF crypts.
****************************************************************************/

void pwd_make_lm_nt_owf(struct pwd_info *pwd, uchar cryptkey[8])
{
DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Gets lm and nt crypts.
****************************************************************************/

void pwd_get_lm_nt_owf(struct pwd_info *pwd, uchar lm_owf[24], uchar nt_owf[24])
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}
