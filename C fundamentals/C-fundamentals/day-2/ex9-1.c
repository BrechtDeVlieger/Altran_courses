#include <stdio.h>
#include <stdlib.h>

void* safe_malloc(size_t size){
	void* ptr = malloc(size);
	if(ptr == NULL){
		printf("Memory allocation failed\n");
		exit(1);
	}
	return ptr;
}

int main(int argc, char* argv[]){
	int* ptr = safe_malloc(sizeof(int)*9999999999999);
	free(ptr);
	return 0;
}
