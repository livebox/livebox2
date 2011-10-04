/*
   Unix SMB/Netbios implementation.
   Version 1.9.
   Kanji Extensions
   Copyright (C) Andrew Tridgell 1992-1998

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

   Adding for Japanese language by <fujita@ainix.isac.co.jp> 1994.9.5
     and extend coding system to EUC/SJIS/JIS/HEX at 1994.10.11
     and add all jis codes sequence type at 1995.8.16
     Notes: Hexadecimal code by <ohki@gssm.otuka.tsukuba.ac.jp>
   Adding features about Machine dependent codes and User Defined Codes
     by Hiroshi MIURA <miura@samba.gr.jp> 2000.3.19
*/

#define _KANJI_C_
#include "includes.h"

/*
 * Function pointers that get overridden when multi-byte code pages
 * are loaded.
 */

const char *(*multibyte_strchr)(const char *, int ) = (const char *(*)(const char *, int )) strchr;
const char *(*multibyte_strrchr)(const char *, int ) = (const char *(*)(const char *, int )) strrchr;
const char *(*multibyte_strstr)(const char *, const char *) = (const char *(*)(const char *, const char *)) strstr;
char *(*multibyte_strtok)(char *, const char *) = (char *(*)(char *, const char *)) strtok;

/*
 * Kanji is treated differently here due to historical accident of
 * it being the first non-English codepage added to Samba.
 * The define 'KANJI' is being overloaded to mean 'use kanji codepage
 * by default' and also 'this is the filename-to-disk conversion
 * method to use'. This really should be removed and all control
 * over this left in the smb.conf parameters 'client codepage'
 * and 'coding system'.
 */

#ifndef KANJI

/*
 * Set the default conversion to be the functions in
 * charcnv.c.
 */

static size_t skip_non_multibyte_char(char);
static BOOL not_multibyte_char_1(char);

char *(*_dos_to_unix)(char *) = dos2unix_format;
char *(*_dos_to_unix_static)(const char *) = dos2unix_format_static;
char *(*_unix_to_dos)(char *) = unix2dos_format;
char *(*_unix_to_dos_static)(const char *) = unix2dos_format_static;
size_t (*_skip_multibyte_char)(char) = skip_non_multibyte_char;
BOOL (*is_multibyte_char_1)(char) = not_multibyte_char_1;

#else /* KANJI */

/*
 * Set the default conversion to be the function
 * sj_to_sj in this file.
 */

static char *sj_to_sj(char *from);
static char *sj_to_sj_static(const char *from);
static size_t skip_kanji_multibyte_char(char);
static BOOL is_kanji_multibyte_char_1(char);

char *(*_dos_to_unix)(char *) = sj_to_sj;
char *(*_dos_to_unix_static)(const char *) = sj_to_sj_static;
char *(*_unix_to_dos)(char *) = sj_to_sj;
char *(*_unix_to_dos_static)(const char *) = sj_to_sj_static;
size_t (*_skip_multibyte_char)(char) = skip_kanji_multibyte_char;
int (*is_multibyte_char_1)(char) = is_kanji_multibyte_char_1;

#endif /* KANJI */

BOOL global_is_multibyte_codepage = False;

/* jis si/so sequence */
static char jis_kso = JIS_KSO;
static char jis_ksi = JIS_KSI;
static char hex_tag = HEXTAG;

/*******************************************************************
  SHIFT JIS functions
********************************************************************/

/*******************************************************************
 search token from S1 separated any char of S2
 S1 contains SHIFT JIS chars.
********************************************************************/

static char *sj_strtok(char *s1, const char *s2)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 search string S2 from S1
 S1 contains SHIFT JIS chars.
********************************************************************/

static const char *sj_strstr(const char *s1, const char *s2)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Search char C from beginning of S.
 S contains SHIFT JIS chars.
********************************************************************/

