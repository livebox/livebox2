/*
   Unix SMB/Netbios implementation.
   Version 1.9.
   name query routines
   Copyright (C) Andrew Tridgell 1994-1998

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

/* nmbd.c sets this to True. */
BOOL global_in_nmbd = False;

/****************************************************************************
 Generate a random trn_id.
****************************************************************************/

static int generate_trn_id(void)
{
	static int trn_id;

	if (trn_id == 0)
		sys_srandom(sys_getpid());

	trn_id = sys_random();

	return trn_id % (unsigned)0x7FFF;
}

/****************************************************************************
 Parse a node status response into an array of structures.
****************************************************************************/

static struct node_status *parse_node_status(char *p, int *num_names)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Do a NBT node status query on an open socket and return an array of
 structures holding the returned names or NULL if the query failed.
**************************************************************************/

struct node_status *node_status_query(int fd,struct nmb_name *name,
				      struct in_addr to_ip, int *num_names)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}


/****************************************************************************
find the first type XX name in a node status reply - used for finding
a servers name given its IP
return the matched name in *name
**************************************************************************/

BOOL name_status_find(const char *q_name, int q_type, int type, struct in_addr to_ip, char *name)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Do a NetBIOS name registation to try to claim a name ...
***************************************************************************/
BOOL name_register(int fd, const char *name, int name_type,
		   struct in_addr name_ip, int opcode,
		   BOOL bcast,
		   struct in_addr to_ip, int *count)
{
DEBUG(1,("function ommited\n"));
/* function omited*/
}

/****************************************************************************
 Do a netbios name query to find someones IP.
 Returns an array of IP addresses or NULL if none.
 *count will be set to the number of addresses returned.
****************************************************************************/
struct in_addr *name_query(int fd,const char *name,int name_type,
			   BOOL bcast,BOOL recurse,
			   struct in_addr to_ip, int *count, int *flags)
{
	BOOL found=False;
	int i, retries = 3;
	int retry_time = bcast?250:2000;
	struct timeval tval;
	struct packet_struct p;
	struct packet_struct *p2;
	struct nmb_packet *nmb = &p.packet.nmb;
	struct in_addr *ip_list = NULL;

	memset((char *)&p,'\0',sizeof(p));
	(*count) = 0;
	(*flags) = 0;

	nmb->header.name_trn_id = generate_trn_id();
	nmb->header.opcode = 0;
	nmb->header.response = False;
	nmb->header.nm_flags.bcast = bcast;
	nmb->header.nm_flags.recursion_available = False;
	nmb->header.nm_flags.recursion_desired = recurse;
	nmb->header.nm_flags.trunc = False;
	nmb->header.nm_flags.authoritative = False;
	nmb->header.rcode = 0;
	nmb->header.qdcount = 1;
	nmb->header.ancount = 0;
	nmb->header.nscount = 0;
	nmb->header.arcount = 0;

	make_nmb_name(&nmb->question.question_name,name,name_type);

	nmb->question.question_type = 0x20;
	nmb->question.question_class = 0x1;

	p.ip = to_ip;
	p.port = NMB_PORT;
	p.fd = fd;
	p.timestamp = time(NULL);
	p.packet_type = NMB_PACKET;

	GetTimeOfDay(&tval);

	if (!send_packet(&p)) 
		return NULL;

	retries--;

