/*
 * File:   main.c
 * Author: hossa
 *
 * Created on September 24, 2021, 11:18 AM
 */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#define Relay  2 // PA2
#define Buzzer 3 // PA2

#define Led0   2 // PC2
#define Led1   7 // PC7
#define Led2   3 // PD3

#define Btn0   0 // PB0
#define Btn1   6 // PD6
#define Btn2   2 // PD2

#define ON  1
#define OFF 0

void init_Relay();
void set_Relay(int state);
void init_Buzzer();
void set_Buzzer(int state);

void init_Leds();
void set_Led(int LedNumber, int state);

int main(void) {
    /* Replace with your application code */
    // Static
    init_Leds();
        while (1) {
            // Dynamic
            set_Led(Led0, ON);
            _delay_ms(500);
            set_Led(Led0, OFF);
            _delay_ms(500);

    }
        return 0;
}

void init_Buzzer() {
    DDRA |= (1 << Buzzer);

}

void set_Buzzer(int state) {
    if (state) {
        PORTA |= (1 << Buzzer);
    } else {
        PORTA &= ~(1 << Buzzer);
    }
}

void init_Relay() {
    // Set pin connected to 
    // Relay as OUTPUT pin
    DDRA |= (1 << Relay); // Pin output

}

void set_Relay(int state) {
    if (state) {
        PORTA |= (1 << Relay); // Relay ON
    } else {
        PORTA &= ~(1 << Relay);

    }
}

void init_Leds() {

    /*
        Led0 >>   PC2
        Led1 >>   PC7
        Led2 >>   PD3
     */
    DDRC |= (1 << Led0) | (1 << Led1);
    DDRD |= (1 << Led2);


}

void set_Led(int LedNumber, int state) {

    if (state) {

        switch (LedNumber) {
            case Led0:
                PORTC |= (1 << Led0);
                break;
            case Led1:
                PORTC |= (1 << Led1);
                break;
            case Led2:
                PORTD |= (1 << Led2);
                break;
        }

    } else {
        switch (LedNumber) {
            case Led0:
                PORTC &= ~(1 << Led0);
                break;
            case Led1:
                PORTC &= ~(1 << Led1);
                break;
            case Led2:
                PORTD &= ~(1 << Led2);
                break;
        }
    }


}
