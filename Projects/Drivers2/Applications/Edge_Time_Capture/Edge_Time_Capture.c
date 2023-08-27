#include <Applications/Edge_Time_Capture/Edge_Time_Capture.h>

static u8 flag = 0;
u32 Rise, Fall;
float Period;

void Edge_Time_Capture(void)
{
    Init_GPIO();
    Init_Timers();
    while (1)
    {
    }
}

static void Init_GPIO(void)
{
    GPIO_Clock_Init(PortF);
    GPIO_Clock_Init(PortD);
    GPIO_InitTypeDef Init = { PF1 | PF2 | PF3, Output, NOPULL };
    GPIO_Init(GPIOF, &Init);
    Init.Pin = PD3;
    Init.Mode = Input;
    Init.Pull = PULL_DOWN;
    Init.AF = On;
    Init.AF_Mode = 7;
    GPIO_Init(GPIOD, &Init);
}

static void Init_Timers(void)
{
    Timer_Clock_Init(WTimer_3);
    Timer_Init_InterruptTypedef Int_Init = { };
    Int_Init.Capture_Event = On;
    Int_Init.Timer = TimerB;
    Timer_Interrupt_Init(wTimer3, &Int_Init);
    Timer_InitTypeDef Init = { };
    Init.Config = Individual;
    Init.Timer = TimerB;
    Init.Count_Mode = Down;
    Init.Load = 0xFFFFFFFF;
    Init.Edge_Mode = Edge_Time;
    Init.Mode = Capture;
    Init.Trigger = Both_Timer;
    Timer_Init(wTimer3, &Init);
    Timer_Interrupt_Register(WTimer_3, TimerB, wTimer3_B_IRQ_Handler_Callback);
    NVIC_Enable(WTimer3_B_Int);
}

static void wTimer3_B_IRQ_Handler_Callback(void)
{
    if (flag)
    {
        flag = 0;
        Fall = Timer_GetCount(wTimer3, TimerB);
        Period = (Rise - Fall) / 16000000.0;
        if (Period < 5)
        {
            GPIO_Write_Pins(GPIOF, ALL_GPIO_PINS, PF1);
        }
        else if (Period < 10)
        {
            GPIO_Write_Pins(GPIOF, ALL_GPIO_PINS, PF2);
        }
        else if (Period < 15)
        {
            GPIO_Write_Pins(GPIOF, ALL_GPIO_PINS, PF3);
        }
    }
    else
    {
        flag = 1;
        Rise = Timer_GetCount(wTimer3, TimerB);
    }
}
