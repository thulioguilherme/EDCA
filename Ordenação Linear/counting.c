#include <stdio.h>
#include "basics.h"

void counting(long int* vector, long int size){
	long int max = getMaxValue(vector, size);
	long int min = getMinValue(vector, size);
	long int range = max - min + 1;
	
	unsigned int count[range];
	long int auxiliar[size];

	for(long int i = 0; i < range; i++){
		count[i] = 0;
	}

	for(long int i = 0; i < size; i++){
		count[vector[i]-min] += 1; 
	}

	for(long int i = 1; i < range; i++){
		count[i] += count[i-1];
	}

	for(long int i = size - 1; i>= 0; i--){
		auxiliar[count[vector[i] - min] - 1] = vector[i];
		count[vector[i] - min] -= 1;
	}

	for(long int i = 0; i < size; i++){
		vector[i] = auxiliar[i];
	}
}

int main(){
	
	long int n;

	scanf("%ld", &n);

	long int vector[n];

	for(long int i = 0; i < n; i++){
		scanf("%ld", &vector[i]);
	}

	counting(vector, n);
	
	showVector(vector, n);
}