#include <stdio.h>
#include <stdlib.h>

int add(int a, int b){
	printf("Adding %d and %d: \n", a, b);
	return a+b;
}

int substract(int a, int b){
	printf("Substracting %d from %d: \n", b, a);
	return a-b;
}

int main(int argc, char *argv[]){
	if(add(atoi(argv[1]), atoi(argv[2])) < 5 && substract(atoi(argv[1]), atoi(argv[2])) > 2){
		printf("True \n");
	}
	else printf("False \n");

	return 0;
}
