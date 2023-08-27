#include "MCAL/Interrupts/Interrupt_Handlers.h"

void Default_GPIO_IRQ_Handler(u8 pin)
{
    while (1)
        ;
}

void GPIOA_IRQ_Handler(void)
{
    (*ptr_GPIO[0])(GPIOF->MIS);
    GPIOF->ICR |= GPIOF->MIS;
}

void GPIOB_IRQ_Handler(void)
{
    (*ptr_GPIO[1])(GPIOF->MIS);
    GPIOF->ICR |= GPIOF->MIS;
}

void GPIOC_IRQ_Handler(void)
{
    (*ptr_GPIO[2])(GPIOF->MIS);
    GPIOF->ICR |= GPIOF->MIS;
}

void GPIOD_IRQ_Handler(void)
{
    (*ptr_GPIO[3])(GPIOF->MIS);
    GPIOF->ICR |= GPIOF->MIS;
}

void GPIOE_IRQ_Handler(void)
{
    (*ptr_GPIO[4])(GPIOF->MIS);
    GPIOF->ICR |= GPIOF->MIS;
}

void GPIOF_IRQ_Handler(void)
{
    (*ptr_GPIO[5])(GPIOF->MIS);
    GPIOF->ICR |= GPIOF->MIS;
}

void Timer0_A_IRQ_Handler(void)
{
    (*ptr_Timer[0])();
    Timer0->GPTMICR |= Timer0->GPTMMIS;
}

void Timer0_B_IRQ_Handler(void)
{
    (*ptr_Timer[1])();
    Timer0->GPTMICR |= Timer0->GPTMMIS;
}

void Timer1_A_IRQ_Handler(void)
{
    (*ptr_Timer[2])();
    Timer1->GPTMICR |= Timer1->GPTMMIS;
}

void Timer1_B_IRQ_Handler(void)
{
    (*ptr_Timer[3])();
    Timer1->GPTMICR |= Timer1->GPTMMIS;
}

void Timer2_A_IRQ_Handler(void)
{
    (*ptr_Timer[4])();
    Timer2->GPTMICR |= Timer2->GPTMMIS;
}

void Timer2_B_IRQ_Handler(void)
{
    (*ptr_Timer[5])();
    Timer2->GPTMICR |= Timer2->GPTMMIS;
}

void Timer3_A_IRQ_Handler(void)
{
    (*ptr_Timer[6])();
    Timer3->GPTMICR |= Timer3->GPTMMIS;
}

void Timer3_B_IRQ_Handler(void)
{
    (*ptr_Timer[7])();
    Timer3->GPTMICR |= Timer3->GPTMMIS;
}

void Timer4_A_IRQ_Handler(void)
{
    (*ptr_Timer[8])();
    Timer4->GPTMICR |= Timer4->GPTMMIS;
}

void Timer4_B_IRQ_Handler(void)
{
    (*ptr_Timer[9])();
    Timer4->GPTMICR |= Timer4->GPTMMIS;
}

void Timer5_A_IRQ_Handler(void)
{
    (*ptr_Timer[10])();
    Timer5->GPTMICR |= Timer5->GPTMMIS;
}

void Timer5_B_IRQ_Handler(void)
{
    (*ptr_Timer[11])();
    Timer5->GPTMICR |= Timer5->GPTMMIS;
}

void wTimer0_A_IRQ_Handler(void)
{
    (*ptr_Timer[12])();
    wTimer0->GPTMICR |= wTimer0->GPTMMIS;
}

void wTimer0_B_IRQ_Handler(void)
{
    (*ptr_Timer[13])();
    wTimer0->GPTMICR |= wTimer0->GPTMMIS;
}

void wTimer1_A_IRQ_Handler(void)
{
    (*ptr_Timer[14])();
    wTimer1->GPTMICR |= wTimer1->GPTMMIS;
}

void wTimer1_B_IRQ_Handler(void)
{
    (*ptr_Timer[15])();
    wTimer1->GPTMICR |= wTimer1->GPTMMIS;
}

void wTimer2_A_IRQ_Handler(void)
{
    (*ptr_Timer[16])();
    wTimer2->GPTMICR |= wTimer2->GPTMMIS;
}

void wTimer2_B_IRQ_Handler(void)
{
    (*ptr_Timer[17])();
    wTimer2->GPTMICR |= wTimer2->GPTMMIS;
}

void wTimer3_A_IRQ_Handler(void)
{
    (*ptr_Timer[18])();
    wTimer3->GPTMICR |= wTimer3->GPTMMIS;
}

void wTimer3_B_IRQ_Handler(void)
{
    (*ptr_Timer[19])();
    wTimer3->GPTMICR |= wTimer3->GPTMMIS;
}

void wTimer4_A_IRQ_Handler(void)
{
    (*ptr_Timer[20])();
    wTimer4->GPTMICR |= wTimer4->GPTMMIS;
}

void wTimer4_B_IRQ_Handler(void)
{
    (*ptr_Timer[21])();
    wTimer4->GPTMICR |= wTimer4->GPTMMIS;
}

void wTimer5_A_IRQ_Handler(void)
{
    (*ptr_Timer[22])();
    wTimer5->GPTMICR |= wTimer5->GPTMMIS;
}

void wTimer5_B_IRQ_Handler(void)
{
    (*ptr_Timer[23])();
    wTimer5->GPTMICR |= wTimer5->GPTMMIS;
}
