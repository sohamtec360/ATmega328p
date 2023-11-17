/*
 * system_init.c
 *
 * Created: 11/14/2023 11:03:40 PM
 *  Author: Soham
 */ 

#include <avr/io.h>

#include "Decleration.h"

void board_init(){
	DDRB = 0X0F;			//(1<<DDD0) | (1<<DDD1) | (1<<DDD2) | (1<<DDD3);
	PORTB = 0X0F;			//~((1<<PORTD0) | (1<<PORTD1) | (1<<PORTD2) | (1<<PORTD3));
	
	DDRD = 0XFF;
	PORTD = 0XFF;			//All PORTD PIN is output for seven segment
	
	DDRC &= ~((1<<DDC0) | (1<<DDD1));	//external interrupt
	PORTC |= (1<<PORTC0) | (1<<PORTC1);
}

void timer_init(){
	TCCR0A &= ~((1<<WGM00) | (1<<WGM01));		//initialized for normal mode of operation
	TCCR0B &= ~(1<<WGM02);
	TCCR0B |= (1<<CS00) | (1<<CS02);			//1024 prescaler
	TIMSK0 |= (1<<TOIE0);						//timer local interrupt enabled
	TCNT0 = 100;								//timer count
}

void PIN_change_Int(){
	PCICR |= (1<<PCIE1);			//enabling this pin for pin change
	PCMSK1 |= (1<<PCINT0) | (1<<PCINT1);			//pin change interrupt is enabled on port c pin 0
}

void ADC_init(){
	ADCSRA |= (1<<ADEN)|(1<<ADIE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);		//ADC module is power up, interrupt enabled, pr-scaler select
	ADMUX &= ~((1<<REFS0) | (1<<REFS1));								//ADC reference voltage select
	ADMUX |= (1<<MUX1);													//ADC channel 1 is selected
	ADCSRA |= (1<<ADATE);
	ADCSRB |= (1<<ADTS2);
	ADCSRA |= (1<<ADSC);
}
