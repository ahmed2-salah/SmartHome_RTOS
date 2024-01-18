/*
 * LM35_interface.h
 *
 *  Created on: Mar 13, 2023
 *      Author: A-plus store
 */

#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_


#define LM35_RESOLUTION_10		10
#define LM35_RESOLUTION_8		8



void LM35_voidInit(void);


/* Description : This Function is Get the Temperature value
 * \input :  Copy_Channel    		 	, Range : CHANNEL_A0 ~ CHANNEL_A7
 *           Copy_u8ADCResolution     	, Range : LM35_RESOLUTION_8 OR LM35_RESOLUTION_10
 *
 * Return  : Temperature value
 */
u8 LM35_u8GetTemperatureValue(u8 Copy_Channel ,u8 Copy_u8ADCResolution );

#endif /* LM35_INTERFACE_H_ */
