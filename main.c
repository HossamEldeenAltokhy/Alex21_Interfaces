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


ISR(INT0_vect){
    // Interrupt service Routine
    
    
    
}

int main(void) {
    /* Replace with your application code */


   
    init_INT(_INT0, _MODE_Rising);
    sei();
    while (1) {

 
       

    }
    return 0;
}
