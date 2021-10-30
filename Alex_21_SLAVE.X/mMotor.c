
#include "config.h"
#include "avr/io.h"
#include "mMotor.h"

void init_Motor(){
    setPinDir(_PA, Motor_Terminal0, OUT);
    setPinDir(_PA, Motor_Terminal1, OUT);
}

void Motor_Reverse(){
    Motor_Stop();
    _delay_ms(1000);
    setPinData(_PA, Motor_Terminal0, ON);
    setPinData(_PA, Motor_Terminal1, OFF);
}
void Motor_Forward(){
    Motor_Stop();
    _delay_ms(1000);
    setPinData(_PA, Motor_Terminal0, OFF);
    setPinData(_PA, Motor_Terminal1, ON);
}

void Motor_Stop(){
    setPinData(_PA, Motor_Terminal0, OFF);
    setPinData(_PA, Motor_Terminal1, OFF);
}