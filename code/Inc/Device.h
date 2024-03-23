typedef struct
{
    volatile unsigned int CR1;
    volatile unsigned int CR2;
    volatile unsigned int CR3;
    volatile unsigned int CR4;

    volatile unsigned int SR1;
    volatile unsigned int SR2;
    volatile unsigned int SCR;
    volatile unsigned int REV0;
    volatile unsigned int PUCRA;
    volatile unsigned int PDCRA;
    volatile unsigned int PUCRB;
    volatile unsigned int PDCRB;
    volatile unsigned int PUCRC;
    volatile unsigned int PDCRC;
    volatile unsigned int PUCRD;
    volatile unsigned int PDCRD;
    volatile unsigned int PUCRE;
    volatile unsigned int PDCRE;
    volatile unsigned int PUCRF;
    volatile unsigned int PDCRF;
}PWR_TypeDef;

#define PWR ((PWR_TypeDef *)0x40007000)
typedef struct
{
    volatile unsigned int CR;
    volatile unsigned int ICSCR;
    volatile unsigned int CFGR;
    volatile unsigned int PLLCFGR;
    
    volatile unsigned int REV1;
    volatile unsigned int REV2;
    
    volatile unsigned int CIER;
    volatile unsigned int CIFR;
    volatile unsigned int CICR;
    
    volatile unsigned int IOPRSTR;
    
    volatile unsigned int AHBRSTR;
    volatile unsigned int APBRSTR1;
    volatile unsigned int APBRSTR2;
    
    volatile unsigned int IOPENR;
        
    volatile unsigned int AHBENR;
    volatile unsigned int APBENR1;
    volatile unsigned int APBENR2;
    
    volatile unsigned int IOPSMENR;
    
    volatile unsigned int AHBSMENR;
    volatile unsigned int APBSMENR1;
    volatile unsigned int APBSMENR2;
    
    volatile unsigned int CCIPR;
    volatile unsigned int CCIPR2;	
    volatile unsigned int BDCR;
    volatile unsigned int CSR;

}RCC_TypeDef;

#define RCC ((RCC_TypeDef *)0x40021000)
/*========================================================*/
typedef struct
{
    volatile unsigned int MODER;
    volatile unsigned int OTYPER;
    volatile unsigned int OSPEEDR;
    volatile unsigned int PUPDR;

    volatile unsigned int IDR;
    volatile unsigned int ODR;
    volatile unsigned int BSRR;
    
    volatile unsigned int LCKR;
    volatile unsigned int AFRL;
    volatile unsigned int AFRH;
    volatile unsigned int BRR;
			
}GPIO_TypeDef;

#define GPIOA ((GPIO_TypeDef *)0x50000000)
#define GPIOB ((GPIO_TypeDef *)0x50000400)
#define GPIOC ((GPIO_TypeDef *)0x50000800)
#define GPIOD ((GPIO_TypeDef *)0x50000C00)
#define GPIOF ((GPIO_TypeDef *)0x50001400)

/*========================================================*/
//定时器模块寄存器定义
/*========================================================*/
typedef struct
{
    volatile unsigned int CR1;
    volatile unsigned int CR2;
    volatile unsigned int SMCR;
    volatile unsigned int DIER;
    volatile unsigned int SR;
    volatile unsigned int EGR;
    volatile unsigned int CCMR1;
    volatile unsigned int CCMR2;
    volatile unsigned int CCER;	
    volatile unsigned int CNT;
    volatile unsigned int PSC;
    volatile unsigned int ARR;
    volatile unsigned int RCR;
    volatile unsigned int CCR1;
    volatile unsigned int CCR2;
    volatile unsigned int CCR3;
    volatile unsigned int CCR4;
    volatile unsigned int BDTR;
    volatile unsigned int DCR;
    volatile unsigned int DMAR;
    volatile unsigned int OR1;
    volatile unsigned int CCMR3;
    volatile unsigned int CCR5;
    volatile unsigned int CCR6;
    volatile unsigned int AF1;
    volatile unsigned int AF2;
    volatile unsigned int TISEL;
}TIM1_TypeDef;

