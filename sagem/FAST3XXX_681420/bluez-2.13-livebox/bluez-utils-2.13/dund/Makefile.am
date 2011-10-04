#
#  $Id: Makefile.am,v 1.4 2004/07/21 15:20:38 holtmann Exp $
#

bin_PROGRAMS = dund

dund_SOURCES = main.c dun.c dund.h sdp.c lib.h msdun.c

LIBS = @BLUEZ_LIBS@

AM_CFLAGS = @BLUEZ_CFLAGS@

man_MANS = dund.1

EXTRA_DIST = $(man_MANS)

MAINTAINERCLEANFILES = Makefile.in
