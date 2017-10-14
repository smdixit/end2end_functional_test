#include <string>
#include <iostream>

#include "Project_Types_MSVC.h"
#include "Rte_BlinkerManager.h"
#include "Blinker_CplxDrv.h"
#include "BlinkManager_Mock.h"
#include "Rte.h"

// Feed
void Rte_Read_ComIn_IgnState(uint8 *IgnState)
{
	*IgnState = gBlinkerManager_Feeder.IgnState;
}

void Rte_Read_ComIn_DoorLockFromOutside(uint8 *pDoorLockFromOutside){
	*pDoorLockFromOutside = gBlinkerManager_Feeder.DoorLockFromOutside;
}

// Suction
void Rte_Read_ComIn_BlinkSwitch_Pos(uint8 BlinkSwitch_Pos) {
	gBlinkerManager_Suction.BlinkSwitch_Pos = BlinkSwitch_Pos;
}

void BlinkerManager_LoadFeeder(sBlinkerManager_Feeder pBlinkerManager_Feeder){
	gBlinkerManager_Feeder = pBlinkerManager_Feeder;
	printf("called %s\n", __FUNCTION__);	
	printf("Ign = %u\n", gBlinkerManager_Feeder.IgnState);
	printf("DoorLockFromOutside = %u\n", gBlinkerManager_Feeder.DoorLockFromOutside);
}

sBlinkerManager_Suction BlinkerManager_DumpCollector(void) {
	return gBlinkerManager_Suction;
}