	while (1) {
		struct timeval tval2;
		struct in_addr *tmp_ip_list;

		GetTimeOfDay(&tval2);
		if (TvalDiff(&tval,&tval2) > retry_time) {
			if (!retries)
				break;
			if (!found && !send_packet(&p))
				return NULL;
			GetTimeOfDay(&tval);
			retries--;
		}
	  
		if ((p2=receive_nmb_packet(fd,90,nmb->header.name_trn_id))) {     
			struct nmb_packet *nmb2 = &p2->packet.nmb;
			debug_nmb_packet(p2);

			/* If we get a Negative Name Query Response from a WINS
			 * server, we should report it and give up.
			 */
			if( 0 == nmb2->header.opcode		/* A query response   */
				&& !(bcast)			/* from a WINS server */
				&& nmb2->header.rcode		/* Error returned     */
				) {

				if( DEBUGLVL( 3 ) ) {
					/* Only executed if DEBUGLEVEL >= 3 */
					dbgtext( "Negative name query response, rcode 0x%02x: ", nmb2->header.rcode );
					switch( nmb2->header.rcode ) {
					case 0x01:
						dbgtext( "Request was invalidly formatted.\n" );
						break;
					case 0x02:
						dbgtext( "Problem with NBNS, cannot process name.\n");
						break;
					case 0x03:
						dbgtext( "The name requested does not exist.\n" );
						break;
					case 0x04:
						dbgtext( "Unsupported request error.\n" );
						break;
					case 0x05:
						dbgtext( "Query refused error.\n" );
						break;
					default:
						dbgtext( "Unrecognized error code.\n" );
						break;
					}
				}

				free_packet(p2);
				return( NULL );
			}

			if (nmb2->header.opcode != 0 ||
					nmb2->header.nm_flags.bcast ||
					nmb2->header.rcode ||
					!nmb2->header.ancount) {
				/* 
				 * XXXX what do we do with this? Could be a
				 * redirect, but we'll discard it for the
				 * moment.
				 */
				free_packet(p2);
				continue;
			}

			tmp_ip_list = (struct in_addr *)Realloc( ip_list, sizeof( ip_list[0] )
												* ( (*count) + nmb2->answers->rdlength/6 ) );

			if (!tmp_ip_list) {
				DEBUG(0,("name_query: Realloc failed.\n"));
					SAFE_FREE(ip_list);
			}

			ip_list = tmp_ip_list;

			if (ip_list) {
				DEBUG(2,("Got a positive name query response from %s ( ", inet_ntoa(p2->ip)));
				for (i=0;i<nmb2->answers->rdlength/6;i++) {
					putip((char *)&ip_list[(*count)],&nmb2->answers->rdata[2+i*6]);
					DEBUGADD(2,("%s ",inet_ntoa(ip_list[(*count)])));
					(*count)++;
				}
				DEBUGADD(2,(")\n"));
			}

			found=True;
			retries=0;
			/* We add the flags back ... */
			if (nmb2->header.response)
			  (*flags) |= NM_FLAGS_RS;
			if (nmb2->header.nm_flags.authoritative)
			  (*flags) |= NM_FLAGS_AA;
			if (nmb2->header.nm_flags.trunc)
			  (*flags) |= NM_FLAGS_TC;
			if (nmb2->header.nm_flags.recursion_desired)
			  (*flags) |= NM_FLAGS_RD;
			if (nmb2->header.nm_flags.recursion_available)
			  (*flags) |= NM_FLAGS_RA;
			if (nmb2->header.nm_flags.bcast)
			  (*flags) |= NM_FLAGS_B;
			free_packet(p2);

			/*
			 * If we're doing a unicast lookup we only
			 * expect one reply. Don't wait the full 2
			 * seconds if we got one. JRA.
			 */
			if(!bcast && found)
				break;
		}
	}

	/* Reach here if we've timed out waiting for replies.. */
	if( !bcast && !found ) {
		/* Timed out wating for WINS server to respond.  Mark it dead. */
		wins_srv_died( to_ip );
	}

	return ip_list;
}

/********************************************************
 Start parsing the lmhosts file.
*********************************************************/

FILE *startlmhosts(const char *fname)
{
  FILE *fp = sys_fopen(fname,"r");
  if (!fp) {
    DEBUG(4,("startlmhosts: Can't open lmhosts file %s. Error was %s\n",
	     fname, strerror(errno)));
    return NULL;
  }
  return fp;
}

/********************************************************
 Parse the next line in the lmhosts file.
*********************************************************/

BOOL getlmhostsent( FILE *fp, pstring name, int *name_type, struct in_addr *ipaddr)
{
  DEBUG(1,("function ommited\n"));
/* function omited*/
}

/********************************************************
 Finish parsing the lmhosts file.
*********************************************************/

void endlmhosts(FILE *fp)
{
 DEBUG(1,("function ommited\n"));
/* function omited*/
}

