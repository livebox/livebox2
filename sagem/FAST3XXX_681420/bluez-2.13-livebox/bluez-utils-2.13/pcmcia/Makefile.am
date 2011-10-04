# 
#  $Id: Makefile.am,v 1.7 2004/07/27 13:04:23 holtmann Exp $
#

datafiles = bluetooth bluetooth.conf

if PCMCIA
pcmciadir = $(sysconfdir)/pcmcia

pcmcia_DATA = $(datafiles)
endif

EXTRA_DIST = $(datafiles)

MAINTAINERCLEANFILES = Makefile.in
