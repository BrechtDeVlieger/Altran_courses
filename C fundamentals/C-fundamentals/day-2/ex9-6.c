#include <stdio.h>
#include <stdlib.h>

int sum_of_lowers(int n){
	return n > 0 ? sum_of_lowers(n-1) + n : 0;
}

int main(int argc, char *argv[]){
	int n = 5;
	printf("The sum of all numbers lower than or equal to %d is %d\n", n, sum_of_lowers(n));
	return 0;
}
