#include <string.h>
#include <stdio.h>
#include <math.h>

int is_armstrong(int number){
	int sum = 0;
	int numbercpy = number;
	int n = 0;
	while(numbercpy > 0){
		n = pow((numbercpy%10),3);
		sum += n;
		numbercpy /= 10;
	}
	//printf("%d: %d\n", number, sum);
	if(sum == number){
		return 1;
	}
	else{
		return 0;
	}
}

int main(int argc, char *argv[]){
	for(int i = 0; i < 1000; i++){
		if(is_armstrong(i)){
			printf("%d\n", i);
		}
	}
	return 0;
}
