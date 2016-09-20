#include <stdio.h>

int stringcmp(char* first, char* second){
	int i = 0;
	while( (first[i] != 0) && (second[i] != 0) ){
		if(first[i] != second[i]){
			return 0;
		}
		i++;
	}
	if(first[i] == second[i]){
		return 1;
	} else {
		return 0;
	}
}

int main(int argc, char* argv[]){
	if(argc != 3){
		printf("Invalid number of arguments (2 required)\n");
		return 1;
	}

	printf("These words are %s equal\n", (stringcmp(argv[1], argv[2]) ? "" : "not"));
	return 0;
}
