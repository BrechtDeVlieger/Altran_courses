#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int decimal;
	int hexadecimal;
	int c;
	char final;
	opterr = 0;

	while((c = getopt(argc, argv, "d:h:")) != 1)
		switch (c)
		{
			case 'd':
				decimal = strtol(optarg, NULL, 10);
				printf("%d -> %#x\n", decimal, decimal);
				final = 'd';
				break;
			case 'h':
				hexadecimal = strtol(optarg, NULL, 16);
				printf("%#x -> %d\n", hexadecimal, hexadecimal);
				final = 'h';
				break;
			default:
				printf("done\n");
		}

	printf("test");
	return 0;
}
