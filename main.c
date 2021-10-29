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





unsigned char incrementer = 100;
unsigned char dutyCycle;

ISR(USART_RXC_vect){

    char data = UDR;
    if(data == 'A'){
        set_Led(Led1 , ON);
        set_Buzzer(ON);
    }
    if(data == 'B'){
        set_Led(Led1 , OFF);
        set_Buzzer(OFF);
    }
    
}

int main(void) {
    /* Replace with your application code */
    setPortDir(_PC, OUT);
    _delay_ms(5);
    init_uart(_BR9600, RX_ENABLE, TX_ENABLE );
    uart_enable_INT(_RXCIE);
    init_Leds();
    init_Buzzer();
    sei();
    while (1) {

 
        
        
    }
    return 0;
}
