#include <stdio.h>

#include "basics.h"
#include "max_heap.h"

int main(){
	long int n;

	scanf("%ld", &n);

	long int vector[n];

	for(long int i = 0; i < n; i++){
		scanf("%ld", &vector[i]);
	}

	buildMaxHeap(vector, n - 1);

	showVector(vector, n);
}