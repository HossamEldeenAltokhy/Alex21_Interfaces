#include "config.h"
#include "mTWI.h"
#include <avr/io.h>

void init_TWI_BitRate(){
    TWSR = (1<<TWPS1)|(1<<TWPS0); // 4^ 64
    TWBR = 255;
}
int TWI_start(char address){
    char bus_status;
    
    // send START condition
    TWCR = (1<<TWSTA)|(1<<TWINT)|(1<<TWEN);  
    // waiting TWINT flag to read status code.
    while (!(TWCR & (1<<TWINT)));
    bus_status  = TWSR & 0xF8; // xxxxx000
    if(bus_status != 0x08)
        return 0;
    TWDR  = address;
    // send SLA+WorR
    TWCR = (1<<TWINT)|(1<<TWEN);  
    // waiting TWINT flag to read status code.
    while (!(TWCR & (1<<TWINT)));
    bus_status  = TWSR & 0xF8; // xxxxx000
    if(bus_status == 0x18)
        return 1;
}
void TWI_stop(){
    TWCR = (1<<TWSTO)|(1<<TWINT)|(1<<TWEN);
    while (TWCR & (1<<TWSTO)); // ******
}
int  TWI_write(char data){
    char bus_status;
    TWDR = data;
    // Send Data
    TWCR = (1<<TWINT)|(1<<TWEN);  
    // waiting TWINT flag to read status code.
    while (!(TWCR & (1<<TWINT)));
    bus_status  = TWSR & 0xF8; // xxxxx000
    if(bus_status == 0x28)
        return 1;
    else
        return 0;
}
char TWI_read(){
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
    // waiting TWINT flag 
    while (!(TWCR & (1<<TWINT)));
    return TWDR;
}


////////////////////////////////////////////////


void TWI_init_slave(char address){
    TWAR = address; // 00000010
    TWCR = (1<<TWEA)|(1<<TWINT)|(1<<TWEN);
}
int TWI_slave_listen(){
    while(1){
        char bus_status;
        // Waiting Flag TWINT to be set
        while(!(TWCR & (1<<TWINT)));
        bus_status =  TWSR & 0xF8;
        // Two conditions or General Call
        // >> SLAVE address + W  >> 0x60 or 0x68
        if(bus_status == 0x60 || bus_status == 0x68)
           return 1; 
        // >> SLAVE address + R  >> 0xA8 or 0xB0
        if(bus_status == 0xA8 || bus_status == 0xB0)
           return 2; 
    }
}
int  TWI_slave_write(char data){
    char bus_status;
    TWDR = data;
    TWCR = (1<<TWEA)|(1<<TWINT)|(1<<TWEN);
    // Waiting Flag TWINT to be set
    while(!(TWCR & (1<<TWINT)));
    bus_status =  TWSR & 0xF8;
    if(bus_status == 0xB8)
        return 1;
    else
        return 0;
}
char TWI_slave_read(){
    char bus_status;
    TWCR = (1<<TWEA)|(1<<TWINT)|(1<<TWEN);
    // Waiting Flag TWINT to be set
    while(!(TWCR & (1<<TWINT)));
    bus_status =  TWSR & 0xF8;
    if(bus_status == 0x80 ||
            bus_status == 0x88||
            bus_status == 0x90||
            bus_status == 0x98)
        return TWDR;
    
}
