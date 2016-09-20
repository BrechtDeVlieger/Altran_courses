#include <stdio.h>
#include <stdlib.h>

int count(const int number, const int* list, const int length){
	if(length == 1){
		return list[length-1] == number ? 1 : 0;
	} else {
		return count(number, list, length-1) + (list[length-1] == number ? 1 : 0);
	}
}
int main(int argc, char* argv[]){
	int* ptr = malloc(sizeof(int)*200);
	int number = strtol(argv[1], NULL, 10);
	for(int i = 0; i < argc-2; i++){
		ptr[i] = strtol(argv[i+2], NULL, 10);
	}
	printf("%d has %d occurrences\n", number, count(number, ptr, argc-2));
	free(ptr);
	
	return 0;
}
