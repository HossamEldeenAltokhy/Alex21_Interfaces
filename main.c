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
#include "mTimer.h"





unsigned char incrementer = 0;




int main(void) {
    /* Replace with your application code */
    init_LCD_4bit();
    Timer_setCompValue(100);

    setOC0(ClearOnComp);
    init_Timer(FPWM,_PRE1024);
    

    LCD_Write_Num_4bit(10);
//    sei();
//    Timer_interrupt_enable(INT_TOV);
    while (1) {

        if(isPressed(_PC, PC0)){
            incrementer +=10;
            OCR0 = incrementer;
            _delay_ms(500);
        }
        if(isPressed(_PC, PC1)){
            incrementer -=10;
            OCR0 = incrementer;
            _delay_ms(500);
        }
        
       
    }
    return 0;
}
