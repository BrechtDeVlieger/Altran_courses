#include <stdio.h>

int main(int argc, char *argv[]){
	int intarray[] = {1,2,4,8,16,32,62};
	char chararray[] = {'B', 'R', 'E', 'C', 'H', 'T'};
	
	int* intptr = intarray;
	char* charptr = chararray;

	for(int i = 0; i < 6; i++){
		printf("intarray element %d has address %p and value %d\n", i, intptr+i, intptr[i]);
		printf("chararray element %d has address %p and value %c\n", i, charptr+i, charptr[i]);
	}
	return 0;
}
