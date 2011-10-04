# $Id: Makefile.in,v 1.2 2002/09/30 19:45:00 dskoll Exp $
# Makefile for LNS handlers
# LIC: GPL

prefix=/usr/local
exec_prefix=${prefix}
mandir=${prefix}/man
docdir=/usr/local/doc/rp-pppoe-$(VERSION)
install=/usr/bin/install -c
install_dir=/usr/bin/install -c -d
sbindir=${exec_prefix}/sbin

HANDLERS=sync-pppd.so cmd.so

OBJS=pty.o sync-pppd.o dstring.o
SRCS=$(OBJS:.o=.c)
CFLAGS=-g -O2 -I.. -I../libevent -I../../libevent -Wall

all: $(HANDLERS) l2tp-control

l2tp-control: cmd-control.o
	mips-linux-uclibc-gcc -o l2tp-control cmd-control.o

cmd-control.o: cmd-control.c
	mips-linux-uclibc-gcc -c -o $@ $^

%.o: %.c
	mips-linux-uclibc-gcc $(CFLAGS) -fPIC -c -o $@ $<

sync-pppd.so: pty.o sync-pppd.o
	mips-linux-uclibc-gcc -shared -o $@ $^

cmd.so: cmd.o dstring.o
	mips-linux-uclibc-gcc -shared -o $@ $^

clean:
	rm -f *.so *.o *~
	rm -f l2tp-control

install: all
	-mkdir -p $(RPM_INSTALL_ROOT)$(sbindir)
	-mkdir -p $(RPM_INSTALL_ROOT)$(prefix)/lib/l2tp/plugins
	$(install) -m 755  l2tp-control  $(RPM_INSTALL_ROOT)$(sbindir)
	$(install) -m 755 $(HANDLERS) $(RPM_INSTALL_ROOT)$(prefix)/lib/l2tp/plugins
distclean: clean
