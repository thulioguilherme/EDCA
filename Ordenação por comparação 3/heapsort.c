#include <stdio.h>

#include "basics.h"
#include "max_heap.h"

void heapsort(long int* vector, long int size){
	buildMaxHeap(vector, size);
	for(long int i = size; i > 0; i--){
		swap(0, i, vector);
		size -= 1;
		maxHeap(vector, 0, size);
	}
}

int main(){
	long int n;

	scanf("%ld", &n);

	long int vector[n];

	for(long int i = 0; i < n; i++){
		scanf("%ld", &vector[i]);
	}

	heapsort(vector, n - 1);

	showVector(vector, n);
}