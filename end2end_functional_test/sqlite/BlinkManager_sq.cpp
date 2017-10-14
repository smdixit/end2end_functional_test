#define BLINK_MANAGER_C
#include "Project_Types_MSVC.h"
#include "Rte_Types_Emulation.h"
#include "Blinker_CplxDrv.h"
#include "stdafx.h"


#include "Rte_BlinkerManager.h"

#include "BlinkManager_Mock.h"
#include "Timer.h"

static uint16 BlinkerOff_timer;

/*
* In bound non pre-emptive callbacks.
*/
STATIC uint8 ErrorType_One(uint8 arg);
STATIC uint8 ErrorType_Two(uint8 arg);
STATIC uint8 ErrorType_Three(uint8 arg);

static pErrorTypes_cb BlinkManager_ErrorTypes_cb[eErrorType_Count] = { &ErrorType_One, &ErrorType_Two , &ErrorType_Three };

void RInit_BlinkManager(void) {
	Register_BlinkManager_ErrorTypes_cb(BlinkManager_ErrorTypes_cb);
}

void Runnable_Main_BlinkManager(void)
{
	uint8 IgnState;
	uint8 IsDoorLockFromOutside;
	BlinkerState BlinkSwitch_Pos;
	uint8 HazardSwitch_Pos;

	Rte_Read_ComIn_IgnState(&IgnState);
	BlinkSwitch_Pos = (BlinkerState) Get_BlinkerSwitch_Pos();
	HazardSwitch_Pos = Get_HazardSwitch_Pos();

	if (FALSE != HazardSwitch_Pos) {
		BlinkSwitch_Pos = BLINKER_BOTH;
		Timer_Destroy_U16(&BlinkerOff_timer);
	}
	else{
		if(BLINKER_OFF_STATE != BlinkSwitch_Pos){
			Rte_Read_ComIn_DoorLockFromOutside(& IsDoorLockFromOutside);
			if( (IGN_ON == IgnState) && (FALSE != IsDoorLockFromOutside) ){
				/* IGN OFF, Door locked, No Hazard,
					but one of blinker ON.
					Wait for 2 mins to switch it off.
				*/
				if(FALSE == Timer_IsCreated_U16(BlinkerOff_timer) ){
					(void) Timer_Create_U16(&BlinkerOff_timer);
				}
				else if(FALSE != Timer_Overrun_U16(BlinkerOff_timer, 2000u) ){
					/* 2 sec over, switch off.*/
					BlinkSwitch_Pos = BLINKER_OFF_STATE;
				}
				else{
					/* Wait, do nothing*/
				}
			}
			else{
				/* On door open / Ignition ON, 2 min wait must be re-started. */
				Timer_Destroy_U16(&BlinkerOff_timer);
			}
		}
	}
	Rte_Read_ComIn_BlinkSwitch_Pos(BlinkSwitch_Pos);
	printf("%s\n", __FUNCTION__);

}

STATIC uint8 ErrorType_One(uint8 arg) {
	printf("%s: arg= %d\n", __FUNCTION__, arg);
	return arg;
}
STATIC uint8 ErrorType_Two(uint8 arg) {
	printf("%s: arg= %d\n", __FUNCTION__, arg);
	return arg;
}
STATIC uint8 ErrorType_Three(uint8 arg) {
	printf("%s: arg= %d\n", __FUNCTION__, arg);
	return arg;
}

/* Static callback, called from source code not part of simulation,
   is invoked like this.
   User needs to define after which iteration / ms, this has to be called,
   of course, along with arg and return values taken care.
*/
#ifdef MOCK_IN_BOUND_NON_PREEMPTIVE_CB_METHOD_02
uint8 Invoke_BlinkManager_ErrorType_One(uint8 arg) {
	uint8 ret = ErrorType_One(arg);
	return ret;
}
#endif //MOCK_IN_BOUND_NON_PREEMPTIVE_CB_METHOD_02

