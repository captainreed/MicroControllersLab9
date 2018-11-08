#include "stm32l476xx.h"
#include "UsartHandler.h"
uint8_t output;
uint8_t buffer[10];

uint8_t lowerToUpper()
{
	return buffer[0] - 32;//the hex value of 23 is 0x20
}


void USART2_IRQHandler(void)
{
UsartRead(buffer);
output = lowerToUpper();
UsartWrite(&output);
}


int main(void){
UsartInit();

	while(1)
	{
	}
}
