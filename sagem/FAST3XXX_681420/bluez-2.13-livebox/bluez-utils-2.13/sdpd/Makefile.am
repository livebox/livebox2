#
#  $Id: Makefile.am,v 1.8 2004/07/21 15:22:21 holtmann Exp $
#

RG_LDADD1 =-nostdlib $(TOOLCHAIN_DIR)/mips-linux-uclibc/lib/crt1.o $(TOOLCHAIN_DIR)/mips-linux-uclibc/lib/crti.o $(TOOLCHAIN_DIR)/lib/gcc/mips-linux-uclibc/3.4.3/crtbegin.o
RG_LDADD2 =-lgcc -lc -lgcc $(TOOLCHAIN_DIR)/lib/gcc/mips-linux-uclibc/3.4.3/crtend.o $(TOOLCHAIN_DIR)/mips-linux-uclibc/lib/crtn.o

sbin_PROGRAMS = sdpd

sdpd_SOURCES = cstate.c main.c request.c service.c servicedb.c sdpd.h

LIBS = @BLUEZ_LIBS@

sdpd_LDFLAGS = $(RG_LDADD1)
sdpd_LDADD = @BLUEZ_LIBS@ $(RG_LDADD2)

AM_CFLAGS = @BLUEZ_CFLAGS@

man_MANS = sdpd.8

EXTRA_DIST = $(man_MANS)

MAINTAINERCLEANFILES = Makefile.in
