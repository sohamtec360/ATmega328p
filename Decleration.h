/*
 * Decleration.h
 *
 * Created: 11/13/2023 10:27:22 PM
 *  Author: Soham
 */ 


#ifndef DECLERATION_H_
#define DECLERATION_H_

unsigned int Digit_Val[4];			//hgfe dcba
unsigned int Digit_EN[4];
unsigned int Digit[10];
unsigned int i;
int j;
unsigned int ch_count, ch_no, ADC_val;				//ACD channel count, channel number

void board_init(void);

void timer_init(void);
void ADC_init(void);
void PIN_change_Int(void);

void Timer_Int_Handler(void);
void PIN_Cheint_Handler(void);
void ADC_int_Handler(void);

#endif /* DECLERATION_H_ */