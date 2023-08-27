#include "GPIO_CTL.h"

const GPIO_TYPE Ports[6] = {{.BASE = GPIO_PORTA_DATA_BITS_R, .DATA = &GPIO_PORTA_DATA_R, .DIR = &GPIO_PORTA_DIR_R, .IS = &GPIO_PORTA_IS_R,
                             .IBE = &GPIO_PORTA_IBE_R, .IEV = &GPIO_PORTA_IEV_R, .IM = &GPIO_PORTA_IM_R, .RIS = &GPIO_PORTA_RIS_R,
                             .MIS = &GPIO_PORTA_ICR_R, .AFSEL = &GPIO_PORTA_AFSEL_R, .DR2R = &GPIO_PORTA_DR2R_R, .DR4R = &GPIO_PORTA_DR4R_R,
                             .DR8R = &GPIO_PORTA_DR8R_R, .ODR = &GPIO_PORTA_ODR_R, .PUR = &GPIO_PORTA_PUR_R, .PDR  = &GPIO_PORTA_PDR_R,
                             .SLR = &GPIO_PORTA_SLR_R, .DEN = &GPIO_PORTA_DEN_R, .LOCK = &GPIO_PORTA_LOCK_R, .CR = &GPIO_PORTA_CR_R,
                             .AMSEL = &GPIO_PORTA_AMSEL_R, .PCTL = &GPIO_PORTA_PCTL_R, .ADCCTL = &GPIO_PORTA_ADCCTL_R, .DMACTL = &GPIO_PORTA_DMACTL_R},
                            {.BASE = GPIO_PORTB_DATA_BITS_R, .DATA = &GPIO_PORTB_DATA_R, .DIR = &GPIO_PORTB_DIR_R, .IS = &GPIO_PORTB_IS_R,
                             .IBE = &GPIO_PORTB_IBE_R, .IEV = &GPIO_PORTB_IEV_R, .IM = &GPIO_PORTB_IM_R, .RIS = &GPIO_PORTB_RIS_R,
                             .MIS = &GPIO_PORTB_ICR_R, .AFSEL = &GPIO_PORTB_AFSEL_R, .DR2R = &GPIO_PORTB_DR2R_R, .DR4R = &GPIO_PORTB_DR4R_R,
                             .DR8R = &GPIO_PORTB_DR8R_R, .ODR = &GPIO_PORTB_ODR_R, .PUR = &GPIO_PORTB_PUR_R, .PDR  = &GPIO_PORTB_PDR_R,
                             .SLR = &GPIO_PORTB_SLR_R, .DEN = &GPIO_PORTB_DEN_R, .LOCK = &GPIO_PORTB_LOCK_R, .CR = &GPIO_PORTB_CR_R,
                             .AMSEL = &GPIO_PORTB_AMSEL_R, .PCTL = &GPIO_PORTB_PCTL_R, .ADCCTL = &GPIO_PORTB_ADCCTL_R, .DMACTL = &GPIO_PORTB_DMACTL_R},
                            {.BASE = GPIO_PORTC_DATA_BITS_R, .DATA = &GPIO_PORTC_DATA_R, .DIR = &GPIO_PORTC_DIR_R, .IS = &GPIO_PORTC_IS_R,
                             .IBE = &GPIO_PORTC_IBE_R, .IEV = &GPIO_PORTC_IEV_R, .IM = &GPIO_PORTC_IM_R, .RIS = &GPIO_PORTC_RIS_R,
                             .MIS = &GPIO_PORTC_ICR_R, .AFSEL = &GPIO_PORTC_AFSEL_R, .DR2R = &GPIO_PORTC_DR2R_R, .DR4R = &GPIO_PORTC_DR4R_R,
                             .DR8R = &GPIO_PORTC_DR8R_R, .ODR = &GPIO_PORTC_ODR_R, .PUR = &GPIO_PORTC_PUR_R, .PDR  = &GPIO_PORTC_PDR_R,
                             .SLR = &GPIO_PORTC_SLR_R, .DEN = &GPIO_PORTC_DEN_R, .LOCK = &GPIO_PORTC_LOCK_R, .CR = &GPIO_PORTC_CR_R,
                             .AMSEL = &GPIO_PORTC_AMSEL_R, .PCTL = &GPIO_PORTC_PCTL_R, .ADCCTL = &GPIO_PORTC_ADCCTL_R, .DMACTL = &GPIO_PORTC_DMACTL_R},
                            {.BASE = GPIO_PORTD_DATA_BITS_R, .DATA = &GPIO_PORTD_DATA_R, .DIR = &GPIO_PORTD_DIR_R, .IS = &GPIO_PORTD_IS_R,
                             .IBE = &GPIO_PORTD_IBE_R, .IEV = &GPIO_PORTD_IEV_R, .IM = &GPIO_PORTD_IM_R, .RIS = &GPIO_PORTD_RIS_R,
                             .MIS = &GPIO_PORTD_ICR_R, .AFSEL = &GPIO_PORTD_AFSEL_R, .DR2R = &GPIO_PORTD_DR2R_R, .DR4R = &GPIO_PORTD_DR4R_R,
                             .DR8R = &GPIO_PORTD_DR8R_R, .ODR = &GPIO_PORTD_ODR_R, .PUR = &GPIO_PORTD_PUR_R, .PDR  = &GPIO_PORTD_PDR_R,
                             .SLR = &GPIO_PORTD_SLR_R, .DEN = &GPIO_PORTD_DEN_R, .LOCK = &GPIO_PORTD_LOCK_R, .CR = &GPIO_PORTD_CR_R,
                             .AMSEL = &GPIO_PORTD_AMSEL_R, .PCTL = &GPIO_PORTD_PCTL_R, .ADCCTL = &GPIO_PORTD_ADCCTL_R, .DMACTL = &GPIO_PORTD_DMACTL_R},
                            {.BASE = GPIO_PORTE_DATA_BITS_R, .DATA = &GPIO_PORTE_DATA_R, .DIR = &GPIO_PORTE_DIR_R, .IS = &GPIO_PORTE_IS_R,
                             .IBE = &GPIO_PORTE_IBE_R, .IEV = &GPIO_PORTE_IEV_R, .IM = &GPIO_PORTE_IM_R, .RIS = &GPIO_PORTE_RIS_R,
                             .MIS = &GPIO_PORTE_ICR_R, .AFSEL = &GPIO_PORTE_AFSEL_R, .DR2R = &GPIO_PORTE_DR2R_R, .DR4R = &GPIO_PORTE_DR4R_R,
                             .DR8R = &GPIO_PORTE_DR8R_R, .ODR = &GPIO_PORTE_ODR_R, .PUR = &GPIO_PORTE_PUR_R, .PDR  = &GPIO_PORTE_PDR_R,
                             .SLR = &GPIO_PORTE_SLR_R, .DEN = &GPIO_PORTE_DEN_R, .LOCK = &GPIO_PORTE_LOCK_R, .CR = &GPIO_PORTE_CR_R,
                             .AMSEL = &GPIO_PORTE_AMSEL_R, .PCTL = &GPIO_PORTE_PCTL_R, .ADCCTL = &GPIO_PORTE_ADCCTL_R, .DMACTL = &GPIO_PORTE_DMACTL_R},
                            {.BASE = GPIO_PORTF_DATA_BITS_R, .DATA = &GPIO_PORTF_DATA_R, .DIR = &GPIO_PORTF_DIR_R, .IS = &GPIO_PORTF_IS_R,
                             .IBE = &GPIO_PORTF_IBE_R, .IEV = &GPIO_PORTF_IEV_R, .IM = &GPIO_PORTF_IM_R, .RIS = &GPIO_PORTF_RIS_R,
                             .MIS = &GPIO_PORTF_ICR_R, .AFSEL = &GPIO_PORTF_AFSEL_R, .DR2R = &GPIO_PORTF_DR2R_R, .DR4R = &GPIO_PORTF_DR4R_R,
                             .DR8R = &GPIO_PORTF_DR8R_R, .ODR = &GPIO_PORTF_ODR_R, .PUR = &GPIO_PORTF_PUR_R, .PDR  = &GPIO_PORTF_PDR_R,
                             .SLR = &GPIO_PORTF_SLR_R, .DEN = &GPIO_PORTF_DEN_R, .LOCK = &GPIO_PORTF_LOCK_R, .CR = &GPIO_PORTF_CR_R,
                             .AMSEL = &GPIO_PORTF_AMSEL_R, .PCTL = &GPIO_PORTF_PCTL_R, .ADCCTL = &GPIO_PORTF_ADCCTL_R, .DMACTL = &GPIO_PORTF_DMACTL_R}
};

