// sqlite_trial.cpp : Defines the entry point for the console application.
//
#if 0
#define MAIN_SCHED_CPP
#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include <windows.h>

#include <list>
#include <vector>

#include "Project_Types_MSVC.h"

#include "PopulateItems.hpp"
#include "Pop_BlinkerManager.hpp"

#include "DumpFromProgram.hpp"
#include "DepopBuses.hpp"
#include "Depop_BlinkManager.hpp"

#include "ComponentFactory.hpp"
#include "Tables.hpp"

#include "Generic_DB_Connector.hpp"

#include "Rte_BlinkerManager.h"
#include "BlinkManager_Mock.h"
#include "Timer.h"

#include "Blink_Manager_Main_Cfg.h"

void Runnable_10ms(void);
void Runnable_20ms(void);

/* CFG */
#define RUNNABLE_10MS_START_DELAY	0
#define RUNNABLE_10MS_PERIODICITY	10

#define RUNNABLE_20MS_START_DELAY	0
#define RUNNABLE_20MS_PERIODICITY	20

/* not CFG*/
#define RUNNABLE_10MS_NEXT_SCHED	( (RUNNABLE_10MS_START_DELAY == 0) ? RUNNABLE_10MS_PERIODICITY : RUNNABLE_10MS_START_DELAY)
#define RUNNABLE_20MS_NEXT_SCHED	( (RUNNABLE_20MS_START_DELAY == 0) ? RUNNABLE_20MS_PERIODICITY : RUNNABLE_20MS_START_DELAY)

char DbName[] = {"test.db\0"};

#define MAX_RUN_TIME 50
#define SCHED_TABLE		\
{	\
	{&Runnable_10ms, RUNNABLE_10MS_START_DELAY, RUNNABLE_10MS_PERIODICITY, RUNNABLE_10MS_NEXT_SCHED, {DbName, NULL, {CMP_BLINK_MGR_CFG} }	},	\
	{&Runnable_20ms, RUNNABLE_20MS_START_DELAY, RUNNABLE_20MS_PERIODICITY, RUNNABLE_20MS_NEXT_SCHED, {DbName, NULL, {CMP_BLINK_MGR_CFG} }	}	\
}

typedef struct TComponentConfig {
	int NumOfInTables;
	int NumOfOutTables; //For now, == NumOfInTables.
	char **InTablesNames;
	char **OutTablesNames;
	char **ComponentNames;
} SComponentConfig;

typedef struct TAppDbConnector {
	char *DbName; //DB name and the class is the same.
	GenericDbConnector *pDbConnector;
	SComponentConfig ComponentConfig;
} SAppDbConnector;

typedef struct TSchedTable {
	void (*pRunnable)(void);
	int StartDelay;
	int Periodicity;
	int NextSched;
	SAppDbConnector AppDbConnector;
} SSchedTable;

SSchedTable SchedTable[2] = SCHED_TABLE;
#define SCHED_TABLE_ELE ( sizeof(SchedTable) / sizeof(SchedTable[0])

HANDLE gDoneEvent;
static int CounterMS = 0;

static int DB_main(SAppDbConnector *pAppDbConnector);

void Runnable_10ms(void)
{
	int i;

	for (i = 0; i < SchedTable[0].AppDbConnector.ComponentConfig.NumOfInTables; i++) {
		//Assume each component has only 1 InTable for now.
		//Later this may be split into InTable for Init, periodic task, Callbacks etc.
		SchedTable[i].AppDbConnector.pDbConnector->LoadThisInstance(CounterMS / 10, SchedTable[0].AppDbConnector.ComponentConfig.InTablesNames[i]);
	}
	
	Runnable_Main_BlinkManager();

	for (i = 0; i < SchedTable[0].AppDbConnector.ComponentConfig.NumOfOutTables; i++) {
		//Assume each component has only 1 InTable for now.
		//Later this may be split into InTable for Init, periodic task, Callbacks etc.
		SchedTable[i].AppDbConnector.pDbConnector->DumpThisInstance(CounterMS / 10, SchedTable[0].AppDbConnector.ComponentConfig.OutTablesNames[i]);
	}
	printf("Runnable_10ms\n");
}

void Runnable_20ms(void)
{
	printf("Runnable_20ms\n");
}

