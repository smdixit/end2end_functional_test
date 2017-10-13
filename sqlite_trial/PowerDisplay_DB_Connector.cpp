#define POWER_DISPLAY_DB_CONNECTOR_CPP
//#include "Generic_DB_Connector.hpp"
#include "sqlite_tryouts_02.h"


int DB_main(void)
{
	GenericDbConnector Conn_01;
	PopulateDisplaysPower pPop;
	Conn_01.SetDbName("test.db\0");
	Conn_01.OpenConnection();
	Conn_01.SetCurrentInTableName("CARS\0");
	int NumRows_Conn_01 = Conn_01.GetNumOfRowsOfInTable();
	cout << "NumRows_Conn_01 CARS =" << NumRows_Conn_01 << endl;
	Conn_01.SetPopulateItem(&pPop);
	(void) Conn_01.GetARowFromInTable(2);

	return 0;
}
