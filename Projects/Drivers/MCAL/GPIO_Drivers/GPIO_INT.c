#include "GPIO_INT.h"

void GPIO_InterruptInit(PIN_TYPE pin, TRIGGER_TYPE trigger, u8 priority)
{
    u8 port = pin / 8;
    u8 pin_num = pin % 8;
    u8 sense = trigger / 2;
    switch (sense)
    {
    case 2:
        CLEAR_BIT(*(Ports[port].IS), pin_num);
        SET_BIT(*(Ports[port].IBE), pin_num);
        break;
    case 1:
        SET_BIT(*(Ports[port].IS), pin_num);
        CLEAR_BIT(*(Ports[port].IBE), pin_num);
        if (trigger == 1)
        {
            SET_BIT(*(Ports[port].IEV), pin_num);
        }
        else
        {
            CLEAR_BIT(*(Ports[port].IEV), pin_num);
        }
        break;
    case 0:
        CLEAR_BIT(*(Ports[port].IS), pin_num);
        CLEAR_BIT(*(Ports[port].IBE), pin_num);
        if (trigger == 1)
        {
            SET_BIT(*(Ports[port].IEV), pin_num);
        }
        else
        {
            CLEAR_BIT(*(Ports[port].IEV), pin_num);
        }
    default:
        break;
    }
    SET_BIT(*(Ports[port].IM), pin_num);
    GPIO_NVIC_Enable(port,priority);
}
void GPIO_InterruptDisable(PIN_TYPE pin){
    u8 port = pin / 8;
    u8 pin_num = pin % 8;
    GPIO_NVIC_Disable(port);
    CLEAR_BIT(*(Ports[port].IM), pin_num);
    CLEAR_BIT(*(Ports[port].IS), pin_num);
    CLEAR_BIT(*(Ports[port].IBE), pin_num);
    CLEAR_BIT(*(Ports[port].IEV), pin_num);
}

void GPIO_NVIC_Enable(u8 port, u8 priority)
{
    switch (port)
    {
    case 0:
        NVIC_EN0_R |= (1 << 0);
        NVIC_PRI0_R |= (priority<<5);
        break;
    case 1:
        NVIC_EN0_R |= (1 << 1);
        NVIC_PRI0_R |= (priority<<13);
        break;
    case 2:
        NVIC_EN0_R |= (1 << 2);
        NVIC_PRI0_R |= (priority<<21);
        break;
    case 3:
        NVIC_EN0_R |= (1 << 3);
        NVIC_PRI0_R |= (priority<<29);
        break;
    case 4:
        NVIC_EN0_R |= (1 << 4);
        NVIC_PRI1_R |= (priority<<5);
        break;
    case 5:
        NVIC_EN0_R |= (1 << 30);
        NVIC_PRI7_R |= (priority<<21);
        break;
    default:
        break;
    }
}

void GPIO_NVIC_Disable(u8 port){
    switch (port)
    {
    case 0:
        NVIC_DIS0_R |= (1 << 0);
        NVIC_PRI0_R &= ~(7<<5);
        break;
    case 1:
        NVIC_DIS0_R |= (1 << 1);
        NVIC_PRI0_R &= ~(7<<13);
        break;
    case 2:
        NVIC_DIS0_R |= (1 << 2);
        NVIC_PRI0_R &= ~(7<<21);
        break;
    case 3:
        NVIC_DIS0_R |= (1 << 3);
        NVIC_PRI0_R &= ~(7<<29);
        break;
    case 4:
        NVIC_DIS0_R |= (1 << 4);
        NVIC_PRI1_R &= ~(7<<5);
        break;
    case 5:
        NVIC_DIS0_R |= (1 << 30);
        NVIC_PRI7_R &= ~(7<<21);
        break;
    default:
        break;
    }
}
