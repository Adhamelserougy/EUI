#ifndef MCAL_INTERRUPTS_NVIC_H_
#define MCAL_INTERRUPTS_NVIC_H_

/* Includes */

#include <UTILS/Register_Map.h>
#include <UTILS/std_typedefs.h>

/* Interrupt Numbers */

#define GPIOA_Int                       0
#define GPIOB_Int                       1
#define GPIOC_Int                       2
#define GPIOD_Int                       3
#define GPIOE_Int                       4
#define UART0_Int                       5
#define UART1_Int                       6
#define SSI0_Int                        7
#define I2C0_Int                        8
#define PWM0_Fault_Int                  9
#define PWM0_Generator0_Int             10
#define PWM0_Generator1_Int             11
#define PWM0_Generator2_Int             12
#define QEI0_Int                        13
#define ADC0_Sequence0_Int              14
/* TBC */
#define Timer0_A_Int                    19
#define Timer0_B_Int                    20
#define Timer1_A_Int                    21
#define Timer1_B_Int                    22
#define Timer2_A_Int                    23
#define Timer2_B_Int                    24
/* TBC */
#define GPIOF_Int                       30
/* TBC */
#define Timer3_A_Int                    35
#define Timer3_B_Int                    36
/* TBC */
#define Timer4_A_Int                    70
#define Timer4_B_Int                    71
#define Timer5_A_Int                    92
#define Timer5_B_Int                    93
#define WTimer0_A_Int                   94
#define WTimer0_B_Int                   95
#define WTimer1_A_Int                   96
#define WTimer1_B_Int                   97
#define WTimer2_A_Int                   98
#define WTimer2_B_Int                   99
#define WTimer3_A_Int                   100
#define WTimer3_B_Int                   101
#define WTimer4_A_Int                   102
#define WTimer4_B_Int                   103
#define WTimer5_A_Int                   104
#define WTimer5_B_Int                   105
/* TBC */

/* Function Prototypes */

void NVIC_Enable(u8 Int);
void NVIC_Set_Priority(u8 Int, u8 Priority);

#endif /* MCAL_INTERRUPTS_NVIC_H_ */
