#ifndef APPLICATIONS_EDGE_TIME_CAPTURE_EDGE_TIME_CAPTURE_H_
#define APPLICATIONS_EDGE_TIME_CAPTURE_EDGE_TIME_CAPTURE_H_

/* Includes */

#include <MCAL/MCAL.h>

/* Function Prototypes */

void Edge_Time_Capture(void);
static void Init_GPIO(void);
static void Init_Timers(void);
static void wTimer3_B_IRQ_Handler_Callback(void);

#endif /* APPLICATIONS_EDGE_TIME_CAPTURE_EDGE_TIME_CAPTURE_H_ */
