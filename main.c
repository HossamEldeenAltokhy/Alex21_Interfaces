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

    
    init_Motor();
    
  

    while (1) {
        Motor_Forward();
        
        _delay_ms(5000);
        
        Motor_Reverse();
        
        _delay_ms(5000);
    }
    return 0;
}
