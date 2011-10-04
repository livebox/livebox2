#
#  $Id: Makefile.am,v 1.5 2004/07/27 13:04:00 holtmann Exp $
#

if CUPS
cupsdir = $(libdir)/cups/backend

cups_PROGRAMS = bluetooth

bluetooth_SOURCES = main.c sdp.c spp.c hcrp.c

LDADD = @BLUEZ_LIBS@

AM_CFLAGS = @BLUEZ_CFLAGS@
endif

MAINTAINERCLEANFILES = Makefile.in
