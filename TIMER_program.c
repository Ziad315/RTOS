/*
 * TIMER_program.c
 *
 *  Created on: 29 Dec 2023
 *      Author: Ziad Yakoot
 */
#include"STD_types.h"
#include"COMMON_MACROS.h"
#include"TIMER_priv.h"
#include"TIMER_interface.h"
#include"TIMER_reg.h"
#include"TIMER_cfg.h"
/*Global pointer to function array hold callback function address*/
static void (*Timer0_pvCompareMatchCallBackFun)(void) = NULL;


void Timer0_Normal(void)
{

	CLR_BIT(TCCR0,TCCR0_FOC0);

	CLR_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);

	CLR_BIT(TCCR0,TCCR0_COM01);
	SET_BIT(TCCR0,TCCR0_COM00);

	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);

}
void Timer0_ctc(void)
{
	    SET_BIT(TIMSK,TIMSK_OCIE0); //enable interrupt
	    CLR_BIT(TCCR0,TCCR0_FOC0);
		SET_BIT(TCCR0,TCCR0_WGM01);
		CLR_BIT(TCCR0,TCCR0_WGM00);

		CLR_BIT(TCCR0,TCCR0_COM01);
		SET_BIT(TCCR0,TCCR0_COM00);

		SET_BIT(TCCR0,TCCR0_CS00);
		SET_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);
		OCR0 = TIMER0_PRELOAD_VAL;
}

void Timer0_PWM_FAST(void)
{
	  SET_BIT(TCCR0,TCCR0_FOC0);
	  SET_BIT(TCCR0,TCCR0_WGM01);
	  SET_BIT(TCCR0,TCCR0_WGM00);

	  SET_BIT(TCCR0,TCCR0_COM01);
	  CLR_BIT(TCCR0,TCCR0_COM00);

	  SET_BIT(TCCR0,TCCR0_CS00);
	  CLR_BIT(TCCR0,TCCR0_CS01);
	  SET_BIT(TCCR0,TCCR0_CS02);
	  OCR0 = TIMER0_PRELOAD_VAL;
}
void Timer0_PWM_PHASE(void)
{
	      SET_BIT(TCCR0,TCCR0_FOC0);
		  CLR_BIT(TCCR0,TCCR0_WGM01);
		  SET_BIT(TCCR0,TCCR0_WGM00);

		  SET_BIT(TCCR0,TCCR0_COM01);
		  CLR_BIT(TCCR0,TCCR0_COM00);

		  SET_BIT(TCCR0,TCCR0_CS00);
		  CLR_BIT(TCCR0,TCCR0_CS01);
		  SET_BIT(TCCR0,TCCR0_CS02);
		  OCR0 = TIMER0_PRELOAD_VAL;
}
void TIMER1_10_BIT(void)
{


	OCR1=2000;
	ICR1=40000;
	/*FAST PWM ICR1 */
		SET_BIT(TCCR1B,TCCR1B_WGM13);
		SET_BIT(TCCR1B,TCCR1B_WGM12);
		SET_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1A,WGM10);

	SET_BIT(TCCR1A,COM1A1);  //Non inverting mode
	CLR_BIT(TCCR1A,COM1A0);

	CLR_BIT(TCCR1B,TCCR1B_CS12);  //PRERSCALAR   8
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS10);


}
uint8 Timer0_uint8_CompareMatchSetCallBack(void (*copy_pv_CallBackFunc)(void))
{
	uint8 local_uint8_error = STD_LOW;
	if(copy_pv_CallBackFunc != NULL)
	{
		Timer0_pvCompareMatchCallBackFun = copy_pv_CallBackFunc;
	}
	else
	{
		local_uint8_error = STD_LOW;
	}
	return local_uint8_error;
}

/*ISR FUNCTION*/
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(Timer0_pvCompareMatchCallBackFun != NULL)
		{
			Timer0_pvCompareMatchCallBackFun();
		}
}


