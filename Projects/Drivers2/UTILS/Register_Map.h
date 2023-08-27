#ifndef UTILS_REGISTER_MAP_H_
#define UTILS_REGISTER_MAP_H_

#include <UTILS/std_typedefs.h>

/******************************************** System Control Base Definition *********************************************/

#define SYSCTL_BASE_ADDRESS             0x400FE000UL

/******************************************** System Control Registers Definition ************************************/

typedef struct{
    volatile u32 DID0;                  /* Device Identification 0 */
    volatile u32 DID1;                  /*  */
    volatile u32 Reserved[10];          /*  */
    volatile u32 PBORCTL;               /*  */
    volatile u32 Reserved2[7];          /*  */
    volatile u32 RIS;                   /*  */
    volatile u32 IMC;                   /*  */
    volatile u32 MISC;                  /*  */
    volatile u32 RESC;                  /*  */
    volatile u32 RCC;                   /*  */
    volatile u32 Reserved3[2];          /*  */
    volatile u32 GPIOHCTL;              /*  */
    volatile u32 RCC2;                  /*  */
    volatile u32 Reserved4[2];          /*  */
    volatile u32 MOSCCTL;               /*  */
    volatile u32 Reserved5[49];         /*  */
    volatile u32 DSLPCLKCFG;            /*  */
    volatile u32 Reserved6;             /*  */
    volatile u32 SYSPROP;               /*  */
    volatile u32 PIOSCCAL;              /*  */
    volatile u32 PIOSCSTAT;             /*  */
    volatile u32 Reserved7[2];          /*  */
    volatile u32 PLLFREQ0;              /*  */
    volatile u32 PLLFREQ1;              /*  */
    volatile u32 PLLSTAT;               /*  */
    volatile u32 Reserved8[7];          /*  */
    volatile u32 SLPPWRCFG;             /*  */
    volatile u32 DSLPPWRCFG;            /*  */
    volatile u32 Reserved9[9];          /*  */
    volatile u32 LDOSPCTL;              /*  */
    volatile u32 LDOSPCAL;              /*  */
    volatile u32 LDODPCTL;              /*  */
    volatile u32 LDODPCAL;              /*  */
    volatile u32 Reserved10[2];         /*  */
    volatile u32 SDPMST;                /*  */
    volatile u32 Reserved11[76];        /*  */
    volatile u32 PPWD;                  /*  */
    volatile u32 PPTIMER;               /*  */
    volatile u32 PPGPIO;                /*  */
    volatile u32 PPDMA; /*  */
    volatile u32 Reserved12; /*  */
    volatile u32 PPHIB; /*  */
    volatile u32 PPUART; /*  */
    volatile u32 PPSSI; /*  */
    volatile u32 PPI2C; /*  */
    volatile u32 Reserved13; /*  */
    volatile u32 PPUSB; /*  */
    volatile u32 Reserved14[2]; /*  */
    volatile u32 PPCAN; /*  */
    volatile u32 PPADC; /*  */
    volatile u32 PPACMP; /*  */
    volatile u32 PPPWM; /*  */
    volatile u32 PPQEI; /*  */
    volatile u32 Reserved15[4]; /*  */
    volatile u32 PPEEPROM; /*  */
    volatile u32 PPWTIMER; /*  */
    volatile u32 Reserved16[104]; /*  */
    volatile u32 SRWD; /*  */
    volatile u32 SRTIMER; /*  */
    volatile u32 SRGPIO; /*  */
    volatile u32 SRDMA; /*  */
    volatile u32 Reserved17; /*  */
    volatile u32 SRHIB; /*  */
    volatile u32 SRUART; /*  */
    volatile u32 SRSSI; /*  */
    volatile u32 SRI2C; /*  */
    volatile u32 Reserved18; /*  */
    volatile u32 SRUSB; /*  */
    volatile u32 Reserved19[2]; /*  */
    volatile u32 SRCAN; /*  */
    volatile u32 SRADC; /*  */
    volatile u32 SRACMP; /*  */
    volatile u32 SRPWM; /*  */
    volatile u32 SRQEI; /*  */
    volatile u32 Reserved20[4]; /*  */
    volatile u32 SREEPROM; /*  */
    volatile u32 SRWTIMER; /*  */
    volatile u32 Reserved21[40]; /*  */
    volatile u32 RCGCWD; /*  */
    volatile u32 RCGCTIMER; /*  */
    volatile u32 RCGCGPIO; /*  */
    volatile u32 RCGCDMA; /*  */
    volatile u32 Reserved22; /*  */
    volatile u32 RCGCHIB; /*  */
    volatile u32 RCGCUART; /*  */
    volatile u32 RCGCSSI; /*  */
    volatile u32 RCGCI2C; /*  */
    volatile u32 Reserved23; /*  */
    volatile u32 RCGCUSB; /*  */
    volatile u32 Reserved24[2]; /*  */
    volatile u32 RCGCCAN; /*  */
    volatile u32 RCGCADC; /*  */
    volatile u32 RCGCACMP; /*  */
    volatile u32 RCGCPWM; /*  */
    volatile u32 RCGCQEI; /*  */
    volatile u32 Reserved25[4]; /*  */
    volatile u32 RCGCEEPROM; /*  */
    volatile u32 RCGCWTIMER; /*  */
    volatile u32 Reserved26[40]; /*  */
    volatile u32 SCGCWD; /*  */
    volatile u32 SCGCTIMER; /*  */
    volatile u32 SCGCGPIO; /*  */
    volatile u32 SCGCDMA; /*  */
    volatile u32 Reserved27; /*  */
    volatile u32 SCGCHIB; /*  */
    volatile u32 SCGCUART; /*  */
    volatile u32 SCGCSSI; /*  */
    volatile u32 SCGCI2C; /*  */
    volatile u32 Reserved28; /*  */
    volatile u32 SCGCUSB; /*  */
    volatile u32 Reserved29[2]; /*  */
    volatile u32 SCGCCAN; /*  */
    volatile u32 SCGCADC; /*  */
    volatile u32 SCGCACMP; /*  */
    volatile u32 SCGCPWM; /*  */
    volatile u32 SCGCQEI; /*  */
    volatile u32 Reserved30[4]; /*  */
    volatile u32 SCGCEEPROM; /*  */
    volatile u32 SCGCWTIMER; /*  */
    volatile u32 Reserved31[40]; /*  */
    volatile u32 DCGCWD; /*  */
    volatile u32 DCGCTIMER; /*  */
    volatile u32 DCGCGPIO; /*  */
    volatile u32 DCGCDMA; /*  */
    volatile u32 Reserved32; /*  */
    volatile u32 DCGCHIB; /*  */
    volatile u32 DCGCUART; /*  */
    volatile u32 DCGCSSI; /*  */
    volatile u32 DCGCI2C; /*  */
    volatile u32 Reserved33; /*  */
    volatile u32 DCGCUSB; /*  */
    volatile u32 Reserved34; /*  */
    volatile u32 DCGCCAN; /*  */
    volatile u32 DCGCADC; /*  */
    volatile u32 DCGCACMP; /*  */
    volatile u32 DCGCPWM; /*  */
    volatile u32 DCGCQEI; /*  */
    volatile u32 Reserved35[4]; /*  */
    volatile u32 DCGCEEPROM; /*  */
    volatile u32 DCGCWTIMER; /*  */
    volatile u32 Reserved36[104]; /*  */
    volatile u32 PRWD; /*  */
    volatile u32 PRTIMER; /*  */
    volatile u32 PRGPIO; /*  */
    volatile u32 PRDMA; /*  */
    volatile u32 Reserved37; /*  */
    volatile u32 PRHIB; /*  */
    volatile u32 PRUART; /*  */
    volatile u32 PRSSI; /*  */
    volatile u32 PRI2C; /*  */
    volatile u32 Reserved38; /*  */
    volatile u32 PRUSB; /*  */
    volatile u32 Reserved39[2]; /*  */
    volatile u32 PRCAN; /*  */
    volatile u32 PRADC; /*  */
    volatile u32 PRACMP; /*  */
    volatile u32 PRPWM; /*  */
    volatile u32 PRQEI; /*  */
    volatile u32 Reserved40[4]; /*  */
    volatile u32 PREEPROM; /*  */
    volatile u32 PRWTIMER; /*  */
}SysCTRL_RegDef_t;

