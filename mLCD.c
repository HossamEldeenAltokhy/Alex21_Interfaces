#include "mLCD.h"
#include "config.h"
#include <avr/io.h>
#include <util/delay.h>
#include "IO.h"


void init_LCD(){
    // Set AVR IO Directions
    setPortDir(LCD_data_dir, OUT);
    setPinDir(LCD_control_dir, RS, OUT);
    setPinDir(LCD_control_dir, RW, OUT);
    setPinDir(LCD_control_dir, EN, OUT);
    
    // 
    LCD_CLEAR();
    
    
    
}
void LCD_DATA(char data){
    setPinData(LCD_control, RS, ON);
    LCD_data = data;
    LCD_EN();
    
}
void LCD_CMD(char cmd){
    setPinData(LCD_control, RS, OFF);
    LCD_data = cmd;
    LCD_EN();
}
void LCD_EN(){
    // Set Enable
    // LCD_control  |= (1<<EN);
    setPinData(LCD_control, EN, ON);
    _delay_us(50);
    // Reset Enable
    // LCD_control  &= ~(1<<EN);
    setPinData(LCD_control, EN, OFF);
}


void LCD_CLEAR(){
    LCD_CMD(0x01);
}