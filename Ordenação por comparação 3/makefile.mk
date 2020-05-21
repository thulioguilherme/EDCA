CC = gcc
CFLAGS = -Wall -Werror

all:	get_max_heap heapsort clean

get_max_heap:	get_max_heap.c max_heap.o max_heap.h basics.o basics.h
	$(CC) $(CFLAGS) -o get_max_heap max_heap.o basics.o get_max_heap.c

heapsort:	heapsort.c max_heap.o max_heap.h basics.o basics.h
	$(CC) $(CFLAGS) -o heapsort max_heap.o basics.o heapsort.c

clean:
	-rm *.o $(objects)