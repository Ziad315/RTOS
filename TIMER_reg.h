/*
 * TIMER_reg.h
 *
 *  Created on: 29 Dec 2023
 *      Author: Ziad Yakoot
 */

#ifndef TIMER_REG_H_
#define TIMER_REG_H_

#define TIMSK                  (*(volatile uint8*)0x59)
#define TIFR                   (*(volatile uint8*)0x58)
/*Timer0*/
#define TCCR0                  (*(volatile uint8*)0x53)
#define TCNT0                  (*(volatile uint8*)0x52)
#define OCR0                   (*(volatile uint8*)0x5C)

#define TCCR1B                  (*(volatile uint8*)0x4E)
#define TCCR1A                  (*(volatile uint8*)0x4f)
#define WGM10					0
#define WGM11					1
#define COM1A1                  7
#define COM1A0                  6

#define TCNT1H                  (*(volatile uint8*)0x4D)
#define TCNT1L                  (*(volatile uint8*)0x4C)

#define OCR1                  (*(volatile uint16*)0x4a)

#define ICR1                   (*(volatile uint16*)0x46)


#endif /* TIMER_REG_H_ */
