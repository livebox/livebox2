#
#  $Id: Makefile.am,v 1.12 2004/11/23 06:46:40 holtmann Exp $
#

SUBDIRS = include src

aclocaldir = $(datadir)/aclocal

aclocal_DATA = bluez.m4

EXTRA_DIST = $(aclocal_DATA)

pkgconfigdir = $(libdir)/pkgconfig

pkgconfig_DATA = bluez.pc

DISTCLEANFILES = bluez.pc

MAINTAINERCLEANFILES = Makefile.in \
	aclocal.m4 configure config.h.in config.sub config.guess \
	ltmain.sh missing install-sh mkinstalldirs
