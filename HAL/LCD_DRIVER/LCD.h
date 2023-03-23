#ifndef LCD_H
#define LCD_H

#include "../../UTILS/STD_TYPES.h"

/******* LCD RAMs *******
enum LCD_RAM{
	CGRAM, DDRAM
};
*/
typedef enum{
	CGRAM, DDRAM
}LCD_RAM;

 // This function shall be responsible for initializing LCD
void LCD_vInit(void);

 // This function shall be responsible for sending commands to LCD
void LCD_vSendCMD(u8 cmd);


 // This function shall be responsible for sending data to LCD
void LCD_vSendData(u8 data);

//This function shall be responsible for printing string on LCD
void LCD_DisplayStr(u8* str);

//This function shall be responsible for changing cursor position
void LCD_goto_row_col(u8 row, u8 col);

//This function shall be responsible for printing a string at a certain position
void LCD_DisplayStr_row_col(u8 * str, u8 row, u8 col);

//This function shall be responsible for printing a decimal number
void LCD_intToStr(u32 number);

//This function shall be responsible for setting the address counter (CG or DD)
//Useless till now
void LCD_setAC(LCD_RAM r, u8 address);

//This function shall be responsible for displaying custom character
void LCD_DisplayCustomChar(u8 * arr, u8 currentDDloc);

#endif
