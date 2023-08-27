#include "MCAL/Interrupts/NVIC.h"

void NVIC_Enable(u8 Int){
    u8 EN_Num = Int / 32;
    u8 Int_Num = Int % 32;
    switch (EN_Num) {
        case 0:
            NVIC->EN0 |= (1<<Int_Num);
            break;
        case 1:
            NVIC->EN1 |= (1<<Int_Num);
            break;
        case 2:
            NVIC->EN2 |= (1<<Int_Num);
            break;
        case 3:
            NVIC->EN3 |= (1<<Int_Num);
            break;
        case 4:
            NVIC->EN4 |= (1<<Int_Num);
            break;
        default:
            break;
    }
}

void NVIC_Set_Priority(u8 Int, u8 Priority){

}
