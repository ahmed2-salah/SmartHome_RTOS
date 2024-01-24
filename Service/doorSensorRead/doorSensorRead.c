
#include "doorSensorRead.h"
/*Free RTOS includes*/
#include"FreeRTOS.h"
#include"task.h"
#include "semphr.h"


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