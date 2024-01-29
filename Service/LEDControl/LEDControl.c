#include"LEDControl.h"

/*HAL includes*/
#include "Led_interface.h"

/*Free RTOS includes*/
#include"FreeRTOS.h"
#include"task.h"
#include "semphr.h"


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