/* 
 * File:   uart.h
 * Author: hossa
 *
 * Created on September 25, 2021, 11:59 AM
 */

#ifndef UART_H
#define	UART_H

#define _BR9600 9600
#define RX_ENABLE   1
#define TX_ENABLE   1
#define RX_DISABLE   0
#define TX_DISABLE   0
#define _RXCIE       0
#define _TXCIE       1
#define _UDRIE       2


void init_uart(int baudRate, int Rx_EN, int Tx_EN);
void uart_send(char data);
void uart_send_Num(int num);
void uart_send_Str(char*);
char uart_receive();
void uart_enable_INT(int _INT);


#endif	/* UART_H */

