#include <stdio.h>
#include "basics.h"

int partition(long int* vector, long int begin, long int end){
	long int pivot, top, i;
	pivot = vector[begin];
	top = begin;
	for(i = begin + 1; i <= end; i++){
		if(vector[i] < pivot){
			vector[top] = vector[i];
			vector[i] = vector[top + 1];
			top++;
		}
	}

	vector[top] = pivot;
	return top;
}

void quicksort(long int* vector, long int begin, long int end){ //Best case: O(n*logn) - Worst case: O(n²)
	long int middle;
	if(begin < end){
		middle = partition(vector, begin, end);
		quicksort(vector, begin, middle - 1);
		quicksort(vector, middle + 1, end);
	}
}

int main(){
	long int n;

	scanf("%ld", &n);

	long int vector[n];

	for(long int i = 0; i < n; i++){
		scanf("%ld", &vector[i]);
	}

	quicksort(vector, 0, n - 1);

	showVector(vector, n);
}