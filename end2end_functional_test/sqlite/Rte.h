#pragma once
#ifndef RTE_C
#define EXTERN extern
#else
#define EXTERN	;
#endif // BLINK_MANAGER_C

typedef struct {
	uint8 IgnState;
	uint8 DoorLockFromOutside;
}sBlinkerManager_Feeder;

typedef struct tBlinkerManager_Suction {
	uint8 BlinkSwitch_Pos;
}sBlinkerManager_Suction;


extern sBlinkerManager_Suction gBlinkerManager_Suction;
extern sBlinkerManager_Feeder gBlinkerManager_Feeder;