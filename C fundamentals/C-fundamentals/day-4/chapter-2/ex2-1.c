#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int sum(int n, ...){
	va_list ap;
	int i=0;
	int sum=0;
	va_start(ap, n);

	for(i = 0; i < n; i++){
		sum+=va_arg(ap, int);
	}
	va_end(ap);
	
	return sum;
}

int main(int argc, char* argv[]){
	int n = 5;
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	printf("Sum: %d\n", sum(n, a, b, c, d, e));

	return 0;
}
