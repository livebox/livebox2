dnl
dnl  $Id: bluez.m4,v 1.1 2004/11/23 06:46:40 holtmann Exp $
dnl

AC_DEFUN([AM_PATH_BLUEZ], [
	BLUEZ_CFLAGS="-Wstrict-prototypes --no-strict-aliasing -D_LIBC_REENTRANT -g -Wall -Os  -meb  -msoft-float  -mabi=32  -march=lx4189  -Wa,-32  -Wa,-march=lx4189  -Wa,-mips1  -D__TARGET__ -DVERSION=\"2.13-J\""
	BLUEZ_LIBS="-lbluetooth"

	AC_SUBST(BLUEZ_CFLAGS)
	AC_SUBST(BLUEZ_LIBS)
])