BOOL name_register_wins(const char *name, int name_type)
{
  int sock, i, return_count;
  int num_interfaces = iface_count();
  struct in_addr sendto_ip;

  /*
   * Check if we have any interfaces, prevents a segfault later
   */

  if (num_interfaces <= 0)
    return False;         /* Should return some indication of the problem */

  /*
   * Do a broadcast register ...
   */

  if (!lp_wins_server())
    return False;

  DEBUG(4, ("name_register_wins:Registering my name %s on %s\n", name, lp_wins_server()));

  sock = open_socket_in(SOCK_DGRAM, 0, 3,
			interpret_addr("0.0.0.0"), True);

  if (sock == -1) return False;

  set_socket_options(sock, "SO_BROADCAST");

  sendto_ip.s_addr = inet_addr(lp_wins_server());

  if (num_interfaces > 1) {

    for (i = 0; i < num_interfaces; i++) {

      if (!name_register(sock, name, name_type, *iface_n_ip(i),
			 NMB_NAME_MULTIHOMED_REG_OPCODE,
			 True, sendto_ip, &return_count)) {

	close(sock);
	return False;

      }

    }

  }
  else {

    if (!name_register(sock, name, name_type, *iface_n_ip(0),
		       NMB_NAME_REG_OPCODE,
		       True, sendto_ip, &return_count)) {

      close(sock);
      return False;

    }

  }

  close(sock);

  return True;

}

/********************************************************
 Resolve via "bcast" method.
*********************************************************/

BOOL name_resolve_bcast(const char *name, int name_type,
			struct in_addr **return_ip_list, int *return_count)
{
	int sock, i;
	int num_interfaces = iface_count();

	*return_ip_list = NULL;
	*return_count = 0;
	
	/*
	 * "bcast" means do a broadcast lookup on all the local interfaces.
	 */

	DEBUG(3,("name_resolve_bcast: Attempting broadcast lookup for name %s<0x%x>\n", name, name_type));

	sock = open_socket_in( SOCK_DGRAM, 0, 3,
			       interpret_addr(lp_socket_address()), True );

	if (sock == -1) return False;

	set_socket_options(sock,"SO_BROADCAST");
	/*
	 * Lookup the name on all the interfaces, return on
	 * the first successful match.
	 */
	for( i = num_interfaces-1; i >= 0; i--) {
		struct in_addr sendto_ip;
		int flags;
		/* Done this way to fix compiler error on IRIX 5.x */
		sendto_ip = *iface_bcast(*iface_n_ip(i));
		*return_ip_list = name_query(sock, name, name_type, True, 
				    True, sendto_ip, return_count, &flags);
		if(*return_ip_list != NULL) {
			close(sock);
			return True;
		}
	}

	close(sock);
	return False;
}

/********************************************************
 Resolve via "wins" method.
*********************************************************/

static BOOL resolve_wins(const char *name, int name_type,
			 struct in_addr **return_iplist, int *return_count)
{
	int sock;
	struct in_addr wins_ip;
	BOOL wins_ismyip;

	*return_iplist = NULL;
	*return_count = 0;
	
	/*
	 * "wins" means do a unicast lookup to the WINS server.
	 * Ignore if there is no WINS server specified or if the
	 * WINS server is one of our interfaces (if we're being
	 * called from within nmbd - we can't do this call as we
	 * would then block).
	 */

	DEBUG(3,("resolve_wins: Attempting wins lookup for name %s<0x%x>\n", name, name_type));

	if (lp_wins_support()) {
		/*
		 * We're providing WINS support. Call ourselves so
		 * long as we're not nmbd.
		 */
		extern struct in_addr loopback_ip;
		wins_ip = loopback_ip;
		wins_ismyip = True;
	} else if( wins_srv_count() < 1 ) {
		DEBUG(3,("resolve_wins: WINS server resolution selected and no WINS servers listed.\n"));
		return False;
	} else {
		wins_ip     = wins_srv_ip();
		wins_ismyip = ismyip(wins_ip);
	}

	DEBUG(3, ("resolve_wins: WINS server == <%s>\n", inet_ntoa(wins_ip)) );
	if((wins_ismyip && !global_in_nmbd) || !wins_ismyip) {
		sock = open_socket_in(  SOCK_DGRAM, 0, 3,
					interpret_addr(lp_socket_address()),
					True );
		if (sock != -1) {
		        int flags;
			*return_iplist = name_query( sock,      name,
						     name_type, False, 
						     True,      wins_ip,
						     return_count, &flags);
			if(*return_iplist != NULL) {
				close(sock);
				return True;
			}
			close(sock);
		}
	}

	return False;
}

/********************************************************
 Resolve via "lmhosts" method.
*********************************************************/

static BOOL resolve_lmhosts(const char *name, int name_type,
			 struct in_addr **return_iplist, int *return_count)
{
	/*
	 * "lmhosts" means parse the local lmhosts file.
	 */
	
	FILE *fp;
	pstring lmhost_name;
	int name_type2;
	struct in_addr return_ip;

	*return_iplist = NULL;
	*return_count = 0;

	DEBUG(3,("resolve_lmhosts: Attempting lmhosts lookup for name %s<0x%x>\n", name, name_type));

