/* 
 * File:   mSPI.h
 * Author: hossa
 *
 * Created on October 30, 2021, 10:47 AM
 */

#ifndef MSPI_H
#define	MSPI_H

#define MOSI    5
#define MISO    6
#define SCK     7
#define SS      4

#define master  1
#define slave   0


#define spi_clk_4       0
#define spi_clk_16      1 
#define spi_clk_64      2 
#define spi_clk_128     3
   
    

 
     

void init_spi(int mode, int clk);
void spi_send(char data);
char spi_receive(void);

#endif	/* MSPI_H */

