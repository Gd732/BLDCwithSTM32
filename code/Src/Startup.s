        AREA	START,CODE,READONLY	
;==========================================================
		EXPORT	__Vectors
		EXPORT	Reset_Handler
		EXTERN	Main
		EXTERN  DMA1_Channel1_IRQHandler
        EXTERN  TIM1_BRK_UP_TRG_COM_IRQHandler
		ENTRY
;==========================================================
__Vectors
		DCD		0x20002000
		DCD     Reset_Handler                  ; Reset Handler
		DCD     0                    		   ; NMI_Handler
		DCD     0              				   ; HardFault_Handler
		DCD     0                              ; Reserved
		DCD     0                              ; Reserved
		DCD     0                              ; Reserved
		DCD     0                              ; Reserved
		DCD     0                              ; Reserved
		DCD     0                              ; Reserved
		DCD     0                              ; Reserved
		DCD     0                              ; SVC_Handler
		DCD     0                              ; Reserved
		DCD     0                              ; Reserved
		DCD     0                              ; PendSV_Handler
		DCD     0                              ; SysTick_Handler

		; External Interrupts
		DCD     0                              ; WWDG_IRQHandler
		DCD     0                              ; Reserved
		DCD     0                              ; RTC_TAMP_IRQHandler
		DCD     0                              ; FLASH_IRQHandler
		DCD     0                              ; RCC_IRQHandler
		DCD     0                              ; EXTI0_1_IRQHandler
		DCD     0                              ; EXTI2_3_IRQHandler
		DCD     0                              ; EXTI4_15_IRQHandler
		DCD     0                              ; Reserved
		DCD     DMA1_Channel1_IRQHandler       ; DMA1_Channel1_IRQHandler
		DCD     0                              ; DMA1_Channel2_3_IRQHandler
		DCD     0                              ; DMA1_Ch4_5_DMAMUX1_OVR_IRQHandler
		DCD     0                              ; ADC1_IRQHandler
		DCD     TIM1_BRK_UP_TRG_COM_IRQHandler ; TIM1_BRK_UP_TRG_COM_IRQHandler
		DCD     0                              ; TIM1_CC_IRQHandler
		DCD     0                              ; Reserved
		DCD     0                              ; TIM3_IRQHandler
		DCD     0				               ; 0
		DCD     0                              ; 0
		DCD     0               				; TIM14_IRQHandler
		DCD     0                              ; 0
		DCD     0                              ; TIM16_IRQHandler
		DCD     0                              ; TIM17_IRQHandler
		DCD     0                              ; I2C1_IRQHandler
		DCD     0                              ; I2C2_IRQHandler
		DCD     0                              ; SPI1_IRQHandler
		DCD     0                              ; SPI2_IRQHandler
		DCD     0                              ; USART1_IRQHandler
		DCD     0                              ; USART2_IRQHandler
		DCD     0                              ; Reserved
		DCD     0                              ; Reserved
		DCD     0                              ; Reserved	
;==========================================================
Reset_Handler
		
		LDR		R0,=0x20000000
		LDR		R1,=0
		LDR		R2,=0x20002000
Ram_Clear
		STR		R1,[R0]
		ADDS	R0,#4
		CMP		R0,R2
		BNE		Ram_Clear
		
		BL		Main	
;==========================================================
		NOP
		END
;========================================================
