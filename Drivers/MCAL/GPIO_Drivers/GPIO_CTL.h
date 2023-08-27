#ifndef MCAL_GPIO_DRIVERS_GPIO_CTL_H_
#define MCAL_GPIO_DRIVERS_GPIO_CTL_H_

#include "GPIO_Regs.h"

typedef enum{
    INPUT, OUTPUT
}MODE_TYPE;

typedef enum{
    FLOAT, PULL_UP, PULL_DOWN
}PULL_TYPE;

typedef enum{
    LOW, HIGH
}STATE_TYPE;

void GPIO_Init(PIN_TYPE,MODE_TYPE,PULL_TYPE);
void GPIO_Write(PIN_TYPE, STATE_TYPE);
void GPIO_Write_Port(PORT_TYPE, u8);
u8 GPIO_Read(PIN_TYPE);
void GPIO_Toggle(PIN_TYPE);
void GPIO_Port_Enable(u8);

#endif /* MCAL_GPIO_DRIVERS_GPIO_CTL_H_ */
