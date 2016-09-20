#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int upperbound, lowerbound;
	int attempts = 0;
	int randnr;
	int range;
	printf("Give upper bound\n");
	fscanf(stdin, "%d", &upperbound);
	printf("Give lower bound\n");
	fscanf(stdin, "%d", &lowerbound);
	range = upperbound - lowerbound;
	randnr = rand()&(range+1) + lowerbound;
	int guess;
	printf("Guess the number\n");
	do {
		attempts ++;
		fscanf(stdin, "%d", &guess);
		if(guess == randnr){
			printf("Correct! %d attempts\n", attempts);
		} else if(guess < randnr){
			printf("Higher!\n");
		} else {
			printf("Lower!\n");
		}
	} while (guess != randnr);
	
	return 0;
}
	
