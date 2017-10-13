
#include "Project_Types_MSVC.h"
#include "Timer.h"
#include <stddef.h>


// !!! At the moment, don't care about roll-over !!!

/*
16 Bit Timer
*/
boolean Timer_Create_U16(uint16 * const pTimer){
	if(NULL != pTimer){
		*pTimer = (uint16)Get_OsTick();
		return TRUE;
	}
	return FALSE;
}

uint16 Timer_Gettime_U16(const uint16 Timer){
    return (uint16)(Get_OsTick() - Timer);
}

boolean Timer_Overrun_U16(const uint16 Timer, uint16 overrun){
	return ( (Timer + overrun) >= (uint16)Get_OsTick() ? FALSE : TRUE);
}

boolean Timer_IsCreated_U16(const uint16 Timer){
	return (Timer == 0u) ?	FALSE : TRUE;
}

void Timer_Destroy_U16(uint16 * const pTimer) {
	*pTimer = 0u;
}

/*
32 Bit Timer
*/
boolean Timer_Create_U32(uint32 * const pTimer){
	if(NULL != pTimer){
		*pTimer = (uint32)Get_OsTick();
		return TRUE;
	}
	return FALSE;
}

uint32 Timer_Gettime_U32(const uint32 Timer){
	return (uint32)((uint32)Get_OsTick - Timer);
}

boolean Timer_Overrun_U32(const uint32 Timer, uint32 overrun){
	return ( (Timer + overrun) >= (uint32)Get_OsTick() ? FALSE : TRUE);
}

boolean Timer_IsCreated_U32(const uint32 Timer){
	return (Timer == 0u) ?	FALSE : TRUE;
}

void Timer_Destroy_U32(uint32 * const pTimer) {
	*pTimer = 0u;
}
