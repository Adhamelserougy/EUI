#ifndef APPLICATIONS_STOPWATCH_STOPWATCH_H_
#define APPLICATIONS_STOPWATCH_STOPWATCH_H_

/* Includes */

#include <HAL/LCD/LCD.h>
#include <MCAL/MCAL.h>
#include <UTILS/std_typedefs.h>

/* Defines */

#define StartStop PF0
#define Reset PF4

/* Stopwatch Struct */

typedef struct
{
    u8 hours;
    u8 minutes;
    u8 seconds;
} Time;

/* Function Prototypes */

void Stopwatch_Init(void);
void Stopwatch_Reset(void);
static void toString(void);
void Lap(void);
static void Init_GPIO(void);
void SYSTick_Handler(void);
void GPIOF_IRQ_Handler_Callback(u8 Pin);

#endif /* APPLICATIONS_STOPWATCH_STOPWATCH_H_ */
