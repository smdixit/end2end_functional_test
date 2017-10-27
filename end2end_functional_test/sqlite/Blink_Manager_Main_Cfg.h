#pragma once
const char *InTable_BlinkerManager[] = { "InTable_BlinkerManager\0", "InTable_Blinker_CplxDrv\0" };
const char *OutTable_BlinkerManager[] = { "OutTable_BlinkerManager\0", "OutTable_Blinker_CplxDrv\0" };
const char *Cmp_BlinkerManager[] = { "BlinkerManager"};

#define CMP_BLINK_MGR_CFG	\
        1, 1, InTable_BlinkerManager, OutTable_BlinkerManager, Cmp_BlinkerManager

/* Common IO */
const char *InTable_Common[] = { "InTable_Common\0", "InTable_Blinker_CplxDrv\0" };
const char *OutTable_Common[] = { "OutTable_Common\0", "OutTable_Blinker_CplxDrv\0" };
const char *Cmp_Common[] = { "Common"};

#define CMP_COMMON_CFG	\
        1, 1, InTable_Common, OutTable_Common, Cmp_Common
