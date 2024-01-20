/********************************************************/
/********************************************************/
/*************** Author: AhmedSalah	  *******************/
/*************** Layer: Service 	  *******************/
/*************** SWC: Task1			  *******************/
/*************** Date: 3/2/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/


#include "BIT_Math.h"
#include "STD_TYPES.h"

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