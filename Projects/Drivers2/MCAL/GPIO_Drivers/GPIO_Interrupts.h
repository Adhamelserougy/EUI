#ifndef MCAL_GPIO_DRIVERS_GPIO_INTERRUPTS_H_
#define MCAL_GPIO_DRIVERS_GPIO_INTERRUPTS_H_

/* Includes */

#include <MCAL/GPIO_Drivers/GPIO.h>
#include <MCAL/Interrupts/Interrupt_Handlers.h>
#include <UTILS/std_typedefs.h>

/* Interrupt Pointers */

void (*ptr_GPIO[6])(u8 Pin);

/* Interrupt Structs */

typedef struct
{
    u8 Pin;
    u8 Sense;
    u8 Trigger;
} GPIO_Init_InterruptTypeDef;

/* Interrupt Enums */

typedef enum
{
    Edge, Level
} GPIO_Int_Sense_Type;

typedef enum
{
    Falling_Edge_GPIO,
    Rising_Edge_GPIO,
    Both_GPIO,
    Low_Level_GPIO = 0,
    High_Level_GPIO
} GPIO_Int_Trigger_Type;

/* Function Prototypes */

void GPIO_Int_Register(Port_Type Port, void (*pfnIntHandler)(u8 Pin));
void GPIO_Interrupt_Init(GPIO_RegDef_t *GPIOx,
                         GPIO_Init_InterruptTypeDef *GPIO_Init);

#endif /* MCAL_GPIO_DRIVERS_GPIO_INTERRUPTS_H_ */
