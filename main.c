#include "stm32l476xx.h"
#include "UsartHandler.h"
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
UsartWrite(&output);
NVIC_ClearPendingIRQ(USART2_IRQn);
}


int main(void){
UsartInit();
	while(1)
	{
	}
}
