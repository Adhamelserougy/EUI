#include "Delay.h"

void Delay(u16 delay)
{
    NVIC_ST_RELOAD_R = delay * Freq_Factor - 1; /* Load SYSTick timer value */
    NVIC_ST_CTRL_R = 0b1; /* Start Counter */
    u8 status = 0;
    while (status == 0)
    {
        status = (NVIC_ST_CTRL_R & (1 << 16)) >> 15;
    } /* Wait for timer to reach 0 */
    NVIC_ST_CURRENT_R = 0; /* Clears count flag in control register */
    NVIC_ST_CTRL_R &= 0; /* Stop timer */
}

void Delay_Micro(u32 delay)
{
    NVIC_ST_RELOAD_R = delay * Freq_Factor_Micro - 1; /* Load SYSTick timer value */
    NVIC_ST_CTRL_R = 0b1; /* Start Counter */
    u8 status = 0;
    while (status == 0)
    {
        status = (NVIC_ST_CTRL_R & (1 << 16)) >> 15;
    } /* Wait for timer to reach 0 */
    NVIC_ST_CURRENT_R = 0; /* Clears count flag in control register */
    NVIC_ST_CTRL_R &= 0; /* Stop timer */
}
