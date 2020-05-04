#include <stdio.h>
#include "basics.h"

void radixsort(long int* vector, long int size, long int digits){
	long int i, exp = 1, max = getMaxValue(vector, size);
	long int auxiliar[size];
	unsigned int count[digits];

	while(max/exp > 0){
		for(i = 0; i < digits; i++){
			count[i] = 0;
		}

		for(i = 0; i < size; i++){
			count[(vector[i] / exp) % digits] += 1;
		}
		for(i = 1; i < digits; i++){
			count[i] += count[i - 1];
		}

		for(i = size-1;i >= 0; i--){
			auxiliar[ count[(vector[i]/exp) % digits] - 1] = vector[i];
			count[ (vector[i]/exp) % digits ] -= 1;
		}

		for(i = 0; i < size; i++){
			vector[i] = auxiliar[i];
		}

		exp *= 10;
	}
}

int main(){
	long int n, digits = 10;

	scanf("%ld", &n);

	long int vector[n];

	for(long int i = 0; i < n; i++){
		scanf("%ld", &vector[i]);
	}

	radixsort(vector, n, digits);
	
	showVector(vector, n);
}