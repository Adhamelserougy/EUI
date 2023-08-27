#include "Keypad.h"

volatile u8 Keypad_Matrix[4][4] =
        { { '1', '2', '3', '+' }, { '4', '5', '6', '-' },
          { '7', '8', '9', '*' }, { 0, '0', '=', '/' } };

extern const GPIO_TYPE Ports[6];
volatile u8 Pressed_Buttons[17];
volatile u8 Button_Count = 0;
volatile u8 flag = 0;

void Keypad_Init(void)
{
    flag = 0;
    GPIO_Write_Port(PortB, 0);
}

void Start(void)
{
    while (1)
    {
        if (flag)
        {
            if (Pressed_Buttons[Button_Count - 1] == '=')
            {
                Send_Data('=');
                flag = 0;
                return;
            }
            else if (Pressed_Buttons[Button_Count - 1] == 0)
            {
                Send_Command(Clear);
                Button_Count = 0;
                flag = 0;
            }
            else
            {
                Send_Data(Pressed_Buttons[Button_Count - 1]);
                flag = 0;
            }
        }
    }
}

void GPIOC_Handler(void)
{
    u8 Interrupt_Source = GPIO_PORTC_MIS_R >> 4;
    u8 column = 0;
    while (Interrupt_Source != 0)
    {
        column++;
        Interrupt_Source >>= 1;
    }
    Interrupt_Source = GPIO_PORTC_DATA_R >> 4;
    u8 data;
    u8 i;
    for (i = 0; i < 3; i++)
    {
        data = ~(1 << (i)) & 0x0F;
        GPIO_Write_Port(PortB, data);
        if (GPIO_PORTC_DATA_R >> 4 == Interrupt_Source)
        {
            break;
        }
    }
    Pressed_Buttons[Button_Count++] = Keypad_Matrix[i][column - 1];
    flag = 1;
    GPIO_Write_Port(PortB, 0);
    Delay(200);
    GPIO_PORTC_ICR_R |= 0xFF;
}
