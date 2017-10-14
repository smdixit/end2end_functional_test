#include "common_mocks.h"

#define Rte_TypeDef_DtCtDisplaysStatus

#include <string.h>
#include "Rte_CtHWSWC_Displays.h"

#include "ComplexDrv_PowerGeneric.h"
#include "ComplexDrv_MonitorFault.h"

#include "Pwm.h"
#include "dio_interface.h"
#include "Port.h"
#include "CtApNvManager_Common.h"
#include "ComplexDrv_Display3Inch_cfg.h"
#include "analog_in_interface.h"


#include "Dispatcher.h"

//Own
#include "Spi_Api_Static.h"

//Feed Out
static DtCtDisplaysStatus Rte_CtHWSWC_Displays_PiCtlDisplaysStatus_PiCtDisplaysStatus;
DtStandardSubsystemControlType Rte_CtHWSWC_HMI_PpCtlDisplaysControl_DeRequiredDisplaysState;
SInt16 Rte_CtHwThermalManagement_PiCtlClusterThermalStatus_DeTube12Temperature;
SInt16 Rte_CtHwThermalManagement_PiCtlClusterThermalStatus_DeTube45Temperature;
SInt16 Rte_CtHwThermalManagement_PiCtlClusterThermalStatus_DeTube3Temperature;

boolean cd_pm_is_gip_display_driver_ready_for_calibration ( void )
{
    return 1;

} // cd_pm_is_gip_display_driver_ready_for_calibration

//Feed In
boolean cd_pm_mon_is_display_healty ( const display_type_t display )
{
	return 1;
}

//Feed In
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtHWSWC_Displays_PiCtlDisplaysStatusRead_PiCtDisplaysStatus(P2VAR(DtCtDisplaysStatus, AUTOMATIC, RTE_CTHWSWC_DISPLAYS_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CtHWSWC_Displays_PiCtlDisplaysStatus_PiCtDisplaysStatus;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

//Feed In
FUNC(Std_ReturnType, RTE_CTAPNVMANAGER_APPL_CODE) CtApNvManager_GetPIMAddress(CtApNvMgr_DataIDType DataId, P2VAR(UInt32, AUTOMATIC, RTE_CTAPNVMANAGER_APPL_VAR) BaseAddress) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Std_ReturnType ret = RTE_E_OK;
	 return ret;
}

boolean cd_pm_gip_initialized_displays ( void )
{
    return 1;

} // cd_pm_gip_initialized_displays

boolean cd_pm_is_splash_request_allowed(void)
{
     return 1;
}



/////////////Feed Out/////////////////////////
//Feed Out
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtHWSWC_Displays_PiCtlDisplaysStatus_PiCtDisplaysStatus(P2CONST(DtCtDisplaysStatus, AUTOMATIC, RTE_CTHWSWC_DISPLAYS_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;
  Rte_CtHWSWC_Displays_PiCtlDisplaysStatus_PiCtDisplaysStatus = *(data);
  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

//Feed Out
void Dig_Out(DIG_OUT_CHANNEL_ENUM_TYPE channel, DIG_OUT_CHANNEL_STATE_TYPE state)
{
	printf("%s channel=%d state=%d\n",__func__, channel, state);
}

//Feed Out
FUNC(void,PORT_CODE) Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
	printf("%s Pin=%d Mode=%d\n",__func__, Pin, Mode);
}

//Feed Out
FUNC(Std_ReturnType, SPI_CODE) Spi_SetupEB
(
  Spi_ChannelType Channel,
  P2CONST(Spi_DataType, AUTOMATIC, SPI_APPL_CONST) SrcDataBufferPtr,
  P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) DesDataBufferPtr,
  Spi_NumberOfDataType Length
)
{
	printf("%s called. With values:", __func__);
}

void cd_pm_mon_display_set_monitoring ( const display_type_t display, const boolean enabled )
{
	printf("noting for now, must not be mocked"); //noting for now, must not be mocked
}

void cd_pm_mon_display_set_hsync_monitoring ( const display_type_t display, const boolean enable )
{
	
}

void cd_pm_mon_activate_fault_monitoring ( const fault_type_t fault, const boolean enabled )
{
	
}

//Feed Out
void cd_pm_mon_display_monitoring_init ( void )
{
	
}

FUNC(void,PWM_CODE)
Pwm_SetDutyCycle (Pwm_ChannelType ChannelNumber, uint16 DutyCycle)
{
	
}

//////////////Feed IO///////////////
FUNC(Std_ReturnType, SPI_CODE) Spi_AsyncTransmit(Spi_SequenceType Sequence)
{
  return E_OK;
}

//Feed IO
Std_ReturnType DispatchMessage ( uint8 msgid, uint8 length, uint8 *MsgPtr, uint8 options )
{
	return E_OK;
}

Std_ReturnType cd_pm_disp3inch_set_config_data( const uint8* const pCfgDataBuff, const uint8 BuffSize )
{
	return E_OK;
}

Std_ReturnType cd_pm_disp3inch_get_config_sequence_data( sDisplayCfgSeqData* const pDestCfgDataBuf, const uint8 Index )
{
	return E_OK;
}

Std_ReturnType cd_PowerRing_SetBrigntness(uint8 PwmPercentage)
{
	return E_OK;
}

//Feed IO
Std_ReturnType cd_pm_disp3inch_get_spi_config( sDisplay3InchSpiConfigType* const pDisplay3SpiCfg)
{
	return E_OK;
}

uint16_t Analog_In_Get_Raw_Counts(ANALOG_IN_CHANNEL_NAME_TYPE channel)
{
	return (uint16_t)0;
}