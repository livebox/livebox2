#
#  $Id: Makefile.am,v 1.6 2004/09/22 15:28:52 holtmann Exp $
#

bin_PROGRAMS = hidd

hidd_SOURCES = main.c hidd.h sdp.c

LIBS = @BLUEZ_LIBS@

AM_CFLAGS = @BLUEZ_CFLAGS@

man_MANS = hidd.1

EXTRA_DIST = $(man_MANS)

MAINTAINERCLEANFILES = Makefile.in
