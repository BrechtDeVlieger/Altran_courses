#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	char* ptr = malloc((sizeof(int))*1000);
	printf("The address is: %p\n", ptr);
	free(ptr);
	ptr = NULL;
	return 0;
}
