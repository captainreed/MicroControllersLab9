#ifndef USARTHANDLER_H
#define USARTHANDLER_H
#include "stm32l476xx.h"

void UsartInit();
void UsartWrite(uint8_t *letter);
void UsartRead(uint8_t *thebuffer);

#endif