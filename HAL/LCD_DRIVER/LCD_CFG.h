
#ifndef LCD_CFG_H
#define LCD_CFG_H

#include "../../MCAL/DIO/DIO_CFG.h"

/********* LCD COMMANDS ********/

#define CLEAR_COMMAND 0x01
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80

#define SET_CGRAM_ADDRESS 0x48
#define SET_DDRAM_ADDRESS 0x80

/******** LCD ROWS ADDRESSES ******/

#define LCD_ROW_1	0x00
#define	LCD_ROW_2	0x40
#define LCD_ROW_3	0x10
#define	LCD_ROW_4	0x50

/******** LCD PORTS ******/

#define LCD_DATA_PORT	GROUP_C
#define LCD_CTRL_PORT	GROUP_D
#define RS_PIN	PIN_7
#define RW_PIN	PIN_6
#define EN_PIN	PIN_5



#endif
