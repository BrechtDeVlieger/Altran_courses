#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	for(int i = 1; i < argc; i ++){
		printf("%s: %lu\n", argv[i], strlen(argv[i]));
	}
	return 0;
}
