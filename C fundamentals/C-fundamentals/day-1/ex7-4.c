#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
	int list[1000];
	for(int i = 0; i < 1000; i++){
		list[i] = rand()%10000;
	}

	int count = 0;
	for(int i = 0; i < 10000; i++){
		count = 0;
		for(int j = 0; j < 10000; j++){
			if(list[j] == i){
				count++;
				if(count >=2){
					printf
