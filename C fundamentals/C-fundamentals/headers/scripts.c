#include "scripts.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void* ask_input(const char* text, const char* format){
	int flag;
	void* ptr = NULL;
	if(strcmp(format, "%d")){
		printf("Give an integer number\n");
		(int*)ptr = malloc(sizeof(int));
	
	} else if(strcmp(format, "%f")){
		printf("Give a double number\n");
		(double*)ptr = malloc(sizeof(double));
	
	} else if(strcmp(format, "%c")){
		printf("Give a character\n");
		(char*)ptr = malloc(sizeof(char));
	
	} else if(strcmp(format, "%s")){
		printf("Give a string (max 100 characters)");
		(char*)ptr = malloc(sizeof(char));

	} else {
		printf("Not a valid format given");
		ptr = NULL;
		return ptr;
	}
	
	void* ptr = NULL;
	flag = printf("%s\n", text);
	assert(flag >= 0);

	flag = fscanf(stdin, format, ptr);
	assert(flag == 1);
	return ptr;
}