#define SYSCTL                          ((SysCTRL_RegDef_t*) SYSCTL_BASE_ADDRESS)

/******************************************** GPIO Base Definition ***************************************************/

#define GPIOA_BASE_ADDRESS              0x40004000UL
#define GPIOB_BASE_ADDRESS              0x40005000UL
#define GPIOC_BASE_ADDRESS              0x40006000UL
#define GPIOD_BASE_ADDRESS              0x40007000UL
#define GPIOE_BASE_ADDRESS              0x40024000UL
#define GPIOF_BASE_ADDRESS              0x40025000UL

/******************************************** GPIO Registers Definition **********************************************/

typedef struct
{
    volatile u32 DATA[256];             /* GPIO Data */
    volatile u32 DIR;                   /* GPIO Direction */
    volatile u32 IS;                    /* GPIO Interrupt Sense */
    volatile u32 IBE;                   /* GPIO Interrupt Both Edges */
    volatile u32 IEV;                   /* GPIO Interrupt Even */
    volatile u32 IM;                    /* GPIO Interrupt Mask */
    volatile u32 RIS;                   /* GPIO Raw Interrupt Status */
    volatile u32 MIS;                   /* GPIO Masked Interrupt Status */
    volatile u32 ICR;                   /* GPIO Interrupt Clear */
    volatile u32 AFSEL;                 /* GPIO Alternate Function Select */
    volatile u32 Reserved[55];          /* Reserved Addresses */
    volatile u32 DR2R;                  /* GPIO 2-mA Drive Select */
    volatile u32 DR4R;                  /* GPIO 2-mA Drive Select */
    volatile u32 DR8R;                  /* GPIO 8-mA Drive Select */
    volatile u32 ODR;                   /* GPIO Open Drain Select */
    volatile u32 PUR;                   /* GPIO Pull-Up Select */
    volatile u32 PDR;                   /* GPIO Pull-Down Select */
    volatile u32 SLR;                   /* GPIO Slew Rate Control Select */
    volatile u32 DEN;                   /* GPIO Digital Enable */
    volatile u32 LOCK;                  /* GPIO Lock */
    volatile u32 CR;                    /* GPIO Commit */
    volatile u32 AMSEL;                 /* GPIO Analog Mode Select */
    volatile u32 PCTL;                  /* GPIO Port Control */
    volatile u32 ADCCTL;                /* GPIO ADC Control */
    volatile u32 DMACTL;                /* GPIO DMA Control */
    volatile u32 PeriphlD4;             /* GPIO Peripheral Identification 4 */
    volatile u32 PeriphlD5;             /* GPIO Peripheral Identification 5 */
    volatile u32 PeriphlD6;             /* GPIO Peripheral Identification 6 */
    volatile u32 PeriphlD7;             /* GPIO Peripheral Identification 6 */
    volatile u32 PeriphlD0;             /* GPIO Peripheral Identification 0 */
    volatile u32 PeriphlD1;             /* GPIO Peripheral Identification 1 */
    volatile u32 PeriphlD2;             /* GPIO Peripheral Identification 2 */
    volatile u32 PeriphlD3;             /* GPIO Peripheral Identification 3 */
    volatile u32 PCelllD0;              /* GPIO PrimeCell Identification 0 */
    volatile u32 PCelllD1;              /* GPIO PrimeCell Identification 1 */
    volatile u32 PCelllD2;              /* GPIO PrimeCell Identification 2 */
    volatile u32 PCelllD3;              /* GPIO PrimeCell Identification 3 */
} GPIO_RegDef_t;

