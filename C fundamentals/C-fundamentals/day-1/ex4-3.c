#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	printf("USER: %s\n", getenv("USER"));
	printf("HOME: %s\n", getenv("HOME"));
	printf("PATH: %s\n", getenv("PATH"));
	return 0;
}
