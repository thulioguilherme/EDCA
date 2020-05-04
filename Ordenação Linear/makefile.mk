CC = gcc
CFLAGS = -Wall -Werror

all:	counting radixsort clean

counting:	counting.c basics.o basics.h
	$(CC) $(CFLAGS) -o counting basics.o counting.c

radixsort:	radixsort.c basics.o basics.h
	$(CC) $(CFLAGS) -o radixsort basics.o radixsort.c

clean:
	-rm *.o $(objects)