#define GPIOA                           ((GPIO_RegDef_t*) GPIOA_BASE_ADDRESS)
#define GPIOB                           ((GPIO_RegDef_t*) GPIOB_BASE_ADDRESS)
#define GPIOC                           ((GPIO_RegDef_t*) GPIOC_BASE_ADDRESS)
#define GPIOD                           ((GPIO_RegDef_t*) GPIOD_BASE_ADDRESS)
#define GPIOE                           ((GPIO_RegDef_t*) GPIOE_BASE_ADDRESS)
#define GPIOF                           ((GPIO_RegDef_t*) GPIOF_BASE_ADDRESS)

/******************************************** Timer Base Definition **************************************************/

#define Timer0_BASE_ADDRESS             0x40030000UL
#define Timer1_BASE_ADDRESS             0x40031000UL
#define Timer2_BASE_ADDRESS             0x40032000UL
#define Timer3_BASE_ADDRESS             0x40033000UL
#define Timer4_BASE_ADDRESS             0x40034000UL
#define Timer5_BASE_ADDRESS             0x40035000UL
#define wTimer0_BASE_ADDRESS            0x40036000UL
#define wTimer1_BASE_ADDRESS            0x40037000UL
#define wTimer2_BASE_ADDRESS            0x4004C000UL
#define wTimer3_BASE_ADDRESS            0x4004D000UL
#define wTimer4_BASE_ADDRESS            0x4004E000UL
#define wTimer5_BASE_ADDRESS            0x4004F000UL

