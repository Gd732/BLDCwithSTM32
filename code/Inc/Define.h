#define    PWM_ALL_OFF_CCER   0x00001000
#define    PWM_ALL_OFF_CCMR1  0x00000000
#define    PWM_ALL_OFF_CCMR2  0x00006800

#define    PWM_LOW_ON_CCER   0x00001444
#define    PWM_LOW_ON_CCMR1  0x00005050
#define    PWM_LOW_ON_CCMR2  0x00006850

#define    PWM_PHASE_FIVE_CCER   	0x00001041    //PWM1H PWM2L
#define    PWM_PHASE_FIVE_CCMR1  	0x00005068
#define    PWM_PHASE_FIVE_CCMR2  	0x00006800

#define    PWM_PHASE_FOUR_CCER   	0x00001401    //PWM1H PWM3L
#define    PWM_PHASE_FOUR_CCMR1  	0x00000068
#define    PWM_PHASE_FOUR_CCMR2  	0x00006850

#define    PWM_PHASE_SIX_CCER   	0x00001410    //PWM2H PWM3L
#define    PWM_PHASE_SIX_CCMR1  	0x00006800
#define    PWM_PHASE_SIX_CCMR2  	0x00006850

#define    PWM_PHASE_TWO_CCER   	0x00001014    //PWM2H PWM1L
#define    PWM_PHASE_TWO_CCMR1  	0x00006850
#define    PWM_PHASE_TWO_CCMR2  	0x00006800

#define    PWM_PHASE_THREE_CCER   0x00001104    //PWM3H PWM1L
#define    PWM_PHASE_THREE_CCMR1  0x00000050
#define    PWM_PHASE_THREE_CCMR2  0x00006868

#define    PWM_PHASE_ONE_CCER   	0x00001140    //PWM3H PWM2L
#define    PWM_PHASE_ONE_CCMR1  	0x00005000
#define    PWM_PHASE_ONE_CCMR2  	0x00006868
/*=======================================================*/
typedef struct
{
    unsigned short AdcResult[3];
    unsigned short Count;
    unsigned char StatusMachineStatus;
    unsigned short HallBuf[3];
    unsigned short HallValueOld;
    unsigned short HallValue;
    unsigned short HallUpdate;
    unsigned short Hall_Update_Count;
    unsigned short PotValueFilter;
    unsigned short PotValue;
    unsigned short VbusValue;
    unsigned short IbusValue;
    unsigned char NumA;
    unsigned char NumB;
    unsigned char MotorStatus;
    unsigned char ReqOff;
    unsigned int SumA;
    unsigned int SumB;
}tBldc_Type;
/*=======================================================*/
typedef union
{
	unsigned short HalfWord;
	struct
	{
		unsigned B0:1;	
		unsigned B1:1;
		unsigned B2:1;
		unsigned B3:1;
		unsigned B4:1;
		unsigned B5:1;
		unsigned B6:1;	
		unsigned B7:1;
		unsigned B8:1;	
		unsigned B9:1;
		unsigned B10:1;
		unsigned B11:1;
		unsigned B12:1;
		unsigned B13:1;
		unsigned B14:1;	
		unsigned B15:1;	
	}Bits;
}UNION_WORD;
/*=======================================================*/
typedef struct
{
    unsigned short DelayCount;
    unsigned short Count;
    unsigned short CountVol;
    unsigned short CountCur;
    unsigned char Code;
}tProtect_Type;
/*========================================================*/
typedef union
{
	unsigned char Word;
	struct
	{	
		unsigned Hall:1;
        unsigned Hoc:1;
		unsigned Unused:6;
	}Bits;
}UNION_ERRORFLAGS;
