#include "..\Inc\Define.h"
#include "..\Inc\Device.h"
/*========================================================*/
void Main(void);
void DMA1_Channel1_IRQHandler(void);

extern void Initialize(void);
extern void BldcInt(void);
extern void BldcApp(void);
extern void ProtectApp(void);
extern void ProtectInt(void);
/*========================================================*/
extern tProtect_Type tProtect;
extern UNION_ERRORFLAGS Error_Flag;
/*========================================================*/
