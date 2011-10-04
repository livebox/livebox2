/*
   Unix SMB/Netbios implementation.
   Version 3.0
   string substitution functions
   Copyright (C) Andrew Tridgell 1992-2000

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

fstring local_machine="";
fstring remote_arch="UNKNOWN";
userdom_struct current_user_info;
pstring samlogon_user="";
BOOL sam_logon_in_ssb = False;
fstring remote_proto="UNKNOWN";
fstring remote_machine="";
static fstring smb_user_name;


/*
  setup the string used by %U substitution
*/
void sub_set_smb_name(const char *name)
{
	fstring tmp;

	/* ignore anonymous settings */
	if (! *name) return;

	fstrcpy(tmp,name);
	trim_string(tmp," "," ");
	strlower(tmp);
	alpha_strcpy(smb_user_name,tmp,SAFE_NETBIOS_CHARS,sizeof(smb_user_name)-1);
}

const char* get_remote_machine_name(void)
{
		return remote_machine;
}


/*******************************************************************
 Given a pointer to a %$(NAME) expand it as an environment variable.
 Return the number of characters by which the pointer should be advanced.
 Based on code by Branko Cibej <branko.cibej@hermes.si>
 When this is called p points at the '%' character.
********************************************************************/

static size_t expand_env_var(char *p, int len)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Patch from jkf@soton.ac.uk
 Added this to implement %p (NIS auto-map version of %H)
*******************************************************************/

static char *automount_path(char *user_name)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Patch from jkf@soton.ac.uk
 This is Luke's original function with the NIS lookup code
 moved out to a separate function.
*******************************************************************/

static char *automount_server(char *user_name)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/****************************************************************************
 Do some standard substitutions in a string.
****************************************************************************/

void standard_sub_basic(char *str, int len)
{
	extern pstring global_myname;
	char *p, *s;
	fstring pidstr;
	struct passwd *pass;

	for (s=str; (p=strchr(s, '%'));s=p) {
		fstring tmp_str;

		int l = len - (int)(p-str);

		switch (*(p+1)) {
		case 'U' :
			fstrcpy(tmp_str, sam_logon_in_ssb?samlogon_user:smb_user_name);
			strlower(tmp_str);
			string_sub(p,"%U",tmp_str,l);
			break;
		case 'G' :
			fstrcpy(tmp_str, sam_logon_in_ssb?samlogon_user:smb_user_name);
			if ((pass = Get_Pwnam(tmp_str, False))!=NULL) {
				string_sub(p,"%G",gidtoname(pass->pw_gid),l);
			} else {
				p += 2;
			}
			break;
		case 'D' :
			fstrcpy(tmp_str, current_user_info.domain);
			strupper(tmp_str);
			string_sub(p,"%D", tmp_str,l);
			break;
		case 'I' : string_sub(p,"%I", client_addr(),l); break;
		case 'L' :
			if (*local_machine)
				string_sub(p,"%L", local_machine,l);
			else {
				pstring temp_name;

				pstrcpy(temp_name, global_myname);
				strlower(temp_name);
				string_sub(p,"%L", temp_name,l);
			}
			break;
		case 'M' : string_sub(p,"%M", client_name(),l); break;
		case 'R' : string_sub(p,"%R", remote_proto,l); break;
		case 'T' : string_sub(p,"%T", timestring(False),l); break;
		case 'a' : string_sub(p,"%a", remote_arch,l); break;
		case 'd' :
			slprintf(pidstr,sizeof(pidstr)-1, "%d",(int)sys_getpid());
			string_sub(p,"%d", pidstr,l);
			break;
		case 'h' : string_sub(p,"%h", myhostname(),l); break;
		case 'm' : string_sub(p,"%m", remote_machine,l); break;
		case 'v' : string_sub(p,"%v", VERSION,l); break;
		case '$' : p += expand_env_var(p,l); break; /* Expand environment variables */
		case '\0':
			p++;
			break; /* don't run off the end of the string */

		default: p+=2;
			break;
		}
	}
}

/****************************************************************************
 Do some standard substitutions in a string.
****************************************************************************/

void standard_sub_advanced(int snum, char *user, const char *connectpath, gid_t gid, char *str, int len)
{
	char *p, *s, *home;

	for (s=str; (p=strchr(s, '%'));s=p) {
		int l = len - (int)(p-str);

		switch (*(p+1)) {
		case 'N' : string_sub(p,"%N", automount_server(user),l); break;
		case 'H':
			if ((home = get_user_home_dir(user))) {
				string_sub(p,"%H",home, l);
			} else {
				p += 2;
			}
			break;
		case 'P':
			string_sub(p,"%P", connectpath, l);
			break;

		case 'S':
			string_sub(p,"%S", lp_servicename(snum), l);
			break;

		case 'g':
			string_sub(p,"%g", gidtoname(gid), l);
			break;
		case 'u':
			string_sub(p,"%u", user, l);
			break;

			/* Patch from jkf@soton.ac.uk Left the %N (NIS
			 * server name) in standard_sub_basic as it is
			 * a feature for logon servers, hence uses the
			 * username.  The %p (NIS server path) code is
			 * here as it is used instead of the default
			 * "path =" string in [homes] and so needs the
			 * service name, not the username.  */
		case 'p':
			string_sub(p,"%p", automount_path(lp_servicename(snum)), l);
			break;
		case '\0':
			p++;
			break; /* don't run off the end of the string */

		default: p+=2;
			break;
		}
	}

	standard_sub_basic(str,len);
}

/****************************************************************************
 Do some standard substitutions in a string.
****************************************************************************/

void standard_sub_conn(connection_struct *conn, char *str, int len)
{
	standard_sub_advanced(SNUM(conn), conn->user, conn->connectpath, conn->gid, str, len);
}

/****************************************************************************
 Like standard_sub but for a homes share where snum still points to the [homes]
 share. No user specific snum created yet so servicename should be the username.
****************************************************************************/

void standard_sub_home(int snum, char *user, char *str, int len)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/****************************************************************************
 Like standard_sub but by snum.
****************************************************************************/

void standard_sub_snum(int snum, char *str, int len)
{
	extern struct current_user current_user;
	static uid_t cached_uid = -1;
	static fstring cached_user;
	/* calling uidtoname() on every substitute would be too expensive, so
	   we cache the result here as nearly every call is for the same uid */

	if (cached_uid != current_user.uid) {
		fstrcpy(cached_user, uidtoname(current_user.uid));
		cached_uid = current_user.uid;
	}

	standard_sub_advanced(snum, cached_user, "", -1, str, len);
}

/*******************************************************************
 Substitute strings with useful parameters.
********************************************************************/

void standard_sub_vuser(char *str, int len, user_struct *vuser)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Substitute strings with useful parameters.
********************************************************************/

void standard_sub_vsnum(char *str, int len, user_struct *vuser, int snum)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}
