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
#include "stm32f4xx.h"
#include "main.h"

/* Defines */
#define EVER        (;;)

/* Prototypes */
int main(void);

void TIM2_IRQHandler(void);
void INTTIM_Config(void);
void GPIO_Config(void);

/* main C entry point */
int main(void)
{
    int i=0;

    // GPIOD INIT
    GPIO_Config();
    // TIMER2 INIT
    INTTIM_Config();

    for EVER
    {
        // regular task processing here
        i++;
    }
}


void GPIO_Config(void)
{
    /* RCC clock config */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    /*-------------------------- GPIO Configuration ----------------------------*/
    /* GPIOD Configuration: Pins 12, 13, 14 and 15 in output push-pull          */
    /*-------------------------- GPIO Configuration ----------------------------*/
    /* GPIOD Configuration: Pins 12, 13, 14 and 15 in output push-pull          */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure = { 0 };
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 |
                                  GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    GPIO_ToggleBits(GPIOD, GPIO_Pin_13 | GPIO_Pin_15);
}
void TIM2_IRQHandler(void)
{
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    GPIO_ToggleBits(GPIOD, GPIO_Pin_13 | GPIO_Pin_15);

}
void INTTIM_Config(void)
{
    //NVIC IRQ Channel init (Channel, priority, enable)
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 5;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

    NVIC_Init(&NVIC_InitStructure);
    //RCC APB1 enable (TIM2ENR)
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    // TIM init
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_Prescaler=42000-1;
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_Period=2000-1;
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
    // TIM period, prescaler, clock div, counter mode
    // TIM IT enable
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
    
    TIM_ITConfig(TIM2, TIM_EventSource_Update,  ENABLE);
    // TIM enable
    TIM_Cmd(TIM2, ENABLE);
}

