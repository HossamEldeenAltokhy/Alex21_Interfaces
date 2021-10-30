/* 
 * File:   mExternalInterrupt.h
 * Author: hossa
 *
 * Created on October 9, 2021, 11:11 AM
 */

#ifndef MEXTERNALINTERRUPT_H
#define	MEXTERNALINTERRUPT_H


#define _INT0   0
#define _INT1   1
#define _INT2   2

#define _MODE_Low           0
#define _MODE_AnyChange     1
#define _MODE_Falling       2
#define _MODE_Rising        3
#define _MODE_INT2_Falling  0
#define _MODE_INT2_Rising   1

void init_INT(int Int_Num, int Mode);




#endif	/* MEXTERNALINTERRUPT_H */

