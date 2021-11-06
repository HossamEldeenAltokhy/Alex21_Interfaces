#include <avr/io.h>
#include "config.h"
#include "mSPI.h"
#include <avr/eeprom.h>

void init_spi(int mode, int clk){
    
    if(mode){
        // Master Mode
        DDRB |= (1<<MOSI)|(1<<SCK)|(1<<SS);
        SPCR |= (1<<SPE)|(1<<MSTR)|(clk<<SPR0);
    }else{
        // Slave Mode
        DDRB |= (1<<MISO);
        SPCR |= (1<<SPE); // SPI Enable
    }
}
void spi2X(){
    SPSR |= (1<<SPI2X);
}
void spi_send(char data){
    SPDR =  data;
 
    while(!(SPSR & (1<<SPIF)));
}
char spi_receive(void){
    
    while(!(SPSR & (1<<SPIF)));
    return SPDR;
}