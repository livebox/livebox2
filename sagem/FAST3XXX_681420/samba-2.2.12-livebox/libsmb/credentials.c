/*
   Unix SMB/Netbios implementation.
   Version 1.9.
   code to manipulate domain credentials
   Copyright (C) Andrew Tridgell 1997-1998

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
represent a credential as a string
****************************************************************************/
char *credstr(const uchar *cred)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/****************************************************************************
  setup the session key.
Input: 8 byte challenge block
       8 byte server challenge block
      16 byte md4 encrypted password
Output:
      8 byte session key
****************************************************************************/
void cred_session_key(const DOM_CHAL *clnt_chal, const DOM_CHAL *srv_chal, const uchar *pass,
			uchar session_key[8])
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/****************************************************************************
create a credential

Input:
      8 byte sesssion key
      8 byte stored credential
      4 byte timestamp

Output:
      8 byte credential
****************************************************************************/
void cred_create(uchar session_key[8], DOM_CHAL *stor_cred, UTIME timestamp,
		 DOM_CHAL *cred)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/****************************************************************************
  check a supplied credential

Input:
      8 byte received credential
      8 byte sesssion key
      8 byte stored credential
      4 byte timestamp

Output:
      returns 1 if computed credential matches received credential
      returns 0 otherwise
****************************************************************************/
int cred_assert(DOM_CHAL *cred, uchar session_key[8], DOM_CHAL *stored_cred,
		UTIME timestamp)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/****************************************************************************
  checks credentials; generates next step in the credential chain
****************************************************************************/
BOOL clnt_deal_with_creds(uchar sess_key[8],
			  DOM_CRED *sto_clnt_cred, DOM_CRED *rcv_srv_cred)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/****************************************************************************
  checks credentials; generates next step in the credential chain
****************************************************************************/
BOOL deal_with_creds(uchar sess_key[8],
		     DOM_CRED *sto_clnt_cred,
		     DOM_CRED *rcv_clnt_cred, DOM_CRED *rtn_srv_cred)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}
