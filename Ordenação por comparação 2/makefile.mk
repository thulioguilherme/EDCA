CC = gcc
CFLAGS = -Wall -Werror

all:	quicksort mergesort clean

quicksort:	quicksort.c basics.o basics.h
	$(CC) $(CFLAGS) -o quicksort basics.o quicksort.c

mergesort:	mergesort.c basics.o basics.h
	$(CC) $(CFLAGS) -o mergesort basics.o mergesort.c

clean:
	-rm *.o $(objects)