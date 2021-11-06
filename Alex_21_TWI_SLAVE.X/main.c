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
    TWI_init_slave(SLA_W);
    while (1) {

        int ListenCode = TWI_slave_listen();
        if(ListenCode == 1){
            char  data  = TWI_slave_read();
            PORTA = data;
        }else if(ListenCode == 2){
            TWI_slave_write('A');
        }
        else{
            // Do nothing
        }
      
        
        
    }
    return 0;
}
