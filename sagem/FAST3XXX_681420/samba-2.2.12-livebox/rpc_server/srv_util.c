/*
 *  Unix SMB/Netbios implementation.
 *  Version 1.9.
 *  RPC Pipe client / server routines
 *  Copyright (C) Andrew Tridgell              1992-1998
 *  Copyright (C) Luke Kenneth Casson Leighton 1996-1998,
 *  Copyright (C) Paul Ashton                  1997-1998.
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

/*  this module apparently provides an implementation of DCE/RPC over a
 *  named pipe (IPC$ connection using SMBtrans).  details of DCE/RPC
 *  documentation are available (in on-line form) from the X-Open group.
 *
 *  this module should provide a level of abstraction between SMB
 *  and DCE/RPC, while minimising the amount of mallocs, unnecessary
 *  data copies, and network traffic.
 *
 *  in this version, which takes a "let's learn what's going on and
 *  get something running" approach, there is additional network
 *  traffic generated, but the code should be easier to understand...
 *
 *  ... if you read the docs.  or stare at packets for weeks on end.
 *
 */

#include "includes.h"

/*
 * A list of the rids of well known BUILTIN and Domain users
 * and groups.
 */

rid_name builtin_alias_rids[] =
{
    { BUILTIN_ALIAS_RID_ADMINS       , "Administrators" },
    { BUILTIN_ALIAS_RID_USERS        , "Users" },
    { BUILTIN_ALIAS_RID_GUESTS       , "Guests" },
    { BUILTIN_ALIAS_RID_POWER_USERS  , "Power Users" },

    { BUILTIN_ALIAS_RID_ACCOUNT_OPS  , "Account Operators" },
    { BUILTIN_ALIAS_RID_SYSTEM_OPS   , "System Operators" },
    { BUILTIN_ALIAS_RID_PRINT_OPS    , "Print Operators" },
    { BUILTIN_ALIAS_RID_BACKUP_OPS   , "Backup Operators" },
    { BUILTIN_ALIAS_RID_REPLICATOR   , "Replicator" },
    { 0                             , NULL }
};

/* array lookup of well-known Domain RID users. */
rid_name domain_user_rids[] =
{
    { DOMAIN_USER_RID_ADMIN         , "Administrator" },
    { DOMAIN_USER_RID_GUEST         , "Guest" },
    { 0                             , NULL }
};

/* array lookup of well-known Domain RID groups. */
rid_name domain_group_rids[] =
{
    { DOMAIN_GROUP_RID_ADMINS       , "Domain Admins" },
    { DOMAIN_GROUP_RID_USERS        , "Domain Users" },
    { DOMAIN_GROUP_RID_GUESTS       , "Domain Guests" },
    { 0                             , NULL }
};

#define LSA_MAX_GROUPS 96

int make_dom_gids(TALLOC_CTX *ctx, char *gids_str, DOM_GID **ppgids)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}


/*******************************************************************
 gets a domain user's groups
 ********************************************************************/
void get_domain_user_groups(char *domain_groups, char *user)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Look up a local (domain) rid and return a name and type.
 ********************************************************************/
NTSTATUS local_lookup_group_name(uint32 rid, char *group_name, uint32 *type)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Look up a local alias rid and return a name and type.
 ********************************************************************/
NTSTATUS local_lookup_alias_name(uint32 rid, char *alias_name, uint32 *type)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Look up a local user rid and return a name and type.
 ********************************************************************/
NTSTATUS local_lookup_user_name(uint32 rid, char *user_name, uint32 *type)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Look up a local (domain) group name and return a rid
 ********************************************************************/
NTSTATUS local_lookup_group_rid(char *group_name, uint32 *rid)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Look up a local (BUILTIN) alias name and return a rid
 ********************************************************************/
NTSTATUS local_lookup_alias_rid(char *alias_name, uint32 *rid)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Look up a local user name and return a rid
 ********************************************************************/
NTSTATUS local_lookup_user_rid(char *user_name, uint32 *rid)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}
