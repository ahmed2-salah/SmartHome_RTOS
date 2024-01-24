#include"TempRead.h"


/*Free RTOS includes*/
#include"FreeRTOS.h"
#include"task.h"
#include "semphr.h"

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