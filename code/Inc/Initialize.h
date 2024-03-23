#include "..\Inc\Define.h"
#include "..\Inc\Device.h"
/*========================================================*/
void Initialize(void);

static void McuRccInitialize(void);
static void McuGpioInitialize(void);
static void McuTimer1Initialize(void);
static void McuAdcInitialize(void);
static void McuDmaInitialize(void);
static void McuNvicInitialize(void);

extern void ProtectInit(void);

/*========================================================*/
extern tBldc_Type tBldc;
/*========================================================*/
