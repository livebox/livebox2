#
#  $Id: Makefile.am,v 1.22 2004/07/27 13:19:00 holtmann Exp $
#

confdir = $(sysconfdir)

conf_DATA = hcid.conf

RG_LDADD1 =-nostdlib $(TOOLCHAIN_DIR)/mips-linux-uclibc/lib/crt1.o $(TOOLCHAIN_DIR)/mips-linux-uclibc/lib/crti.o $(TOOLCHAIN_DIR)/lib/gcc/mips-linux-uclibc/3.4.3/crtbegin.o
RG_LDADD2 =-lgcc -lc -lgcc $(TOOLCHAIN_DIR)/lib/gcc/mips-linux-uclibc/3.4.3/crtend.o $(TOOLCHAIN_DIR)/mips-linux-uclibc/lib/crtn.o

sbin_PROGRAMS = hcid

if DBUS
dbus_hcid_sources = dbus.c
dbus_hcid_libs    = @DBUS_LIBS@
dbus_hcid_cflags  = -DENABLE_DBUS -DDBUS_API_SUBJECT_TO_CHANGE
else
dbus_hcid_sources =
dbus_hcid_libs    =
dbus_hcid_cflags  =
endif

#hcid_SOURCES = glib-ectomy.h glib-ectomy.c hcid.h kword.h kword.c lexer.l lib.c lib.h main.c parser.h parser.y security.c $(dbus_hcid_sources)
hcid_SOURCES = glib-ectomy.h glib-ectomy.c hcid.h kword.h kword.c lexer.c lib.c lib.h main.c parser.h parser.c security.c $(dbus_hcid_sources)

LIBS = $(dbus_hcid_libs) @BLUEZ_LIBS@

hcid_LDFLAGS = $(RG_LDADD1)
hcid_LDADD = @BLUEZ_LIBS@ -lmgt_client $(RG_LDADD2)

AM_CFLAGS = @BLUEZ_CFLAGS@ @DBUS_CFLAGS@ $(dbus_hcid_cflags)

man_MANS = hcid.8 hcid.conf.5

AM_YFLAGS = -d

#CLEANFILES = lexer.c parser.c parser.h

EXTRA_DIST = $(man_MANS) $(conf_DATA) dbus.c

MAINTAINERCLEANFILES = Makefile.in

pinfile = $(confdir)/pin

install-data-local:
	[ -f $(DESTDIR)$(pinfile) ] || \
		echo "BlueZ" > $(DESTDIR)$(pinfile); \
		chmod 600 $(DESTDIR)$(pinfile)

uninstall-local:
	@rm -f $(DESTDIR)$(pinfile)
