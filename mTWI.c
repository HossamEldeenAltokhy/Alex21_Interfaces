#include "config.h"
#include "mTWI.h"
#include <avr/io.h>


int TWI_start(char address){
    char bus_status;
    
    // send START condition
    TWCR |= (1<<TWSTA)|(1<<TWINT)|(1<<TWEN);  
    // waiting TWINT flag to read status code.
    while (!(TWCR & (1<<TWINT)));
    bus_status  = TWSR & 0xF8; // xxxxx000
    if(bus_status != 0x08)
        return 0;
    TWDR  = address;
    // send SLA+WorR
    TWCR |= (1<<TWINT)|(1<<TWEN);  
    // waiting TWINT flag to read status code.
    while (!(TWCR & (1<<TWINT)));
    bus_status  = TWSR & 0xF8; // xxxxx000
    if(bus_status == 0x18)
        return 1;
}
void TWI_stop(){
    TWCR |= (1<<TWSTO)|(1<<TWINT)|(1<<TWEN);
    while (TWCR & (1<<TWSTO)); // ******
}
int  TWI_write(char data){
    char bus_status;
    TWDR = data;
    // Send Data
    TWCR |= (1<<TWINT)|(1<<TWEN);  
    // waiting TWINT flag to read status code.
    while (!(TWCR & (1<<TWINT)));
    bus_status  = TWSR & 0xF8; // xxxxx000
    if(bus_status == 0x28)
        return 1;
    else
        return 0;
}
char TWI_read(){
    TWCR |= (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
    // waiting TWINT flag 
    while (!(TWCR & (1<<TWINT)));
    return TWDR;
}


