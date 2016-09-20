#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void* safe_malloc(size_t size){
	void* ptr = malloc(size);
	assert(ptr != NULL);
	return ptr;
}

int main(int argc, char* argv[]){
	int* ptr = safe_malloc(sizeof(int)*9999999999999);
	free(ptr);
	return 0;
}
