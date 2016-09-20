#include <stdio.h>

void *memcopy(void *dest, const void *src, size_t n){
	char* destination = dest;
	const char* source = src;
	
	for(size_t i = 0; i < n; i++){
		destination[i] = source[i];
	}
}

int main(int argc, char* argv[]){
	int name[] = {1,2,3,4,5};
	int* newname[5];

	memcopy(newname, name, 5);
	printf("Address: %p | name: %i", newname, name[2]);
}
