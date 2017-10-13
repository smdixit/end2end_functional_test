#define BLINKER_CPLXDRV_C
#include "Project_Types_MSVC.h"
#include "Blinker_CplxDrv.h"
#include "Adc.h"
#include "Digital_IO.h"
#include "Blinker_CplxDrv_Mock.h"

static pErrorTypes_cb *pBlinkManager_ErrorTypes_cb;

uint8 Get_BlinkerSwitch_Pos(void) {

	uint8 BlinkSwitch_Pos;
	uint16 BlinkerSwitch = AdcGetCounts_Blinker_cdd(ADC_GROUP_1, BLINKER_SWITCH_POS_CH);

	if ((BLINKER_OFF_COUNT <= BlinkerSwitch) && (BLINKER_LEFT_COUNT > BlinkerSwitch)) {
		BlinkSwitch_Pos = BLINKER_OFF_STATE;
	}
	else if ((BLINKER_LEFT_COUNT <= BlinkerSwitch) && (BLINKER_RIGHT_COUNT > BlinkerSwitch)) {
		BlinkSwitch_Pos = BLINKER_LEFT;
	}
	else if ((BLINKER_RIGHT_COUNT <= BlinkerSwitch) && (BLINKER_ERROR > BlinkerSwitch)) {
		BlinkSwitch_Pos = BLINKER_RIGHT;
	}
	else {
		BlinkSwitch_Pos = BLINKER_ERROR;
	}

	return BlinkSwitch_Pos;
}

uint8 Get_HazardSwitch_Pos(void) {
	uint8 HazardSwitch_Pos = Digital_InOut_Blinker_cdd(HAZARD_CH);
	return HazardSwitch_Pos;
}

/* This is invoked from a differnt path, say from another complex driver,
	and that source is not part of this simulation.
*/

/* Register Callbacks*/
void Register_BlinkManager_ErrorTypes_cb(pErrorTypes_cb *pCallbackList) {
	pBlinkManager_ErrorTypes_cb = pCallbackList;
}
