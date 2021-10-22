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





unsigned char incrementer = 100;
unsigned char dutyCycle;



int main(void) {
    /* Replace with your application code */
    init_LCD_4bit();
    Timer_setCompValue(100);
    dutyCycle = OCR0*100/255;
    setOC0(ClearOnComp);
    init_Timer(PWM,_PRE1024);
    

    LCD_Write_Num_4bit(dutyCycle);
    LCD_DATA_4bit('%');
    
//    sei();
//    Timer_interrupt_enable(INT_TOV);
    while (1) {

        if(isPressed(_PC, PC0)){
            incrementer +=10;
            Timer_setCompValue(incrementer);
            dutyCycle = incrementer *100/255;
            LCD_CLEAR_4bit();
            LCD_Write_Num_4bit(dutyCycle);
            LCD_DATA_4bit('%');
            _delay_ms(500);
        }
        if(isPressed(_PC, PC1)){
            incrementer -=10;
            Timer_setCompValue(incrementer);
            dutyCycle = incrementer *100/255;
            LCD_CLEAR_4bit();
            LCD_Write_Num_4bit(dutyCycle);
            LCD_DATA_4bit('%');
            _delay_ms(500);
        }
        
       
    }
    return 0;
}
