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
#include <avr/eeprom.h>





int main(void) {
    /* Replace with your application code */
   
 
//    eeprom_write_byte(( uint8_t *) 10, 55);
//    _delay_ms(50);
    init_LCD_4bit();
    
    _delay_ms(50);
    int data =  eeprom_read_byte((const uint8_t *) 10);
    _delay_ms(50);
    LCD_Write_Num_4bit(data);
    while (1) {

      
        
        
    }
    return 0;
}
