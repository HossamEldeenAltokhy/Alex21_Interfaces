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
#include "mLCD.h"
#include "mTWI.h"
#include <avr/eeprom.h>





int main(void) {
    /* Replace with your application code */
   
 
    init_TWI_BitRate();
    _delay_ms(5000);
    while (1) {

        if(TWI_start(SLA_W)){
            // Start Condition Succesfully done.
            int code = TWI_write(7);
            if(code == 1){
                TWI_stop();
            }
        }
        
        
        _delay_ms(500);
      
        
        
    }
    return 0;
}
