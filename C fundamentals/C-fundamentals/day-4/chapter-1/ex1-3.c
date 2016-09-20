#include <stdio.h>

#define BITSELECT(x,n) ((x>>n)&1)

int main(int argc, char* argv[]){
	int x = 4;
	int n = 2;
	int bit = BITSELECT(x,n);
	printf("bit %d in %d: %d\n", n, x, bit);
	
	return 0;
}
