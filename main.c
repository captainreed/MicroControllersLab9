#include "stm32l476xx.h"
#include "UsartHandler.h"
#include "LCD.h"
char input;
uint8_t output;
uint8_t buffer;

uint8_t lowerToUpper(uint8_t charIn)
{
	if(charIn > 96 && charIn < 123)
	{
	return charIn - 32;//the hex value of 23 is 0x20
	}
	else
	{
		return 0;
	}
}


void USART2_IRQHandler(void)
{
buffer = UsartRead();
output = lowerToUpper(buffer);
LCD_DisplayString((uint8_t*) "O");
UsartWrite(output);
NVIC_ClearPendingIRQ(USART2_IRQn);//need to clear the interrupt flag here
}


int main(void){
LCD_Initialization();
RCC->AHB2ENR |= RCC_AHB2ENR_GPIODEN;// PD5 PD6
GPIOD->MODER &= ~(GPIO_MODER_MODER5_0 | GPIO_MODER_MODER5_1 | GPIO_MODER_MODER6_0 | GPIO_MODER_MODER6_1);//clear bits
GPIOD->MODER |= (GPIO_MODER_MODER5_1 | GPIO_MODER_MODER6_1);//set to alt function
GPIOD->AFR[0] |= (GPIO_AFRL_AFSEL5_0 | GPIO_AFRL_AFSEL5_1 | GPIO_AFRL_AFSEL5_2 | GPIO_AFRL_AFSEL6_0 | GPIO_AFRL_AFSEL6_1 | GPIO_AFRL_AFSEL6_2);// set the pins to right alt function
GPIOD->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR5_0 | GPIO_OSPEEDER_OSPEEDR5_1 | GPIO_OSPEEDER_OSPEEDR6_0 | GPIO_OSPEEDER_OSPEEDR6_1);// set to fast?
GPIOD->PUPDR &= ~(GPIO_PUPDR_PUPDR5_0 | GPIO_PUPDR_PUPDR5_1 | GPIO_PUPDR_PUPDR6_0 | GPIO_PUPDR_PUPDR6_1);//clear bits
GPIOD->PUPDR |= (GPIO_PUPDR_PUPDR5_0 | GPIO_PUPDR_PUPDR6_0);//select pull up
GPIOD->OTYPER &= ~(GPIO_OTYPER_OT_5 | GPIO_OTYPER_OT_6);// set to push pull?
RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN;
RCC->CCIPR &= ~RCC_CCIPR_USART2SEL;
RCC->CCIPR |= RCC_CCIPR_USART2SEL_0;
UsartInit();

LCD_DisplayString((uint8_t*) "test");
	while(1)
	{
		//LCD_DisplayString((uint8_t*) "N");
		//UsartWrite((uint8_t)'M');
		//UsartWrite((uint8_t)'A');//this line was for testing masking of usartwrite
		//UsartRead();
		//LCD_DisplayString((uint8_t*) "W");
	}
}
