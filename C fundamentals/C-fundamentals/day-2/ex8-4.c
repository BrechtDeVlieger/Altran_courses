#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_vowel(const char letter){
	char vowels[] = {'a', 'e', 'i', 'u', 'y', 'o'};
	for(int i = 0; i < 6; i++){
		if(letter == vowels[i]){
			return 1;
		}
	}
	return 0;
}

char* word_to_PL(const char* word){
	char* pl_word;
	if(is_vowel(word[0])){
		pl_word = strcat(pl_word, word);
		pl_word = strcat(pl_word, "way");
	} else {
		pl_word = strcat(pl_word, word+1);
		pl_word = strcat(pl_word, word[0]);
		pl_word = strcat(pl_word, "ay");
	}
	return pl_word;
}

int main(int argc, char* argv[]){
	if(argc < 2){
		printf("Too few arguments\n");
		return 1;
	}

	for(int i = 1; i < argc; i++){
		printf("%s ", word_to_PL(argv[i]));
	}
	printf("\n");

	return 0;
}
