/*
 * File:   main.c
 * Author: hossa
 *
 * Created on September 24, 2021, 11:18 AM
 */



#include <avr/io.h>

#include "config.h"

int main(void) {
    /* Replace with your application code */

    //unsigned char x = 0;
    //setPortDir(_PA, OUT);

    //    setPortDir(_PC, IN);

    // setPortData(_PA, 0x0F);// 00001111


    setPinDir(_PA, PA0, OUT);
    setPinDir(_PC, PC0, IN);



    setPinData(_PA, PA0, ON);
    _delay_ms(200);
    setPinData(_PA, PA0, OFF);
    while (1) {


        _delay_ms(500);


    }
    return 0;
}
