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




int main(void) {
    /* Replace with your application code */

    init_keypad();
    init_LCD_4bit();

    while (1) {

 
        while (getKey()) {

            LCD_DATA_4bit(getKey());
        }

    }
    return 0;
}