static const char *sj_strchr (const char *s, int c)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Search char C end of S.
 S contains SHIFT JIS chars.
********************************************************************/

static const char *sj_strrchr(const char *s, int c)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Kanji multibyte char skip function.
*******************************************************************/

static size_t skip_kanji_multibyte_char(char c)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Kanji multibyte char identification.
*******************************************************************/

static BOOL is_kanji_multibyte_char_1(char c)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 The following functions are the only ones needed to do multibyte
 support for Hangul, Big5 and Simplified Chinese. Most of the
 real work for these codepages is done in the generic multibyte
 functions. The only reason these functions are needed at all
 is that the is_xxx(c) calls are really preprocessor macros.
********************************************************************/

/*******************************************************************
  Hangul (Korean - code page 949) function.
********************************************************************/

static BOOL hangul_is_multibyte_char_1(char c)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
  Big5 Traditional Chinese (code page 950) function.
********************************************************************/

static BOOL big5_is_multibyte_char_1(char c)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
  Simplified Chinese (code page 936) function.
********************************************************************/

static BOOL simpch_is_multibyte_char_1(char c)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
  Generic multibyte functions - used by Hangul, Big5 and Simplified
  Chinese codepages.
********************************************************************/

/*******************************************************************
 search token from S1 separated any char of S2
 S1 contains generic multibyte chars.
********************************************************************/

static char *generic_multibyte_strtok(char *s1, const char *s2)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 search string S2 from S1
 S1 contains generic multibyte chars.
********************************************************************/

static const char *generic_multibyte_strstr(const char *s1, const char *s2)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Search char C from beginning of S.
 S contains generic multibyte chars.
********************************************************************/

static const char *generic_multibyte_strchr(const char *s, int c)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Search char C end of S.
 S contains generic multibyte chars.
********************************************************************/

static const char *generic_multibyte_strrchr(const char *s, int c)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Generic multibyte char skip function.
*******************************************************************/

static size_t skip_generic_multibyte_char(char c)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
  Code conversion
********************************************************************/

/* convesion buffer */
static char cvtbuf[2*sizeof(pstring)];

/*******************************************************************
  EUC <-> SJIS
********************************************************************/

static int euc2sjis (int hi, int lo)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static int sjis2euc (int hi, int lo)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Convert FROM contain SHIFT JIS codes to EUC codes
 return converted buffer
********************************************************************/

