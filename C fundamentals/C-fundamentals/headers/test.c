#include "scripts.h"
#include <stdio.h>

int main(int argc, char* argv[]){
	int* number = ask_input("Give a number:", "%d");
	printf("%d\n", *number);
	
	free(number);
	return 0;
}
