/*
 * Unix SMB/Netbios implementation. Version 1.9. SMB parameters and setup
 * Copyright (C) Andrew Tridgell 1992-1998 Modified by Jeremy Allison 1995.
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 675
 * Mass Ave, Cambridge, MA 02139, USA.
 */

/*
 * This file also contains migration code to move from an old
 * trust account password file stored in the file :
 * ${SAMBA_HOME}/private/{domain}.{netbiosname}.mac
 * into a record stored in the tdb ${SAMBA_HOME}/private/secrets.tdb
 * database. JRA.
 */

#include "includes.h"

extern pstring global_myname;


static int mach_passwd_lock_depth;
static FILE *mach_passwd_fp;

/***************************************************************
 Lock an fd. Abandon after waitsecs seconds.
****************************************************************/

static BOOL pw_file_lock(int fd, int type, int secs, int *plock_depth)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/***************************************************************
 Unlock an fd. Abandon after waitsecs seconds.
****************************************************************/

static BOOL pw_file_unlock(int fd, int *plock_depth)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/************************************************************************
 Routine to get the name for an old trust account file.
************************************************************************/

static void get_trust_account_file_name( char *domain, char *name, char *mac_file)
{
  unsigned int mac_file_len;

  /* strip the filename to the last '/' */
  get_private_directory(mac_file);
  pstrcat(mac_file, "/");

  mac_file_len = strlen(mac_file);

  if ((int)(sizeof(pstring) - mac_file_len - strlen(domain) - strlen(name) - 6) < 0) {
    DEBUG(0,("trust_password_lock: path %s too long to add trust details.\n",
	      mac_file));
    return;
  }

  pstrcat(mac_file, domain);
  pstrcat(mac_file, ".");
  pstrcat(mac_file, name);
  pstrcat(mac_file, ".mac");
}

/************************************************************************
 Routine to lock the old trust account password file for a domain.
 As this is a function to migrate to the new secrets.tdb, we never
 create the file here, only open it.
************************************************************************/

static BOOL trust_password_file_lock(char *domain, char *name)
{
  pstring mac_file;

  if(mach_passwd_lock_depth == 0) {
    int fd;

    get_trust_account_file_name( domain, name, mac_file);

    if ((fd = sys_open(mac_file, O_RDWR, 0)) == -1)
      return False;

    if((mach_passwd_fp = fdopen(fd, "w+b")) == NULL) {
	DEBUG(0,("trust_password_lock: cannot open file %s - Error was %s.\n",
	      mac_file, strerror(errno) ));
	return False;
    }

    if(!pw_file_lock(fileno(mach_passwd_fp), F_WRLCK, 60, &mach_passwd_lock_depth)) {
      DEBUG(0,("trust_password_lock: cannot lock file %s\n", mac_file));
      fclose(mach_passwd_fp);
      return False;
    }

  }

  return True;
}

/************************************************************************
 Routine to unlock the old trust account password file for a domain.
************************************************************************/

static BOOL trust_password_file_unlock(void)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/************************************************************************
 Routine to delete the old trust account password file for a domain.
 Note that this file must be locked as it is truncated before the
 delete. This is to ensure it only gets deleted by one smbd.
************************************************************************/

static BOOL trust_password_file_delete( char *domain, char *name )
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/************************************************************************
 Routine to get the old trust account password for a domain - to convert
 to the new secrets.tdb entry.
 The user of this function must have locked the trust password file.
************************************************************************/

static BOOL get_trust_account_password_from_file( unsigned char *ret_pwd, time_t *pass_last_set_time)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/************************************************************************
 Migrate an old DOMAIN.MACINE.mac password file to the tdb secrets db.
************************************************************************/

BOOL migrate_from_old_password_file(char *domain)
{
	struct machine_acct_pass pass;

	if (!trust_password_file_lock(domain, global_myname))
		return True;

	if (!get_trust_account_password_from_file( pass.hash, &pass.mod_time)) {
		trust_password_file_unlock();
		return False;
	}

	if (!secrets_store(trust_keystr(domain), (void *)&pass, sizeof(pass)))
		return False;

	trust_password_file_delete(domain, global_myname);
	trust_password_file_unlock();

	return True;
}
