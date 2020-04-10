#include <stdio.h>
#include "basics.h"

void insertionsort(long int* vector, long int size){ //Best case: O(n) - Worst case: O(n²)
	long int tmp, i;
	for(long int j = 1; j < size; j++){
		tmp = vector[j];
		for(i = j - 1; (i >= 0) && (vector[i] > tmp); i--){
			vector[i + 1] = vector[i];
		}
		vector[i + 1] = tmp;
	}
}

int main(){
	long int n;

	scanf("%ld", &n);

	long int vector[n];

	for(int i = 0; i < n; i++){
		scanf("%ld", &vector[i]);
	}

	insertionsort(vector, n);

	showVector(vector, n);
}