void SchedActions(SSchedTable *pSchedTable)
{
	pSchedTable->NextSched = CounterMS + pSchedTable->Periodicity;
	pSchedTable->pRunnable();
}

void Scheduler(void)
{
	int i;
	for(i = 0; i < (sizeof(SchedTable) / sizeof(SchedTable[0]) ); i++)
	{
		if(CounterMS > SchedTable[i].StartDelay)
		{
			if(CounterMS == SchedTable[i].NextSched)
			{
				SchedActions(&SchedTable[i]);
			}			
		}
		else{
			//Less or equal
			if(CounterMS == SchedTable[i].StartDelay)
			{
				SchedActions(&SchedTable[i]);
			}
			else{
				//Start delay not yet reached, do nothing for this task.
			}
		}
	}
}

static int ConnectToDb(void)
{
	(void)DB_main(&SchedTable[0].AppDbConnector);    
    return(1);
}

VOID CALLBACK TimerRoutine(PVOID lpParam, BOOLEAN TimerOrWaitFired)
{
    if (lpParam == NULL)
    {
        printf("TimerRoutine lpParam is NULL\n");
    }
    else
    {
        // lpParam points to the argument; in this case it is an int
        if(TimerOrWaitFired)
        {      
			CounterMS++;
			printf("The wait timed out: %d\n", CounterMS);
			Scheduler();			
        }
        else
        {
            printf("The wait event was signaled.\n");
        }
    }

    SetEvent(gDoneEvent);
}

static int FireTimer(void)
{
	HANDLE hTimer = NULL;
    HANDLE hTimerQueue = NULL;
    int arg = 123;

    // Use an event object to track the TimerRoutine execution
    gDoneEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    if (NULL == gDoneEvent)
    {
        printf("CreateEvent failed (%d)\n", GetLastError());
        return 1;
    }

    // Create the timer queue.
    hTimerQueue = CreateTimerQueue();
    if (NULL == hTimerQueue)
    {
        printf("CreateTimerQueue failed (%d)\n", GetLastError());
        return 2;
    }

    // Set a timer to call the timer routine in 1 m seconds.
    if (!CreateTimerQueueTimer( &hTimer, hTimerQueue, 
            (WAITORTIMERCALLBACK)TimerRoutine, &arg , 1, 0, 0))
    {
        printf("CreateTimerQueueTimer failed (%d)\n", GetLastError());
        return 3;
    }

    // TODO: Do other useful work here 

   // printf("Call timer routine in 10 seconds...\n");

    // Wait for the timer-queue thread to complete using an event 
    // object. The thread will signal the event at that time.

    if (WaitForSingleObject(gDoneEvent, INFINITE) != WAIT_OBJECT_0)
        printf("WaitForSingleObject failed (%d)\n", GetLastError());

    CloseHandle(gDoneEvent);

    // Delete all timers in the timer queue.
    if (!DeleteTimerQueue(hTimerQueue))
        printf("DeleteTimerQueue failed (%d)\n", GetLastError());

	return 0;
}

static int Perform_rw(void)
{
	char s[30], *data;
    int Val;

	printf("Enter number of Millisecconds to run from here.\n");
	printf("Example:If you are at 30ms and want to run till 40ms, enter: -R 10\n");
	printf("Enter: -R time\n");

	if( fgets (s, 30, stdin)==NULL ){
		printf("failed to read your input!!\n");
		return - 1;
	}

	if( !strncmp("-R", &s[0], 2))
	{
		Val = strtol(&s[2], &data, 10);
		if(Val < 0)
		{
			printf("wrong usage of addr or value field\n");
			return - 1;
		}
		printf("Value= %u\n", Val);
	}
	else
	{
		printf("wrong usage\n");
		return - 1;
	}
	return Val;
}

