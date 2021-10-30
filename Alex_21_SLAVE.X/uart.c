#include <avr/io.h>
#include "uart.h"
#include "config.h"

void init_uart(int baudRate, int Rx_EN, int Tx_EN) {

    UCSRB |= (Rx_EN << RXEN);
    UCSRB |= (Tx_EN << TXEN);
    int _UBRR = (F_CPU / 16.0 / baudRate) - 1;
    UBRRL = (char) _UBRR;
    if (_UBRR > 255) {
        UBRRH = (_UBRR >> 8);
    }

}

void uart_enable_INT(int _INT){
    if(_INT == _RXCIE){
        UCSRB |= (1<<RXCIE);
    }
    if(_INT == _TXCIE){
        UCSRB |= (1<<TXCIE);
    }
    if(_INT == _UDRIE){
        UCSRB |= (1<<UDRIE);
    }
}

void uart_send(char data) {

    while (!(UCSRA & (1 << UDRE)));

    UDR = data;



}

void uart_send_Num(int num) {

}

void uart_send_Str(char* ptr) {

}

char uart_receive(void) {

    /* Wait for data to be received */
    while (!(UCSRA & (1 << RXC)));
    /* Get and return received data from buffer */
    return UDR;
}
