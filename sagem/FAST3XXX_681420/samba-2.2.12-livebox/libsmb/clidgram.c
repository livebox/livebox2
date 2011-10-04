/*
   Unix SMB/Netbios implementation.
   Version 3.0
   client dgram calls
   Copyright (C) Andrew Tridgell 1994-1998
   Copyright (C) Richard Sharpe 2001
   Copyright (C) John Terpstra 2001

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

#define NO_SYSLOG

#include "includes.h"

/*
 * cli_send_mailslot, send a mailslot for client code ...
 */

int cli_send_mailslot(int dgram_sock, BOOL unique, const char *mailslot,
		      char *buf, int len,
		      const char *srcname, int src_type,
		      const char *dstname, int dest_type,
		      struct in_addr dest_ip, struct in_addr src_ip,
		      int dest_port, int src_port)
{
DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*
 * cli_get_response: Get a response ...
 */
int cli_get_response(int dgram_sock, BOOL unique, const char *mailslot, char *buf, int bufsiz)
{
DEBUG(1,("function ommited\n"));
/* function omited*/

}

/*
 * cli_get_backup_list: Send a get backup list request ...
 */

static char cli_backup_list[1024];

int cli_get_backup_list(const char *myname, const char *send_to_name)
{
DEBUG(1,("function ommited\n"));
/* function omited*/
}

/*
 * cli_get_backup_server: Get the backup list and retrieve a server from it
 */

int cli_get_backup_server(char *my_name, char *target, char *servername, int namesize)
{

DEBUG(1,("function ommited\n"));
/* function omited*/

}



