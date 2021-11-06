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
    setPortDir(_PA, OUT);
    init_TWI_BitRate();
    _delay_ms(5000);
    int x = 1;
    while (1) {

        if(TWI_start(SLA_W)){
            // Start Condition Successfully done.
            int code = TWI_write(x++);
            _delay_ms(50);
            
                TWI_stop();
          
        }
      
        _delay_ms(500);
        if(TWI_start(SLA_R)){
            // Start Condition Successfully done.
            char data = TWI_read();
            PORTA = data;
            
                TWI_stop();
          
        }
      
        _delay_ms(500);
        
        
     
    }
    return 0;
}
