/*
 * LM35_program.c
 *
 *  Created on: Mar 13, 2023
 *      Author: A-plus store
 */

#include "BIT_Math.h"
#include "STD_TYPES.h"

#include "LM35_interface.h"
#include "ADC_interface.h"




void LM35_voidInit(void)
{
	ADC_voidInit();

}



/*The selection the Resolution please check the ADC_configration*/
u8 LM35_u8GetTemperatureValue(u8 Copy_Channel ,u8 Copy_u8ADCResolution)
{
	u16 Local_u16ADCResult ;
	u16 Local_u16AnalogValue ;

	ADC_u16StartConversionSynch(Copy_Channel, &Local_u16ADCResult);

	if ( Copy_u8ADCResolution == LM35_RESOLUTION_10 )
	{
		Local_u16AnalogValue = (u16)(((u32)Local_u16ADCResult * 5000UL )/1024UL);
	}

	else if (Copy_u8ADCResolution == LM35_RESOLUTION_8)
	{
		Local_u16AnalogValue = (u16)(((u32)Local_u16ADCResult * 5000UL )/256UL);
	}

	/* Convert ( mv --> Temp ) */
	 return (Local_u16AnalogValue / 10) ;
}
