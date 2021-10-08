/*
 * File:   main.c
 * Author: hossa
 *
 * Created on September 24, 2021, 11:18 AM
 */



#include <avr/io.h>

#include "config.h"
#include "mLCD_4bit.h"

int x = 100;

char str[] = "ALEX1234567890*#";//        ALEX 21";
char str1[] = "Y = ";
int main(void) {
    /* Replace with your application code */


    init_LCD_4bit();
    _delay_ms(50);
    LCD_Write_Str_4bit(str);
    while (1) {

    }
    return 0;
}
