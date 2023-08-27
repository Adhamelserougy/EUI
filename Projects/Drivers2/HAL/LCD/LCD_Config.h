#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

//#define LCD_Mode_4bit
#define LCD_Mode_8bit

#ifdef LCD_Mode_4bit

#define D4          PE5
#define D5          PE4
#define D6          PB1
#define D7          PB0
#define E           PF1
#define RS          PE3

#endif

#ifdef LCD_Mode_8bit

#define D0          PA7
#define D1          PA6
#define D2          PA5
#define D3          PB4
#define D4          PE5
#define D5          PE4
#define D6          PB1
#define D7          PB0
#define E           PF1
#define RS          PE3

#endif

#endif /* HAL_LCD_LCD_CONFIG_H_ */
