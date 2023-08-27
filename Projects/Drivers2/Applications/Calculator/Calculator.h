#ifndef APPLICATIONS_CALCULATOR_CALCULATOR_H_
#define APPLICATIONS_CALCULATOR_CALCULATOR_H_

/* Includes */

#include <MCAL/MCAL.h>
#include <HAL/Keypad/Keypad.h>
#include <HAL/LCD/LCD.h>
#include <UTILS/Delay.h>

/* Defines */

#define arrsize 20

/* Function Prototype */

void Calculator_App(void);
static void Init_GPIO(void);
static void Get_Buttons(void);
static void Calculator(void);
static void Sort_Operands(u8 index);
static void Sort_Operators(u8 index);
static void Filter_Input(void);
static void Clear_Data(void);
static void toString(void);
static void Calculator_Handler_Callback(u8 Pin);

#endif /* APPLICATIONS_CALCULATOR_CALCULATOR_H_ */
