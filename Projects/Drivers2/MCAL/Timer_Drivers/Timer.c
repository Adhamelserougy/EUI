#include <MCAL/Timer_Drivers/Timer.h>

void Timer_Init(Timer_RegDef_t *Timerx, Timer_InitTypeDef *Timer_Init)
{
    Timerx->GPTMCFG = Timer_Init->Config;
    switch (Timer_Init->Config)
    {
    case Individual:
        switch (Timer_Init->Timer)
        {
        case TimerA:
            Timerx->GPTMTAMR |= Timer_Init->Mode | (Timer_Init->Count_Mode << 4)
                    | (Timer_Init->Edge_Mode << 2) | (Timer_Init->PWM << 3);
            Timerx->GPTMTAILR = Timer_Init->Load;
            Timerx->GPTMTAPR = Timer_Init->Prescalar;
            Timerx->GPTMCTL |= (Timer_Init->Polarity << 6)
                    | (Timer_Init->Trigger << 2);
            Timerx->GPTMCTL |= (1 << 0);
            break;
        case TimerB:
            Timerx->GPTMTBMR |= Timer_Init->Mode | (Timer_Init->Count_Mode << 4)
                    | (Timer_Init->Edge_Mode << 2) | (Timer_Init->PWM << 3);
            Timerx->GPTMTBILR = Timer_Init->Load;
            Timerx->GPTMTBPR = Timer_Init->Prescalar;
            Timerx->GPTMCTL |= (Timer_Init->Polarity << 14)
                    | (Timer_Init->Trigger << 10);
            Timerx->GPTMCTL |= (1 << 8);
            break;
        default:
            break;
        }
        break;
    case Concatenated:
        break;
    }
}

void Timer_Clock_Init(u8 Timers)
{
    if (Timers < 6)
    {
        SYSCTL->RCGCTIMER |= (1 << Timers);
    }
    else
    {
        SYSCTL->RCGCWTIMER |= (1 << (Timers - 6));
    }
}

void Timer_Interrupt_Init(Timer_RegDef_t *Timerx,
                          Timer_Init_InterruptTypedef *Timer_Int)
{
    switch (Timer_Int->Timer)
    {
    case TimerA:
        Timerx->GPTMIMR |= (Timer_Int->Time_Out << 0)
                | (Timer_Int->Capture_Match << 1)
                | (Timer_Int->Capture_Event << 2) | (Timer_Int->Match << 4);
        Timerx->GPTMTAMR |= (Timer_Int->PWM << 9) | (Timer_Int->Match << 5);
        break;
    case TimerB:
        Timerx->GPTMIMR |= (Timer_Int->Time_Out << 8)
                | (Timer_Int->Capture_Match << 9)
                | (Timer_Int->Capture_Event << 10) | (Timer_Int->Match << 11);
        Timerx->GPTMTBMR |= (Timer_Int->PWM << 9) | (Timer_Int->Match << 5);
        break;
    default:
        break;
    }
}

void Timer_SetMatch(Timer_RegDef_t *Timerx, u8 Timer, u64 Match)
{
    switch (Timer)
    {
    case TimerA:
        Timerx->GPTMTAMATCHR = Match;
        break;
    case TimerB:
        Timerx->GPTMTBMATCHR = Match;
        break;
    default:
        break;
    }
}

u64 Timer_GetMatch(Timer_RegDef_t *Timerx, u8 Timer)
{
    switch (Timer)
    {
    case TimerA:
        return Timerx->GPTMTAMATCHR;
    case TimerB:
        return Timerx->GPTMTBMATCHR;
    default:
        break;
    }
    return 0;
}

void Timer_SetLoad(Timer_RegDef_t *Timerx, u8 Timer, u64 Load)
{
    switch (Timer)
    {
    case TimerA:
        Timerx->GPTMTAILR = Load;
        break;
    case TimerB:
        Timerx->GPTMTBILR = Load;
        break;
    default:
        break;
    }
}

u64 Timer_GetCount(Timer_RegDef_t *Timerx, u8 Timer)
{
    switch (Timer)
    {
    case TimerA:
        return Timerx->GPTMTAR;
    case TimerB:
        return Timerx->GPTMTBR;
    default:
        break;
    }
    return 0;
}

void Timer_Interrupt_Register(u8 Timer, u8 SubTimer,
                              void (*pfnIntHandler)(void))
{
    u8 Handler = Timer * 2 + SubTimer;
    ptr_Timer[Handler] = pfnIntHandler;
}
