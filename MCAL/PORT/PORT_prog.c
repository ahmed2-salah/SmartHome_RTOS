/********************************************************/
/********************************************************/
/*************** Author: AhmedSalah	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: PORT_Module	  *******************/
/*************** Date: 23/12/2022 	  *******************/
/*************** Author: Adel Hani    *******************/
/********************************************************/
/********************************************************/

#include "STD_TYPES.h"

#include "PORT_Config.h"
#include "PORT_Private.h"
#include "PORT_interface.h"
#include "PORT_Register.h"


void PORT_voidInit(void)
{
	DDRA_REG=PORTA_DIR;
	DDRB_REG=PORTB_DIR;
	DDRC_REG=PORTC_DIR;
	DDRD_REG=PORTD_DIR;

	PORTA_REG=PORTA_INITIAL_VALUE;
	PORTB_REG=PORTB_INITIAL_VALUE;
	PORTC_REG=PORTC_INITIAL_VALUE;
	PORTD_REG=PORTD_INITIAL_VALUE;

}
