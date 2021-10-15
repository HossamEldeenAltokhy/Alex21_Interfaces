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
int main(void) {
    /* Replace with your application code */


   
   
    init_ADC(ADC1, _AREF, _PS128);
    init_LCD_4bit();
    _delay_ms(100);
    
    while (1) {

        ADC_StartConv();
        int data = ADC_read()* 4.8828125;
        LCD_CLEAR_4bit();
        LCD_Write_Num_4bit(data);
        LCD_Write_Str_4bit(unit);
        _delay_ms(500);
       

    }
    return 0;
}
