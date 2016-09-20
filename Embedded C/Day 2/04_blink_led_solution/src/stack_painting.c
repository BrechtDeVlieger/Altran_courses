#include <stdint.h>
#include <stm32f4xx.h>

void stack_painting(void){
	uint32_t* estack = __get_MSP();
	estack--;
	uint32_t value = 0xBEEFCAFE;
	while(estack > 0x20010000){
		*(estack) = value;
		estack--;
	}
}
