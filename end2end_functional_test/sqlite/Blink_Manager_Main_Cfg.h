#pragma once
const char *InTable_CommonInputs[] = { "InTable_CommonInputs\0", "InTable_Blinker_CplxDrv\0" };
const char *OutTable_BlinkerManager[] = { "OutTable_BlinkerManager\0", "OutTable_Blinker_CplxDrv\0" };
const char *Cmp_BlinkerManager[] = { "BlinkerManager"};

#define CMP_BLINK_MGR_CFG	\
        1, 1, InTable_CommonInputs, OutTable_BlinkerManager, Cmp_BlinkerManager
