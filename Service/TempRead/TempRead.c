#include"TempRead.h"


/*Free RTOS includes*/
#include"FreeRTOS.h"
#include"task.h"
#include "semphr.h"

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
