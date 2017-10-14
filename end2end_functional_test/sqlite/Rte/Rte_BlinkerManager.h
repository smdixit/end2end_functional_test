//#ifndef RTE_BLINKERMANAGER_H
//#define RTE_BLINKERMANAGER_H

#include "Project_Types_MSVC.h"

void Runnable_Main_BlinkManager(void); //May need to be removed from compiler.
void Rte_Read_ComIn_IgnState(uint8 *IgnState);
void Rte_Read_ComIn_BlinkSwitch_Pos(uint8 BlinkSwitch_Pos);
void Rte_Read_ComIn_DoorLockFromOutside(uint8 *pDoorLockFromOutside);

//#endif /RTE_BLINKERMANAGER_H