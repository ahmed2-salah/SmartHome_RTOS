/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: PORT_Module	  *******************/
/*************** Date: 23/12/2022 	  *******************/
/*************** Author: Adel Hani    *******************/
/********************************************************/
/********************************************************/

#ifndef PORT_REGISTER_H_
#define PORT_REGISTER_H_
/***********************************************/
/**************** Register macros **************/
/***********************************************/

#define  DDRA_REG        *((volatile u8*)  0x3A)
#define  PORTA_REG       *((volatile u8*)  0x3B)

#define  PORTB_REG       *((volatile u8*)  0x38)
#define  DDRB_REG        *((volatile u8*)  0x37)

#define  PORTC_REG       *((volatile u8*)  0x35)
#define  DDRC_REG        *((volatile u8*)  0x34)

#define  PORTD_REG       *((volatile u8*)  0x32)
#define  DDRD_REG        *((volatile u8*)  0x31)


#endif /* PORT_REGISTER_H_ */
