/********************************************************/
/********************************************************/
/*************** Author: AhmedSalah	  *******************/
/*************** Layer: Service 	  *******************/
/*************** SWC: Task1			  *******************/
/*************** Date: 3/2/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef Task_1_H_
#define Task_1_H_

#define SW_PRESSED    		    0
#define SW_NOT_PRESSED 			1


//  SW Port Macros
#define SW_PORTA    0
#define SW_PORTB    1
#define SW_PORTC    2
#define SW_PORTD    3

//  SW Pin Macros
#define SW_PIN0     0
#define SW_PIN1     1
#define SW_PIN2     2
#define SW_PIN3     3
#define SW_PIN4     4
#define SW_PIN5     5
#define SW_PIN6     6
#define SW_PIN7     7

//  SW direction
#define SW_PIN_OUTPUT   1
#define SW_PIN_INPUT    0

//  SW State
#define SW_PIN_HIGH   1
#define SW_PIN_LOW	   0

// Port SW Direction
#define SW_PORT_OUTPUT		 0xff
#define SW_PORT_INPUT 		 0x00

//  Port SW State
#define SW_PORT_HIGH   	 0xff
#define SW_PORT_LOW	     0x00

/*******************************************************************/
/************* Options of State :- *********************************/
/*	 	 	 	 	 	 	 	 1- SW_Int_PULL_UP
 *	 	 	 	 	 	 	 	 2- SW_Ext_PULL_UP
 *	 	 	 	 	 	 	 	 3- SW_Ext_PULL_DOWN
 *	 	 	 	 	 	 	 	 4- SW_FLOATING
/*******************************************************************/
#define SW_INTERNAL_PULL_UP     0
#define SW_EXTERNAL_PULL_UP     1
#define SW_EXTERNAL_PULL_DOWN   2
#define SW_FLOATING       		3



typedef struct{

	u8 Port;				// SW_PORTA or SW_PORTB or SW_PORTC or SW_PORTD
	u8 Pin ;                // SW_PIN0 , SW_PIN1 ,SW_PIN2 , SW_PIN3 , SW_PIN4 , SW_PIN5 , SW_PIN6 , SW_PIN7
	u8 Pull_State;          // SW_PORTA or SW_PORTB or SW_PORTC or SW_PORTD
}SW_Type;


/* Description : this Function is to init Pin_Switch
 * \input :  SW_T SW_Configuration	 , Range : SW_Configuration-> SW_PORTA ~ SW_PORTD
 *             						 , Range : SW_Configuration-> SW_PIN   ~ SW_PIN7
 *           		 		         , Range : SW_Configuration-> 	1- SW_Int_PULL_UP
 *	 	 	 	 	 	 	 	 									2- SW_Ext_PULL_UP
 *	 	 	 	 	 	 	 										3- SW_Ext_PULL_DOWN
 *	 	 	 	 	 	 	 										4- SW_FLOATING
 * Return  : nothing
 */
void SW_voidPinInit(SW_Type *SW_structConfig);




/* Description : this Function is to set Pin_Switch States
 * \input :  SW_T SW_Configuration	 , Range : SW_Configuration-> SW_PORTA ~ SW_PORTD
 *             						 , Range : SW_Configuration-> SW_PIN   ~ SW_PIN7
 *           		 		         , Range : SW_Configuration-> 	1- SW_Int_PULL_UP
 *	 	 	 	 	 	 	 	 									2- SW_Ext_PULL_UP
 *	 	 	 	 	 	 	 										3- SW_Ext_PULL_DOWN
 *	 	 	 	 	 	 	 										4- SW_FLOATING
 * Return  : States Pressed Or not
 */
u8 SW_u8GetPressed(SW_Type *SW_structconfig);


#endif /* SW_INTERFACE_H_ */
