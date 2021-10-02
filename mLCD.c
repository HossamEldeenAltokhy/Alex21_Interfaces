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
    // Write Mode Only
    setPinData(LCD_control, RW, OFF);
    
    _delay_ms(50);
    // 
    LCD_CLEAR();
    
    LCD_CMD(_8BIT_MODE);
    _delay_ms(1);
    LCD_CMD(D_ON_C_OFF);
    _delay_ms(1);
    LCD_CMD(ReturnHome);
    _delay_ms(1);
    LCD_CMD(Inc_Cur);
    _delay_ms(50);
    // LCD 8 bit mode + 2 lines
    // Curser OFF , Display ON
    // Return Home 
    
    
}
void LCD_DATA(char data){
    setPinData(LCD_control, RS, ON);
//    LCD_data = data;
    setPortData(LCD_data, data);
    LCD_EN();
    
}
void LCD_CMD(char cmd){
    setPinData(LCD_control, RS, OFF);
    setPortData(LCD_data, cmd);
    LCD_EN();
}
//5/10000000
void LCD_EN(){
    // Set Enable
//     LCD_control  |= (1<<EN);
    setPinData(LCD_control, EN, ON);
    _delay_us(400);
    // Reset Enable
//     LCD_control  &= ~(1<<EN);
    setPinData(LCD_control, EN, OFF);
}


void LCD_CLEAR(){
    LCD_CMD(0x01); // 00000001
}

void LCD_Write_Str(char* str){
    for(int i = 0 ; str[i]!= '\0'; i++){
        LCD_DATA(str[i]);
    }
}

void LCD_Write_Num(int num){
   // Write Code Here 
}