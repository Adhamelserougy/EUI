#ifndef MCAL_GPIO_DRIVERS_GPIO_INT_H_
#define MCAL_GPIO_DRIVERS_GPIO_INT_H_

#include "GPIO_Regs.h"

typedef enum{
    FALLING_EDGE, RISING_EDGE,
    LOW_LEVEL, HIGH_LEVEL, BOTH
}TRIGGER_TYPE;

extern const GPIO_TYPE Ports[6];

void GPIO_InterruptInit(PIN_TYPE, TRIGGER_TYPE, u8);
void GPIO_InterruptDisable(PIN_TYPE);
void GPIO_NVIC_Enable(u8,u8);
void GPIO_NVIC_Disable(u8);

#endif /* MCAL_GPIO_DRIVERS_GPIO_INT_H_ */
