#ifndef ADC_H
#define ADC_H

#include "Project_Types_MSVC.h"

#define ADC_GROUP_1 0x0u
#define ADC_GROUP_2 0x1u

typedef enum Adc_ch1{
	BLINKER_SWITCH_POS_CH,
	NOF_ADC_CH1
}EADC;

uint16 AdcGetCounts(uint8, uint8);

#endif //ADC_H
