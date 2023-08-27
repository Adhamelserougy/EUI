#ifndef APPLICATIONS_PERIODIC_DELAY_PERIODIC_DELAY_H_
#define APPLICATIONS_PERIODIC_DELAY_PERIODIC_DELAY_H_

/* Includes */

#include <MCAL/MCAL.h>

/* Function Prototypes */

void Periodic_Delay(void);
static void Init_GPIO(void);
static void Init_Timers(void);
static void Timer2_A_IRQ_Handler_Callback(void);

#endif /* APPLICATIONS_PERIODIC_DELAY_PERIODIC_DELAY_H_ */
