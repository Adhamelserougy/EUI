#include <HAL/Keypad/Keypad.h>

void Keypad_Init(void)
{
    GPIO_Write(GPIOD, H1 | H2 | H3 | H4, 0);
}
