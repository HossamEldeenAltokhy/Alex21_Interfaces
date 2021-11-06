/* 
 * File:   mTWI.h
 * Author: hossa
 *
 * Created on November 5, 2021, 12:52 PM
 */

#ifndef MTWI_H
#define	MTWI_H


#define mAddress   0x06
#define SLA_W      0x02   //00000010
#define SLA_R      0x03   //00000011

void init_TWI_BitRate();

int  TWI_start(char address);
void TWI_stop();
int  TWI_write(char data);
char TWI_read();

///////////////


void TWI_init_slave(char address);
int  TWI_slave_listen();
int  TWI_slave_write(char data);
char TWI_slave_read();





#endif	/* MTWI_H */

