/* 
 * File:   mADC.h
 * Author: hossa
 *
 * Created on October 9, 2021, 1:24 PM
 */

#ifndef MADC_H
#define	MADC_H



void init_ADC(int ch, int ref, int prescaler);
// ADMUX
// ADCSRA
void ADC_StartConv();

int ADC_read();

// ADCSRA   >> ADIF  -- Interrupt 

//while(!(ADCSRA & (1<<ADIF)));

#endif	/* MADC_H */

