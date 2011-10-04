# 
#  $Id: Makefile.am,v 1.1 2004/07/27 12:35:17 holtmann Exp $
#

datafiles = bcm203x.usermap

if BCM203X
usbdir = $(sysconfdir)/hotplug/usb

usb_DATA = $(datafiles)

usb_PROGRAMS = bcm203x

LDADD = @USB_LIBS@

AM_CFLAGS = @USB_CFLAGS@
endif

EXTRA_DIST = $(datafiles)

MAINTAINERCLEANFILES = Makefile.in
