

boolean Timer_Create_U16(uint16 * const pTimer);
uint16 Timer_Gettime_U16(const uint16 Timer);
boolean Timer_Overrun_U16(const uint16 Timer, uint16 overrun);
boolean Timer_IsCreated_U16(const uint16 Timer);
void Timer_Destroy_U16(uint16 * const pTimer);

boolean Timer_Create_U32(uint32 * const pTimer);
uint32 Timer_Gettime_U32(const uint32 Timer);
boolean Timer_Overrun_U32(const uint32 Timer, uint32 overrun);
boolean Timer_IsCreated_U32(const uint32 Timer);
void Timer_Destroy_U32(uint32 * const pTimer);

uint32 Get_OsTick(void);
