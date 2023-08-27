#include <UTILS/Delay.h>

#ifdef Hardware_Delay

/* Delay in milliseconds */

void Delay_ms(u32 delay){
    NVIC->STRELEAD = delay * Freq_Factor_Milli - 1;
    NVIC->STCURRENT = 0xFF;
    NVIC->STCTRL = 0x01;
    while(!(NVIC->STCTRL&(1<<16)));
    NVIC->STCURRENT = 0xFF;
    NVIC->STCTRL = 0;
}

/* Delay in microseconds */

void Delay_us(u32 delay){
    NVIC->STRELEAD = delay * Freq_Factor_Micro - 1;
    NVIC->STCURRENT = 0xFF;
    NVIC->STCTRL = 0x01;
    while(!(NVIC->STCTRL&(1<<16)));
    NVIC->STCURRENT = 0xFF;
    NVIC->STCTRL = 0;
}

#endif

#ifdef Software_Delay

/* Delay in millisecond */

void Delay_ms(u32 delay)
{
    delay *= 762;
    u32 i;
    for(i = delay; i > 0; i--);
}

/* Delay in microsecond not accurate */

void Delay_us(u32 delay)
{
    u32 i;
    for(i = delay; i > 0; i--);
}

#endif
