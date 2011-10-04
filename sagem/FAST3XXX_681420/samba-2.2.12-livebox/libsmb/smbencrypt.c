/*
   Unix SMB/Netbios implementation.
   Version 1.9.
   SMB parameters and setup
   Copyright (C) Andrew Tridgell 1992-1998
   Modified by Jeremy Allison 1995.

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

#include "byteorder.h"

/*
   This implements the X/Open SMB password encryption
   It takes a password, a 8 byte "crypt key" and puts 24 bytes of
   encrypted password into p24 */
void SMBencrypt(const uchar *passwd, uchar *c8, uchar *p24)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*
 * Creates the MD4 Hash of the users password in NT UNICODE.
 */

void E_md4hash(const uchar *passwd, uchar *p16)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/* Does both the NT and LM owfs of a user's password */
void nt_lm_owf_gen(char *pwd, uchar nt_p16[16], uchar p16[16])
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/* Does the des encryption from the NT or LM MD4 hash. */
void SMBOWFencrypt(uchar passwd[16], uchar *c8, uchar p24[24])
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/* Does the des encryption from the FIRST 8 BYTES of the NT or LM MD4 hash. */
void NTLMSSPOWFencrypt(uchar passwd[8], uchar *ntlmchalresp, uchar p24[24])
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/* Does the NT MD4 hash then des encryption. */

void SMBNTencrypt(const uchar *passwd, uchar *c8, uchar *p24)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

BOOL make_oem_passwd_hash(char data[516], const char *passwd, uchar old_pw_hash[16], BOOL unicode)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/***********************************************************
 Encode a password buffer.
************************************************************/

BOOL encode_pw_buffer(char buffer[516], const char *new_pass,
			int new_pw_len, BOOL nt_pass_set)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/***********************************************************
 decode a password buffer
************************************************************/
BOOL decode_pw_buffer(char in_buffer[516], char *new_pwrd,
		      int new_pwrd_size, uint32 *new_pw_len,
		      uchar nt_p16[16], uchar p16[16])
{
	DEBUG(1,("function ommited\n"));
/* function omited*/

}

/* Calculate the NT owfs of a user's password */
void nt_owf_genW(const UNISTR2 *pwd, uchar nt_p16[16])
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}