	fp = startlmhosts( LMHOSTSFILE );
	if(fp) {
		while (getlmhostsent(fp, lmhost_name, &name_type2, &return_ip)) {
			if (strequal(name, lmhost_name) && 
                ((name_type2 == -1) || (name_type == name_type2))
               ) {
				endlmhosts(fp);
				*return_iplist = (struct in_addr *)malloc(sizeof(struct in_addr));
				if(*return_iplist == NULL) {
					DEBUG(3,("resolve_lmhosts: malloc fail !\n"));
					return False;
				}
				**return_iplist = return_ip;
				*return_count = 1;
				return True; 
			}
		}
		endlmhosts(fp);
	}
	return False;
}


/********************************************************
 Resolve via "hosts" method.
*********************************************************/

static BOOL resolve_hosts(const char *name,
			 struct in_addr **return_iplist, int *return_count)
{
	/*
	 * "host" means do a localhost, or dns lookup.
	 */
	struct hostent *hp;

	*return_iplist = NULL;
	*return_count = 0;

	DEBUG(3,("resolve_hosts: Attempting host lookup for name %s<0x20>\n", name));
	
	if (((hp = sys_gethostbyname(name)) != NULL) && (hp->h_addr != NULL)) {
		int i = 0, j;
		while (hp->h_addr_list[i]) i++;
		DEBUG(10, ("%d addresses returned\n", i));
		*return_iplist = (struct in_addr *)malloc(i*sizeof(struct in_addr));
		if(*return_iplist == NULL) {
			DEBUG(3,("resolve_hosts: malloc fail !\n"));
			return False;
		}
                for (j = 0; j < i; j++)
			putip(&(*return_iplist)[j], (char *)hp->h_addr_list[j]);
		*return_count = i;
		return True;
	}
	return False;
}

/********************************************************
 Internal interface to resolve a name into an IP address.
 Use this function if the string is either an IP address, DNS
 or host name or NetBIOS name. This uses the name switch in the
 smb.conf to determine the order of name resolution.
*********************************************************/

static BOOL internal_resolve_name(const char *name, int name_type,
					struct in_addr **return_iplist, int *return_count)
{
  pstring name_resolve_list;
  fstring tok;
  const char *ptr;
  BOOL allones = (strcmp(name,"255.255.255.255") == 0);
  BOOL allzeros = (strcmp(name,"0.0.0.0") == 0);
  BOOL is_address = is_ipaddress(name);
  BOOL result = False;
  struct in_addr *nodupes_iplist;
  int i;

  *return_iplist = NULL;
  *return_count = 0;

  if (allzeros || allones || is_address) {
	*return_iplist = (struct in_addr *)malloc(sizeof(struct in_addr));
	if(*return_iplist == NULL) {
		DEBUG(3,("internal_resolve_name: malloc fail !\n"));
		return False;
	}
	if(is_address) { 
		/* if it's in the form of an IP address then get the lib to interpret it */
		if (((*return_iplist)->s_addr = inet_addr(name)) == 0xFFFFFFFF ){
			DEBUG(1,("internal_resolve_name: inet_addr failed on %s\n", name));
			return False;
		}
	} else {
		(*return_iplist)->s_addr = allones ? 0xFFFFFFFF : 0;
		*return_count = 1;
	}
    return True;
  }
 
  /* Check netbios name cache */

  if (namecache_fetch(name, name_type, return_iplist, return_count)) {
    /* This could be a negative response */
    return (*return_count > 0);
  }

  pstrcpy(name_resolve_list, lp_name_resolve_order());
  ptr = name_resolve_list;
  if (!ptr || !*ptr)
    ptr = "host";

  while (next_token(&ptr, tok, LIST_SEP, sizeof(tok))) {
	  if((strequal(tok, "host") || strequal(tok, "hosts"))) {
		  if (name_type == 0x20 && resolve_hosts(name, return_iplist, return_count)) {
			  result = True;
              goto done;
		  }
	  } else if(strequal( tok, "lmhosts")) {
		  if (resolve_lmhosts(name, name_type, return_iplist, return_count)) {
			  result = True;
              goto done;
		  }
	  } else if(strequal( tok, "wins")) {
		  /* don't resolve 1D via WINS */
		  if (name_type != 0x1D &&
		        resolve_wins(name, name_type, return_iplist, return_count)) {
			  result = True;
              goto done;
		  }
	  } else if(strequal( tok, "bcast")) {
		  if (name_resolve_bcast(name, name_type, return_iplist, return_count)) {
			  result = True;
              goto done;
		  }
	  } else {
		  DEBUG(0,("resolve_name: unknown name switch type %s\n", tok));
	  }
  }

