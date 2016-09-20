#include <stdio.h>

int stringlen(char* word){
	char* ptr = word;
	int length = 0;
	while(*ptr != 0){
		length++;
		ptr++;
	}
	return length;
}

int main(int argc, char* argv[]){
	char* word = "Brecht";
	int length = stringlen(word);
	printf("%d\n", length);
	return 0;
}
