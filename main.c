/*
 * File:   main.c
 * Author: hossa
 *
 * Created on September 24, 2021, 11:18 AM
 */



#include <avr/io.h>

#include "config.h"

int x = 100;

char str[] = "ALEX1234567890*#";//        ALEX 21";
char str1[] = "Y = ";
int main(void) {
    /* Replace with your application code */

    init_LCD();

    //    _delay_ms(50);
    goto_XY(row0,  15);
    LCD_Write_Str(str);
//    goto_XY(row1,  2);
//    LCD_Write_Str(str1);
    while (1) {
        
        for(int i =0 ; i <32; i++){
            LCD_shiftRight();

            _delay_ms(500);

        }
        LCD_CMD(ReturnHome);
        _delay_ms(1);
        goto_XY(row0,  15);
        LCD_Write_Str(str);
        _delay_ms(500);
        
    }
    return 0;
}
