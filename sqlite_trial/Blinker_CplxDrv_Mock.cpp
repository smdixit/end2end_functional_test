#include "Project_Types_MSVC.h"
#include "Blinker_CplxDrv_Mock.h"

uint16 AdcGetCounts_Blinker_cdd(uint8 ch, uint8 port)
{
	return (uint16)( (ch << 8) | port);

}

uint8 Digital_InOut_Blinker_cdd(uint8 ch)
{
	return ch;
}
