#include <HAL/LCD/LCD.h>

#ifdef LCD_Mode_8bit

void LCD_Init(void)
{
    LCD_Send_Command(LCD_Function_8bit);
    LCD_Send_Command(LCD_Display_On | LCD_Cursor_On | LCD_Blink_On);
    LCD_Send_Command(0x06);
    LCD_Send_Command(LCD_Clear);
    LCD_Send_Command(LCD_First_Line);
}
void LCD_Send_Data(u8 Data)
{
    GPIO_Write(GPIOA, D0, (Data & (1 << 0)) >> 0);
    GPIO_Write(GPIOA, D1, (Data & (1 << 1)) >> 1);
    GPIO_Write(GPIOA, D2, (Data & (1 << 2)) >> 2);
    GPIO_Write(GPIOB, D3, (Data & (1 << 3)) >> 3);
    GPIO_Write(GPIOE, D4, (Data & (1 << 4)) >> 4);
    GPIO_Write(GPIOE, D5, (Data & (1 << 5)) >> 5);
    GPIO_Write(GPIOB, D6, (Data & (1 << 6)) >> 6);
    GPIO_Write(GPIOB, D7, (Data & (1 << 7)) >> 7);
    GPIO_Write(GPIOE, RS, High);
    GPIO_Write(GPIOF, E, High);
    Delay_us(1);
    GPIO_Write(GPIOF, E, Low);
    Delay_ms(2);
}
void LCD_Send_Command(u8 Command)
{
    GPIO_Write(GPIOA, D0, (Command & (1 << 0)) >> 0);
    GPIO_Write(GPIOA, D1, (Command & (1 << 1)) >> 1);
    GPIO_Write(GPIOA, D2, (Command & (1 << 2)) >> 2);
    GPIO_Write(GPIOB, D3, (Command & (1 << 3)) >> 3);
    GPIO_Write(GPIOE, D4, (Command & (1 << 4)) >> 4);
    GPIO_Write(GPIOE, D5, (Command & (1 << 5)) >> 5);
    GPIO_Write(GPIOB, D6, (Command & (1 << 6)) >> 6);
    GPIO_Write(GPIOB, D7, (Command & (1 << 7)) >> 7);
    GPIO_Write(GPIOE, RS, Low);
    GPIO_Write(GPIOF, E, High);
    Delay_us(1);
    GPIO_Write(GPIOF, E, Low);
    Delay_ms(2);
}
void LCD_Send_String(u8 *str)
{
    int i;
    for (i = 0; str[i] != 0; i++) /* Send each char of string till the NULL */
    {
        LCD_Send_Data(str[i]);
    }
}
#endif

#ifdef LCD_Mode_4bit

void LCD_Init(void)
{
    LCD_Send_Command(LCD_Function_4bit);
    LCD_Send_Command(LCD_Display_On | LCD_Cursor_On | LCD_Blink_On);
    LCD_Send_Command(0x06);
    LCD_Send_Command(LCD_Clear);
    LCD_Send_Command(LCD_First_Line);
}
void LCD_Send_Data(u8 Data)
{
    GPIO_Write(GPIOE, D4, (Data & (1 << 4)) >> 4);
    GPIO_Write(GPIOE, D5, (Data & (1 << 5)) >> 5);
    GPIO_Write(GPIOB, D6, (Data & (1 << 6)) >> 6);
    GPIO_Write(GPIOB, D7, (Data & (1 << 7)) >> 7);
    GPIO_Write(GPIOE, RS, High);
    GPIO_Write(GPIOF, E, High);
    Delay_us(1);
    GPIO_Write(GPIOF, E, Low);
    Delay_us(200);
    GPIO_Write(GPIOE, D4, (Data & (1 << 0)) >> 0);
    GPIO_Write(GPIOE, D5, (Data & (1 << 1)) >> 1);
    GPIO_Write(GPIOB, D6, (Data & (1 << 2)) >> 2);
    GPIO_Write(GPIOB, D7, (Data & (1 << 3)) >> 3);
    GPIO_Write(GPIOE, RS, High);
    GPIO_Write(GPIOF, E, High);
    Delay_us(1);
    GPIO_Write(GPIOF, E, Low);
    Delay_ms(2);
}
void LCD_Send_Command(u8 Command)
{
    GPIO_Write(GPIOE, D4, (Command & (1 << 4)) >> 4);
    GPIO_Write(GPIOE, D5, (Command & (1 << 5)) >> 5);
    GPIO_Write(GPIOB, D6, (Command & (1 << 6)) >> 6);
    GPIO_Write(GPIOB, D7, (Command & (1 << 7)) >> 7);
    GPIO_Write(GPIOE, RS, Low);
    GPIO_Write(GPIOF, E, High);
    Delay_us(1);
    GPIO_Write(GPIOF, E, Low);
    Delay_us(200);
    GPIO_Write(GPIOE, D4, (Command & (1 << 0)) >> 0);
    GPIO_Write(GPIOE, D5, (Command & (1 << 1)) >> 1);
    GPIO_Write(GPIOB, D6, (Command & (1 << 2)) >> 2);
    GPIO_Write(GPIOB, D7, (Command & (1 << 3)) >> 3);
    GPIO_Write(GPIOE, RS, Low);
    GPIO_Write(GPIOF, E, High);
    Delay_us(1);
    GPIO_Write(GPIOF, E, Low);
    Delay_ms(2);
}
void LCD_Send_String(u8 *str)
{
    int i;
    for (i = 0; str[i] != 0; i++) /* Send each char of string till the NULL */
    {
        LCD_Send_Data(str[i]);
    }
}

#endif
