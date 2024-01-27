/*
 * RTOS_priv.h
 *
 *  Created on: 26 Jan 2024
 *      Author: Ziad Yakoot
 */

#ifndef RTOS_PRIV_H_
#define RTOS_PRIV_H_

typedef struct
{
	uint16 periodicity;
	uint8 taskstate;
	uint16 firstDelay;
	void (*taskFunc)(void);

}task_t;

static void Schedular(void);

#define TASK_RUNNING			0
#define TASK_SUSPENDED			1


#define OFFSET					1


#endif /* RTOS_PRIV_H_ */
