CC = gcc
CFLAGS = -Wall -Werror

all:	dijkstra kruskal prim clean

dijkstra:	dijkstra.c min_priority_queue.o min_priority_queue.h
	$(CC) $(CFLAGS) -o dijkstra min_priority_queue.o dijkstra.c

prim:		prim.c min_priority_queue.o min_priority_queue.h
	$(CC) $(CFLAGS) -o prim min_priority_queue.o prim.c

kruskal:	kruskal.c adapted_quicksort.o adapted_quicksort.h
	$(CC) $(CFLAGS) -o kruskal adapted_quicksort.o kruskal.c

clean:
	-rm *.o $(objects)