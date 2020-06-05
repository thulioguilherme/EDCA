#include "adapted_quicksort.h"

int adapted_partition(long int* weights, long int* u, long int* v, long int begin, long int end) {
  long int pivot, top, i, aux_u, aux_v;
  pivot = weights[begin];
  aux_u = u[begin];
  aux_v = v[begin];

  top = begin;
  for(i = begin + 1; i <= end; i++) {
    if(weights[i] < pivot) {
      weights[top] = weights[i];
      weights[i]   = weights[top + 1];

      u[top] = u[i];
      u[i]   = u[top + 1];

      v[top] = v[i];
      v[i]   = v[top + 1];

      top++;
    }
  }

  weights[top] = pivot;
  u[top]       = aux_u;
  v[top]       = aux_v;

  return top;
}

void adapted_quicksort(long int* weights, long int* u, long int* v, long int begin, long int end) { //Best case: O(n*logn) - Worst case: O(n²)
  long int middle;
  if(begin < end) {
    middle = adapted_partition(weights, u, v, begin, end);
    adapted_quicksort(weights, u, v, begin, middle - 1);
    adapted_quicksort(weights, u, v, middle + 1, end);
  }
}