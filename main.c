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


ISR(INT0_vect){
       
    togglePinData(_PC, Led0);
    
}


int main(void) {
    /* Replace with your application code */

    // Select Interrupt Mode on Rising Edge.
    MCUCR |= (1<<ISC01)|(1<<ISC00);
    // Enable Interrupt 0
    GICR |= (1<<INT0);
    sei();
    
    setPinDir(_PC, Led0, OUT);
    setPortDir(_PA, OUT);
    while (1) {

        togglePortData(_PA);
        _delay_ms(200);
        
    }
    return 0;
}
