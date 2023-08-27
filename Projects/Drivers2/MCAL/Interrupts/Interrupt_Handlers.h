#ifndef MCAL_INTERRUPTS_INTERRUPT_HANDLERS_H_
#define MCAL_INTERRUPTS_INTERRUPT_HANDLERS_H_

/* Includes */

#include <UTILS/Register_Map.h>
#include <MCAL/GPIO_Drivers/GPIO.h>
#include "MCAL/Interrupts/NVIC.h"

/* Interrupt Handler Prototypes */

void Default_GPIO_IRQ_Handler(u8);
void GPIOA_IRQ_Handler(void);
void GPIOB_IRQ_Handler(void);
void GPIOC_IRQ_Handler(void);
void GPIOD_IRQ_Handler(void);
void GPIOE_IRQ_Handler(void);
void GPIOF_IRQ_Handler(void);
void Timer0_A_IRQ_Handler(void);
void Timer0_B_IRQ_Handler(void);
void Timer1_A_IRQ_Handler(void);
void Timer1_B_IRQ_Handler(void);
void Timer2_A_IRQ_Handler(void);
void Timer2_B_IRQ_Handler(void);
void Timer3_A_IRQ_Handler(void);
void Timer3_B_IRQ_Handler(void);
void Timer4_A_IRQ_Handler(void);
void Timer4_B_IRQ_Handler(void);
void Timer5_A_IRQ_Handler(void);
void Timer5_B_IRQ_Handler(void);
void wTimer0_A_IRQ_Handler(void);
void wTimer0_B_IRQ_Handler(void);
void wTimer1_A_IRQ_Handler(void);
void wTimer1_B_IRQ_Handler(void);
void wTimer2_A_IRQ_Handler(void);
void wTimer2_B_IRQ_Handler(void);
void wTimer3_A_IRQ_Handler(void);
void wTimer3_B_IRQ_Handler(void);
void wTimer4_A_IRQ_Handler(void);
void wTimer4_B_IRQ_Handler(void);
void wTimer5_A_IRQ_Handler(void);
void wTimer5_B_IRQ_Handler(void);

/* Callback Function Pointers */

extern void (*ptr_GPIO[6])(u8 pin);
extern void (*ptr_Timer[24])(void);

#endif /* MCAL_INTERRUPTS_INTERRUPT_HANDLERS_H_ */
