using namespace std;
#include "Blink_Manager_Main_Cfg.h"

#include "Scheduler.hpp"
#include "tablegui_if.h"

/* CFG */
#define RUNNABLE_10MS_START_DELAY	0
#define RUNNABLE_10MS_PERIODICITY	10

#define RUNNABLE_20MS_START_DELAY	0
#define RUNNABLE_20MS_PERIODICITY	20

/* not CFG*/
#define RUNNABLE_10MS_NEXT_SCHED	( (RUNNABLE_10MS_START_DELAY == 0) ? RUNNABLE_10MS_PERIODICITY : RUNNABLE_10MS_START_DELAY)
#define RUNNABLE_20MS_NEXT_SCHED	( (RUNNABLE_20MS_START_DELAY == 0) ? RUNNABLE_20MS_PERIODICITY : RUNNABLE_20MS_START_DELAY)

#define MAX_RUN_TIME 50

typedef struct TComponentConfig {
    int NumOfInTables;
    int NumOfOutTables; //For now, == NumOfInTables.
    const char **InTablesNames;
    const char **OutTablesNames;
    const char **ComponentNames;
} SComponentConfig;

typedef struct TAppDbConnector {
    const char *DbName; //DB name and the class is the same.
    GenericDbConnector *pDbConnector;
    SComponentConfig ComponentConfig;
} SAppDbConnector;

typedef struct TSchedTable {
    void (*pRunnable)(int CounterMS);
    int StartDelay;
    int Periodicity;
    int NextSched;
    SAppDbConnector AppDbConnector;
} SSchedTable;

static int CounterMS;


int DB_main(SAppDbConnector *pAppDbConnector);
int DB_main_init(SAppDbConnector *pAppDbConnector);
void SchedActions(SSchedTable *pSchedTable, int CounterMS);


void Runnable_10ms(int CounterMS);
void Runnable_20ms(int CounterMS);
#define SCHED_TABLE_ELE ( sizeof(SchedTable) / sizeof(  [0])
int ConnectToDb(void);
void App_Init();
void SchedulerRun(int CounterMS);

#define DBNAME "C:\\apps\\RTC602\\13.10x\\harness\\test.db\0"
#define SCHED_TABLE_10		\
  {     \
    {&Runnable_10ms, RUNNABLE_10MS_START_DELAY, RUNNABLE_10MS_PERIODICITY, RUNNABLE_10MS_NEXT_SCHED, {DBNAME, NULL, {CMP_BLINK_MGR_CFG} }	},	\
    {&Runnable_20ms, RUNNABLE_20MS_START_DELAY, RUNNABLE_20MS_PERIODICITY, RUNNABLE_20MS_NEXT_SCHED, {DBNAME, NULL, {CMP_BLINK_MGR_CFG} }	}   \
  }
SSchedTable SchedTable[2] = SCHED_TABLE_10;
#define NUM_ELEMENTS_SCHEDTABLE ( sizeof(SchedTable) / sizeof(SchedTable[0]) )

void Runnable_10ms(int CounterMS)
{
    int i;

    for (i = 0; i < SchedTable[0].AppDbConnector.ComponentConfig.NumOfInTables; i++) {
        //Assume each component has only 1 InTable for now.
        //Later this may be split into InTable for Init, periodic task, Callbacks etc.
        SchedTable[i].AppDbConnector.pDbConnector->LoadThisInstance ((CounterMS/10), SchedTable[0].AppDbConnector.ComponentConfig.InTablesNames[i]);
    }

    Runnable_Main_BlinkManager();

    for (i = 0; i < SchedTable[0].AppDbConnector.ComponentConfig.NumOfOutTables; i++) {
        //Assume each component has only 1 InTable for now.
        //Later this may be split into InTable for Init, periodic task, Callbacks etc.
        SchedTable[i].AppDbConnector.pDbConnector->DumpThisInstance( (CounterMS/10), SchedTable[0].AppDbConnector.ComponentConfig.OutTablesNames[i]);
    }
    printf("Runnable_10ms\n");
   // printSmt();
}

void Runnable_20ms(int CounterMS)
{
    printf("Runnable_20ms\n");
}

void SchedActions(SSchedTable *pSchedTable, int CounterMS)
{
    pSchedTable->NextSched = CounterMS + pSchedTable->Periodicity;
    pSchedTable->pRunnable(CounterMS);
}

void SchedulerRun(int CounterMS)
{
    int i;
    for(i = 0; i < (sizeof(SchedTable) / sizeof(SchedTable[0]) ); i++)
    {
        if(CounterMS > SchedTable[i].StartDelay)
        {
            if(CounterMS == SchedTable[i].NextSched)
            {
                SchedActions(&SchedTable[i], CounterMS);
            }
        }
        else{
            //Less or equal
            if(CounterMS == SchedTable[i].StartDelay)
            {
                SchedActions(&SchedTable[i], CounterMS);
            }
            else{
                //Start delay not yet reached, do nothing for this task.
            }
        }
    }
}

int ConnectToDb(void)
{
    (void)DB_main(&SchedTable[0].AppDbConnector);
    return(1);
}

int DB_main_init(SAppDbConnector *pAppDbConnector)
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
    int i;

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
        pThisDbConnector->ClearThisTable(TableStr);
        //pThisDbConnector->PutARowToThisOutTable(hTableConnection, 0);
    }
    //pThisDbConnector->GetARowFromThisInTable(1, 1); //This line crashes program.
#endif
    return 0;
}

void App_Init()
{
    int i;

    //for (i = 0; i < SCHED_TABLE_ELE ); i++){
    for (i = 0; i < 1; i++){
        DB_main_init(&SchedTable[i].AppDbConnector);
    }
    //Rte_Init.
    //Modules Init.
}

void Scheduler(void)
{
  App_Init();
  //qInfo() << "App_Init success";
  ConnectToDb();
  //qInfo() << "ConnectToDb success";
}

void SomeSignal(void)
{
    printf("%s\n", __FUNCTION__);
}

void thisFeeder(struct DataFromGui_t DataFromGui,  StaticTables_t mStaticTables)
{
    int i, j;
    string TableStr;
    string  inTable = mStaticTables.tableName;
    Tables *pTable = NULL;

    for (i = 0; i < NUM_ELEMENTS_SCHEDTABLE; i++) {
        for (j = 0; i < SchedTable[i].AppDbConnector.ComponentConfig.NumOfInTables; j++) {
            TableStr = SchedTable[i].AppDbConnector.ComponentConfig.InTablesNames[j];
            if(0 == TableStr.compare(inTable) ) {
                pTable = SchedTable[i].AppDbConnector.pDbConnector->tableInstanceByName(inTable);
                break;
            }
        }
    }
    if(NULL != pTable)
    {
        pTable->pPopulateItems->FeedToCmpFromGui(DataFromGui, mStaticTables.colName);
    }else{
        printf("Error\n");
    }
}

