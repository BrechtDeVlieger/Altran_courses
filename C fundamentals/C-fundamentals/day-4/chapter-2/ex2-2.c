#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>

char* concatenate(char* arg1, ...){
	va_list ap;
	va_list aq;
	va_copy(aq, ap);
	va_start(ap, arg1);
	char* word;
	int length = strlen(arg1);
	while(strcmp(word = va_arg(ap, char*),"\0")){
		length += strlen(word);
	}
	va_end(ap);

	char* ptr = malloc(sizeof(char)*(length+1));
	assert(ptr != NULL);

	va_start(aq, arg1);
	strcpy(ptr, arg1);
	while(strcmp(word = va_arg(aq, char*),"\0")){
		ptr = strcat(ptr, word);
	}
	va_end(aq);

	return ptr;
}

char* concatenate1(char* arg1, ...){
	va_list ap;
	va_start(ap, arg1);
	char* word;
	int length = strlen(arg1);
	char* ptr = malloc(sizeof(char)*(length+1));
	char* newptr = NULL;
	strcpy(ptr, arg1);
	while(strcmp(word = va_arg(ap, char*),"\0")){
		length += strlen(word);
		newptr = realloc(ptr, sizeof(char)*(length+1));
		assert(newptr!=NULL);
		ptr = newptr;
		ptr = strcat(ptr, word);
	}
	va_end(ap);

	return ptr;
}

int main(int argc, char* argv[]){
	char* word = concatenate1("Brecht", "De", "Vlieger", "\0");
	printf("Tot chars: %s\n", word);
	free(word);
	return 0;
}
