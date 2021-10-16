/* 
 * File:   mTimer.h
 * Author: hossa
 *
 * Created on October 16, 2021, 10:22 AM
 */

#ifndef MTIMER_H
#define	MTIMER_H

#define NORMAL      0
#define PWM         0x40// 1    
#define CTC         0x08// 2
#define FPWM        0x48// 3



#define TimerOFF     0

#define NoPrescaller 1
#define _PRE8        2
#define _PRE64       3
#define _PRE256      4
#define _PRE1024     5

#define _EX_Falling  6
#define _EX_Rising   7


void init_Timer(int mode, int ClockSelect);

void Timer_interrupt_enable();
#endif	/* MTIMER_H */

