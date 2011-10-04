/*
   Unix SMB/CIFS implementation.
   new hash based name mangling implementation
   Copyright (C) Andrew Tridgell 2002
   Copyright (C) Simo Sorce 2002

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

/*
  this mangling scheme uses the following format

  Annnn~n.AAA

  where nnnnn is a base 36 hash, and A represents characters from the original string

  The hash is taken of the leading part of the long filename, in uppercase

  for simplicity, we only allow ascii characters in 8.3 names
 */

 /* hash alghorithm changed to FNV1 by idra@samba.org (Simo Sorce).
  * see http://www.isthe.com/chongo/tech/comp/fnv/index.html for a
  * discussion on Fowler / Noll / Vo (FNV) Hash by one of it's authors
  */

/*
  ===============================================================================
  NOTE NOTE NOTE!!!

  This file deliberately uses non-multibyte string functions in many places. This
  is *not* a mistake. This code is multi-byte safe, but it gets this property
  through some very subtle knowledge of the way multi-byte strings are encoded
  and the fact that this mangling algorithm only supports ascii characters in
  8.3 names.

  please don't convert this file to use the *_m() functions!!
  ===============================================================================
*/


#include "includes.h"

/* these flags are used to mark characters in as having particular
   properties */
#define FLAG_BASECHAR 1
#define FLAG_ASCII 2
#define FLAG_ILLEGAL 4
#define FLAG_WILDCARD 8

/* the "possible" flags are used as a fast way to find possible DOS
   reserved filenames */
#define FLAG_POSSIBLE1 16
#define FLAG_POSSIBLE2 32
#define FLAG_POSSIBLE3 64
#define FLAG_POSSIBLE4 128

/* by default have a max of 4096 entries in the cache. */
#ifndef MANGLE_CACHE_SIZE
#define MANGLE_CACHE_SIZE 4096
#endif

#define FNV1_PRIME 0x01000193
/*the following number is a fnv1 of the string: idra@samba.org 2002 */
#define FNV1_INIT  0xa6b93095

/* these tables are used to provide fast tests for characters */
static unsigned char char_flags[256];

#define FLAG_CHECK(c, flag) (char_flags[(unsigned char)(c)] & (flag))

/* we will use a very simple direct mapped prefix cache. The big
   advantage of this cache structure is speed and low memory usage

   The cache is indexed by the low-order bits of the hash, and confirmed by
   hashing the resulting cache entry to match the known hash
*/
static char **prefix_cache;
static u32 *prefix_cache_hashes;

/* these are the characters we use in the 8.3 hash. Must be 36 chars long */
static const char *basechars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static unsigned char base_reverse[256];
#define base_forward(v) basechars[v]

/* the list of reserved dos names - all of these are illegal */
static const char *reserved_names[] =
{ "AUX", "LOCK$", "CON", "COM1", "COM2", "COM3", "COM4",
  "LPT1", "LPT2", "LPT3", "NUL", "PRN", NULL };

/*
   hash a string of the specified length. The string does not need to be
   null terminated

   this hash needs to be fast with a low collision rate (what hash doesn't?)
*/
static u32 mangle_hash(const char *key, unsigned length)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*
   initialise (ie. allocate) the prefix cache
 */
static BOOL cache_init(void)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*
  insert an entry into the prefix cache. The string might not be null
  terminated */
static void cache_insert(const char *prefix, int length, u32 hash)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*
  lookup an entry in the prefix cache. Return NULL if not found.
*/
static const char *cache_lookup(u32 hash)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}


/*
   determine if a string is possibly in a mangled format, ignoring
   case

   In this algorithm, mangled names use only pure ascii characters (no
   multi-byte) so we can avoid doing a UCS2 conversion
 */
static BOOL is_mangled_component(const char *name)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}



/*
   determine if a string is possibly in a mangled format, ignoring
   case

   In this algorithm, mangled names use only pure ascii characters (no
   multi-byte) so we can avoid doing a UCS2 conversion

   NOTE! This interface must be able to handle a path with unix
   directory separators. It should return true if any component is
   mangled
 */
static BOOL is_mangled(const char *name)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}


/*
   see if a filename is an allowable 8.3 name.

   we are only going to allow ascii characters in 8.3 names, as this
   simplifies things greatly (it means that we know the string won't
   get larger when converted from UNIX to DOS formats)
*/
static BOOL is_8_3(const char *name, BOOL check_case, BOOL allow_wildcards)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}


/*
  reset the mangling cache on a smb.conf reload. This only really makes sense for
  mangling backends that have parameters in smb.conf, and as this backend doesn't
  this is a NULL operation
*/
static void mangle_reset(void)
{
	/* noop */
}


/*
  try to find a 8.3 name in the cache, and if found then
  replace the string with the original long name.

  The filename must be able to hold at least sizeof(fstring)
*/
static BOOL check_cache(char *name, size_t maxlen)
{
	u32 hash, multiplier;
	int i;
	const char *prefix;
	char extension[4];

	/* make sure that this is a mangled name from this cache */
	if (!is_mangled(name)) {
		DEBUG(10,("check_cache: %s -> not mangled\n", name));
		return False;
	}

	/* we need to extract the hash from the 8.3 name */
	hash = base_reverse[(unsigned char)name[7]];
	for (multiplier=36, i=5;i>=1;i--) {
		u32 v = base_reverse[(unsigned char)name[i]];
		hash += multiplier * v;
		multiplier *= 36;
	}

	/* now look in the prefix cache for that hash */
	prefix = cache_lookup(hash);
	if (!prefix) {
		DEBUG(10,("check_cache: %s -> %08X -> not found\n", name, hash));
		return False;
	}

	/* we found it - construct the full name */
	if (name[8] == '.') {
		strncpy(extension, name+9, 3);
		extension[3] = 0;
	} else {
		extension[0] = 0;
	}

	if (extension[0]) {
		DEBUG(10,("check_cache: %s -> %s.%s\n", name, prefix, extension));
		slprintf(name, maxlen, "%s.%s", prefix, extension);
	} else {
		DEBUG(10,("check_cache: %s -> %s\n", name, prefix));
		safe_strcpy(name, prefix, maxlen);
	}

	return True;
}


/*
  look for a DOS reserved name
*/
static BOOL is_reserved_name(const char *name)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*
 See if a filename is a legal long filename.
 A filename ending in a '.' is not legal unless it's "." or "..". JRA.
*/

static BOOL is_legal_name(const char *name)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*
  the main forward mapping function, which converts a long filename to
  a 8.3 name

  if need83 is not set then we only do the mangling if the name is illegal
  as a long name

  if cache83 is not set then we don't cache the result

  the name parameter must be able to hold 13 bytes
*/
static void name_map(char *name, BOOL need83, BOOL cache83)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}


/* initialise the flags table

  we allow only a very restricted set of characters as 'ascii' in this
  mangling backend. This isn't a significant problem as modern clients
  use the 'long' filenames anyway, and those don't have these
  restrictions.
*/
static void init_tables(void)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}


/*
  the following provides the abstraction layer to make it easier
  to drop in an alternative mangling implementation */
static struct mangle_fns mangle_fns = {
	is_mangled,
	is_8_3,
	mangle_reset,
	check_cache,
	name_map
};

/* return the methods for this mangling implementation */
struct mangle_fns *mangle_hash2_init(void)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}
