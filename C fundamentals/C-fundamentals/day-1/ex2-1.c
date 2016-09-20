#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert_to_int(char *argument){
	int output = 0;
	if(argument[0] == '0'){
		if(argument[1] == 'x' || argument [1] == 'X'){
			output = (int)strtol(argument, NULL, 16);
		}
		else{
			output = (int)strtol(argument, NULL, 8);
		}
	}
	else{
		output = atoi(argument);
	}
	return output;
}


int main(int argc, char *argv[]){
	char operator = *argv[1];
	int result = 0;
	if(argc < 4){
		printf("Too few arguments");
		return 1;
	}
	if(strlen(argv[1]) > 1){
		printf("Operator should be a single character");
		return 1;
	}
	switch(operator){
		case '+':
			result = convert_to_int(argv[2]);
			for(int i = 3; i < argc; i++){
				result += convert_to_int(argv[i]);
			}
			break;

		case '-':
			result = convert_to_int(argv[2]);
			for(int i = 3; i < argc; i++){
				result -= convert_to_int(argv[i]);
			}
			break;

		case '*':
			result = convert_to_int(argv[2]);
			for(int i = 3; i < argc; i++){
				result *= convert_to_int(argv[i]);
			}
			break;

		case '/':
			result = convert_to_int(argv[2]);
			for(int i = 3; i < argc; i++){
				int j = convert_to_int(argv[i]);
				if(j != 0){
					result /= convert_to_int(argv[i]);
				}
				else{
					printf("Divide by zero!\n");
					return 1;
				}
			}
			break;

		case '%':
			result = convert_to_int(argv[2]);
			for(int i = 3; i < argc; i++){
				result %= convert_to_int(argv[i]);
			}
			break;

		default:
			printf("Invalid operator\n");
			return 1;
	}
	printf("%d\n", result);
	return 0;
}

