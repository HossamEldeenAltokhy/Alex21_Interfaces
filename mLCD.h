/* 
 * File:   mLCD.h
 * Author: hossa
 *
 * Created on October 1, 2021, 1:49 PM
 */

#ifndef MLCD_H
#ifndef MLCD_4BIT_H
#define	MLCD_H

// HW --- Connections Configurations

#define RS      PC0
#define RW      PC1
#define EN      PC2


#define LCD_control         _PC
#define LCD_control_dir     _PC

#define LCD_data            _PD       
#define LCD_data_dir        _PD
///////////////////////////////////////
//Command List
#define _8BIT_MODE 0x38
#define ReturnHome 0x02
#define D_ON_C_OFF 0x0C
#define Inc_Cur    0x06

#define ShiftRight 0x1C

#define row0        0
#define row1        1

void init_LCD();
void LCD_DATA(char data);
void LCD_CMD(char cmd);
void LCD_EN();

void LCD_CLEAR();

void LCD_Write_Str(char*);

void LCD_Write_Num(int num);

void goto_XY(int row, int column);

void LCD_shiftRight();
#endif	/* MLCD_H */
#endif	/* MLCD_H */

