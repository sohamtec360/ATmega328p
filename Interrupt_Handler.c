/*
 * Interrupt_Handler.c
 *
 * Created: 11/14/2023 11:07:05 PM
 *  Author: Soham
 */ 


#include <avr/io.h>

#include "Decleration.h"

void Timer_Int_Handler(){
	PORTB |= 0X0F;
	PORTD = Digit_Val[i];
	PORTB &= Digit_EN[i];
	
	i++;
		
	if (i==4){
		i=0;
	}
	TCNT0 = 100;
}

void PIN_Cheint_Handler(){
	if (!(PINC&(1<<PINC0))){	
		ch_count++;
		ADMUX = ((1<<MUX0)|(1<<MUX1));
	}
	
	if (!(PINC&(1<<PINC1))){
		ch_no++;
		ADMUX = (1<<MUX1);
	}
	
}

void ADC_int_Handler(){
	ADC_val = ADCL;
	ADC_val |= (ADCH<<8);
	
	for (j=3; j>=0; j--)
	{
		Digit_Val[j] = Digit[ADC_val%10];
		ADC_val=ADC_val/10;
	}
	
}