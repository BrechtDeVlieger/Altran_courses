/*
 * main.c
 *
 *  Created on: 14 Feb 2013
 *      Author: Maxime Vincent
 * Description: Framework to get a LED to blink
 *
 *     Purpose: Purpose is to demonstrate the configuration of a peripheral
 *              on the STM32F4 MCU
 *
 *     Context: Written in the context of the Embedded C course by TASS Belgium.
 */

/* Includes */
#include <stdint.h>
#include "main.h"
#include "stm32f4xx.h"

static void delay(void);

/* main C entry point - should never return */
void main(void)
{
    /* Enable peripheral clocks */
    RCC->AHB1ENR|=RCC_AHB1ENR_GPIODEN;

    /* Configure pins */
    GPIOD->MODER|=GPIO_MODER_MODER15_0;
    GPIOD->MODER|=GPIO_MODER_MODER14_0;
    GPIOD->MODER|=GPIO_MODER_MODER13_0;
    GPIOD->MODER|=GPIO_MODER_MODER12_0;
    /* Set GPIO Mode */
    /* Set GPIO Output type */

    while (1)
    {
        static uint8_t led_val = 0;

        /* toggle the led */
        if (led_val)
        {
            led_val = 0;
	    GPIOD->BSRRL = 0xFFFF;
        }
        else
        {
            led_val = 1;
	    GPIOD->BSRRH = 0xFFFF;
        }
	

        /* wait a bit */
        delay();
    }
}

static void delay(void)
{
    uint32_t i = 0;
    while (i < 3200000) /* waste some clocks */
    { i++; }
}
