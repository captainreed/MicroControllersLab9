#ifndef USARTHANDLER_H
#define USARTHANDLER_H
#include "stm32l476xx.h"

void UsartInit();
void UsartWrite(uint8_t letter);
uint8_t UsartRead();

#endif