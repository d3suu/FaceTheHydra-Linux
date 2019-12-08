#include "stack.h"
#include <time.h>
#include <stdlib.h>

void shuffle(int* library){
	// Fisher-Yates algorithm from geeksforgeeks.org
	void swap(int* a, int* b){
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	srand(time(NULL));

	for(int i = 59; i > 0; i--){
		int j = rand() % (i+1);
		swap(&library[i], &library[j]);
	}
}
