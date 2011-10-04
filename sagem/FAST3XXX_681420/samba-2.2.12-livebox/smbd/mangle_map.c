/*
   Unix SMB/CIFS implementation.
   Name mapping code
   Copyright (C) Jeremy Allison 1998
   Copyright (C) Andrew Tridgell 2002

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


/* ************************************************************************** **
 * Used only in do_fwd_mangled_map(), below.
 * ************************************************************************** **
 */
static char *map_filename( char *s,         /* This is null terminated */
			   const char *pattern,   /* This isn't. */
			   int len )        /* This is the length of pattern. */
  {
DEBUG(1,("function ommited\n"));
	/* function omited*/
  } /* map_filename */


/* ************************************************************************** **
 * MangledMap is a series of name pairs in () separated by spaces.
 * If s matches the first of the pair then the name given is the
 * second of the pair.  A * means any number of any character and if
 * present in the second of the pair as well as the first the
 * matching part of the first string takes the place of the * in the
 * second.
 *
 * I wanted this so that we could have RCS files which can be used
 * by UNIX and DOS programs.  My mapping string is (RCS rcs) which
 * converts the UNIX RCS file subdirectory to lowercase thus
 * preventing mangling.
 *
 * See 'mangled map' in smb.conf(5).
 *
 * ************************************************************************** **
 */
static void mangled_map(char *s, const char *MangledMap)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*
  front end routine to the mangled map code
  personally I think that the whole idea of "mangled map" is completely bogus
*/
void mangle_map_filename(char *fname, int snum)
{
	char *map;

	map = lp_mangled_map(snum);
	if (!map || !*map) return;

	mangled_map(fname, map);
}
