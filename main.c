/*
 * main.c
 *
 *  Created on: 26 Jan 2024
 *      Author: Ziad Yakoot
 */
#include "STD_types.h"
#include "COMMON_MACROS.h"
#include "RTOS_priv.h"
#include "RTOS_interface.h"
#include "RTOS_cfg.h"
#include "DIO_reg.h"
#include "GIE_interface.h"
#include "TIMER_interface.h"
#include "DIO_interface.h"
void led1()
{
	TOG_BIT(PORTA,PIN1);

}
void led2()
{
	TOG_BIT(PORTA,PIN2);
}
void led3()
{
	TOG_BIT(PORTA,PIN3);

}
int main()
{
	DIO_setPinDirection(DIO_PORTA,PIN1,OUTPUT);
	DIO_setPinDirection(DIO_PORTA,PIN2,OUTPUT);
	DIO_setPinDirection(DIO_PORTA,PIN3,OUTPUT);

	RTOS_uint8_CreateTask(0,1000,1000,&led1);
	RTOS_uint8_CreateTask(1,2000,2000,&led2);
	RTOS_uint8_CreateTask(2,3000,2000,&led3);
	RTOS_void_Start();

	while(1)
	{

	}
}
