#include <stdio.h>
#include <math.h>
#include <limits.h>

#include "min_priority_queue.h"

void dijkstra(long int n, long int graph[n][n], long int source, long int destiny) {
  long int vertexes_pos[n];
  long int parents[n];
  long int costs[n];
  long int heap_size = -1;

  /* initialize single source */
  for (long int i = 0; i < n; i++) {
    if (i == source) {
      min_heap_insert(vertexes_pos, costs, parents, &heap_size, i, 0);
    } else {
      min_heap_insert(vertexes_pos, costs, parents, &heap_size, i, LONG_MAX);
    }
  }

  for (long int i = 0; i < n - 1; i++) {
    long int min = heap_extract_min(vertexes_pos, costs, &heap_size);

    for (long int j = 0; j <= heap_size; j++) {
      /* relax */
      if (graph[min][vertexes_pos[j]] > 0 && costs[vertexes_pos[j]] > (costs[min] + graph[min][vertexes_pos[j]]) ) {
        parents[vertexes_pos[j]] = min;

        heap_decrease_key(vertexes_pos, costs, heap_size, j, costs[min] + graph[min][vertexes_pos[j]]);
      }
    }
  }

  /* uncomment to show the minimal path
  printf("---- minimal path ----\n");
  long int p = destiny;
  while(p != source) {
    printf("%ld - %ld\n", parents[p], p);
    p = parents[p];
  }
  */

  printf("%ld\n", costs[destiny]);
}

int main(void) {
  long int n;

  scanf("%ld", &n);

  long int graph[n][n];
  long int weight;

  /* read graph */
  for (long int i = 0; i < n - 1; i++) {
    for (long int j = 0; j < n - 1 - i; j++) {
      scanf("%ld", &weight);
      graph[i][j + i + 1] = weight;
      graph[i + j + 1][i] = weight;
    }
    graph[i][i] = 0;
  }
  graph[n - 1][n - 1] = 0;

  dijkstra(n, graph, 0, n - 1);
}