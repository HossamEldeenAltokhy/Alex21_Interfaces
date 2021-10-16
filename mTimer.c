#include "config.h"
#include "mTimer.h"
#include <avr/io.h>



void init_Timer(int mode, int ClockSelect){
    
    TCCR0 &= ~((1<<WGM00)|(1<<WGM01));
    TCCR0 &= ~((1<<CS02)|(1<<CS01)|(1<<CS00));
    
    TCCR0 |= mode;
    TCCR0 |= ClockSelect;
//    switch(mode){
//        case NORMAL:
//            TCCR0 &= ~((1<<WGM00)|(1<<WGM01));
//            break;
//        case PWM:
//            TCCR0 |= (1<<WGM00);
//            break;
//        case CTC:
//            TCCR0 |= (1<<WGM01);
//            break;
//        case FPWM:
//            TCCR0 |= ((1<<WGM00)|(1<<WGM01));
//            break;
//    }
    
    
    

//    switch(ClockSelect){
//        case TimerOFF:
//            TCCR0 &= ~((1<<CS02)|(1<<CS01)|(1<<CS00));
//            break;
//        case NoPrescaller:
//            TCCR0 |= (1<<CS00);
//            break;
//        case _PRE8:
//            TCCR0 |=(1<<CS01);
//            break;
//        case _PRE64:
//            TCCR0 |=(1<<CS01)|(1<<CS00);
//            break;
//        case _PRE256:
//            TCCR0 |=(1<<CS02);
//            break;
//        case _PRE1024:
//            TCCR0 |=((1<<CS02)|(1<<CS00));
//            break;
//        case _EX_Falling:
//            TCCR0 |=((1<<CS02)|(1<<CS01));
//            break;
//        case _EX_Rising:
//            TCCR0 |=((1<<CS02)|(1<<CS01)|(1<<CS00));
//            break;
//       
//        
//    }
}

void Timer_interrupt_enable(int INT_selector){
    TIMSK |= (1<<INT_selector);
}

void Timer_setCompValue(unsigned char compValue){
    OCR0 =  compValue;
}