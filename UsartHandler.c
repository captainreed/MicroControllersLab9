#include "UsartHandler.h"
#include "stm32l476xx.h"

uint8_t inputbuffer;

void UsartInit()
{
USART2->CR1 &= ~USART_CR1_UE; // dissable usart
USART2->CR1 &= ~USART_CR1_M; // set to be 8 bit message
USART2->CR2 &= ~USART_CR2_STOP; //set to be 1 stop bit
USART2->CR1 &= ~USART_CR1_PCE; //set parity
USART2->CR1 &= ~USART_CR1_OVER8; // set oversampling
USART2->BRR =  0x208D; // set baud rate
USART2->CR1 |= (USART_CR1_TE | USART_CR1_RE);//enable transmission and reception
USART2->CR1 |= USART_CR1_UE;//enable usart
while ((USART2->ISR & USART_ISR_TEACK) == 0)
	{
		
	}
while ((USART2->ISR & USART_ISR_REACK) == 0)
	{
		
	}
}

void UsartWrite(uint8_t letter)
{
	while(!(USART2->ISR & USART_ISR_TXE));//wait for the transmission empty flag
	USART2->TDR = letter & 0xFF;

	while(!(USART2->ISR & USART_ISR_TC));//wait until the input status register is cleared
	USART2->ICR |= USART_ICR_TCCF;
	
}

uint8_t UsartRead()
{
	while(!(USART2->ISR & USART_ISR_RXNE));
	inputbuffer = USART2->RDR;
	return inputbuffer;
}
