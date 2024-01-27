/*
 * GIE_program.c
 *
 *  Created on: 18 Dec 2023
 *      Author: Ziad Yakoot
 */

#include "STD_types.h"
#include "COMMON_MACROS.h"
#include "GIE_reg.h"
#include "GIE_interface.h"

void GIE_voidEnableGlobleInterrupt(void)
{
	SET_BIT(STATUS_REGISTER ,STATUS_RESIGTER_I);
}


void GIE_voidDisableGlobleInterrupt(void)
{
	CLR_BIT(STATUS_REGISTER ,STATUS_RESIGTER_I);
}
