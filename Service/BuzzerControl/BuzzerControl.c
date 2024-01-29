#include "BuzzerContrlo.h"
/*HAL includes*/
#include"Buzzer_interface.h"

/*Free RTOS includes*/
#include"FreeRTOS.h"
#include"task.h"
#include "semphr.h"


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