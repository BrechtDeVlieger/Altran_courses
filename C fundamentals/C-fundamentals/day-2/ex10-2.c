#include <stdlib.h>
#include <stdio.h>

int add_hours(const int first, const int second){
	return (first + second)%24;
}

void is_valid(const int entry){
	if(entry < 0 || entry > 23){
		printf("Invalid entry\n");
		exit(1);
	}
}

int main(int argc, char* argv[]){
	if(argc != 3){
		printf("Invalid number of arguments (three required)!\n");
		return 1;
	}
	int first = strtol(argv[1], NULL, 10);
	int second = strtol(argv[2], NULL, 10);
	is_valid(first);
	is_valid(second);
	printf("The sum is %dh\n", add_hours(first, second));

	return 0;
}
