#
#  $Id: Makefile.am,v 1.4 2004/07/21 15:21:27 holtmann Exp $
#

bin_PROGRAMS = pand

pand_SOURCES = main.c pand.h bnep.c sdp.c

LIBS = @BLUEZ_LIBS@

AM_CFLAGS = @BLUEZ_CFLAGS@

man_MANS = pand.1

EXTRA_DIST = $(man_MANS)

MAINTAINERCLEANFILES = Makefile.in
