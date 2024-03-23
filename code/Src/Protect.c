#include "..\Inc\Protect.h"
/*========================================================*/
void ProtectInit(void)
{
    tProtect.DelayCount = 400; //20ms
    
    while(tProtect.DelayCount != 0);
}
/*========================================================*/
void ProtectApp(void)
{
    VoltageDetect();//检查Vbus（USB连接）是否正常
    HallDetect();//检查霍尔传感器是否正常工作
    if((tProtect.Code != 0x00) && (tBldc.StatusMachineStatus != 0))
        tBldc.ReqOff = 1;//若以上工作状态不正常，则重启电机
}
/*========================================================*/
void ProtectInt(void)
{
    CurrentDetect();
    
    if(tProtect.DelayCount != 0)
        tProtect.DelayCount --;
    
    tProtect.Count ++;
    if(tProtect.Count >= 20)
    {
        tProtect.Count = 0;
        
        if(tProtect.CountVol)
            tProtect.CountVol --;
        
        if(tProtect.CountCur)
            tProtect.CountCur --;
    }
}
/*========================================================*/
static void CurrentDetect(void)
{
    if(Error_Flag.Bits.Hoc)
        tProtect.Code = 0x05;
    
    if(tBldc.IbusValue > 3103) //2.5V  5A
    {
        if(tProtect.CountCur == 0)
            tProtect.Code = 0x04;
    }
    else
    {
        tProtect.CountCur = 10;
    } 
}
/*========================================================*/
static void VoltageDetect(void)
{
    if(tBldc.VbusValue > 3385) //30V
    {
        if(tProtect.CountVol == 0)
            tProtect.Code = 0x03;
    }
    else if(tBldc.VbusValue > 1805) //16V
    {
        tProtect.CountVol = 10;
    }
    else
    {
        if(tProtect.CountVol == 0)
            tProtect.Code = 0x02;
    }
}
/*========================================================*/
static void HallDetect(void)
{
    if(Error_Flag.Bits.Hall)
        tProtect.Code = 0x01;
}
/*========================================================*/
