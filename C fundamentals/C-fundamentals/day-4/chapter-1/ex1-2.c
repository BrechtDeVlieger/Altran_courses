#include <stdio.h>

#define SWAP(t,x,y) do{t tmp=x; x=y; y=tmp;}while(0)

int main(int argc, char* argv[]){
	int x = 4;
	int y = 5;
	SWAP(int,x,y);
	printf("x: %d\ny: %d\n", x, y);
	
	return 0;
}
