#include <MCAL/GPIO_Drivers/GPIO_Interrupts.h>

void GPIO_Interrupt_Init(GPIO_RegDef_t *GPIOx,
                         GPIO_Init_InterruptTypeDef *GPIO_Init)
{
    GPIOx->IM &= ~GPIO_Init->Pin;
    GPIOx->IS &= ~GPIO_Init->Pin;
    GPIOx->IBE &= ~GPIO_Init->Pin;
    GPIOx->IEV &= ~GPIO_Init->Pin;
    GPIOx->IS |= GPIO_Init->Sense ? GPIO_Init->Pin : 0;
    if (GPIO_Init->Trigger == Both_GPIO & GPIO_Init->Sense == Level)
    {
        GPIOx->IBE |= GPIO_Init->Pin;
    }
    else
    {
        GPIOx->IEV |= GPIO_Init->Trigger ? GPIO_Init->Pin : 0;
    }
    GPIOx->IM |= GPIO_Init->Pin;
}

void GPIO_Int_Register(Port_Type Port, void (*pfnIntHandler)(u8 Pin))
{
    ptr_GPIO[5] = pfnIntHandler;
}
