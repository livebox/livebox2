#
#  $Id: Makefile.am,v 1.23 2004/07/28 17:45:58 holtmann Exp $
#

if HID2HCI
hid2hci_programs = hid2hci
hid2hci_manfiles = hid2hci.8
else
hid2hci_programs =
hid2hci_manfiles =
endif

RG_LDADD1 =-nostdlib $(TOOLCHAIN_DIR)/mips-linux-uclibc/lib/crt1.o $(TOOLCHAIN_DIR)/mips-linux-uclibc/lib/crti.o $(TOOLCHAIN_DIR)/lib/gcc/mips-linux-uclibc/3.4.3/crtbegin.o
RG_LDADD2 =-lgcc -lc -lgcc $(TOOLCHAIN_DIR)/lib/gcc/mips-linux-uclibc/3.4.3/crtend.o $(TOOLCHAIN_DIR)/mips-linux-uclibc/lib/crtn.o

sbin_PROGRAMS = hciattach hciconfig $(hid2hci_programs)

bin_PROGRAMS = hcitool l2ping sdptool ciptool

#noinst_PROGRAMS = ppporc hcisecfilter

hciconfig_SOURCES = hciconfig.c csr.h csr.c

hciconfig_LDFLAGS = $(RG_LDADD1)
hciconfig_LDADD = @BLUEZ_LIBS@ $(RG_LDADD2)

hcitool_LDADD = @BLUEZ_LIBS@

l2ping_LDADD = @BLUEZ_LIBS@

sdptool_LDADD = @BLUEZ_LIBS@

ciptool_LDADD = @BLUEZ_LIBS@

hciattach_LDFLAGS = $(RG_LDADD1)
hciattach_LDADD = @BLUEZ_LIBS@ $(RG_LDADD2)

#ppporc_LDADD = @BLUEZ_LIBS@

if HID2HCI
hid2hci_LDADD = @USB_LIBS@
endif

AM_CFLAGS = @BLUEZ_CFLAGS@ @USB_CFLAGS@

man_MANS = hciattach.8 hciconfig.8 hcitool.1 l2ping.1 sdptool.1 ciptool.1 $(hid2hci_manfiles)

EXTRA_DIST = $(man_MANS) hid2hci.8 hid2hci.c

MAINTAINERCLEANFILES = Makefile.in
