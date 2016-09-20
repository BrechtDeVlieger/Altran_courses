#include <stdio.h>

#define IS_UPPER_CASE(c) ((c>=65 && c<=90)?"yes":"no")

int main(int argc, char* argv[]){
	char c = 'Z'+1;
	printf("Is '%c' upper case? %s\n", c, IS_UPPER_CASE(c));
	
	return 0;
}
