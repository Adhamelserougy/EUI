#ifndef MCAL_GPIO_DRIVERS_GPIO_REGS_H_
#define MCAL_GPIO_DRIVERS_GPIO_REGS_H_

#include "tm4c123gh6pm.h"
#include "UTILS/STDtypes.h"
#include "UTILS/bitwise_operation.h"

/* GPIO registers */
typedef struct{
    volatile u32* BASE;
    volatile u32* DATA;
    volatile u32* DIR;
    volatile u32* IS;
    volatile u32* IBE;
    volatile u32* IEV;
    volatile u32* IM;
    volatile u32* RIS;
    volatile u32* MIS;
    volatile u32* ICR;
    volatile u32* AFSEL;
    volatile u32* DR2R;
    volatile u32* DR4R;
    volatile u32* DR8R;
    volatile u32* ODR;
    volatile u32* PUR;
    volatile u32* PDR;
    volatile u32* SLR;
    volatile u32* DEN;
    volatile u32* LOCK;
    volatile u32* CR;
    volatile u32* AMSEL;
    volatile u32* PCTL;
    volatile u32* ADCCTL;
    volatile u32* DMACTL;
}GPIO_TYPE;

/* Pin numbers */
typedef enum{
    PA2 = 2, PA3, PA4, PA5, PA6, PA7,
    PB0, PB1 ,PB2, PB3, PB4, PB5, PB6, PB7,
    PC4 = 20, PC5, PC6, PC7,
    PD0, PD1, PD2, PD3, PD4, PD5, PD6, PD7,
    PE0, PE1, PE2, PE3, PE4, PE5,
    PF0 = 40, PF1, PF2, PF3, PF4
}PIN_TYPE;

/* Port numbers */
typedef enum{
    PortA, PortB, PortC, PortD, PortE, PortF
}PORT_TYPE;

#endif /* MCAL_GPIO_DRIVERS_GPIO_REGS_H_ */
