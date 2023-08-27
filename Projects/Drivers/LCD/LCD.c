#include "LCD.h"

void LCD_Init(void)
{
    Delay(1000);
//    Send_Command(0x33);
    Send_Command(0x28); /* 2 line, 5*7 matrix in 4-bit mode */
    Send_Command(0x0F); /* Display on cursor off */
    Send_Command(0x06); /* Increment cursor (shift cursor to right) */
    Send_Command(0x01); /* Clear display screen */

}

void Send_Command(u8 command)
{
    u8 dataH = (command & 0xF0)>>4;
    u8 dataL = 0x0F & command;
    GPIO_Write_Port(PortD, dataH);
    GPIO_Write(RS, LOW);
    GPIO_Write(EN, HIGH);
    Delay_Micro(1);
    GPIO_Write(EN, LOW);
    Delay_Micro(200);
    GPIO_Write_Port(PortD, dataL);
    GPIO_Write(EN, HIGH);
    Delay_Micro(1);
    GPIO_Write(EN, LOW);
    Delay(2);
}

void Send_Data(u8 data)
{
    u8 dataH = (0xF0 & data) >> 4;
    u8 dataL = 0x0F & data;
    GPIO_Write_Port(PortD, dataH);
    GPIO_Write(RS, HIGH);
    GPIO_Write(EN, HIGH);
    Delay_Micro(5);
    GPIO_Write(EN, LOW);
    Delay_Micro(200);
    GPIO_Write_Port(PortD, dataL);
    GPIO_Write(EN, HIGH);
    Delay_Micro(5);
    GPIO_Write(EN, LOW);
    Delay(2);
}

void Send_String(char *str)
{
    Send_Command(Clear);
    int i;
    for (i = 0; str[i] != 0; i++) /* Send each char of string till the NULL */
    {
        Send_Data(str[i]);
    }
}

