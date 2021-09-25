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
    // Static
    init_Leds();
    init_Buttons();
    init_Relay();
    init_Buzzer();
    while (1) {

        if (isPressed(_PB, Btn0)) {
            // Pressed
            set_Led(Led0, ON);
            set_Led(Led1, ON);
            set_Led(Led2, ON);
        } else {
            // Release
            set_Led(Led0, OFF);
            set_Led(Led1, OFF);
            set_Led(Led2, OFF);
        }

        if(isPressed(_PD, Btn1)){
            set_Relay(ON);
        }else{
            set_Relay(OFF);
        }


        if(isPressed(_PD, Btn2)){
            set_Buzzer(ON);
        }else{
            set_Buzzer(OFF);
        }
    }
    

    return 0;
}
