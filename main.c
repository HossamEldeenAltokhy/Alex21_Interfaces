/*
 * File:   main.c
 * Author: hossa
 *
 * Created on September 24, 2021, 11:18 AM
 */



#include <avr/io.h>
#include <avr/interrupt.h>
#include "config.h"
#include "mLCD_4bit.h"
#include "mKeypad.h"
#include "mExternalInterrupt.h"
#include "mADC.h"

char unit[] = " mV";


ISR(ADC_vect){
    // When ADC finish Conversion
    int data = ADC_read()* 4.887585532746823069403714565;
    LCD_CLEAR_4bit();
    LCD_Write_Num_4bit(data);
    LCD_Write_Str_4bit(unit);
    // READING.....
    ADC_StartConv();
}

int main(void) {
    /* Replace with your application code */

    init_ADC(0x10, _AVCC, _PS128);
    ADC_init_INTERRUPT();
    init_LCD_4bit();
    _delay_ms(100);
    sei();
    ADC_StartConv();
    while (1) {

        
//        int data = ADC_read()* 4.887585532746823069403714565;
//        LCD_CLEAR_4bit();
//        LCD_Write_Num_4bit(data);
//        LCD_Write_Str_4bit(unit);
        _delay_ms(500);
       
    }
    return 0;
}