/* Clock enable flag */
static u8 PORT_CLOCK_FLAG[6] = { 0, 0, 0, 0, 0, 0 };

void GPIO_Init(PIN_TYPE pin, MODE_TYPE mode, PULL_TYPE pull)
{
    u8 port = pin / 8;
    u8 pin_num = pin % 8;
    GPIO_Port_Enable(port);
    *(Ports[port].LOCK) = 0x4C4F434BU;
    SET_BIT(*(Ports[port].CR), pin_num);
    switch (mode)
    {
    case INPUT:
        CLEAR_BIT(*(Ports[port].DIR), pin_num);
        break;
    case OUTPUT:
        SET_BIT(*(Ports[port].DIR), pin_num);
        break;
    default:
        break;
    }
    switch (pull)
    {
    case FLOAT:
        CLEAR_BIT(*(Ports[port].PUR), pin_num);
        CLEAR_BIT(*(Ports[port].PDR), pin_num);
        break;
    case PULL_UP:
        CLEAR_BIT(*(Ports[port].PDR), pin_num);
        SET_BIT(*(Ports[port].PUR), pin_num);
        break;
    case PULL_DOWN:
        CLEAR_BIT(*(Ports[port].PUR), pin_num);
        SET_BIT(*(Ports[port].PDR), pin_num);
        break;
    default:
        break;
    }
    SET_BIT(*(Ports[port].DEN), pin_num);
}
void GPIO_Write(PIN_TYPE pin, STATE_TYPE state)
{
    u8 port = pin / 8;
    u8 pin_num = pin % 8;
    if (state == 1)
    {
        Ports[port].BASE[1 << pin_num] = 1 << pin_num;
    }
    else
    {
        Ports[port].BASE[1 << pin_num] = 0;
    }
}

void GPIO_Write_Port(PORT_TYPE port, u8 data){
    *(Ports[port].DATA) = data;
}

u8 GPIO_Read(PIN_TYPE pin)
{
    u8 port = pin / 8;
    u8 pin_num = pin % 8;
    return READ_BIT(*(Ports[port].DATA), pin_num);
}

void GPIO_Toggle(PIN_TYPE pin)
{
    u8 port = pin / 8;
    u8 pin_num = pin % 8;
    TOGGLE_BIT(*(Ports[port].DATA), pin_num);
}

void GPIO_Port_Enable(u8 port)
{
    if (PORT_CLOCK_FLAG[port] != 0)
    {
        return;
    }
    else
    {
        SYSCTL_RCGCGPIO_R |= (1 << port);
        PORT_CLOCK_FLAG[port] = 1;
    }
}
