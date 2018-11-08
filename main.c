#include "stm32l476xx.h"
#include "UsartHandler.h"
char input;
uint8_t output;
uint8_t buffer[10];

uint8_t lowerToUpper()
{
	return buffer[0] - 32;//the hex value of 23 is 0x20
}


void USART2_IRQHandler(void)
{
UsartRead();
output = lowerToUpper();
UsartWrite(output);
}


int main(void){
RCC->AHB2ENR |= RCCAHB2ENR_GPIODEN;// PD5 PD6
GPIOD->MODER &= ~(GPIO_MODER_MODER5_0 | GPIO_MODER_MODER5_1 | GPIO_MODER_MODER6_0 | GPIO_MODER_MODER6_1);//clear bits
GPIOD->MODER |= (GPIO_MODER_MODER5_1 | GPIO_MODER_MODER6_1);//set to alt function
GPIOD->AFR[0] |= 0x07700000;// set the pins to right alt function
GPIOD->OSPEEDER |= (GPIO_OSPEEDER_OSPEEDR5_0 | GPIO_OSPEEDER_OSPEEDR5_1 | GPIO_OSPEEDER_OSPEEDR6_0 | GPIO_OSPEEDER_OSPEEDR6_1);// set to fast?
GPIOD->PUPDR &= ~(GPIO_PUPDR_PUPDR5_0 | GPIO_PUPDR_PUPDR5_1 | GPIO_PUPDR_PUPDR6_0 | GPIO_PUPDR_PUPDR6_1);//clear bits
GPIOD->PUPDR |= (GPIO_PUPDR_PUPDR5_0 | GPIO_PUPDR_PUPDR6_0);//select pull up
GPIOD->OTYPER &= ~(GPIO_OTYPER_OT_5 | GPIO_OTYPER_OT_6);// set to push pull?
UsartInit();

	while(1)
	{

	}
}
