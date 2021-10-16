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


ISR(TIMER0_OVF_vect){
    static int x,y;
    x++;
    y++;
    
    if(y == 30){
        togglePortData(_PD);
        y = 0;
    }
    if(x == 60){
        togglePortData(_PC);
        x = 0;
    }
    
}



int main(void) {
    /* Replace with your application code */

    setPortDir(_PC, OUT);
    setPortDir(_PD, OUT);
    init_Timer(NORMAL, _PRE1024);
    Timer_interrupt_enable();
    
    

    sei();
    
    while (1) {


       
    }
    return 0;
}
