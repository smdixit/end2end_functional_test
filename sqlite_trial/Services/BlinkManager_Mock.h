#ifndef BLINK_MGR_MOCK_H
#define BLINK_MGR_MOCK_H

#include "Project_Types_MSVC.h"
#include "Adc.h"
#include "Digital_IO.h"
#include "Rte.h"

#define MOCK_IN_BOUND_NON_PREEMPTIVE_CB_METHOD_01
#ifndef MOCK_IN_BOUND_NON_PREEMPTIVE_CB_METHOD_01
#define STATIC static
#else
#define STATIC
#endif // MOCK_IN_BOUND_NON_PREEMPTIVE_CB_METHOD_01

#define MOCK_IN_BOUND_NON_PREEMPTIVE_CB_METHOD_02

#ifndef BLINK_MANAGER_C
#define EXTERN extern "C"
#else
#define EXTERN	;
#endif // BLINK_MANAGER_C

void BlinkerManager_LoadFeeder(sBlinkerManager_Feeder pBlinkerManager_Feeder);
sBlinkerManager_Suction BlinkerManager_DumpCollector(void);

#endif // BLINK_MGR_MOCK_H