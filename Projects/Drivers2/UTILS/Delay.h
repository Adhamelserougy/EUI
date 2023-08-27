#ifndef UTILS_DELAY_H_
#define UTILS_DELAY_H_

/* Includes */

#include <UTILS/std_typedefs.h>
#include <UTILS/Register_Map.h>

/* Frequency Factors */

#define Freq_Factor_Milli               4000
#define Freq_Factor_Micro               4

/* Checks */

//#define Hardware_Delay /* Uses SysTick Timer */
#define Software_Delay

/* Function Prototypes */

void Delay_ms(u32 delay);
void Delay_us(u32 delay);

#endif /* UTILS_DELAY_H_ */