/******************************************** Timer Register Definition **********************************************/

typedef struct{
    volatile u32 GPTMCFG;               /*  */
    volatile u32 GPTMTAMR;              /*  */
    volatile u32 GPTMTBMR;              /*  */
    volatile u32 GPTMCTL;               /*  */
    volatile u32 GPTMSYNC;              /*  */
    volatile u32 Reserved;              /*  */
    volatile u32 GPTMIMR;               /*  */
    volatile u32 GPTMRIS;               /*  */
    volatile u32 GPTMMIS;               /*  */
    volatile u32 GPTMICR;               /*  */
    volatile u32 GPTMTAILR;             /*  */
    volatile u32 GPTMTBILR;             /*  */
    volatile u32 GPTMTAMATCHR;          /*  */
    volatile u32 GPTMTBMATCHR;          /*  */
    volatile u32 GPTMTAPR;              /*  */
    volatile u32 GPTMTBPR;              /*  */
    volatile u32 GPTMTAPMR;             /*  */
    volatile u32 GPTMTBPMR;             /*  */
    volatile u32 GPTMTAR;               /*  */
    volatile u32 GPTMTBR;               /*  */
    volatile u32 GPTMTAV;               /*  */
    volatile u32 GPTMTBV;               /*  */
    volatile u32 GPTMRTCPD;             /*  */
    volatile u32 GPTMTAPS;              /*  */
    volatile u32 GPTMTBPS;              /*  */
    volatile u32 GPTMTAPV;              /*  */
    volatile u32 GPTMTBPV;              /*  */
    volatile u32 Reserved2[981];        /*  */
    volatile u32 GPTMPP;                /*  */
}Timer_RegDef_t;

#define Timer0                          ((Timer_RegDef_t*) Timer0_BASE_ADDRESS)
#define Timer1                          ((Timer_RegDef_t*) Timer1_BASE_ADDRESS)
#define Timer2                          ((Timer_RegDef_t*) Timer2_BASE_ADDRESS)
#define Timer3                          ((Timer_RegDef_t*) Timer3_BASE_ADDRESS)
#define Timer4                          ((Timer_RegDef_t*) Timer4_BASE_ADDRESS)
#define Timer5                          ((Timer_RegDef_t*) Timer5_BASE_ADDRESS)
#define wTimer0                         ((Timer_RegDef_t*) wTimer0_BASE_ADDRESS)
#define wTimer1                         ((Timer_RegDef_t*) wTimer1_BASE_ADDRESS)
#define wTimer2                         ((Timer_RegDef_t*) wTimer2_BASE_ADDRESS)
#define wTimer3                         ((Timer_RegDef_t*) wTimer3_BASE_ADDRESS)
#define wTimer4                         ((Timer_RegDef_t*) wTimer4_BASE_ADDRESS)
#define wTimer5                         ((Timer_RegDef_t*) wTimer5_BASE_ADDRESS)

/******************************************** ADC Base Definition ****************************************************/

#define ADC0_BASE_ADDRESS               0x40038000UL
#define ADC1_BASE_ADDRESS               0x40039000UL

/******************************************** ADC Base Register ******************************************************/

