#include "config.h"
#include "mExternalInterrupt.h"
#include <avr/io.h>

void init_INT(int Int_Num, int Mode){
    switch(Int_Num){
        case _INT0:
            MCUCR |= Mode;
            GICR |= (1<<INT0);
            break;
        case _INT1:
            MCUCR |= (Mode<<2);
            GICR |= (1<<INT1);
            break;
        case _INT2:
            MCUCSR |= (Mode<<ISC2);
            GICR |= (1<<INT2);
            break;
        default:
            break;
        }
}
