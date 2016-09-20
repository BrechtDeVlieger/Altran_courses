#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct relative_time {
	int days;
	int hours;
	int minutes;
	int seconds;
};

typedef struct relative_time relTime;

relTime* build_rt(){
	relTime rt = {0,0,0,0};
	relTime* rt_ptr = malloc(sizeof(relTime));
	*rt_ptr = rt;
	return rt_ptr;
}

void make_valid(relTime* ptr){
	assert(ptr->days >= 0);
	assert(ptr->hours >= 0);
	assert(ptr->minutes >= 0);
	assert(ptr->seconds >= 0);
	ptr->minutes += ptr->seconds/60;
	ptr->seconds %= 60;
	ptr->hours += ptr->minutes/60;
	ptr->minutes %= 60;
	ptr->days += ptr->hours/24;
	ptr->hours %= 24;
}

void assign_rt(relTime* ptr, int d, int h, int m, int s){
	ptr->days = d;
	ptr->hours = h;
	ptr->minutes = m;
	ptr->seconds = s;
	make_valid(ptr);
}

relTime* add_rt(relTime* ptr1, relTime* ptr2){
	relTime* sum = build_rt();
	sum->days = ptr1->days + ptr2->days;
	sum->hours = ptr1->hours + ptr2->hours;
	sum->minutes = ptr1->minutes + ptr2->minutes;
	sum->seconds = ptr1->seconds + ptr2->seconds;
	make_valid(sum);
	return sum;
}

void print_rt(relTime* ptr){
	printf("Day: %d | Time: %02d:%02d:%02d\n", ptr->days, ptr->hours, ptr->minutes,
			ptr->seconds);
}

int main(int argc, char* argv[]){
	relTime* rt_ptr2 = build_rt();
	relTime* rt_ptr1 = build_rt();
	assign_rt(rt_ptr1, 2, 12, 36, 6);
	assign_rt(rt_ptr2, 4, 3, 19, 48);
	relTime* sum = add_rt(rt_ptr1, rt_ptr2);
	print_rt(sum);
	free(rt_ptr1);
	free(rt_ptr2);
	free(sum);
	return 0;
}
