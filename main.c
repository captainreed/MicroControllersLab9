#include "PiezoBuzzer.h"
#include "stm32l476xx.h"
#include "waveGenerator.h"

//new files:
//readADC.c
//waveGenerator.c this is where the interrupts will be initiated

void TIM2_IRQHandler()
{
NVIC_ClearPendingIRQ(TIM2_IRQn);// clear the pending flag every time the function is used
}
//interupt 1
/*
configure to be triggered every 500 ms
find average of ADC array
adcValue = average of the array
newFreq = math.floor(100 + 900*(adcValue/maxADCValue))
clear the array
call setFreq(newFreq)

*/
void TIM3_IRQHandler()
{
NVIC_ClearPendingIRQ(TIM3_IRQn);// clear the pending flag every time the function is used

}
//interupt 2
/*
set the interupt to be triggered every 2 ms

read the ADC
store ADC value in array
*/

void TIM4_IRQHandler()
{
NVIC_ClearPendingIRQ(TIM4_IRQn);// clear the pending flag every time the function is used

}
//interupt 3
/*
set the new output value for the DAC
*/


int main(void){
	
	initBuzzer();
	configInterupts();

	while(1)
	{

	}
	
	
	
}
