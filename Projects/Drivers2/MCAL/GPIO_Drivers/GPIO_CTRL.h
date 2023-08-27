#ifndef MCAL_GPIO_DRIVERS_GPIO_CTRL_H_
#define MCAL_GPIO_DRIVERS_GPIO_CTRL_H_

/* Includes */

#include <UTILS/Register_Map.h>
#include <UTILS/std_typedefs.h>
#include <MCAL/GPIO_Drivers/GPIO.h>

/* Config Structs */

typedef struct
{
    u8 Pin;
    u8 Mode;
    u8 Pull;
    u8 AF;
    u8 AF_Mode;
} GPIO_InitTypeDef;

/* Config Enums */

typedef enum
{
    Input = 0, Output = 1
} GPIO_Mode_Type;

typedef enum
{
    NOPULL, PULL_UP, PULL_DOWN
} Pull_Mode_type;

typedef enum
{
    Low, High
} GPIO_State_Type;

/* Function Prototypes */

void GPIO_Init(GPIO_RegDef_t *GPIOx, GPIO_InitTypeDef *GPIO_Init);
void GPIO_Clock_Init(Port_Type Port);
void GPIO_Write(GPIO_RegDef_t *GPIOx, u8 Pin, u8 Mode);
void GPIO_Write_Pins(GPIO_RegDef_t *GPIOx, u8 Pins, u8 State);
void GPIO_Toggle(GPIO_RegDef_t *GPIOx, u8 Pins);
u8 GPIO_Read(GPIO_RegDef_t *GPIOx, u8 Pins);

#endif /* MCAL_GPIO_DRIVERS_GPIO_CTRL_H_ */
