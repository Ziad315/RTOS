/*
 * TIMER_interface.h
 *
 *  Created on: 29 Dec 2023
 *      Author: Ziad Yakoot
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define TIMER0_OVF_VECTOR_ID         10

void Timer0_Normal(void);
void Timer0_ctc(void);
void Timer0_PWM_FAST(void);
void Timer0_PWM_PHASE(void);
void TIMER1_10_BIT(void);
uint8 Timer0_uint8_CompareMatchSetCallBack(void (*copy_pv_CallBackFunc)(void));

#endif /* TIMER_INTERFACE_H_ */