  /* All of the resolve_* functions above have returned false. */

  SAFE_FREE(*return_iplist);
  return False;

  done:

  /* Remove duplicate entries.  Some queries, notably #1c (domain
     controllers) return the PDC in iplist[0] and then all domain
     controllers including the PDC in iplist[1..n].  Iterating over
     the iplist when the PDC is down will cause two sets of timeouts. */

  if (*return_count && (nodupes_iplist =
			(struct in_addr *)malloc(sizeof(struct in_addr) * (*return_count)))) {
      int nodupes_count = 0;
 
      /* Iterate over return_iplist looking for duplicates */
 
      for (i = 0; i < *return_count; i++) {
          BOOL is_dupe = False;
          int j;
 
          for (j = i + 1; j < *return_count; j++) {
              if (ip_equal((*return_iplist)[i],
                       (*return_iplist)[j])) {
                  is_dupe = True;
                  break;
              }
          }
 
          if (!is_dupe) {
 
              /* This one not a duplicate */
 
              nodupes_iplist[nodupes_count] = (*return_iplist)[i];
              nodupes_count++;
          }
      }
 
      /* Switcheroo with original list */
 
      free(*return_iplist);
 
      *return_iplist = nodupes_iplist;
      *return_count = nodupes_count;
  }
 
  /* Display some debugging info */
 
  DEBUG(10, ("internal_resolve_name: returning %d addresses: ",
         *return_count));
 
  for (i = 0; i < *return_count; i++)
      DEBUGADD(10, ("%s ", inet_ntoa((*return_iplist)[i])));
 
  DEBUG(10, ("\n"));
 
  return result;
}

/********************************************************
 Internal interface to resolve a name into one IP address.
 Use this function if the string is either an IP address, DNS
 or host name or NetBIOS name. This uses the name switch in the
 smb.conf to determine the order of name resolution.
*********************************************************/

BOOL resolve_name(const char *name, struct in_addr *return_ip, int name_type)
{
	struct in_addr *ip_list = NULL;
	int count = 0;

	if (is_ipaddress(name)) {
		*return_ip = *interpret_addr2(name);
		return True;
	}

	if(internal_resolve_name(name, name_type, &ip_list, &count)) {
		int i;
		/* only return valid addresses for TCP connections */
		for (i=0; i<count; i++) {
			char *ip_str = inet_ntoa(ip_list[i]);
			if (ip_str &&
				strcmp(ip_str, "255.255.255.255") != 0 &&
				strcmp(ip_str, "0.0.0.0") != 0) {
				*return_ip = ip_list[i];
				SAFE_FREE(ip_list);
				return True;
			}
		}
	}
	SAFE_FREE(ip_list);
	return False;
}

/**************************************************************************
 Resolve a name to a list of addresses
**************************************************************************/
BOOL resolve_name_2(const char *name, struct in_addr **return_ip, int *count, int name_type)
{

	DEBUG(1,("function ommited\n"));
/* function omited*/

}

/********************************************************
 resolve a name of format \\server_name or \\ipaddress
 into a name.  also, cut the \\ from the front for us.
*********************************************************/

BOOL resolve_srv_name(const char* srv_name, fstring dest_host,
				struct in_addr *ip)
{
DEBUG(1,("function ommited\n"));
/* function omited*/
}


/********************************************************
 Find the IP address of the master browser or DMB for a workgroup.
*********************************************************/

BOOL find_master_ip(char *group, struct in_addr *master_ip)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/********************************************************
 Lookup a DC name given a Domain name and IP address.
*********************************************************/

BOOL lookup_dc_name(const char *srcname, const char *domain,
		    struct in_addr *dc_ip, char *ret_name)
{
DEBUG(1,("function ommited\n"));
/* function omited*/
}


/********************************************************
 Get the IP address list of the PDC/BDC's of a Domain.
*********************************************************/

BOOL get_dc_list(BOOL pdc_only, const char *group, struct in_addr **ip_list, int *count)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}

/********************************************************
 Get the IP address list of the Local Master Browsers
********************************************************/

BOOL get_lmb_list(struct in_addr **ip_list, int *count)
{
	DEBUG(1,("function ommited\n"));
/* function omited*/
}
