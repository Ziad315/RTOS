/*
 * RTOS_interface.h
 *
 *  Created on: 26 Jan 2024
 *      Author: Ziad Yakoot
 */

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

#define EMPTY_PRIORITY			0
#define TAKEN_PRIORITY			1

void RTOS_void_Start(void);
uint8 RTOS_uint8_CreateTask(uint8 copy_uint8_priority, uint16 copy_uint16_periodicity, uint16 copy_uint8_firstDelay, void (*pvTaskFunc)(void));
void RTOS_void_suspendTask(uint8 copy_uint8_priority);

#endif /* RTOS_INTERFACE_H_ */
