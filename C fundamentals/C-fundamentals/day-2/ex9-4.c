#include <stdio.h>
#include <stdlib.h>

double c2k(const double celsius){
	return celsius + 273.15;
}

double f2c(const double fahrenheit){
	return (fahrenheit - 32) * 5 / 9;
}

int main(int argc, char *argv[]){
	double f = 120.0;
	double c = 25.0;

	printf("%f degrees fahrenheit -> %f Kelvin\n", f, c2k(f2c(f)));
	printf("%f degrees celsius -> %f Kelvin\n", c, c2k(c));
	return 0;
}
