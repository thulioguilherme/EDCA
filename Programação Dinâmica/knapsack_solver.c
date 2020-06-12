#include <stdio.h>

long int max_value(long int v1, long int v2) {
  return (v1 > v2) ? v1 : v2;
}

void knapsack_solver(long int num_items, long int capacity, long int* values, long int* weights) {
  /* initialize */
  long int g[num_items + 1][capacity + 1];
  for(long int i = 0; i <= capacity; i++) {
    g[num_items][i] = 0;
  }

  for(long int i = num_items - 1; i >= 0; i--) {
    for(long int y = 0; y <= capacity; y++) {
      if(weights[i] > y) {
        g[i][y] = g[i + 1][y];
      } else {
        g[i][y] = max_value(g[i + 1][y], g[i + 1][y - weights[i]] + values[i]);
      }
    }
  }

  /* uncomment to show the items of the knapsack
  printf("---- knapsack items ----\n");
  long int max_value    = g[0][capacity];
  long int max_capacity = capacity;
  
  for(long int i = 0; i < num_items && max_value > 0; i++) {
    if(max_value == g[i + 1][max_capacity]) continue;

    printf("item index: %ld - weight: %ld - value: %ld\n", i, weights[i], values[i]);

    max_capacity -= weights[i];
    max_value    -= values[i];
  }
  */

  printf("%ld\n", g[0][capacity]);
}

int main(void) {
  long int n, M;

  scanf("%ld %ld", &n, &M);

  long int v[n], w[n];
  for(long int i = 0; i < n; i++) {
    scanf("%ld %ld", &w[i], &v[i]);
  }

  knapsack_solver(n, M, v, w);
}