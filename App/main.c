/********************************************************/
/********************************************************/
/*************** Author: AhmedSalah	  *******************/
/*************** Layer: App		      *******************/
/*************** SWC: main			  *******************/
/*************** Date: 20/1/2024 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

/*LIB includes*/
#include"STD_TYPES.h"
#include "BIT_Math.h"
/********************************************************/

/*MCAL includes*/
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "USART_interface.h"
/********************************************************/

/*HAL includes*/
#include "CLCD_interface.h"
#include "LM35_interface.h"
#include "SW_interface.h"
#include "Led_interface.h"
#include "Buzzer_interface.h"
/********************************************************/

/*Service Layer includes*/

#include"BuzzerControl.h"
#include"doorReadSensor.h"
#include"LCDdisplay.h"
#include"LEDControl.h"
#include"SwitchHandle.h"
#include"TempRead.h"
#include"UARTcommunication.h"

/********************************************************/

/*Tasks Prototypes*/
void SwitchHandle(void *pv);
void LEDControl(void *pv);
void doorSensorRead(void *pv);
void BuzzerControl(void *pv);
void TempRead(void *pv);
void LCDdisplay(void *pv);
void UARTcommunication(void *pv);
/********************************************************/

/*--------------------Configuration Structures-----------------------------*/

/*Switch configuration*/
SW_Type SWConfig={SW_PORTB,SW_PIN7,SW_INTERNAL_PULL_UP };

/*LED configuration*/
LED_T LedConfig={LED_PORTB,LED_PIN0,LED_SINK};

/*Buzzer configuration*/
BUZZER_T buzzerConfig ={BUZZ_PORTB,BUZZ_PIN1,BUZZ_SINK};

/*Door Switch configuration*/
SW_Type SWConfig_d={SW_PORTB,SW_PIN6,SW_INTERNAL_PULL_UP };
/********************************************************/

/*Software Shared Resources*/
u8 Led_SW_state;
u8 door_SW_state;
u8 temp_value;
/********************************************************/


/********************************************************/

/*Handlers of binary semaphores*/
xSemaphoreHandle SemA; /*Synchronize between SwitchHandle&LEDControl */
xSemaphoreHandle SemB; /*Synchronize between doorSensorRead&BuzzerControl */
/********************************************************/

void main(void)
{
	/*Modules Init*/
	PORT_voidInit(); /*PORT*/
	USART_voidInit();/*UART*/
	CLCD_voidInit(); /*LCD*/
	LM35_voidInit(); /*LM35*/
	SW_voidPinInit(&SWConfig); /*SW*/
	SW_voidPinInit(&SWConfig_d); /*Door_SW*/
	LED_voidPinInit(&LedConfig); /*LED*/
	BUZZ_voidInit(&buzzerConfig); /*Buzzer*/



	/*Tasks Creation*/
	xTaskCreate(&SwitchHandle      ,NULL  ,50  ,NULL,1   ,NULL);
	xTaskCreate(&LEDControl        ,NULL  ,50  ,NULL,0   ,NULL);
	xTaskCreate(&doorSensorRead    ,NULL  ,50  ,NULL,1   ,NULL);
	xTaskCreate(&BuzzerControl     ,NULL  ,50  ,NULL,0   ,NULL);
	xTaskCreate(&TempRead          ,NULL  ,50  ,NULL,0   ,NULL);
	xTaskCreate(&LCDdisplay        ,NULL  ,250 ,NULL,0   ,NULL);
	xTaskCreate(&UARTcommunication ,NULL  ,150 ,NULL,0   ,NULL);


	/*Semaphores Creation*/
	vSemaphoreCreateBinary(SemA);
	vSemaphoreCreateBinary(SemB);

	vTaskStartScheduler();
	while(1)
	{

	}
}
/********************************************************/

