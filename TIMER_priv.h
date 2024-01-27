/*
 * TIMER_priv.h
 *
 *  Created on: 29 Dec 2023
 *      Author: Ziad Yakoot
 */

#ifndef TIMER_PRIV_H_
#define TIMER_PRIV_H_

#define TIMSK_OCIE2                     7
#define TIMSK_TOIE2                     6
#define TIMSK_TICIE1                    5
#define TIMSK_OCIE1A                    4
#define TIMSK_OCIE1B                    3
#define TIMSK_TOIE1                     2
#define TIMSK_OCIE0                     1
#define TIMSK_TOIE0                     0

#define TIFR_OCF2                       7
#define TIFR_TOV2                       6
#define TIFR_ICF1                       5
#define TIFR_OCF1A                      4
#define TIFR_OCF1B                      3
#define TIFR_TOV1                       2
#define TIFR_OCF0                       1
#define TIFR_TOV0                       0

#define TCCR0_FOC0                     7
#define TCCR0_WGM00                    6
#define TCCR0_COM01                    5
#define TCCR0_COM00                    4
#define TCCR0_WGM01                    3
#define TCCR0_CS02                     2
#define TCCR0_CS01                     1
#define TCCR0_CS00                     0

#define WAV_GEN_MODE_NORMAL          0
#define WAV_GEN_MODE_PWM_PHASE       1
#define WAV_GEN_MODE_CTC             2
#define WAV_GEN_MODE_PWM_FAST        3

#define COM_OUTPUT_NO_PWM_NORMAL          0
#define COM_OUTPUT_NO_PWM_TOG_OC0         1
#define COM_OUTPUT_NO_PWM_CLR_OC0         2
#define COM_OUTPUT_NO_PWM_SET_OC0         3

#define COM_OUTPUT_FAST_NORMAL            0
#define COM_OUTPUT_FAST_CLR_OC0           2
#define COM_OUTPUT_FAST_SET_OC0           3

#define COM_OUTPUT_PHASE_NORMAL            0
#define COM_OUTPUT_PHASE_CLR_OC0           2
#define COM_OUTPUT_PHASE_SET_OC0           3


#define CLOCK_SELECT_NO_CLOCK              0
#define CLOCK_SELECT_NO_PRESCALE           1
#define CLOCK_SELECT_8_PRESCALE            2
#define CLOCK_SELECT_64_PRESCALE           3
#define CLOCK_SELECT_256_PRESCALE          4
#define CLOCK_SELECT_1024_PRESCALE         5
#define CLOCK_SELECT_EXT_FALLING_EDGE      6
#define CLOCK_SELECT_EXT_RISING_EDGE       7

#define ENABLE                  1
#define DISABLE                 0
#define TIMER0_PRESCALAR_MASK      0b11111000



/*TIMER1*/
#define TCCR1B_ICNC1                  7
#define TCCR1B_ICES1                  6
#define TCCR1B_WGM13                  4
#define TCCR1B_WGM12                  3
#define TCCR1B_CS12                   2
#define TCCR1B_CS11                   1
#define TCCR1B_CS10                   0





#endif /* TIMER_PRIV_H_ */
