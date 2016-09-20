#include <stdio.h>
#include <stdlib.h>

enum colors{
	COLOR_RED,
	COLOR_GREEN,
	COLOR_BLUE,
	COLOR_MAX,
}

char* COLORS_to_text(const int color){
	assert(color < COLOR_MAX);
	assert(color >= COLOR_RED);
	switch(color){
		case COLOR_RED:
			return "Red";
			break;

		case COLOR_GREEN:
			return "Green";
			break;

		case COLOR_BLUE:
			return "Blue";
			break;

		case default:
			printf("Invalid entry");
			exit();
	}
}

int main(int argc, char* argv[]){
	
