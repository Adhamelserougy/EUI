#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include "UTILS/STDtypes.h"
#include "LCD/LCD.h"
#include "Keypad/Keypad.h"

#define arrsize 20

void Calculator(void);
void Filter_Input(void);
void Sort_Operands(u8 index);
void Sort_Operators(u8 index);
void Clear_Data(void);
void app(void);
void toString(void);

#endif /* CALCULATOR_H_ */
