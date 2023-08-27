#include <Applications/Periodic_Delay/Periodic_Delay.h>

void Periodic_Delay(void)
{
    Init_GPIO();
    Init_Timers();
    while(1);
}

static void Init_GPIO(void)
{
    GPIO_Clock_Init(PortF);
    GPIO_InitTypeDef Init = { PF1 | PF2 | PF3, Output, NOPULL };
    GPIO_Init(GPIOF, &Init);
}

static void Init_Timers(void)
{
    Timer_Clock_Init(Timer_2);
    Timer_Init_InterruptTypedef Int_Init = {};
    Int_Init.Time_Out = On;
    Int_Init.Timer = TimerA;
    Timer_Interrupt_Init(Timer2, &Int_Init);
    Timer_InitTypeDef Init = {};
    Init.Config = Individual;
    Init.Load = 31249;
    Init.Prescalar = 255;
    Init.Mode = Periodic;
    Init.Timer = TimerA;
    Timer_Init(Timer2, &Init);
    Timer_Interrupt_Register(Timer_2, TimerA, Timer2_A_IRQ_Handler_Callback);
    NVIC_Enable(Timer2_A_Int);
}

static void Timer2_A_IRQ_Handler_Callback(void)
{
    GPIO_Toggle(GPIOF, PF1 | PF2 | PF3);
}