typedef struct{
    volatile u32 ADCACTSS; /*  */
    volatile u32 ADCRIS; /*  */
    volatile u32 ADCIM; /*  */
    volatile u32 ADCISC; /*  */
    volatile u32 ADCOSTAT; /*  */
    volatile u32 ADCEMUX; /*  */
    volatile u32 ADCUSTAT; /*  */
    volatile u32 ADCTSSEL; /*  */
    volatile u32 ADCSSPRI; /*  */
    volatile u32 ADCSPC; /*  */
    volatile u32 ADCPSSI; /*  */
    volatile u32 Reserved; /*  */
    volatile u32 ADCSAC; /*  */
    volatile u32 ADCDCISC; /*  */
    volatile u32 ADCCTL; /*  */
    volatile u32 Reserved2; /*  */
    volatile u32 ADCSSMUX0; /*  */
    volatile u32 ADCSSCTL0; /*  */
    volatile u32 ADCSSFIFO0; /*  */
    volatile u32 ADCSSFSTAT0; /*  */
    volatile u32 ADCSSOP0; /*  */
    volatile u32 ADCSSDC0; /*  */
    volatile u32 Reserved3[2]; /*  */
    volatile u32 ADCSSMUX1; /*  */
    volatile u32 ADCSSCTL1; /*  */
    volatile u32 ADCSSFIFO1; /*  */
    volatile u32 ADCSSFSTAT1; /*  */
    volatile u32 ADCSSOP1; /*  */
    volatile u32 ADCSSDC1; /*  */
    volatile u32 Reserved4[2]; /*  */
    volatile u32 ADCSSMUX2; /*  */
    volatile u32 ADCSSFIFO2; /*  */
    volatile u32 ADCSSFSTAT2; /*  */
    volatile u32 ADCSSOP2; /*  */
    volatile u32 ADCSSDC2; /*  */
    volatile u32 Reserved5[2]; /*  */
    volatile u32 ADCSSMUX3; /*  */
    volatile u32 ADCSSCTL3; /*  */
    volatile u32 ADCSSFIFO3; /*  */
    volatile u32 ADCSSFSTAT3; /*  */
    volatile u32 ADCSSOP3; /*  */
    volatile u32 ADCSSDC3; /*  */
    volatile u32 Reserved6[787]; /*  */
    volatile u32 ADCDCRIC; /*  */
    volatile u32 Reserved7[63]; /*  */
    volatile u32 ADCDCCTL0; /*  */
    volatile u32 ADCDCCTL1; /*  */
    volatile u32 ADCDCCTL2; /*  */
    volatile u32 ADCDCCTL3; /*  */
    volatile u32 ADCDCCTL4; /*  */
    volatile u32 ADCDCCTL5; /*  */
    volatile u32 ADCDCCTL6; /*  */
    volatile u32 ADCDCCTL7; /*  */
    volatile u32 Reserved8[8]; /*  */
    volatile u32 ADCDCCMP0; /*  */
    volatile u32 ADCDCCMP1; /*  */
    volatile u32 ADCDCCMP2; /*  */
    volatile u32 ADCDCCMP3; /*  */
    volatile u32 ADCDCCMP4; /*  */
    volatile u32 ADCDCCMP5; /*  */
    volatile u32 ADCDCCMP6; /*  */
    volatile u32 ADCDCCMP7; /*  */
    volatile u32 Reserved9[88]; /*  */
    volatile u32 ADCPP; /*  */
    volatile u32 ADCPC; /*  */
    volatile u32 ADCCC; /*  */
}ADC_RegDef_t;

#define ADC0                            ((ADC_RegDef_t*) ADC0_BASE_ADDRESS)
#define ADC1                            ((ADC_RegDef_t*) ADC1_BASE_ADDRESS)

/******************************************** NVIC Base Definition ***************************************************/

#define NVIC_BASE_ADDRESS               0xE000E000UL

/******************************************** NVIC Register Definition ***********************************************/

