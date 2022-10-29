cc=clang
CFLAGS?=-Os -pedantic -Wall 
PREFIX?=/usr/X11R6

all:
	$(CC) $(CFLAGS) -I$(PREFIX)/include jwm.c -L$(PREFIX)/lib -lX11 -o jwm

clean:
	rm -f jwm

