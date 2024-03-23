#include "..\Inc\Bldc.h"
/*=======================================================*/
void BldcInt(void)
{
    StatusMachine();
    AdcFilter();
    BldcCount();
}
/*=======================================================*/
static void BldcCount(void)
{
    if(tBldc.Count != 0)
        tBldc.Count --;
}
/*=======================================================*/
void BldcApp(void)
{
    PotValueProcess();//获取并转换端口AD_POT返回的模拟值
    MotorRunStopControl();//根据电机当前状态与霍尔传感器返回的状态，
                          //确定需要使能的相绕组
}
/*=======================================================*/
static void GetHallValue(void)
{
	unsigned char i;
	UNION_WORD Temp;
    
    i = 0;
    do
    {
        Temp.HalfWord = 0;
        Temp.Bits.B2 = GPIOB -> IDR & 0x01;
        Temp.Bits.B1 = (GPIOA -> IDR >> 7) & 0x01;
        Temp.Bits.B0 = (GPIOA -> IDR >> 6) & 0x01;
        tBldc.HallBuf[i++] = Temp.HalfWord;
        TIM3 -> CNT = 0;
        while(TIM3 -> CNT <  64); //Wait 1us For Hall Signal Filter
    }while(i < 3);
    
    if((tBldc.HallBuf[0] == tBldc.HallBuf[1]) && (tBldc.HallBuf[1] == tBldc.HallBuf[2]))
    {
        tBldc.HallValue = Temp.HalfWord;
        if (tBldc.HallValue != tBldc.HallValueOld)
        {
            tBldc.HallValueOld = tBldc.HallValue;
            
            if ((tBldc.HallValue > 0) && (tBldc.HallValue < 7))
            {
                tBldc.HallUpdate = 1;
            }
            else
            {
                Error_Flag.Bits.Hall = 1;
            }
        }	
    }
    else
    {
        tBldc.HallUpdate = 0;
    }
}
/*=======================================================*/
static void StatusMachine(void)
{
    if(tBldc.StatusMachineStatus == 0)
    {
        TIM1 -> CCER = PWM_ALL_OFF_CCER;
        TIM1 -> CCMR1 = PWM_ALL_OFF_CCMR1;
        TIM1 -> CCMR2 = PWM_ALL_OFF_CCMR2;
        
        TIM1 -> CCR1 = MIN_DUTY;
        TIM1 -> CCR2 = MIN_DUTY;
        TIM1 -> CCR3 = MIN_DUTY;
        
        tBldc.Hall_Update_Count = 0;
        tBldc.HallValue = 0;
        tBldc.HallUpdate = 0;
        tBldc.HallValueOld = 0;
    }
    else if(tBldc.StatusMachineStatus == 1)
    {
        TIM1 -> CCER = PWM_LOW_ON_CCER;
        TIM1 -> CCMR1 = PWM_LOW_ON_CCMR1;
        TIM1 -> CCMR2 = PWM_LOW_ON_CCMR2;
        
        tBldc.Count = 2000;
        tBldc.StatusMachineStatus = 2;
    }
    else if(tBldc.StatusMachineStatus == 2)
    {
        if(tBldc.Count == 0)
        {
            TIM1 -> CCER = PWM_ALL_OFF_CCER;
            TIM1 -> CCMR1 = PWM_ALL_OFF_CCMR1;
            TIM1 -> CCMR2 = PWM_ALL_OFF_CCMR2;
            
            TIM1 -> CCR1 = tBldc.PotValue;
            TIM1 -> CCR2 = tBldc.PotValue;
            TIM1 -> CCR3 = tBldc.PotValue;
            
            GetHallValue();
            if(tBldc.HallUpdate == 1)
            {
                tBldc.HallUpdate = 0;
                TIM1 -> CCER = PwmPhaseOutReg0[tBldc.HallValue];
                TIM1 -> CCMR1 = PwmPhaseOutReg1[tBldc.HallValue];
                TIM1 -> CCMR2 = PwmPhaseOutReg2[tBldc.HallValue];              
            }
            tBldc.StatusMachineStatus = 3;
        }
    }
    else if(tBldc.StatusMachineStatus == 3)
    {
        TIM1 -> CCR1 = tBldc.PotValue;
        TIM1 -> CCR2 = tBldc.PotValue;
        TIM1 -> CCR3 = tBldc.PotValue;
        GetHallValue();
        if(tBldc.HallUpdate == 1)
        {
            tBldc.HallUpdate = 0;
            tBldc.Hall_Update_Count = 0;
            TIM1 -> CCER = PwmPhaseOutReg0[tBldc.HallValue];
            TIM1 -> CCMR1 = PwmPhaseOutReg1[tBldc.HallValue];
            TIM1 -> CCMR2 = PwmPhaseOutReg2[tBldc.HallValue]; 
        }
        else
        {
            if (tBldc.Hall_Update_Count < 65535)
            {	
                tBldc.Hall_Update_Count ++;
            }
            else
            {
                Error_Flag.Bits.Hall = 1;
            }
        }
    }
}
/*=======================================================*/
static void AdcFilter(void)
{
    tBldc.SumA += tBldc.AdcResult[0];
    tBldc.NumA++;
    
    if(tBldc.NumA >= 16)
    {
        tBldc.PotValueFilter = tBldc.SumA >> 4;
        tBldc.NumA = 0;
        tBldc.SumA = 0;
    }
    
    tBldc.SumB += tBldc.AdcResult[1];
    tBldc.NumB++;
    
    if(tBldc.NumB >= 64)
    {
        tBldc.VbusValue = tBldc.SumB >> 6;
        tBldc.NumB = 0;
        tBldc.SumB = 0;
    }
}
/*=======================================================*/
static void PotValueProcess(void)
{
    unsigned short TempA;
    unsigned int TempB;
    
    TempA = tBldc.PotValueFilter << 4;
    TempB = TempA * MAX_DUTY;
    TempA = TempB >> 16;
    
    if(TempA < 200)
        TempA = 0;
    
    if(TempA > 3136) //98%
        TempA = MAX_DUTY;
    
    tBldc.PotValue = TempA;
}
/*=======================================================*/
static void MotorRunStopControl(void)
{
    if(tBldc.MotorStatus == 0)
    {
        if((tProtect.Code == 0x00) && (tBldc.PotValue >= MIN_DUTY))
        {
            tBldc.MotorStatus = 1;
            tBldc.StatusMachineStatus = 1;
        }
    }
    else
    {
        if((tBldc.ReqOff == 1) || (tBldc.PotValue == 0))
        {
            tBldc.ReqOff = 0;
            tBldc.MotorStatus = 0;
            tBldc.StatusMachineStatus = 0;           
        }
    }
}
/*========================================================*/
