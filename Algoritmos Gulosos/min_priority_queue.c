#include <math.h>
#include <limits.h>

#include "min_priority_queue.h"

void min_heapify(long int* vertexes_pos, long int* costs, long int index, long int heap_size) {
  long int left  = 2 * index + 1;
  long int right = 2 * index + 2;
  long int lower;

  if (left <= heap_size && costs[vertexes_pos[left]] < costs[vertexes_pos[index]]) {
    lower = left;
  } else {
    lower = index;
  }

  if (right <= heap_size && costs[vertexes_pos[right]] < costs[vertexes_pos[lower]]) {
    lower = right;
  }

  if (lower != index) {
    long int tmp        = vertexes_pos[lower];
    vertexes_pos[lower] = vertexes_pos[index];
    vertexes_pos[index] = tmp;

    min_heapify(vertexes_pos, costs, lower, heap_size);
  }
}

/* returns the vertex with the minimum cost without extract it */
long int heap_minimun(long int* vertexes_pos, long int heap_size) {
  if (heap_size < 0) return -1;

  /* minimum vertex is always on the first position */
  long int vertex = vertexes_pos[0];

  return vertex;
}

/* returns the vertex with the minimum cost after extract it */
long int heap_extract_min(long int* vertexes_pos, long int* costs, long int* heap_size) {
  /* check if the heap is empty */
  if (*heap_size < 0) return -1;

  long int min = vertexes_pos[0];

  /* change the position of the first element with the last */
  vertexes_pos[0] = vertexes_pos[*heap_size];

  /* decrease heap_size */
  *heap_size = *heap_size - 1;

  /* check if the vector is still heap (the parent value is lower than his children) */
  min_heapify(vertexes_pos, costs, 0, *heap_size);

  return min;
}

/* change the value of an element to lower */
void heap_decrease_key(long int* vertexes_pos, long int* costs, long int heap_size, long int position, long int key) {
  /* if the value is higher, exit */
  if (key > costs[vertexes_pos[position]]) return;

  /* update value */
  costs[vertexes_pos[position]] = key;

  long int parent_position = (long int)floor((position - 1) / 2);

  /* check if the vector is still heap (the parent value is lower than his children) */
  long int new_position = position;
  while ((parent_position >= 0) && costs[vertexes_pos[new_position]] < costs[vertexes_pos[parent_position]]) {
    /* if the child is lower, change with the parent */
    long int tmp                  = vertexes_pos[new_position];
    vertexes_pos[new_position]    = vertexes_pos[parent_position];
    vertexes_pos[parent_position] = tmp;

    new_position = parent_position;

    if (parent_position <= 0) break;

    parent_position = (long int)floor((parent_position - 1) / 2);
  }
}

/* insert a new element in the vector */
void min_heap_insert(long int* vertexes_pos, long int* costs, long int* parents, long int* heap_size, long int vertex, long int cost) {
  /* all new vertexes are insert in the end with cost +INF */
  *heap_size               = *heap_size + 1;
  vertexes_pos[*heap_size] = vertex;
  costs[*heap_size]        = LONG_MAX;

  if (cost == 0) {
    parents[*heap_size] = vertex;
  } else {
    parents[*heap_size] = -1;
  }

  heap_decrease_key(vertexes_pos, costs, *heap_size, *heap_size, cost);
}