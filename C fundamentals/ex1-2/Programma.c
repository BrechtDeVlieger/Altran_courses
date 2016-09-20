#include <stdio.h>

int main(int argc, char *argv[]){
	if (argv[0]){
		printf("%s\n", argv[2:]);
	}
	return 0;
}
