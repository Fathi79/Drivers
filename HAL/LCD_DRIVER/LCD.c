
#include "LCD.h"
#include "LCD_CFG.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../UTILS/STD_TYPES.h"
#include "avr/delay.h"


void LCD_vInit(void)
{
	setPortDir(LCD_DATA_PORT, 0xFF);
	setPinDir(LCD_CTRL_PORT, RS_PIN, OUTPUT);
	setPinDir(LCD_CTRL_PORT, RW_PIN, OUTPUT);
	setPinDir(LCD_CTRL_PORT, EN_PIN, OUTPUT);
	_delay_ms(1);
	LCD_vSendCMD(TWO_LINE_LCD_Eight_BIT_MODE);
	_delay_ms(1);
	LCD_vSendCMD(CURSOR_ON);
	_delay_ms(1);
	LCD_vSendCMD(CLEAR_COMMAND);
	_delay_ms(1);

}

void LCD_vSendCMD(u8 cmd)
{
	setPinValue(LCD_CTRL_PORT, RS_PIN, LOW);
	setPinValue(LCD_CTRL_PORT, RW_PIN, LOW);
	setPinValue(LCD_CTRL_PORT, EN_PIN, LOW);
	_delay_ms(1);
	setPinValue(LCD_CTRL_PORT, EN_PIN, HIGH);
	_delay_ms(1);
	setPortValue(LCD_DATA_PORT, cmd);
	_delay_ms(1);
	setPinValue(LCD_CTRL_PORT, EN_PIN, LOW);
	//_delay_ms(1);
	//setPinValue(LCD_CTRL_PORT, EN_PIN, HIGH);
	//_delay_ms(1);
}

void LCD_vSendData(u8 data)
{
	setPortValue(LCD_DATA_PORT, data);
	//_delay_us(100);
	setPinValue(LCD_CTRL_PORT, RS_PIN, HIGH);
	setPinValue(LCD_CTRL_PORT, RW_PIN, LOW);
	setPinValue(LCD_CTRL_PORT, EN_PIN, LOW);
	_delay_ms(1);
	setPinValue(LCD_CTRL_PORT, EN_PIN, HIGH);
	_delay_ms(1);
	//setPortValue(LCD_DATA_PORT, data);
	_delay_ms(1);
	setPinValue(LCD_CTRL_PORT, EN_PIN, LOW);
	//_delay_us(0.4);
	//setPortValue(LCD_DATA_PORT, 0);
	//_delay_us(0.25);
	//setPinValue(LCD_CTRL_PORT, EN_PIN, HIGH);
}

void LCD_DisplayStr(u8* str)
{
	while(*str != '\0')
	{
		LCD_vSendData(*str);
		str++;
	}
}

void LCD_goto_row_col(u8 row, u8 col)
{
	switch(row)
	{
		case 1:
			break;
		case 2:
			col = col + LCD_ROW_2;
	}

	LCD_vSendCMD(SET_CURSOR_LOCATION | col);
}

void LCD_DisplayStr_row_col(u8 * str, u8 row, u8 col)
{
	LCD_goto_row_col(row, col);
	LCD_DisplayStr(str);
}

void LCD_intToStr(u32 number)
{
	u8 arr_new[11];		//The max value of u32 has ten digits
	u8 arr1[11], i = 0, j;
	if(number == 0)
	{
		LCD_DisplayStr("0");
		return;
	}

	while(number != 0)
	{
		arr1[i] = (number % 10) + 0x30;
		number /= 10;
		i++;
	}

	i--;
	j = 0;
	while(i < 11) //After it reaches zero
	{
		arr_new[j] = arr1[i];
		j++;
		i--;
	}

	arr_new[j] = '\0';

	LCD_DisplayStr(arr_new);
}


void LCD_setAC(LCD_RAM r, u8 address)
{
	u8 cmd, bit = 1;

	switch(r)
	{
	case CGRAM:
		cmd = 0x40;
		while (bit <= 32)
		{
			cmd = cmd | (address & bit);
			bit *= 2;
		}
		break;
	case DDRAM:
		cmd = 0x80;
		while (bit <= 64)
		{
			cmd = cmd | (address & bit);
			bit *= 2;
		}
	}

	LCD_vSendCMD(cmd);
}

void LCD_DisplayCustomChar(u8 * arr, u8 currentDDloc)
{
	u8 i;
	//LCD_setAC(CGRAM, 0x48);
	LCD_vSendCMD(SET_CGRAM_ADDRESS);
	for(i = 0; i < 7; i++)
		LCD_vSendData(arr[i]);

	//LCD_setAC(DDRAM, currentDDloc);
	LCD_vSendCMD(SET_DDRAM_ADDRESS | currentDDloc);
	LCD_vSendData(0x01);
}
