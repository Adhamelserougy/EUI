
#ifndef MCAL_DELAY_H_

#include <tm4c123gh6pm.h>
#include "UTILS/STDtypes.h"

#define MCAL_DELAY_H_

#define Freq_Factor 4000 /* Change according to clock frequency */
#define Freq_Factor_Micro 4 /* Change according to clock frequency */

void Delay(u16 delay);
void Delay_Micro(u32 delay);
//void SYSTick_Handler(void);

#endif /* MCAL_DELAY_H_ */
