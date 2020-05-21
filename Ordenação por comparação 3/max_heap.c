#include "basics.h"
#include "max_heap.h"

void maxHeap(long int* vector, long int index, long int size){
	long int left = 2*index;
	long int right = 2*index + 1;
	long int largest;
	
	if(left <= size && vector[left] > vector[index]){
		largest = left;
	}else{
		largest = index;
	}

	if(right <= size && vector[right] > vector[largest]){
		largest = right;
	}

	if(largest != index){
		swap(index, largest, vector);
		maxHeap(vector, largest, size);
	}	
}

void buildMaxHeap(long int* vector, long int size){
	 long int n = size - 1;
	 for(long int i = n/2; i >= 0; i--){
	 	maxHeap(vector, i, size);
	 }
}