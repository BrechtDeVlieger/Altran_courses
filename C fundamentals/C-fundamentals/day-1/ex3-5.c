#include <string.h>
#include <stdio.h>

int make_upper(char a){
	if(a >= 'a'){
		a -= ('a'-'A');
	}
	return a;
}

int is_palindrome(char *word){
	int length = strlen(word);

	int still_ok = 1;
	for(int i = 0; i < length/2; i++){
		printf("%d, %d\n",make_upper(word[i]), make_upper(word[length-1-i]));
		if(make_upper(word[i]) != make_upper(word[length-1-i])){
			still_ok = 0;
			break;
		}
	}
	return still_ok;
}

int main(int argc, char *argv[]){
	for(int i = 1; i < argc; i++){
		if(is_palindrome(argv[i])){
			printf("%s is a palindrome\n", argv[i]);
		} else {
			printf("%s is not a palindrome\n", argv[i]);
		}
	return 0;
	}
}
