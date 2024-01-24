/********************************************************/
/********************************************************/
/*************** Author: AhmedSalah	  *******************/
/*************** Layer: HAL 		  *******************/
/*************** SWC: SW			  *******************/
/*************** Date: 3/2/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/
#include "BIT_Math.h"
#include "STD_TYPES.h"

#define F_CPU 8000000UL
#include <avr/delay.h>

#include "DIO_interface.h"
#include "SW_interface.h"

/********************************************************/
void SW_voidPinInit(SW_Type *SW_structConfig)
{
	DIO_enumSetPinDirection(SW_structConfig->Port,SW_structConfig->Pin,SW_PIN_INPUT);


	/*if State is PUll UP Internal in MC*/
	if (SW_structConfig->Pull_State == SW_INTERNAL_PULL_UP)
	{
		DIO_enumSetPinValue(SW_structConfig->Port,SW_structConfig->Pin,SW_PIN_HIGH);
	}
}


u8 SW_u8GetPressed(SW_Type *SW_structconfig)
{
	/*the return  */
	static	u8 Local_u8PinVal = SW_NOT_PRESSED ;
	static	u8 Local_u8Result = SW_NOT_PRESSED ;

	/*if the State is Pull_up General*/
	if ((SW_structconfig ->Pull_State == SW_INTERNAL_PULL_UP)  || (SW_structconfig ->Pull_State == SW_EXTERNAL_PULL_UP))
	{
		/*Get value from Switch*/
		DIO_enumGetPinValue(SW_structconfig->Port,SW_structconfig->Pin,&Local_u8PinVal);

		/*Pressed*/
		if( Local_u8PinVal == 0 )
		{
			Local_u8Result= SW_PRESSED;
			_delay_ms(40);
		}
		/*Not Pressed*/
		else if( Local_u8PinVal == 1 )
		{
			Local_u8Result= SW_NOT_PRESSED;
			_delay_ms(40);

		}
	}

	else if (SW_structconfig->Pull_State == SW_EXTERNAL_PULL_DOWN)
	{
		/*Get value from Switch*/
		DIO_enumGetPinValue(SW_structconfig->Port,SW_structconfig->Pin,&Local_u8PinVal);

		/*Pressed*/
		if( Local_u8PinVal == 1 )
		{
			Local_u8Result= SW_PRESSED;
			_delay_ms(40);

		}
		/*Not Pressed*/
		else if( Local_u8PinVal == 0 )
		{
			Local_u8Result= SW_NOT_PRESSED;
			_delay_ms(40);

		}
	}

	return Local_u8Result;
}
