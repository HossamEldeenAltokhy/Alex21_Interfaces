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


int main(void) {
    /* Replace with your application code */


   
   
    init_ADC(_ch1, _AREF, _Pre128);
    init_LCD_4bit();
    while (1) {

        ADC_StartConv();
        int data = ADC_read();
        LCD_CLEAR_4bit();
        LCD_Write_Num_4bit(data);
        _delay_ms(500);
       

    }
    return 0;
}
