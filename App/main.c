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

/*Free RTOS includes*/
#include"FreeRTOS.h"
#include"task.h"
#include "semphr.h"

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
void SwitchHandle(void *pv)
{
	u8 Local_u8_semState1; /*Variable to store return state of SemTake*/

	while(1)
	{
		/*Taking semaphoreA*/
		Local_u8_semState1=xSemaphoreTake(SemA,0);
		if(Local_u8_semState1==pdPASS)
		{
			/*Reading SW State & access Led_SW_state shared resource */
			Led_SW_state=SW_u8GetPressed(&SWConfig);
			vTaskDelay(50);
		}
	}

}
/********************************************************/
void LEDControl(void *pv)
{
	u8 Local_u8_semState1; /*Variable to store return state of SemTake*/

	while(1)
	{
		/*Taking semaphoreA*/
		Local_u8_semState1=xSemaphoreTake(SemA,0);
		if(Local_u8_semState1==pdPASS)
		{
			/*checking on Led_SW_state & access shared resource */
			if(Led_SW_state==SW_PRESSED)
			{
				LED_voidPinToggle(&LedConfig);
			}

		}

	}
}
/********************************************************/
void doorSensorRead(void *pv)
{
	u8 Local_u8_semState1; /*Variable to store return state of SemTake*/

	while(1)
	{
		/*Taking semaphoreB*/
		Local_u8_semState1=xSemaphoreTake(SemB,0);
		if(Local_u8_semState1==pdPASS)
		{
			/*Reading door state & access shared resource door_SW_state*/
			door_SW_state=SW_u8GetPressed(&SWConfig_d);

			vTaskDelay(50);
		}

	}
}
/********************************************************/
void BuzzerControl(void *pv)
{
	u8 Local_u8_semState1; /*Variable to store return state of SemTake*/

	while(1)
	{
		/*Taking semaphoreB*/
		Local_u8_semState1=xSemaphoreTake(SemB,0);
		if(Local_u8_semState1==pdPASS)
		{
			/*Check on door_SW & access door_SW_state shared resource*/
			if(door_SW_state==SW_PRESSED)
			{
				BUZZ_voidTurnOn(&buzzerConfig);
			}
			else
			{
				BUZZ_voidTurnOff(&buzzerConfig);
			}
		}
	}
}
/********************************************************/
void TempRead(void *pv)
{
	while(1)
	{
		/*Read temperature periodically every 100ms*/
		temp_value=LM35_u8GetTemperatureValue(0, 10);
		vTaskDelay(100);
	}
}
/********************************************************/
void LCDdisplay(void *pv)
{
	while(1)
	{
		/*Led State*/
		CLCD_voidGoToXY(0,0);
		if(Led_SW_state==LED_HIGH)
		{
			CLCD_voidSendString("Led is ON");
		}
		else
		{
			CLCD_voidSendString("Led is OFF");
		}

		/*Door State*/
		CLCD_voidGoToXY(1,0);
		if(door_SW_state==SW_PRESSED)
		{
			CLCD_voidSendString("Door is open");
		}
		else
		{
			CLCD_voidSendString("Door is close");
		}
		/*Temperature Value*/
		CLCD_voidGoToXY(2,0);
		CLCD_voidSendData(temp_value);
	}
}
/********************************************************/
void UARTcommunication(void *pv)
{
	while(1)
	{
		/*Led State*/
		if(Led_SW_state==LED_HIGH)
		{
			USART_u8SendStringSynch("Led is ON");
		}
		else
		{
			USART_u8SendStringSynch("Led is OFF");
		}

		/*Door State*/
		if(door_SW_state==SW_PRESSED)
		{
			USART_u8SendStringSynch("Door is open");
		}
		else
		{
			USART_u8SendStringSynch("Door is close");
		}
		/*Temperature Value*/
		USART_u8SendData(temp_value);

		vTaskDelay(500);
	}
}
/********************************************************/
