#include <MCAL/GPIO_Drivers/GPIO_CTRL.h>

/* Initializes GPIO */

void GPIO_Init(GPIO_RegDef_t *GPIOx, GPIO_InitTypeDef *GPIO_Init)
{
    if ((u32)&(*GPIOx) == 0x40006000UL && GPIO_Init->Pin & 0x0F)
    {
        while (1)
            ;
    }
    else if ((u32)&(*GPIOx) == 0x40004000UL && GPIO_Init->Pin & 0x07)
    {
        while (1)
            ;
    }
    GPIOx->LOCK = 0x4C4F434B;
    GPIOx->CR |= GPIO_Init->Pin;
    GPIOx->DIR |= GPIO_Init->Mode ? GPIO_Init->Pin : 0;
    switch (GPIO_Init->Pull)
    {
    case NOPULL:
        GPIOx->PUR &= ~GPIO_Init->Pin;
        GPIOx->PDR &= ~GPIO_Init->Pin;
        break;
    case PULL_UP:
        GPIOx->PUR |= GPIO_Init->Pin;
        GPIOx->PDR &= ~GPIO_Init->Pin;
        break;
    case PULL_DOWN:
        GPIOx->PUR &= ~GPIO_Init->Pin;
        GPIOx->PDR |= GPIO_Init->Pin;
        break;
    default:
        break;
    }
    u8 pin_value;
    switch (GPIO_Init->Pin)
    {
    case 0x01:
        pin_value = 0;
        break;
    case 0x02:
        pin_value = 1;
        break;
    case 0x04:
        pin_value = 2;
        break;
    case 0x08:
        pin_value = 3;
        break;
    case 0x10:
        pin_value = 4;
        break;
    case 0x20:
        pin_value = 5;
        break;
    case 0x40:
        pin_value = 6;
        break;
    case 0x80:
        pin_value = 7;
        break;
    default:
        break;
    }
    if (GPIO_Init->AF)
    {
        GPIOx->AFSEL |= GPIO_Init->Pin;
        GPIOx->PCTL |= (GPIO_Init->AF_Mode << (pin_value * 4));
    }
    else
    {
        GPIOx->AFSEL &= ~GPIO_Init->Pin;
        GPIOx->PCTL &= ~(0x0F << (pin_value * 4));
    }
    GPIOx->DEN |= GPIO_Init->Pin;
}

/* Enables Port Clock */

void GPIO_Clock_Init(Port_Type Port)
{
    SYSCTL->RCGCGPIO |= Port;
}

/* Writes to pins */

void GPIO_Write(GPIO_RegDef_t *GPIOx, u8 Pin, u8 State)
{
    GPIOx->DATA[Pin] =  State ? Pin : 0;
}

void GPIO_Write_Pins(GPIO_RegDef_t *GPIOx, u8 Pins, u8 State)
{
    GPIOx->DATA[Pins] = State;
}

/* Toggles Pins */

void GPIO_Toggle(GPIO_RegDef_t *GPIOx, u8 Pins)
{
    GPIOx->DATA[Pins] ^= Pins;
}

/* Reads Pins */

u8 GPIO_Read(GPIO_RegDef_t *GPIOx, u8 Pin)
{
    return GPIOx->DATA[Pin];
}
