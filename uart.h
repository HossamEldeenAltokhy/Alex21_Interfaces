/* 
 * File:   uart.h
 * Author: hossa
 *
 * Created on September 25, 2021, 11:59 AM
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

    void init_uart(int baudRate, int Rx_EN, int Tx_EN, int Int_EN);
    void uart_send(char data);
    void uart_send_Num(int num);
    void uart_send_Str(char*);
    char uart_receive();


#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