static char *sj_to_euc_static(const char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static char *sj_to_euc(char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Convert FROM contain EUC codes to SHIFT JIS codes
 return converted buffer
********************************************************************/

static char *euc_to_sj_static(const char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static char *euc_to_sj(char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
  EUC3 <-> SJIS
********************************************************************/
static int sjis3euc (int hi, int lo, int *len)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static int  euc3sjis (int hi, int lo, BOOL is_3byte)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Convert FROM contain SHIFT JIS codes to EUC codes (with SS2)
 return converted buffer
********************************************************************/

static char *sj_to_euc3_static(const char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static char *sj_to_euc3(char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Convert FROM contain EUC codes (with Sup-Kanji) to SHIFT JIS codes
 return converted buffer
********************************************************************/

static char *euc3_to_sj_static(const char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static char *euc3_to_sj(char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
  JIS7,JIS8,JUNET <-> SJIS
********************************************************************/

static int sjis2jis(int hi, int lo)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static int jis2sjis(int hi, int lo)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Convert FROM contain JIS codes to SHIFT JIS codes
 return converted buffer
********************************************************************/

static char *jis8_to_sj_static(const char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static char *jis8_to_sj(char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Convert FROM contain SHIFT JIS codes to JIS codes
 return converted buffer
********************************************************************/

static char *sj_to_jis8_static(const char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static char *sj_to_jis8(char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Convert FROM contain 7 bits JIS codes to SHIFT JIS codes
 return converted buffer
********************************************************************/

static char *jis7_to_sj_static(const char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static char *jis7_to_sj(char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Convert FROM contain SHIFT JIS codes to 7 bits JIS codes
 return converted buffer
********************************************************************/

static char *sj_to_jis7_static(const char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static char *sj_to_jis7(char *from)
{
  pstrcpy(from, sj_to_jis7_static(from));
  return from;
}

/*******************************************************************
 Convert FROM contain 7 bits JIS(junet) codes to SHIFT JIS codes
 return converted buffer
********************************************************************/

static char *junet_to_sj_static(const char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static char *junet_to_sj(char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Convert FROM contain SHIFT JIS codes to 7 bits JIS(junet) codes
 return converted buffer
********************************************************************/

static char *sj_to_junet_static(const char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static char *sj_to_junet(char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
  HEX <-> SJIS
********************************************************************/
/* ":xx" -> a byte */

static char *hex_to_sj_static(const char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static char *hex_to_sj(char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
  kanji/kana -> ":xx"
********************************************************************/

static char *sj_to_hex_static(const char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static char *sj_to_hex(char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
  CAP <-> SJIS
********************************************************************/
/* ":xx" CAP -> a byte */
static char *cap_to_sj_static(const char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static char *cap_to_sj(char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
  kanji/kana -> ":xx" - CAP format.
********************************************************************/
static char *sj_to_cap_static(const char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static char *sj_to_cap(char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 sj to sj
********************************************************************/

static char *sj_to_sj_static(const char *from)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static char *sj_to_sj(char *from)
{
	DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 cp to utf8
********************************************************************/
static char *cp_to_utf8_static(const char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static char *cp_to_utf8(char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 utf8 to cp
********************************************************************/
static char *utf8_to_cp_static(const char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

static char *utf8_to_cp(char *from)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/************************************************************************
 conversion:
 _dos_to_unix		_unix_to_dos
************************************************************************/

static void setup_string_function(int codes)
{
    switch (codes) {
    default:
	_dos_to_unix = dos2unix_format;
	_dos_to_unix_static = dos2unix_format_static;
	_unix_to_dos = unix2dos_format;
	_unix_to_dos_static = unix2dos_format_static;
	break;

    case SJIS_CODE:
	_dos_to_unix = sj_to_sj;
	_dos_to_unix_static = sj_to_sj_static;
	_unix_to_dos = sj_to_sj;
	_unix_to_dos_static = sj_to_sj_static;
	break;

    case EUC_CODE:
	_dos_to_unix = sj_to_euc;
	_dos_to_unix_static = sj_to_euc_static;
	_unix_to_dos = euc_to_sj;
	_unix_to_dos_static = euc_to_sj_static;
	break;

    case JIS7_CODE:
	_dos_to_unix = sj_to_jis7;
	_dos_to_unix_static = sj_to_jis7_static;
	_unix_to_dos = jis7_to_sj;
	_unix_to_dos_static = jis7_to_sj_static;
	break;

    case JIS8_CODE:
	_dos_to_unix = sj_to_jis8;
	_dos_to_unix_static = sj_to_jis8_static;
	_unix_to_dos = jis8_to_sj;
	_unix_to_dos_static = jis8_to_sj_static;
	break;

    case JUNET_CODE:
	_dos_to_unix = sj_to_junet;
	_dos_to_unix_static = sj_to_junet_static;
	_unix_to_dos = junet_to_sj;
	_unix_to_dos_static = junet_to_sj_static;
	break;

    case HEX_CODE:
	_dos_to_unix = sj_to_hex;
	_dos_to_unix_static = sj_to_hex_static;
	_unix_to_dos = hex_to_sj;
	_unix_to_dos_static = hex_to_sj_static;
	break;

    case CAP_CODE:
	_dos_to_unix = sj_to_cap;
	_dos_to_unix_static = sj_to_cap_static;
	_unix_to_dos = cap_to_sj;
	_unix_to_dos_static = cap_to_sj_static;
	break;

    case UTF8_CODE:
	_dos_to_unix = cp_to_utf8;
	_dos_to_unix_static = cp_to_utf8_static;
	_unix_to_dos = utf8_to_cp;
	_unix_to_dos_static = utf8_to_cp_static;
	break;

    case EUC3_CODE:
	_dos_to_unix = sj_to_euc3;
	_dos_to_unix_static = sj_to_euc3_static;
	_unix_to_dos = euc3_to_sj;
	_unix_to_dos_static = euc3_to_sj_static;
	break;
    }
}

/************************************************************************
 Interpret coding system.
************************************************************************/

void interpret_coding_system(const char *str)
{
    int codes = UNKNOWN_CODE;

    if (strequal (str, "sjis")) {
	codes = SJIS_CODE;
    } else if (strequal (str, "euc")) {
	codes = EUC_CODE;
    } else if (strequal (str, "cap")) {
	codes = CAP_CODE;
	hex_tag = HEXTAG;
    } else if (strequal (str, "hex")) {
	codes = HEX_CODE;
	hex_tag = HEXTAG;
    } else if (!strncasecmp (str, "hex", 3)) {
	codes = HEX_CODE;
	hex_tag = (str[3] ? str[3] : HEXTAG);
    } else if (strequal (str, "j8bb")) {
	codes = JIS8_CODE;
	jis_kso = 'B';
	jis_ksi = 'B';
    } else if (strequal (str, "j8bj") || strequal (str, "jis8")) {
	codes = JIS8_CODE;
	jis_kso = 'B';
	jis_ksi = 'J';
    } else if (strequal (str, "j8bh")) {
	codes = JIS8_CODE;
	jis_kso = 'B';
	jis_ksi = 'H';
    } else if (strequal (str, "j8@b")) {
	codes = JIS8_CODE;
	jis_kso = '@';
	jis_ksi = 'B';
    } else if (strequal (str, "j8@j")) {
	codes = JIS8_CODE;
	jis_kso = '@';
	jis_ksi = 'J';
    } else if (strequal (str, "j8@h")) {
	codes = JIS8_CODE;
	jis_kso = '@';
	jis_ksi = 'H';
    } else if (strequal (str, "j7bb")) {
	codes = JIS7_CODE;
	jis_kso = 'B';
	jis_ksi = 'B';
    } else if (strequal (str, "j7bj") || strequal (str, "jis7")) {
	codes = JIS7_CODE;
	jis_kso = 'B';
	jis_ksi = 'J';
    } else if (strequal (str, "j7bh")) {
	codes = JIS7_CODE;
	jis_kso = 'B';
	jis_ksi = 'H';
    } else if (strequal (str, "j7@b")) {
	codes = JIS7_CODE;
	jis_kso = '@';
	jis_ksi = 'B';
    } else if (strequal (str, "j7@j")) {
	codes = JIS7_CODE;
	jis_kso = '@';
	jis_ksi = 'J';
    } else if (strequal (str, "j7@h")) {
	codes = JIS7_CODE;
	jis_kso = '@';
	jis_ksi = 'H';
    } else if (strequal (str, "jubb")) {
	codes = JUNET_CODE;
	jis_kso = 'B';
	jis_ksi = 'B';
    } else if (strequal (str, "jubj") || strequal (str, "junet")) {
	codes = JUNET_CODE;
	jis_kso = 'B';
	jis_ksi = 'J';
    } else if (strequal (str, "jubh")) {
	codes = JUNET_CODE;
	jis_kso = 'B';
	jis_ksi = 'H';
    } else if (strequal (str, "ju@b")) {
	codes = JUNET_CODE;
	jis_kso = '@';
	jis_ksi = 'B';
    } else if (strequal (str, "ju@j")) {
	codes = JUNET_CODE;
	jis_kso = '@';
	jis_ksi = 'J';
    } else if (strequal (str, "ju@h")) {
	codes = JUNET_CODE;
	jis_kso = '@';
	jis_ksi = 'H';
    } else if (strequal (str, "utf8")) {
      codes = UTF8_CODE;
    } else if (strequal (str, "euc3")) {
      codes = EUC3_CODE;
    }
    setup_string_function (codes);
}

/*******************************************************************
 Non multibyte char function.
*******************************************************************/

static size_t skip_non_multibyte_char(char c)
{
  return 0;
}

/*******************************************************************
 Function that always says a character isn't multibyte.
*******************************************************************/

static BOOL not_multibyte_char_1(char c)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}

/*******************************************************************
 Setup the function pointers for the functions that are replaced
 when multi-byte codepages are used.

 The dos_to_unix and unix_to_dos function pointers are only
 replaced by setup_string_function called by interpret_coding_system
 above.
*******************************************************************/

void initialize_multibyte_vectors( int client_codepage)
{
  switch( client_codepage )
  {
  case KANJI_CODEPAGE:
    multibyte_strchr = sj_strchr;
    multibyte_strrchr = sj_strrchr;
    multibyte_strstr = sj_strstr;
    multibyte_strtok = sj_strtok;
    _skip_multibyte_char = skip_kanji_multibyte_char;
    is_multibyte_char_1 = is_kanji_multibyte_char_1;
    global_is_multibyte_codepage = True;
    break;
  case HANGUL_CODEPAGE:
    multibyte_strchr = generic_multibyte_strchr;
    multibyte_strrchr = generic_multibyte_strrchr;
    multibyte_strstr = generic_multibyte_strstr;
    multibyte_strtok = generic_multibyte_strtok;
    _skip_multibyte_char = skip_generic_multibyte_char;
    is_multibyte_char_1 = hangul_is_multibyte_char_1;
    global_is_multibyte_codepage = True;
    break;
  case BIG5_CODEPAGE:
    multibyte_strchr = generic_multibyte_strchr;
    multibyte_strrchr = generic_multibyte_strrchr;
    multibyte_strstr = generic_multibyte_strstr;
    multibyte_strtok = generic_multibyte_strtok;
    _skip_multibyte_char = skip_generic_multibyte_char;
    is_multibyte_char_1 = big5_is_multibyte_char_1;
    global_is_multibyte_codepage = True;
    break;
  case SIMPLIFIED_CHINESE_CODEPAGE:
    multibyte_strchr = generic_multibyte_strchr;
    multibyte_strrchr = generic_multibyte_strrchr;
    multibyte_strstr = generic_multibyte_strstr;
    multibyte_strtok = generic_multibyte_strtok;
    _skip_multibyte_char = skip_generic_multibyte_char;
    is_multibyte_char_1 = simpch_is_multibyte_char_1;
    global_is_multibyte_codepage = True;
    break;
  /*
   * Single char size code page.
   */
  default:
    multibyte_strchr = (const char *(*)(const char *, int )) strchr;
    multibyte_strrchr = (const char *(*)(const char *, int )) strrchr;
    multibyte_strstr = (const char *(*)(const char *, const char *)) strstr;
    multibyte_strtok = (char *(*)(char *, const char *)) strtok;
    _skip_multibyte_char = skip_non_multibyte_char;
    is_multibyte_char_1 = not_multibyte_char_1;
    global_is_multibyte_codepage = False;
    break;
  }
}
/* *******************************************************
   function(s) for "dynamic" encoding of SWAT output.
   in this version, only dos_to_dos, dos_to_unix, unix_to_dos
   are used for bug fix. conversion to web encoding
   (to catalog file encoding) is not needed because
   they are using same character codes.
   **************************************************** */
static char *no_conversion_static(const char *str)
{
DEBUG(1,("function ommited\n"));
	/* function omited*/
}
char *(*_dos_to_dos_static)(const char *) = no_conversion_static;
