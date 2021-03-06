/*
   Unix SMB\CIFS implementation.

   winbind client code

   Copyright (C) Tim Potter 2000
   Copyright (C) Andrew Tridgell 2000

   This library is free software; you can redistribute it and\or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with this library; if not, write to the
   Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA  02111-1307, USA.
*/

#include "includes.h"
#include "nsswitch/sys_nss.h"

NSS_STATUS winbindd_request(int req_type,
				 struct winbindd_request *request,
				 struct winbindd_response *response);

static BOOL parse_domain_user(const char *domuser, fstring domain, fstring user)
{
        char *p = strchr(domuser,*lp_winbind_separator());

        if (!p)
                return False;

        fstrcpy(user, p+1);
        fstrcpy(domain, domuser);
        domain[PTR_DIFF(p, domuser)] = 0;
        strupper(domain);
        return True;
}

/* Call winbindd to convert a name to a sid */

BOOL winbind_lookup_name(const char *dom_name, const char *name, DOM_SID *sid, 
                         enum SID_NAME_USE *name_type)
{
	struct winbindd_request request;
	struct winbindd_response response;
	NSS_STATUS result;
	
	if (!sid || !name_type)
		return False;

	/* Send off request */

	ZERO_STRUCT(request);
	ZERO_STRUCT(response);

	if (dom_name == NULL) {
		if (!parse_domain_user(name, request.data.name.dom_name, request.data.name.name))
			return False;
	} else {
		fstrcpy(request.data.name.dom_name, dom_name);
		fstrcpy(request.data.name.name, name);
	}

	if ((result = winbindd_request(WINBINDD_LOOKUPNAME, &request, 
				       &response)) == NSS_STATUS_SUCCESS) {
		string_to_sid(sid, response.data.sid.sid);
		*name_type = (enum SID_NAME_USE)response.data.sid.type;
	}

	return result == NSS_STATUS_SUCCESS;
}

/* Call winbindd to convert sid to name */

BOOL winbind_lookup_sid(DOM_SID *sid,
			fstring dom_name, fstring name,
			enum SID_NAME_USE *name_type)
{
	DEBUG(1, ("********** winbind_lookup_sid ommited************\n"));
}

/* Call winbindd to convert SID to uid */

BOOL winbind_sid_to_uid(uid_t *puid, DOM_SID *sid)
{
	DEBUG(1, ("********** winbind_sid_to_uid ommited************\n"));
}

/* Call winbindd to convert uid to sid */

BOOL winbind_uid_to_sid(DOM_SID *sid, uid_t uid)
{
	struct winbindd_request request;
	struct winbindd_response response;
	int result;

	if (!sid)
		return False;

	/* Initialise request */

	ZERO_STRUCT(request);
	ZERO_STRUCT(response);

	request.data.uid = uid;

	/* Make request */

	result = winbindd_request(WINBINDD_UID_TO_SID, &request, &response);

	/* Copy out result */

	if (result == NSS_STATUS_SUCCESS) {
		string_to_sid(sid, response.data.sid.sid);
	} else {
		sid_copy(sid, &global_sid_NULL);
	}

	return (result == NSS_STATUS_SUCCESS);
}

/* Call winbindd to convert SID to gid */

BOOL winbind_sid_to_gid(gid_t *pgid, DOM_SID *sid)
{
	DEBUG(1, ("********** winbind_sid_to_gid ommited************\n"));
}

/* Call winbindd to convert gid to sid */

BOOL winbind_gid_to_sid(DOM_SID *sid, gid_t gid)
{
	DEBUG(1, ("********** winbind_gid_to_sid ommited************\n"));
}

/* Fetch the list of groups a user is a member of from winbindd.  This is
   used by winbind_getgroups. */

static int wb_getgroups(const char *user, gid_t **groups)
{
	DEBUG(1, ("********** wb_getgroups ommited************\n"));
}

/* Call winbindd to initialise group membership.  This is necessary for
   some systems (i.e RH5.2) that do not have an initgroups function as part
   of the nss extension.  In RH5.2 this is implemented using getgrent()
   which can be amazingly inefficient as well as having problems with
   username case. */

int winbind_initgroups(char *user, gid_t gid)
{
	gid_t *tgr, *groups = NULL;
	int result;

	/* Call normal initgroups if we are a local user */

	if (!strchr(user, *lp_winbind_separator())) {
		return initgroups(user, gid);
	}

	result = wb_getgroups(user, &groups);

	DEBUG(10,("winbind_getgroups: %s: result = %s\n", user,
		  result == -1 ? "FAIL" : "SUCCESS"));

	if (result != -1) {
		int ngroups = result, i;
		BOOL is_member = False;

		/* Check to see if the passed gid is already in the list */

		for (i = 0; i < ngroups; i++) {
			if (groups[i] == gid) {
				is_member = True;
			}
		}

		/* Add group to list if necessary */

		if (!is_member) {
			tgr = (gid_t *)Realloc(groups, sizeof(gid_t) * ngroups + 1);

			if (!tgr) {
				errno = ENOMEM;
				result = -1;
				goto done;
			}
			else groups = tgr;

			groups[ngroups] = gid;
			ngroups++;
		}

		/* Set the groups */

		if (sys_setgroups(ngroups, groups) == -1) {
			errno = EPERM;
			result = -1;
			goto done;
		}

	} else {

		/* The call failed.  Set errno to something so we don't get
		   a bogus value from the last failed system call. */

		errno = EIO;
	}

	/* Free response data if necessary */

 done:
	SAFE_FREE(groups);

	return result;
}

/* Return a list of groups the user is a member of.  This function is
   useful for large systems where inverting the group database would be too
   time consuming.  If size is zero, list is not modified and the total
   number of groups for the user is returned. */

int winbind_getgroups(const char *user, int size, gid_t *list)
{
	DEBUG(1, ("********** winbind_getgroups ommited************\n"));
}

/* Utility function. Convert a uid_t to a name if possible. */

BOOL winbind_uidtoname(fstring name, uid_t uid)
{
	DOM_SID sid;
	fstring dom_name;
	fstring user_name;
	enum SID_NAME_USE name_type;

	if (!winbind_uid_to_sid(&sid, uid))
		return False;
	if (!winbind_lookup_sid(&sid, dom_name, user_name, &name_type))
		return False;

	if (name_type != SID_NAME_USER)
		return False;

	slprintf(name, sizeof(fstring)-1, "%s%s%s", dom_name, 
                 lp_winbind_separator(), user_name);

	return True;
}

/* Utility function. Convert a gid_t to a name if possible. */

BOOL winbind_gidtoname(fstring name, gid_t gid)
{
	DEBUG(1, ("********** winbind_gidtoname ommited************\n"));
}

/* Utility function. Convert a name to a uid_t if possible. */

BOOL winbind_nametouid(uid_t *puid, const char *name)
{
	DEBUG(1, ("********** winbind_nametouid ommited************\n"));
}

/* Utility function. Convert a name to a gid_t if possible. */

BOOL winbind_nametogid(gid_t *pgid, const char *gname)
{
	DEBUG(1, ("********** winbind_nametogid ommited************\n"));
}
