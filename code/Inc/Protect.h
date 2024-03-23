#include "..\Inc\Define.h"
#include "..\Inc\Device.h"
/*========================================================*/
void ProtectInit(void);
void ProtectApp(void);
void ProtectInt(void);

static void VoltageDetect(void);
static void CurrentDetect(void);
static void HallDetect(void);
/*========================================================*/
tProtect_Type tProtect;
UNION_ERRORFLAGS Error_Flag;

extern tBldc_Type tBldc;
/*========================================================*/
