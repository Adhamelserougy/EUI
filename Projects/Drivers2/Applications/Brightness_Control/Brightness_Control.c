#include <Applications/Brightness_Control/Brightness_Control.h>

void Brightness_Control(void)
{
    Init_GPIO();
    Init_Timers();
    u8 Flag = 1;
    u16 Match = 0;
    while (1)
    {
        if (Flag)
        {
            Timer_SetMatch(Timer1, TimerA, Match++);
        }
        else
        {
            Timer_SetMatch(Timer1, TimerA, Match--);
        }
        if (Timer_GetMatch(Timer1, TimerA) > 10000)
            Flag = 0;
        else if (Timer_GetMatch(Timer1, TimerA) < 100)
        {
            Flag = 1;
        }
        else
        {

        }
        Delay_ms(1);
    }
}

static void Init_GPIO(void)
{
    GPIO_Clock_Init(PortF);
    GPIO_InitTypeDef Init = { PF2, Output, NOPULL, 1, 7 };
    GPIO_Init(GPIOF, &Init);
}

static void Init_Timers(void)
{
    Timer_Clock_Init(Timer_1);
    Timer_InitTypeDef Init_Timer = { 0xFFFF, 0, Individual, TimerA, On, 0,
                                     Inverted, Periodic, Down, 0 };
    Timer_Init(Timer1, &Init_Timer);
}
