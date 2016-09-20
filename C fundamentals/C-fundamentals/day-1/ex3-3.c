#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	for(int i = 1; i < argc; i++){
		int index = 0;
		while(*(argv[i] + index) != '\0'){
			if(*(argv[i]+index) >= 'a'){
				*(argv[i]+index)-=('a'-'A');
			}
			index ++;
		}
		printf("%s\n", argv[i]);
	}
	return 0;
}
