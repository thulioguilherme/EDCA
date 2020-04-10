CC = gcc
CFLAGS = -Wall -Werror

all:	selection insertion clean

selection:	selection.c basics.o basics.h
	$(CC) $(CFLAGS) -o selection basics.o selection.c

insertion:	insertion.c basics.o basics.h
	$(CC) $(CFLAGS) -o insertion basics.o insertion.c

clean:
	-rm *.o $(objects)