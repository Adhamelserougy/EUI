#ifndef MCAL_TIMER_DRIVERS_TIMER_H_
#define MCAL_TIMER_DRIVERS_TIMER_H_

/* Include */

#include <UTILS/Register_Map.h>
#include <UTILS/std_typedefs.h>

/* Interrupt Pointers */

void (*ptr_Timer[24])(void);

/* Timer Structs */

typedef struct
{
    u64 Load;
    u16 Prescalar;
    u8 Config;
    u8 Timer;
    u8 PWM;
    u8 Trigger;
    u8 Polarity;
    u8 Mode;
    u8 Count_Mode;
    u8 Edge_Mode;
} Timer_InitTypeDef;

typedef struct
{
    u8 Timer;
    u8 Time_Out;
    u8 Capture_Match;
    u8 Capture_Event;
    u8 Match;
    u8 PWM;
} Timer_Init_InterruptTypedef;

/* Timer Enums */

typedef enum
{
    Timer_0,
    Timer_1,
    Timer_2,
    Timer_3,
    Timer_4,
    Timer_5,
    WTimer_0,
    WTimer_1,
    WTimer_2,
    WTimer_3,
    WTimer_4,
    WTimer_5
} Timers_Type;

typedef enum
{
    Rising_Edge_Timer, Falling_Edge_Timer, Both_Timer = 0x03
} Timer_Trigger_Type;

typedef enum
{
    Off, On
} Timer_ON_OFF_Type;

typedef enum
{
    Non_Inverted, Inverted
} Timer_Output_Polarity;

typedef enum
{
    Concatenated, Individual = 0x04
} Timer_Config_Type;

typedef enum
{
    TimerA, TimerB
} Timer_Type;

typedef enum
{
    One_Shot = 0x01, Periodic, Capture
} Timer_Mode_Type;

typedef enum
{
    Down, Up
} Timer_Count_Mode_Type;

typedef enum
{
    Edge_Count, Edge_Time
} Timer_Edge_Mode_Type;

/* Function Prototypes */

void Timer_Init(Timer_RegDef_t *Timerx, Timer_InitTypeDef *Timer_Init);
void Timer_Clock_Init(u8 Timers);
void Timer_Interrupt_Init(Timer_RegDef_t* Timerx,
                          Timer_Init_InterruptTypedef* Timer_Int);
void Timer_SetMatch(Timer_RegDef_t *Timerx, u8 Timer, u64 Match);
u64 Timer_GetMatch(Timer_RegDef_t *Timerx, u8 Timer);
void Timer_SetLoad(Timer_RegDef_t *Timerx, u8 Timer, u64 Load);
u64 Timer_GetCount(Timer_RegDef_t *Timerx, u8 Timer);
void Timer_Interrupt_Register(u8 Timer, u8 SubTimer,
                              void (*pfnIntHandler)(void));

#endif /* MCAL_TIMER_DRIVERS_TIMER_H_ */
