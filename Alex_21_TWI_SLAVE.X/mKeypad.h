/* 
 * File:   mKeypad.h
 * Author: hossa
 *
 * Created on October 9, 2021, 10:51 AM
 */

#ifndef MKEYPAD_H
#define	MKEYPAD_H


#define KEYPAD_PORT    PORTD
#define KEYPAD_DIR     DDRD
#define _KEPAD         _PD

#define COLUMN0        PD0
#define COLUMN1        PD1
#define COLUMN2        PD2
/////////////////////
#define ROW0           PD4      
#define ROW1           PD5    
#define ROW2           PD6    
#define ROW3           PD7 

void init_keypad();
char getKey();


#endif	/* MKEYPAD_H */

