#include "..\Inc\Initialize.h"
/*========================================================*/
void Initialize(void)
{
    McuRccInitialize();//时钟初始化
    McuGpioInitialize();//GPIO初始化
    McuTimer1Initialize();//TIM1初始化
    McuDmaInitialize();//DMA初始化
    McuAdcInitialize();//ADC初始化
    
    McuNvicInitialize();//中断控制器初始化
    ProtectInit();//保护功能初始化
}
/*========================================================*/
//Fvco = FPLLIN * (N / M)
//FPLLR = Fvco / R = 320MHz / 5 = 64MHz
//FPLLP = Fvco / P = 320MHz / 3 = 80MHz
static void McuRccInitialize(void)
{
    FLASH -> ACR |= 0x00000100; //CPU Prefetch enable
    FLASH -> ACR |= 0x00000002; //Flash memory access latency :Two wait states
    
    RCC -> PLLCFGR = 0x90052812; //R = 5 PLLREN = 1 P = 3 PLLPEN = 1 N = 40 M = 2 PLLSRC = HSI16
                                 //Fvco = 320MHz FPLLR = 64MHz FPLLP = 80MHz
    RCC -> CR |= 0x01000000; //PLLON = 1
    while((RCC -> CR & 0x02000000) == 0); //wait PLL lock OK
    
    RCC -> CFGR = 0x00000002; //Enalbe System Clock Switch to PLLRCLK
    while((RCC -> CFGR & 0x00000038) == 0x2); //Ensure System Clock Switch OK
    
    //SCB -> VTOR = 0x08000000;
    
    RCC -> IOPENR  |= 0x00000003;  	//enable GPIOA-GPIOB clock
    RCC -> APBENR1 |= 0x00000002; //enable Timer3 Clock
    RCC -> APBENR2 |= 0x00100800; //enable ADC Timer1 Clock
    RCC -> AHBENR |= 0x00000001; //enable DMA Clock
}
/*========================================================*/
static void McuGpioInitialize(void)
{
    GPIOA -> MODER &= 0xebea0f7f;  //PA8/9/10 Set as Alternate function mode   PA6/7 Set as Input mode  PA0/1/2 Set as Analog mode PA3 Set as Output
    GPIOB -> MODER &= 0xaafffffc;  //PB12/13/14/15 Set as Alternate function mode PB0 Set as Input mode
    
    GPIOA -> OTYPER = 0x0;
    GPIOB -> OTYPER = 0x0;
    
    GPIOA -> OSPEEDR |= 0x002a0080;
    GPIOB -> OSPEEDR |= 0xa8000000;
    
    GPIOA -> PUPDR = 0x0;
    GPIOB -> PUPDR = 0x0;
    
    GPIOA -> AFRH = 0x00000222; //PA8/9/10 AF2
    GPIOB -> AFRH = 0x22220000; //PB12/13/14/15 AF2
}
/*========================================================*/
static void McuTimer1Initialize(void)
{
    TIM1 -> CR1 = 0x0; //Edge-aligned Counter Mode
    TIM1 -> PSC = 0x0;
    TIM1 -> ARR = 3199; //64MHz/20KHz = 3200
    
    TIM1 -> CCER = PWM_ALL_OFF_CCER;
    TIM1 -> CCMR1 = PWM_ALL_OFF_CCMR1;
    TIM1 -> CCMR2 = PWM_ALL_OFF_CCMR2;
    
    TIM1 -> CCR1 = 0;
    TIM1 -> CCR2 = 0;
    TIM1 -> CCR3 = 0;
    TIM1 -> CCR4 = 256; //Trigger Point PWM ON 4us
    
    TIM1 -> BDTR = 0x0003d000; //MOE = 1 AOE = 1 BKP = 0��Low�� BKE = 1 fSAMPLING=fCK_INT, N=8
    TIM1 -> DIER |= 0x00000080; //BIE = 1
    TIM1 -> CR1 |= 0x1; //Enable Counter
}
/*========================================================*/
static void McuAdcInitialize(void)
{
    TIM3 -> ARR = 65535;
    TIM3 -> PSC = 0;							
    TIM3 -> CNT = 0;
    TIM3 -> CR1 |= 0x00000001;
    
    ADC1 -> CR |= 0x10000000;
    //Wait ADC Voltage Regulator Startup Time 20us set 100us
    TIM3 -> CNT = 0;
    while(TIM3 -> CNT <  6400);
    
    ADC1 -> CR |= 0x80000000;
    while((ADC1 -> CR & 0x80000000) != 0); //Wait Adc calibration is complete
    
    ADC1 -> CFGR1 = 0x00201840; //CONT = 1 Falling edge TRG1 12bits DMAEN = 1 DMACFG = 1 CHSELRMOD = 1
    ADC1 -> CFGR2 = 0x40000000; //ADC clock = PCLK/2
    ADC1 -> SMPR = 0x00000000; //Channel-x sampling time selection  SMP1[2:0] register 1.5 ADC clock
    ADC1 -> CHSELR = 0x0000f210;
    while((ADC1 -> ISR & 0x00002000) == 0x0);
    
    ADC1 -> CCR = 0x0;
    ADC1 -> CR |= 0x00000001; //ADEN = 1
    
    while((ADC1 -> ISR & 0x00000001) == 0x0);
    ADC1 -> CFGR1 |= 0x00000003;
    ADC1 -> CR |= 0x00000004; //ADSTART = 1
}
/*========================================================*/
static void McuDmaInitialize(void)
{
    DMA1 -> CCR1 = 0x000035a2;
    DMA1 -> CNDTR1 = 0x3;
    DMA1 -> CPAR1 = (unsigned int)&ADC1 -> DR;
    DMA1 -> CMAR1 = (unsigned int)&tBldc;
    DMA1 -> CCR1 |= 0x00000001;
    
    DMAMUX -> C0CR = 0x5; //ADC Source
}
/*========================================================*/
static void McuNvicInitialize(void)
{
    NVIC -> IPR3 = 0x00000000;
    NVIC -> IPR2 = 0x00004000;	//IRQ9 DMA1 Channel 1 
    NVIC -> ISER |= 0x00002200;	//IRQ9 DMA1 Channel 1 IRQ13 TIM BREAK
}
/*========================================================*/
