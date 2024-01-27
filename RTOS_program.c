/*
 * ppp.c
 *
 *  Created on: 27 Jan 2024
 *      Author: Ziad Yakoot
 */
#include"STD_types.h"
#include"RTOS_priv.h"
#include"RTOS_interface.h"
#include"RTOS_cfg.h"
#include"GIE_interface.h"
#include"TIMER_interface.h"


task_t systemTasks[TASK_NUM]={0};



void RTOS_void_Start(void)
{
	Timer0_uint8_CompareMatchSetCallBack(&Schedular);
	GIE_voidEnableGlobleInterrupt();
	Timer0_ctc();
}

uint8 RTOS_uint8_CreateTask(uint8 copy_uint8_priority, uint16 copy_uint16_periodicity, uint16 copy_uint8_firstDelay, void (*pvTaskFunc)(void))
{
	uint8 errorState=0;
	if(systemTasks[copy_uint8_priority].taskFunc==NULL)
	{
		systemTasks[copy_uint8_priority].periodicity=copy_uint16_periodicity;
		systemTasks[copy_uint8_priority].taskstate=TASK_RUNNING;
		systemTasks[copy_uint8_priority].firstDelay=copy_uint8_firstDelay;
		systemTasks[copy_uint8_priority].taskFunc=pvTaskFunc;
	}
	else
	{
		errorState=1;
	}

	return errorState;
}

void RTOS_void_suspendTask(uint8 copy_uint8_priority)
{
	systemTasks[copy_uint8_priority].taskstate=TASK_SUSPENDED;
}

static void Schedular(void)
{
	uint8 counter;
	for(counter=0; counter<TASK_NUM ;counter++)
	{
      if(systemTasks[counter].taskstate==TASK_RUNNING)
      {
    	  if(systemTasks[counter].firstDelay==STD_LOW)
    	  {
    		  if(systemTasks[counter].taskFunc!=NULL)
    		  {
    			  systemTasks[counter].taskFunc();
    			  systemTasks[counter].firstDelay=systemTasks[counter].periodicity-OFFSET;
    		  }
    		  else
    		  {

    		  }
    	  }
    	  else
    	  {
    		  systemTasks[counter].firstDelay--;
    	  }
      }
      else
      {

      }
	}
}
