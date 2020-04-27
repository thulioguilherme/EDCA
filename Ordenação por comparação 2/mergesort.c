#include <stdio.h>
#include "basics.h"

void mergeConquer(long int begin, long int middle, long int end, long int* vector, long int* keeper){
	for(long int i = begin; i <= end; i++){
		keeper[i] = vector[i];
	}
	long int i = begin;
	long int j = middle + 1;
	long int k = begin;

	while(i <= middle && j <= end){
		if(keeper[i] <= keeper[j]){
			vector[k] = keeper[i];
			i++;
		}else{
			vector[k] = keeper[j];
			j++;
		}
		k++;
	}

	while(i <= middle){
		vector[k] = keeper[i];
		k++;
		i++;
	}

	while(j <= end){
		vector[k] = keeper[j];
		j++;
		k++;
	}
}

void mergeDivide(long int begin, long int end, long int* vector, long int* keeper){
	if(begin < end){
		long int middle = begin + (end - begin) / 2;
		mergeDivide(begin, middle, vector, keeper);
		mergeDivide(middle + 1, end, vector, keeper);
		mergeConquer(begin, middle, end, vector, keeper);
	}
}

void mergesort(long int* vector, long int* keeper, long int size){ // Best case: O(n*logn) - Worst case: O(n*logn)
	for(long int i = 0; i < size; i++){
		keeper[i] = vector[i];
	}
	mergeDivide(0, size - 1, vector, keeper);
}

int main(){
	long int n;

	scanf("%ld", &n);

	long int vector[n], keeper[n];

	for(long int i = 0; i < n; i++){
		scanf("%ld", &vector[i]);
	}

	mergesort(vector, keeper, n);

	showVector(vector, n);
}