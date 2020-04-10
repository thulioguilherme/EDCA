#include <stdio.h>
#include "basics.h"

void selectionsort(long int* vector, long int size){ //Best case: O(n²) - Worst case: O(n²)
	long int min, tmp;
	for(long int i = 0; i < size - 1; i++){
		min = i;
		for(long int j = i + 1; j < size; j++){
			if(vector[j] < vector[min]){
				min = j;
			}
		}
		tmp = vector[min];
		vector[min] = vector[i];
		vector[i] = tmp;
	}
}

int main(){
	long int n;

	scanf("%ld", &n);

	long int vector[n];

	for(long int i = 0; i < n; i++){
		scanf("%ld", &vector[i]);
	}

	selectionsort(vector, n);

	showVector(vector, n);
}