static int DB_main_init(SAppDbConnector *pAppDbConnector)
{
	int hTableConnection;
	string TableStr;
	int i, NumRows_Conn_01;

	GenericDbConnector *pThisDbConnector = pAppDbConnector->pDbConnector;
	pThisDbConnector = new GenericDbConnector();
	pThisDbConnector->SetDbName(pAppDbConnector->DbName);
	pThisDbConnector->OpenConnection();
	pAppDbConnector->pDbConnector = pThisDbConnector;

	return 0;
}
int DB_main(SAppDbConnector *pAppDbConnector){
	int hTableConnection;
	string TableStr;
	int i, NumRows, it_NumRows;

	GenericDbConnector *pThisDbConnector = pAppDbConnector->pDbConnector;
	//for(i=0; i < pAppDbConnector->ComponentConfig.NumOfInTables; i++){
	for(i=0; i < 1; i++){
		TableStr = pAppDbConnector->ComponentConfig.InTablesNames[i];
		hTableConnection = pAppDbConnector->pDbConnector->CreateTable(TableStr, pAppDbConnector->ComponentConfig.ComponentNames[i]);
		pAppDbConnector->pDbConnector->LoadTableFullyFromDb(hTableConnection);
	}
#if 1
	//for (i = 0; i < pAppDbConnector->ComponentConfig.NumOfOutTables; i++) {
	for (i = 0; i < 1; i++) {
		TableStr = pAppDbConnector->ComponentConfig.OutTablesNames[i];
		hTableConnection = pThisDbConnector->CreateTable(TableStr, pAppDbConnector->ComponentConfig.ComponentNames[i]);
		//pThisDbConnector->PutARowToThisOutTable(hTableConnection, 0);
	}
	//pThisDbConnector->GetARowFromThisInTable(1, 1); //This line crashes program.
#endif
	return 0;
}

#if 0
int DB_main(void)
{
	GenericDbConnector Conn_01;
	Conn_01.SetDbName("test.db\0");
	Conn_01.OpenConnection();

	Conn_01.CreateTable("CARS\0", "Pop_BlinkerManager");
	int NumRows_Conn_01 = Conn_01.GetNumOfRowsOfThisInTable(0);
	cout << "NumRows_Conn_01 CARS =" << NumRows_Conn_01 << endl;

	Conn_01.CreateTable("BUSES\0", "Pop_BlinkerManager");
	NumRows_Conn_01 = Conn_01.GetNumOfRowsOfThisInTable(1);
	cout << "NumRows_Conn_01 BUSES =" << NumRows_Conn_01 << endl;

	return 0;
}
#endif

uint16 computeCrc16(const void *data, uint16 byteNumber){
   /* data : address of the table 
	* byteNumber : number of bytes to use as input 
	*/
   uint16 i, j;
   uint16 byte, crc, mask;
   uint8* data8 = (uint8*) data;

   i = 0x00u;
   crc = 0x0000u;
   while (i < byteNumber) {
      byte = data8[i];               /* Get next byte. */
      crc = crc ^ byte;
      for (j = 0x00u; j < 8u; j++) {
         //mask = (uint16)(- ( (sint32)crc & (sint32)1u ));
		  mask = (uint16) ( (0x0u == (crc & 0x1u)) ? 0x0u : 0xffffu);
		 printf("crc = %x, mask = %x\n", crc, mask);
         crc = ((uint16)(crc >> 1u)) ^ (0xA001u & mask); /* CRC-16-ANSI */
      }
      i = i + 1u;
   }
   return crc;
}

static void App_Init()
{
	int i;

	//for (i = 0; i < SCHED_TABLE_ELE ); i++){
	for (i = 0; i < 1; i++){
		DB_main_init(&SchedTable[i].AppDbConnector);
	}
	//Rte_Init.
	//Modules Init.
}


int main()
{

#ifdef AUTO_RUN_COMPLETELY
	static int RunTill = MAX_RUN_TIME; //In MS.
#else
	static int RunTill = 0; //In MS
#endif
	//uint16 thisCRC = computeCrc16(&SchedTable, sizeof(SchedTable));
	App_Init();
	ConnectToDb();
#if 1 //for db rw.
	RunTill = Perform_rw();
	if(RunTill < 0) {
		printf("Invalid RunTill value, exiting..\n");
		return -1;
	}
	
	do{
		if(CounterMS < RunTill){
			FireTimer();
		}
		else{
			//CounterMS is greater.
			printf("\nNow, time over in terget : %d milliseconds\n", CounterMS);
			RunTill = CounterMS + Perform_rw();
			if(RunTill < 0) {
				printf("Invalid RunTill value, exiting..\n");
				return -1;
			}
		}
	}while(CounterMS < MAX_RUN_TIME); //so many ms are over, and task at MAX_RUN_TIME is called and completed.
#endif //for db rw.
   return 0;
}

/* Exported If*/
int Get_OsTick(void)
{
	return CounterMS;
}
#endif
