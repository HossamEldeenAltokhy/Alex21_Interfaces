/* 
 * File:   IO.h
 * Author: hossa
 *
 * Created on September 25, 2021, 11:46 AM
 */

#ifndef IO_H
#define	IO_H

#ifdef	__cplusplus
extern "C" {
#endif


    
void init_Relay();
void set_Relay(int state);
void init_Buzzer();
void set_Buzzer(int state);

void init_Leds();
void set_Led(int LedNumber, int state);

void init_Buttons();

int isPress_B(int pinNum);
int isPressed(int portNum, int pinNum);

// PORT Level
void setPortDir(int portNum, int state);
void setPortData(int portNum, int data);
void togglePortData(int portNum);
// Pin Level

void setPinDir(int portNum, int pinNum,int state);
void setPinData(int portNum, int pinNum, int data);
void togglePinData(int portNum, int pinNum);



#ifdef	__cplusplus
}
#endif

#endif	/* IO_H */

