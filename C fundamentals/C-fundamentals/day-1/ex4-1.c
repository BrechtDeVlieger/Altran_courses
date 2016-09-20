#include <stdio.h>

int max(int a, int b){
	return a > b ? a : b;
}

int main(int argc, char *argv[]){
	int biggest = 0;
	int numbers[10];
	printf("Give ten numbers:\n");
	for(int i = 0; i < 10; i++){
		fscanf(stdin, "%d", (numbers+i));
	}
	biggest = numbers[0];
	for(int i = 1; i < 10; i++){
		biggest = max(biggest,numbers[i]);
	}
	printf("\nThe biggest number is %d\n", biggest);
	return 0;
}
