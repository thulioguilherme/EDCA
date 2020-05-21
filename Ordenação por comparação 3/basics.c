#include <stdio.h>

#include "basics.h"

void showVector(long int* vector, long int size){
	for(long int i = 0; i < size; i++){
		printf("%ld\n", vector[i]);
	}
}

void swap(long int i, long int j, long int* vector){
	long int tmp = vector[i];
	vector[i] = vector[j];
	vector[j] = tmp;	
}