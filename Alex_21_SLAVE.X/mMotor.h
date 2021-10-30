/* 
 * File:   mMotor.h
 * Author: hossa
 *
 * Created on October 2, 2021, 1:30 PM
 */

#ifndef MMOTOR_H
#define	MMOTOR_H


#define Motor_Terminal0    PA0
#define Motor_Terminal1    PA1

void init_Motor();

void Motor_Forward();
void Motor_Reverse();

void Motor_Stop();

#endif	/* MMOTOR_H */