#define TIM1 ((TIM1_TypeDef *)0x40012c00)
/*========================================================*/
typedef struct
{
    volatile unsigned int CR1;
    volatile unsigned int CR2;
    volatile unsigned int SMCR;
    volatile unsigned int DIER;
    volatile unsigned int SR;
    volatile unsigned int EGR;
    volatile unsigned int CCMR1;
    volatile unsigned int CCMR2;
    volatile unsigned int CCER;	
    volatile unsigned int CNT;
    volatile unsigned int PSC;
    volatile unsigned int ARR;
    unsigned int REV0;
    volatile unsigned int CCR1;
    volatile unsigned int CCR2;
    volatile unsigned int CCR3;
    volatile unsigned int CCR4;
    unsigned int REV1;
    volatile unsigned int DCR;
    volatile unsigned int DMAR;
    unsigned int REV2[4];
    volatile unsigned int AF1;
    unsigned int REV3;	
    volatile unsigned int TISEL;
	
}TIM3_TypeDef;

#define TIM3 ((TIM3_TypeDef *)0x40000400)
/*========================================================*/
typedef struct
{
    volatile unsigned int CR1;
    unsigned int REV0[2];
    volatile unsigned int DIER;
    volatile unsigned int SR;
    volatile unsigned int EGR;
    volatile unsigned int CCMR1;
    unsigned int REV1;
    volatile unsigned int CCER;	
    volatile unsigned int CNT;
    volatile unsigned int PSC;
    volatile unsigned int ARR;
    unsigned int REV2;
    volatile unsigned int CCR1;
    unsigned int REV3[9];
    volatile unsigned int TISEL;	
}TIM14_TypeDef;

#define TIM14 ((TIM1_TypeDef *)0x40002000)
/*========================================================*/
typedef struct
{
    volatile unsigned int CR1;
    volatile unsigned int CR2;
    unsigned int REV0;
    volatile unsigned int DIER;
    volatile unsigned int SR;
    volatile unsigned int EGR;
    volatile unsigned int CCMR1;
    unsigned int REV1;
    volatile unsigned int CCER;	
    volatile unsigned int CNT;
    volatile unsigned int PSC;
    volatile unsigned int ARR;
    volatile unsigned int RCR;
    volatile unsigned int CCR1;
    unsigned int REV2[3];
    volatile unsigned int BDTR;
    volatile unsigned int DCR;
    volatile unsigned int DMAR;		
    unsigned int REV3[4];
    volatile unsigned int AF1;
    unsigned int REV4;	
    volatile unsigned int TISEL;
}TIM17_TypeDef;

#define TIM17 ((TIM17_TypeDef *)0x40001400)
/*========================================================*/
//ADC模块寄存器定义
/*========================================================*/
typedef struct
{
    volatile unsigned int ISR;
    volatile unsigned int IER;
    volatile unsigned int CR;
    volatile unsigned int CFGR1;
    volatile unsigned int CFGR2;
    volatile unsigned int SMPR;
    volatile unsigned int RESERVED1;
    volatile unsigned int RESERVED2;
    volatile unsigned int AWD1TR;
    volatile unsigned int AWD2TR;
    volatile unsigned int CHSELR;
    volatile unsigned int AWD3TR;
    volatile unsigned int RESERVED3[4];
    volatile unsigned int DR;
    volatile unsigned int RESERVED4[24];
    volatile unsigned int AWD2CR;
    volatile unsigned int AWD3CR;
    volatile unsigned int RESERVED5[3];
    volatile unsigned int CALFACT;
    volatile unsigned int RESERVED6[148];
    volatile unsigned int CCR;
	
}ADC_TypeDef;

