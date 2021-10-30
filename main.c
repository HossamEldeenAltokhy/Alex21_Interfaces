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
#include "uart.h"
#include "mSPI.h"





int main(void) {
    /* Replace with your application code */
   
    init_spi( master , spi_clk_128);
    
    char counter = 0; 
    while (1) {

        spi_send(counter++);
        _delay_ms(500);
        
        
        
    }
    return 0;
}
