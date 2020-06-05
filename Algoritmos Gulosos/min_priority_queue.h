#ifndef MIN_PRIORITY_QUEUE_H
#define MIN_PRIORITY_QUEUE_H
void min_heapify(long int* vertexes_pos, long int* costs, long int index, long int heap_size);
long int heap_minimun(long int* vertexes_pos, long int heap_size);
long int heap_extract_min(long int* vertexes_pos, long int* costs, long int* heap_size);
void heap_decrease_key(long int* vertexes_pos, long int* costs, long int heap_size, long int position, long int key);
void min_heap_insert(long int* vertexes_pos, long int* costs, long int* parents, long int* heap_size, long int vertex, long int cost);
#endif