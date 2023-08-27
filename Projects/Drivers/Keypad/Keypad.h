#ifndef KEYPAD_KEYPAD_H_
#define KEYPAD_KEYPAD_H_

#include "MCAL/GPIO_Drivers/GPIO_CTL.h"
#include "LCD/LCD.h"
#include "UTILS/Delay.h"

#define H1 PB0
#define H2 PB1
#define H3 PB2
#define H4 PB3
#define V1 PC4
#define V2 PC5
#define V3 PC6
#define V4 PC7

void GPIOC_Handler(void);
void Keypad_Init(void);
void Start(void);

#endif /* KEYPAD_KEYPAD_H_ */
