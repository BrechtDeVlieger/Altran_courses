#include <stdio.h>

#define MIN2(x,y) (x<y?x:y)
#define MIN3(x,y,z) (z<MIN2(x,y)?z:MIN2(x,y))

int main(int argc, char* argv[]){
	int x = 4;
	int y = 6;
	int z = 1;
	printf("smallest of %d and %d: %d\n", x, y, MIN2(x,y));
	printf("smallest of %d, %d and %d: %d\n", x, y, z, MIN3(x,y,z));
	
	return 0;
}
