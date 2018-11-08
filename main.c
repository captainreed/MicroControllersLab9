#include "stm32l476xx.h"
#include "UsartHandler.h"
char input;
uint8_t output;
uint8_t buffer;

uint8_t lowerToUpper()
{
	return buffer - 32;//the hex value of 23 is 0x20
}


void USART2_IRQHandler(void)
{
UsartRead(&buffer);
output = lowerToUpper();
UsartWrite(output);
NVIC_ClearPendingIRQ(USART2_IRQn);
}


int main(void){
RCC->AHB2ENR |= RCCAHB2ENR_GPIODEN;// PD5 PD6
GPIOD->MODER &= ~;//clear bits
GPIOD->MODER |= ;//set to alt function
GPIOD->AFR[0] |= ;// set the pins to right alt function
GPIOD->OSPEEDER |= ;// set to fast?
GPIOD->PUPDR &= ~ ;//clear bits
GPIOD->PUPDR |= ;//select pull up
GPIOD->OTYPER &= ~;// set to push pull?
UsartInit();
	while(1)
	{

	}
}
