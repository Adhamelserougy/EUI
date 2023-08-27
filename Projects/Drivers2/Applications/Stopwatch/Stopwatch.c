#include <Applications/Stopwatch/Stopwatch.h>

static Time time;
static Time lap1;
static Time lap2;
static Time lap3;
static u8 Arr[5];
static u8 Lap1[5];
static u8 Lap2[5];
static u8 Lap3[5];
static u8 flag;
static u8 Lap_Flag;

void Stopwatch_Init(void)
{
    Init_GPIO();
    LCD_Init();
    GPIO_Int_Register(PortF, GPIOF_IRQ_Handler_Callback);
    Stopwatch_Reset();
    NVIC->STRELEAD = 4000000;
    NVIC->STCTRL |= 0x02;
}

void Stopwatch_Reset(void)
{
    LCD_Send_Command(LCD_Clear);
    Lap_Flag = 0;
    flag = 1;
    time.minutes = 0;
    time.seconds = 0;
    lap1.minutes = 0;
    lap1.seconds = 0;
    lap2.minutes = 0;
    lap2.seconds = 0;
    lap3.minutes = 0;
    lap3.seconds = 0;
    NVIC->STCTRL |= 0x01;
}

static void toString(void)
{
    Arr[0] = (time.minutes / 10) + '0';
    Arr[1] = (time.minutes % 10) + '0';
    Arr[2] = ':';
    Arr[3] = (time.seconds / 10) + '0';
    Arr[4] = (time.seconds % 10) + '0';
    u8 i;
    LCD_Send_Command(LCD_First_Line);
    for (i = 0; i < 5; i++)
    {
        LCD_Send_Data(Arr[i]);
    }

    if (Lap_Flag)
    {
        Lap1[0] = (lap1.minutes / 10) + '0';
        Lap1[1] = (lap1.minutes % 10) + '0';
        Lap1[2] = ':';
        Lap1[3] = (lap1.seconds / 10) + '0';
        Lap1[4] = (lap1.seconds % 10) + '0';
        LCD_Send_Command(0x80 + 0x08);
        LCD_Send_Data('1');
        LCD_Send_Data('>');
        for (i = 0; i < 5; i++)
        {
            LCD_Send_Data(Lap1[i]);
        }

        Lap2[0] = (lap2.minutes / 10) + '0';
        Lap2[1] = (lap2.minutes % 10) + '0';
        Lap2[2] = ':';
        Lap2[3] = (lap2.seconds / 10) + '0';
        Lap2[4] = (lap2.seconds % 10) + '0';
        LCD_Send_Command(LCD_Second_Line);
        LCD_Send_Data('2');
        LCD_Send_Data('>');
        for (i = 0; i < 5; i++)
        {
            LCD_Send_Data(Lap2[i]);
        }

        Lap3[0] = (lap3.minutes / 10) + '0';
        Lap3[1] = (lap3.minutes % 10) + '0';
        Lap3[2] = ':';
        Lap3[3] = (lap3.seconds / 10) + '0';
        Lap3[4] = (lap3.seconds % 10) + '0';
        LCD_Send_Command(0x80 + 0x48);
        LCD_Send_Data('3');
        LCD_Send_Data('>');
        for (i = 0; i < 5; i++)
        {
            LCD_Send_Data(Lap3[i]);
        }
        Lap_Flag = 0;
    }
}

void Lap(void)
{

    lap3.minutes = lap2.minutes;
    lap3.seconds = lap2.seconds;
    lap2.minutes = lap1.minutes;
    lap2.seconds = lap1.seconds;
    lap1.minutes = time.minutes;
    lap1.seconds = time.seconds;
    Lap_Flag = 1;
}

static void Init_GPIO(void)
{
    GPIO_Clock_Init(PortA);
    GPIO_Clock_Init(PortB);
    GPIO_Clock_Init(PortE);
    GPIO_Clock_Init(PortF);
    GPIO_InitTypeDef GPIO_Init_Struct = { D0 | D1 | D2, Output, NOPULL };
    GPIO_Init(GPIOA, &GPIO_Init_Struct);
    GPIO_Init_Struct.Pin = D3 | D6 | D7;
    GPIO_Init(GPIOB, &GPIO_Init_Struct);
    GPIO_Init_Struct.Pin = D4 | D5 | RS;
    GPIO_Init(GPIOE, &GPIO_Init_Struct);
    GPIO_Init_Struct.Pin = E;
    GPIO_Init(GPIOF, &GPIO_Init_Struct);
    GPIO_Init_Struct.Pin = StartStop | Reset;
    GPIO_Init_Struct.Mode = Input;
    GPIO_Init_Struct.Pull = PULL_UP;
    GPIO_Init(GPIOF, &GPIO_Init_Struct);
    GPIO_Init_InterruptTypeDef GPIO_Init_Int_Struct = { PF0 | PF4, Edge,
                                                        Rising_Edge_GPIO };
    GPIO_Interrupt_Init(GPIOF, &GPIO_Init_Int_Struct);
    NVIC_Enable(GPIOF_Int);
}

void SYSTick_Handler(void)
{
    time.seconds++;
    if (time.seconds == 60)
    {
        time.seconds = 0;
        time.minutes++;
    }
    toString();

}

void GPIOF_IRQ_Handler_Callback(u8 Pin)
{
    if (Pin == PF0)
    {
        if (flag)
        {
            NVIC->STCTRL &= ~(1 << 0);
            flag = 0;
        }
        else
        {
            NVIC->STCTRL |= (1 << 0);
            flag = 1;
        }
    }
    else
    {
        if (!flag)
        {
            Stopwatch_Reset();
        }
        else
        {
            Lap();
        }
    }
}