typedef struct{
    volatile u32 Reserved[2];
    volatile u32 ACTLR; /*  */
    volatile u32 Reserved2;
    /* SysTick Registers */
    volatile u32 STCTRL;
    volatile u32 STRELEAD;
    volatile u32 STCURRENT;
    volatile u32 Reserved3[57]; /*  */
    /* NVIC Registers */
    volatile u32 EN0; /*  */
    volatile u32 EN1; /*  */
    volatile u32 EN2; /*  */
    volatile u32 EN3; /*  */
    volatile u32 EN4; /*  */
    volatile u32 Reserved4[27]; /*  */
    volatile u32 DIS0; /*  */
    volatile u32 DIS1; /*  */
    volatile u32 DIS2; /*  */
    volatile u32 DIS3; /*  */
    volatile u32 DIS4; /*  */
    volatile u32 Reserved5[27]; /*  */
    volatile u32 PEND0; /*  */
    volatile u32 PEND1; /*  */
    volatile u32 PEND2; /*  */
    volatile u32 PEND3; /*  */
    volatile u32 PEND4; /*  */
    volatile u32 Reserved6[27]; /*  */
    volatile u32 UNPEND0; /*  */
    volatile u32 UNPEND1; /*  */
    volatile u32 UNPEND2; /*  */
    volatile u32 UNPEND3; /*  */
    volatile u32 UNPEND4; /*  */
    volatile u32 Reserved7[27]; /*  */
    volatile u32 ACTIVE0; /*  */
    volatile u32 ACTIVE1; /*  */
    volatile u32 ACTIVE2; /*  */
    volatile u32 ACTIVE3; /*  */
    volatile u32 ACTIVE4; /*  */
    volatile u32 Reserved8[59]; /*  */
    volatile u32 PRI0; /*  */
    volatile u32 PRI1; /*  */
    volatile u32 PRI2; /*  */
    volatile u32 PRI3; /*  */
    volatile u32 PRI4; /*  */
    volatile u32 PRI5; /*  */
    volatile u32 PRI6; /*  */
    volatile u32 PRI7; /*  */
    volatile u32 PRI8; /*  */
    volatile u32 PRI9; /*  */
    volatile u32 PRI10; /*  */
    volatile u32 PRI11; /*  */
    volatile u32 PRI12; /*  */
    volatile u32 PRI13; /*  */
    volatile u32 PRI14; /*  */
    volatile u32 PRI15; /*  */
    volatile u32 PRI16; /*  */
    volatile u32 PRI17; /*  */
    volatile u32 PRI18; /*  */
    volatile u32 PRI19; /*  */
    volatile u32 PRI20; /*  */
    volatile u32 PRI21; /*  */
    volatile u32 PRI22; /*  */
    volatile u32 PRI23; /*  */
    volatile u32 PRI24; /*  */
    volatile u32 PRI25; /*  */
    volatile u32 PRI26; /*  */
    volatile u32 PRI27; /*  */
    volatile u32 PRI28; /*  */
    volatile u32 PRI29; /*  */
    volatile u32 PRI30; /*  */
    volatile u32 PRI31; /*  */
    volatile u32 PRI32; /*  */
    volatile u32 PRI33; /*  */
    volatile u32 PRI34; /*  */
    volatile u32 Reserved9[541]; /*  */
    volatile u32 CPUID; /*  */
    volatile u32 INTCTRL; /*  */
    volatile u32 VTABLE; /*  */
    volatile u32 APINT; /*  */
    volatile u32 SYSCTRL; /*  */
    volatile u32 CFGCTRL; /*  */
    volatile u32 SYSPRI1; /*  */
    volatile u32 SYSPRI2; /*  */
    volatile u32 SYSPRI3; /*  */
    volatile u32 SYSHNDCTRL; /*  */
    volatile u32 FAULTSTAT; /*  */
    volatile u32 HFAULTSTAT; /*  */
    volatile u32 Reserved10; /*  */
    volatile u32 MMADDR; /*  */
    volatile u32 FAULTADDR; /*  */
    volatile u32 Reserved11[19]; /*  */
    volatile u32 CPAC; /*  */
    volatile u32 Reserved12; /*  */
    volatile u32 MPUTYPE; /*  */
    volatile u32 MPUCTRL; /*  */
    volatile u32 MPUNUMBER; /*  */
    volatile u32 MPUBASE; /*  */
    volatile u32 MPUATTR; /*  */
    volatile u32 MPUBASE1; /*  */
    volatile u32 MPUATTR1; /*  */
    volatile u32 MPUBASE2; /*  */
    volatile u32 MPUATTR2; /*  */
    volatile u32 MPUBASE3; /*  */
    volatile u32 MPUATTR3; /*  */
    volatile u32 Reserved13[81]; /*  */
    volatile u32 SWTRIG; /*  */
    volatile u32 Reserved14[12]; /*  */
    volatile u32 FPCC; /*  */
    volatile u32 FPCA; /*  */
    volatile u32 FPDSC; /*  */
}NVIC_RegDef_t;

#define NVIC                            ((NVIC_RegDef_t*) NVIC_BASE_ADDRESS)

#endif /* UTILS_REGISTER_MAP_H_ */
