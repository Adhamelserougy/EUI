#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

/* Includes */

#include <HAL/LCD/LCD_Config.h>
#include <MCAL/MCAL.h>
#include <UTILS/std_typedefs.h>
#include <UTILS/Delay.h>

/* Command Defines */

#define LCD_Clear                       0x01
#define LCD_First_Line                  0x80
#define LCD_Second_Line                 0xC0
#define LCD_Home                        0x02
#define LCD_Display_On                  0x0C
#define LCD_Cursor_On                   0x0A
#define LCD_Blink_On                    0x09
#define LCD_Function_8bit               0x38
#define LCD_Function_4bit               0x28

/* Function Prototypes */

void LCD_Init(void);
void LCD_Send_Data(u8 Data);
void LCD_Send_Command(u8 Command);
void LCD_Send_String(u8* str);

#endif /* HAL_LCD_LCD_H_ */
