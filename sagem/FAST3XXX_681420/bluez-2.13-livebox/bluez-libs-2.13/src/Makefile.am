#  
#  $Id: Makefile.am,v 1.17 2004/12/25 17:27:06 holtmann Exp $
#

lib_LTLIBRARIES = libbluetooth.la libmgt_client.la

libbluetooth_la_SOURCES = bluetooth.c hci.c sdp.c
libmgt_client_la_SOURCES = mgt_client.c
libbluetooth_la_LDFLAGS = -version-info 1:13:0

INCLUDES = -I$(top_builddir)/include

MAINTAINERCLEANFILES = Makefile.in