#define ADC1 ((ADC_TypeDef *)0x40012400)
/*========================================================*/
//DMA模块寄存器定义
/*========================================================*/
typedef struct
{
    volatile unsigned int ISR;
    volatile unsigned int IFCR;
    volatile unsigned int CCR1;
    volatile unsigned int CNDTR1;
    volatile unsigned int CPAR1;
    volatile unsigned int CMAR1;
    volatile unsigned int RESERVED1;
    volatile unsigned int CCR2;
    volatile unsigned int CNDTR2;
    volatile unsigned int CPAR2;
    volatile unsigned int CMAR2;
    volatile unsigned int RESERVED2;
    volatile unsigned int CCR3;
    volatile unsigned int CNDTR3;
    volatile unsigned int CPAR3;
    volatile unsigned int CMAR3;
    volatile unsigned int RESERVED3;
    volatile unsigned int CCR4;
    volatile unsigned int CNDTR4;
    volatile unsigned int CPAR4;
    volatile unsigned int CMAR4;
    volatile unsigned int RESERVED4;
    volatile unsigned int CCR5;
    volatile unsigned int CNDTR5;
    volatile unsigned int CPAR5;
    volatile unsigned int CMAR5;
    volatile unsigned int RESERVED5;
    volatile unsigned int CCR6;
    volatile unsigned int CNDTR6;
    volatile unsigned int CPAR6;
    volatile unsigned int CMAR6;
    volatile unsigned int RESERVED6;
    volatile unsigned int CCR7;
    volatile unsigned int CNDTR7;
    volatile unsigned int CPAR7;
    volatile unsigned int CMAR7;
}DMA1_TypeDef;

#define DMA1 ((DMA1_TypeDef *)0x40020000)
typedef struct
{
    volatile unsigned int C0CR;
    volatile unsigned int C1CR;
    volatile unsigned int C2CR;
    volatile unsigned int C3CR;
    volatile unsigned int C4CR;
    volatile unsigned int C5CR;
    volatile unsigned int C6CR;
    volatile unsigned int Reserved1[25];
    volatile unsigned int CSR;
    volatile unsigned int CFR;
    volatile unsigned int Reserved2[117];
    volatile unsigned int RG0CR;
    volatile unsigned int RG1CR;
    volatile unsigned int RG2CR;
    volatile unsigned int RG3CR;
    volatile unsigned int Reserved3[45];
    volatile unsigned int RGSR;
    volatile unsigned int RGCFR;
    volatile unsigned int Reserved4[693];
}DMAMUX_TypeDef;

#define DMAMUX ((DMAMUX_TypeDef *)0x40020800)
typedef struct
{
    volatile unsigned int CR1;
    volatile unsigned int CR2;
    volatile unsigned int OAR1;
    volatile unsigned int OAR2;
    volatile unsigned int TIMINGR;
    volatile unsigned int TIMEOUTR;
    volatile unsigned int ISR;
    volatile unsigned int ICR;
    volatile unsigned int PECR;
    volatile unsigned int RXDR;
    volatile unsigned int TXDR;
	
}I2C_TypeDef;
#define I2C1 ((I2C_TypeDef *)0x40005400)
#define I2C2 ((I2C_TypeDef *)0x40005800)

/*========================================================*/
//NVIC模块寄存器定义
/*========================================================*/
typedef struct
{
    volatile unsigned int ISER;
    unsigned int REV0[31];
    volatile unsigned int ICER;
    unsigned int REV1[31];
    volatile unsigned int ISPR;
    unsigned int REV2[31];
    volatile unsigned int ICPR;
    unsigned int REV3[95];
    volatile unsigned int IPR0;
    volatile unsigned int IPR1;
    volatile unsigned int IPR2;
    volatile unsigned int IPR3;
    volatile unsigned int IPR4;
    volatile unsigned int IPR5;
    volatile unsigned int IPR6;
    volatile unsigned int IPR7;
	
}NVIC_TypeDef;

