/* ========================================================================== **
 *                                debugparse.c
 *
 * Copyright (C) 1998 by Christopher R. Hertel
 *
 * Email: crh@ubiqx.mn.org
 *
 * -------------------------------------------------------------------------- **
 * This module is a very simple parser for Samba debug log files.
 * -------------------------------------------------------------------------- **
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * -------------------------------------------------------------------------- **
 * The important function in this module is dbg_char2token().  The rest is
 * basically fluff.  (Potentially useful fluff, but still fluff.)
 * ========================================================================== **
 */

#include "debugparse.h"
#include "includes.h"
/* -------------------------------------------------------------------------- **
 * Constants...
 *
 *  DBG_BSIZE - This internal constant is used only by dbg_test().  It is the
 *          size of the read buffer.  I've tested the function using a
 *          DBG_BSIZE value of 2.
 */

#define DBG_BSIZE 128

/* -------------------------------------------------------------------------- **
 * Functions...
 */

const char *dbg_token2string( dbg_Token tok )
  {
	DEBUG(1,("function ommited\n"));
 /* function omited*/
  } /* dbg_token2string */

dbg_Token dbg_char2token( dbg_Token *state, int c )
  {
DEBUG(1,("function ommited\n"));
/* function omited*/
  } /* dbg_char2token */

void dbg_test( void )
  {
DEBUG(1,("function ommited\n"));
/* function omited*/
  } /* dbg_test */


/* -------------------------------------------------------------------------- **
 * This simple main line can be uncommented and used to test the parser.
 */

/*
 * int main( void )
 *  {
 *  dbg_test();
 *  return( 0 );
 *  }
 */

/* ========================================================================== */
