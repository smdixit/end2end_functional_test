#ifndef Blinker_CplxDrv_H
#define Blinker_CplxDrv_H

#define BLINKER_OFF_COUNT			100u
#define BLINKER_LEFT_COUNT			200u
#define BLINKER_RIGHT_COUNT			300u
#define BLINKER_ERROR_COUNT			400u

typedef uint8(*pErrorTypes_cb)(uint8 arg);

typedef enum {
	eErrorType_One,
	eErrorType_Two,
	eErrorType_Three,
	eErrorType_Count
}List_BlinkManager_ErrorTypes_cb;

typedef enum {
	BLINKER_OFF_STATE,
	BLINKER_LEFT,
	BLINKER_RIGHT,
	BLINKER_BOTH,
	BLINKER_ERROR
}BlinkerState;

uint8 Get_BlinkerSwitch_Pos(void);
uint8 Get_HazardSwitch_Pos(void);

void Register_BlinkManager_ErrorTypes_cb(pErrorTypes_cb *pCallbackList);
#endif // !Blinker_CplxDrv_H

