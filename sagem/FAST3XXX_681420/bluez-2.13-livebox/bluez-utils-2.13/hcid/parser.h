/* A Bison parser, made by GNU Bison 1.875a.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     K_OPTIONS = 258,
     K_DEVICE = 259,
     K_AUTOINIT = 260,
     K_SECURITY = 261,
     K_PAIRING = 262,
     K_PTYPE = 263,
     K_NAME = 264,
     K_CLASS = 265,
     K_LM = 266,
     K_LP = 267,
     K_AUTH = 268,
     K_ENCRYPT = 269,
     K_ISCAN = 270,
     K_PSCAN = 271,
     K_PINHELP = 272,
     K_DBUSPINHELP = 273,
     K_YES = 274,
     K_NO = 275,
     WORD = 276,
     PATH = 277,
     STRING = 278,
     LIST = 279,
     HCI = 280,
     BDADDR = 281,
     NUM = 282
   };
#endif
#define K_OPTIONS 258
#define K_DEVICE 259
#define K_AUTOINIT 260
#define K_SECURITY 261
#define K_PAIRING 262
#define K_PTYPE 263
#define K_NAME 264
#define K_CLASS 265
#define K_LM 266
#define K_LP 267
#define K_AUTH 268
#define K_ENCRYPT 269
#define K_ISCAN 270
#define K_PSCAN 271
#define K_PINHELP 272
#define K_DBUSPINHELP 273
#define K_YES 274
#define K_NO 275
#define WORD 276
#define PATH 277
#define STRING 278
#define LIST 279
#define HCI 280
#define BDADDR 281
#define NUM 282




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 60 "parser.y"
typedef union YYSTYPE {
	char *str;
	long  num;
} YYSTYPE;
/* Line 1240 of yacc.c.  */
#line 96 "y.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



