#include <stdio.h>

#include "adapted_quicksort.h"

void kruskal(long int n, long int graph[n][n]) {
  long int trees[n][n];
  long int trees_size[n];
  long int trees_index[n];
  long int trees_u[n][n];
  long int trees_v[n][n];
  long int trees_w[n][n];

  /* compute the number of distinct and valid vertexes */
  long int num_valid_vertexs = 0;
  for(long int i = 0; i < n; i++) {
    trees[i][0]    = i;
    trees_index[i] = i;
    trees_size[i]  = 1;

    for(long int j = i + 1; j < n; j++) {
      if(graph[i][j] != 0) {
        num_valid_vertexs += 1;
      }
    }
  }

  long int u[num_valid_vertexs];
  long int v[num_valid_vertexs];
  long int w[num_valid_vertexs];
  long int count = 0;

  /* pass all the vertexes to a vector */
  for(long int i = 0; i < n; i++) {
    for(long int j = i + 1; j < n; j++) {
      if(graph[i][j] != 0) {
        u[count] =  i;
        v[count] =  j;
        w[count] =  graph[i][j];
        count   +=  1;
      }
    }
  }

  /* sort vertexes based on the weight */
  adapted_quicksort(w, u, v, 0, count - 1);

  for(long int i = 0; i < count; i++) {
    if(trees_index[u[i]] != trees_index[v[i]]) {
      long int j = 0;
      long int old_size_first_tree = trees_size[ trees_index[ u[i] ] ];
      long int old_size_second_tree = trees_size[ trees_index[ v[i] ] ];

      /* union the sets U and V */
      while(j < trees_size[ trees_index[ v[i] ] ]) {
        trees[ trees_index[ u[i] ] ][ trees_size[trees_index[u[i]]] ] = trees[trees_index[v[i]]][j];

        trees_size[ trees_index[ u[i] ] ] += 1;
        j++;
      }

      /* connect trees */
      if(old_size_first_tree == 1 && old_size_second_tree == 1) {
        trees_u[ trees_index[ u[i] ] ][0] = u[i];
        trees_v[ trees_index[ u[i] ] ][0] = v[i];
        trees_w[ trees_index[ u[i] ] ][0] = w[i];
      } else {
        for(long int k = 0; k < (old_size_second_tree - 1); k++) {
          trees_u[ trees_index[ u[i] ] ][old_size_first_tree - 1] = trees_u[ trees_index[ v[i] ] ][k];
          trees_v[ trees_index[ u[i] ] ][old_size_first_tree - 1] = trees_v[ trees_index[ v[i] ] ][k];
          trees_w[ trees_index[ u[i] ] ][old_size_first_tree - 1] = trees_w[ trees_index[ v[i] ] ][k];

          old_size_first_tree += 1;
        }

        trees_u[ trees_index[ u[i] ] ][old_size_first_tree - 1] = u[i];
        trees_v[ trees_index[ u[i] ] ][old_size_first_tree - 1] = v[i];
        trees_w[ trees_index[ u[i] ] ][old_size_first_tree - 1] = w[i];
      }

      /* make the vertexes of a set point to same tree */
      long int old_index = trees_index[v[i]];
      for(long int k = 0; k < n; k++) {
        if(trees_index[k] == old_index) {
          trees_index[k] = trees_index[u[i]];
        }
      }
    }
  }

  /* uncomment to show the minimal spanning tree
  printf("---- minimal spanning tree ----\n");
  for(long int i = 0; i < trees_size[ trees_index[0] ] - 1; i++) {
    printf("u: %ld - v: %ld - w: %ld\n", trees_u[trees_index[0]][i], trees_v[trees_index[0]][i], trees_w[trees_index[0]][i]);
  }
  */

  /* compute cost */
  long int cost = 0;
  for(long int i = 0; i < trees_size[ trees_index[0] ] - 1; i++) {
    cost += trees_w[trees_index[0]][i];
  }
  printf("%ld\n", cost);
}

int main(void) {
  long int n;

  scanf("%ld", &n);

  long int graph[n][n];
  long int weight;

  for(long int i = 0; i < n - 1; i++) {
    for(long int j = 0; j < n - 1 - i; j++) {
      scanf("%ld", &weight);
      graph[i][j + i + 1] = weight;
      graph[i + j + 1][i] = weight;
    }
    graph[i][i] = 0;
  }
  graph[n - 1][n - 1] = 0;

  kruskal(n, graph);
}