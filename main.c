/*
 * File:   main.c
 * Author: hossa
 *
 * Created on September 24, 2021, 11:18 AM
 */



#include <avr/io.h>

#include "config.h"

int x =100;

char str[]= "ALEX 21";
int main(void) {
    /* Replace with your application code */

    init_LCD();
    
//    _delay_ms(50);
    
    LCD_Write_Str(str);
    while (1) {


        


    }
    return 0;
}
