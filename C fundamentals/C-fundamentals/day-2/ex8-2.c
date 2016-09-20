#include <stdio.h>
#include <stdlib.h>

int is_bigger(const void* p1, const void* p2){
	const int* ptr1 = p1;
	const int* ptr2 = p2;
	return *ptr1 > *ptr2 ? 1 : -1;
}

int main(int argc, char *argv[]){
	printf("How many numbers would you like me to store?\n");
	size_t number;
	fscanf(stdin, "%lu", &number);
	int* ptr = calloc(number, sizeof(int));
	printf("Now give %lu numbers:\n", number);
	for(int i = 0; i < number; i++){
		fscanf(stdin, "%d", (ptr+i));
	}

	printf("Here are your original numbers:\n");
	for(int i = 0; i < number; i++){
		printf("address: %p | number: %d\n", (ptr+i), ptr[i]);
	}
	

	printf("Here are your sorted numbers:\n");
	qsort(ptr , number, sizeof(int), is_bigger);
	for(int i = 0; i < number; i++){
		printf("address: %p | number: %d\n", (ptr+i), ptr[i]);
	}

	free(ptr);
	return 0;
}


