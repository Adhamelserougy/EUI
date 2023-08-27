#ifndef APPLICATIONS_BRIGHTNESS_CONTROL_BRIGHTNESS_CONTROL_H_
#define APPLICATIONS_BRIGHTNESS_CONTROL_BRIGHTNESS_CONTROL_H_

/* Includes */

#include <UTILS/Delay.h>
#include <MCAL/MCAL.h>

/* Function Prototypes */

void Brightness_Control(void);
static void Init_GPIO(void);
static void Init_Timers(void);

#endif /* APPLICATIONS_BRIGHTNESS_CONTROL_BRIGHTNESS_CONTROL_H_ */
