/*
 * main.c
 *
 *  Created on: 14 Feb 2013
 *      Author: Maxime Vincent
 * Description: Virtually the most simple demo that can be run on an ARM MCU.
 *              The target is barely running - all clocks are off, the core is
 *              just executing a few simple instructions.
 *
 *     Purpose: Purpose is to demonstrate an openocd-gdb setup to flash and 
 *              step through code on the target.
 *
 *     Context: Written in the context of the Embedded C course by TASS Belgium.
 */

/* Includes */
#include "main.h"
#include <stdint.h>
#include <math.h>
#include "stm32f4xx.h"

/* Defines */
#define EVER        (;;)

void fast_increment(uint32_t * i);
void fast_calc(void);
/* main C entry point - should never return */
void main(void)
{
    RCC->AHB1ENR|=RCC_AHB1ENR_GPIODEN;

    /*Configure pins */
    GPIOD->MODER|=GPIO_MODER_MODER15_0;
    GPIOD->MODER|=GPIO_MODER_MODER14_0;
    GPIOD->MODER|=GPIO_MODER_MODER13_0;
    GPIOD->MODER|=GPIO_MODER_MODER12_0;
    uint32_t i=0;
    uint32_t result;
    int led_val = 0;

    for EVER
    {
	if(led_val){
	    led_val = 0;
	    GPIOD->BSRRL = 0xFFFF;
	}
	else {
	    led_val = 1;
	    GPIOD->BSRRH = 0xFFFF;
	}
        i++;
        fast_calc();
    }
}

__attribute__ ((section (".fastcode"))) 
void fast_increment(uint32_t * i)
{
    (*i)++;
}

//__attribute__ ((section (".fastcode"))) 
void fast_calc(void){
	float i = 6.2;
	int j = 0;
	float k;
	for(j = 0; j < 100000; j++){
		k = sinf(i);
	}
}
