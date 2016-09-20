#include <stdio.h>

#define STR(s) #s

int main(int argc, char* argv[]){
	printf("%s\n", STR(__LINE__));
	
	return 0;
}
