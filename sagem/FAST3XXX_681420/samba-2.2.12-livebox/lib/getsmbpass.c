/* Copyright (C) 1992-1998 Free Software Foundation, Inc.
This file is part of the GNU C Library.

The GNU C Library is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public License as
published by the Free Software Foundation; either version 2 of the
License, or (at your option) any later version.

The GNU C Library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.

You should have received a copy of the GNU Library General Public
License along with the GNU C Library; see the file COPYING.LIB.  If
not, write to the Free Software Foundation, Inc., 675 Mass Ave,
Cambridge, MA 02139, USA.  */

/* Modified to use with samba by Jeremy Allison, 8th July 1995. */

#include "includes.h"

#ifdef REPLACE_GETPASS

#ifdef SYSV_TERMIO

/* SYSTEM V TERMIO HANDLING */

static struct termio t;

#define ECHO_IS_ON(t) ((t).c_lflag & ECHO)
#define TURN_ECHO_OFF(t) ((t).c_lflag &= ~ECHO)
#define TURN_ECHO_ON(t) ((t).c_lflag |= ECHO)

#ifndef TCSAFLUSH
#define TCSAFLUSH 1
#endif

#ifndef TCSANOW
#define TCSANOW 0
#endif

static int tcgetattr(int fd, struct termio *t)
{
	return ioctl(fd, TCGETA, t);
}

static int tcsetattr(int fd, int flags, struct termio *t)
{
	if(flags & TCSAFLUSH)
		ioctl(fd, TCFLSH, TCIOFLUSH);
	return ioctl(fd, TCSETS, t);
}

#elif !defined(TCSAFLUSH)

/* BSD TERMIO HANDLING */

static struct sgttyb t;

#define ECHO_IS_ON(t) ((t).sg_flags & ECHO)
#define TURN_ECHO_OFF(t) ((t).sg_flags &= ~ECHO)
#define TURN_ECHO_ON(t) ((t).sg_flags |= ECHO)

#define TCSAFLUSH 1
#define TCSANOW 0

static int tcgetattr(int fd, struct sgttyb *t)
{
	return ioctl(fd, TIOCGETP, (char *)t);
}

static int tcsetattr(int fd, int flags, struct sgttyb *t)
{
	return ioctl(fd, TIOCSETP, (char *)t);
}

#else /* POSIX TERMIO HANDLING */
#define ECHO_IS_ON(t) ((t).c_lflag & ECHO)
#define TURN_ECHO_OFF(t) ((t).c_lflag &= ~ECHO)
#define TURN_ECHO_ON(t) ((t).c_lflag |= ECHO)

static struct termios t;
#endif /* SYSV_TERMIO */

char *getsmbpass(const char *prompt)
{
 DEBUG(1,("function ommited\n"));
	/* function omited*/
}

#else
 void getsmbpasswd_dummy(void);
 void getsmbpasswd_dummy(void) {;}
#endif
