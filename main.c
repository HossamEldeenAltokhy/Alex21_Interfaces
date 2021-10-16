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

#define sec   5
#define min   0

ISR(TIMER0_COMP_vect){
    static int x = 0; 
    x++;
    
    PORTC = x;
   _delay_ms(50);
    if(x  == 255){
        x = 0;
    }
    
//    togglePortData(_PC);
    
}



int main(void) {
    /* Replace with your application code */


    setPortData(_PC, OUT);
    
    setPinDir(_PD, PD0, IN);
    setPinDir(_PD, PD1, IN);

    _delay_ms(200);
    init_Timer(CTC, _PRE1024);
    Timer_setCompValue(200);
    Timer_interrupt_enable(INT_TOC);
    

    sei();
    int setOCR = 200;
    while (1) {
        if(isPressed(_PD, PD0)){
            setOCR+=10;
            Timer_setCompValue(setOCR);
           _delay_ms(200); 
        }
        if(isPressed(_PD, PD1)){
            setOCR-=10;
            Timer_setCompValue(setOCR);
            _delay_ms(200); 
        }
       
    }
    return 0;
}
