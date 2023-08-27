#include "main.h"

int main(void)
{
//    GPIO_Init(PF1, OUTPUT, FLOAT);
    GPIO_Init(D4, OUTPUT, FLOAT);
    GPIO_Init(D5, OUTPUT, FLOAT);
    GPIO_Init(D6, OUTPUT, FLOAT);
    GPIO_Init(D7, OUTPUT, FLOAT);
    GPIO_Init(EN, OUTPUT, FLOAT);
    GPIO_Init(RS, OUTPUT, FLOAT);
    LCD_Init();
    Delay(100);
    Send_String("Begin:");
    GPIO_Init(H1, OUTPUT, FLOAT);
    GPIO_Init(H2, OUTPUT, FLOAT);
    GPIO_Init(H3, OUTPUT, FLOAT);
    GPIO_Init(H4, OUTPUT, FLOAT);
    GPIO_Init(V1, INPUT, PULL_UP);
    GPIO_Init(V2, INPUT, PULL_UP);
    GPIO_Init(V3, INPUT, PULL_UP);
    GPIO_Init(V4, INPUT, PULL_UP);
    GPIO_InterruptInit(V1, FALLING_EDGE, 0);
    GPIO_InterruptInit(V2, FALLING_EDGE, 0);
    GPIO_InterruptInit(V3, FALLING_EDGE, 0);
    GPIO_InterruptInit(V4, FALLING_EDGE, 0);

    while (1)
    {
        Delay(1000);
        Send_Command(Clear);
        Keypad_Init();
        Start();
        app();
    }
}
