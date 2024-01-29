#include"LCDdisplay.h"

/*HAL includes*/
#include "CLCD_interface.h"

/*Free RTOS includes*/
#include"FreeRTOS.h"
#include"task.h"
#include "semphr.h"



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