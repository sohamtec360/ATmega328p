/*
 * adc.c
 *
 * Created: 11/13/2023 4:27:43 PM
 * Author : Soham
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU	16000000ul
#include <util/delay.h>

#include "Decleration.h"

int main(void)
{	
	sei();					//global interrupt is enabled

	board_init();
	timer_init();
	PIN_change_Int();
	ADC_init();
	
    while (1) 
    {

	}
}

ISR(TIMER0_OVF_vect)
{
	Timer_Int_Handler();
}
ISR(PCINT1_vect){
	PIN_Cheint_Handler();
}
ISR(ADC_vect){
	ADC_int_Handler();
}