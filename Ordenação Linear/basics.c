#include <stdio.h>
#include "basics.h"

long int getMaxValue(long int* vector, long int size){
	long int max = vector[0];
	for(long int i = 1; i < size; i++){
		if(vector[i] > max){
			max = vector[i];
		}
	}

	return max;
}

long int getMinValue(long int* vector, long int size){
	long int min = vector[0];
	for(long int i = 1; i < size; i++){
		if(vector[i] < min){
			min = vector[i];
		}
	}

	return min;
}

void showVector(long int* vector, long int size){
	for(long int i = 0; i < size; i++){
		printf("%ld\n", vector[i]);
	}
}