#define NVIC ((NVIC_TypeDef *)0xe000e100)
typedef struct
{
    volatile unsigned int CPUID;
    volatile unsigned int ICSR;
    volatile unsigned int VTOR;
    volatile unsigned int AIRCR;
    volatile unsigned int SCR;
    volatile unsigned int CCR;
    volatile unsigned int RESERVED1;
    volatile unsigned int SHPR2;
    volatile unsigned int SHPR3;
	
}SCB_TypeDef;

#define SCB ((SCB_TypeDef *)0xe000ed00)
typedef struct
{
    volatile unsigned int	CR1;
    volatile unsigned int	CR2;
    volatile unsigned int	CR3;
    volatile unsigned int	BRR;
    volatile unsigned int	GTPR;
    volatile unsigned int	RTOR;
    volatile unsigned int	RQR;
    volatile unsigned int	ISR;
    volatile unsigned int	ICR;
    volatile unsigned int	RDR;
    volatile unsigned int	TDR;
    volatile unsigned int	PRESC;
}UART_TypeDef;

#define UART1 ((UART_TypeDef *)0x40013800)
typedef struct
{
    volatile unsigned int CR1;
    volatile unsigned int CR2;
    volatile unsigned int SR;
    volatile unsigned int DR;
    volatile unsigned int CRCPR;
    volatile unsigned int RXCRCR;
    volatile unsigned int TXCRCR;
    volatile unsigned int I2SCFGR;
    volatile unsigned int I2SPR;
}SPI_TypeDef;

#define SPI1 ((SPI_TypeDef *)0x40013000)
typedef struct
{
    volatile unsigned int TR; 
    volatile unsigned int	DR;
    volatile unsigned int	SSR;
    volatile unsigned int	ICSR;
    volatile unsigned int	PRER;
    volatile unsigned int	WUTR;
    volatile unsigned int	CR;
    unsigned int REV0[2];	
    volatile unsigned int	WPR;
    volatile unsigned int	CALR;
    volatile unsigned int	SHIFTR;
    volatile unsigned int	TSTR;
    volatile unsigned int	TSDR;
    volatile unsigned int	TSSSR;
    unsigned int REV1;
    volatile unsigned int	ALRMAR;
    volatile unsigned int	ALRMASSR;
    volatile unsigned int	ALRMBR;
    volatile unsigned int	ALRMBSSR;
    volatile unsigned int	SR;
    volatile unsigned int	MISR;
    unsigned int REV2;
    volatile unsigned int	SCR;
}RTC_TypeDef;

#define RTC ((RTC_TypeDef *)0x40002800)

/*========================================================*/
//FLASH模块寄存器定义
/*========================================================*/
typedef struct
{
    volatile unsigned int ACR;
    unsigned int REV0;
    volatile unsigned int KEYR;
    volatile unsigned int OPTKEYR;
    volatile unsigned int SR;
    volatile unsigned int CR;
    volatile unsigned int ECCR;
    unsigned int REV1;
    volatile unsigned int OPTR;
    unsigned int REV2[2];
    volatile unsigned int WRP1AR;
    volatile unsigned int WRP1BR;
}FLASH_TypeDef;

#define FLASH ((FLASH_TypeDef *)0x40022000)
typedef struct
{
    volatile unsigned int TAMP_CR1;
    volatile unsigned int TAMP_CR2;
    unsigned int REV0;
    volatile unsigned int TAMP_FLTCR;
    unsigned int REV1[7];
    volatile unsigned int TAMP_IER;
    volatile unsigned int TAMP_SR;
    volatile unsigned int TAMP_MISR;
    unsigned int REV2;
    volatile unsigned int TAMP_SCR;		
    unsigned int REV3[48];
    volatile unsigned int TAMP_BKP0R;
    volatile unsigned int TAMP_BKP1R;
    volatile unsigned int TAMP_BKP2R;
    volatile unsigned int TAMP_BKP3R;
    volatile unsigned int TAMP_BKP4R;
}TAMP_TypeDef;

#define TAMP ((TAMP_TypeDef *)0x4000b000)
