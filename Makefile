PREFIX?=/usr/X11R6
CFLAGS?=-Os -pedantic -Wall

all:
	$(CC) $(CFLAGS) -I$(PREFIX)/include jwm.c -L$(PREFIX)/lib -lX11 -o jwm

clean:
	rm -f jwm

