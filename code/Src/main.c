#include "..\Inc\main.h"
/*========================================================*/
void main(void)
{
    Initialize();
    
    do
    {
        BldcApp();//执行一次直流无刷电机的对应操作
        ProtectApp(); //执行一次保护操作
    }while(1);
}
/*========================================================*/
void DMA1_Channel1_IRQHandler(void)
{
    unsigned int Temp;
    
    Temp = DMA1 -> ISR;
    Temp &= 0x00000002;
    if(Temp != 0)
    {
        DMA1 -> IFCR |= 0x00000002; //Clear Transfer flag
        BldcInt();
        ProtectInt();
    }
}
/*========================================================*/
void TIM1_BRK_UP_TRG_COM_IRQHandler(void)
{
    unsigned int Temp;
    
    Temp = TIM1 -> SR;
    Temp &= 0x00000080;
    
    if(Temp != 0)
    {
        TIM1 -> SR &= 0xffffff7f;
        if((GPIOB -> IDR & 0xe000) == 0x0)
        {
            Error_Flag.Bits.Hoc = 1;
            TIM1 -> DIER &= 0xff7f; //Disable Break Interrupt
        }
    }
}
/*========================================================*/
