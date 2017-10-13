#pragma once

//#indef DEPOP_BUSES_COPY_H
//#define DEPOP_BUSES_COPY_H

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include "Rte.h"
#include "BlinkManager_Mock.h"

using namespace std;

class Depop_BlinkManager : public DumpFromProgram {
public:
	sBlinkerManager_Suction BlinkerManager_Suction;
	int iter;
	string schema;

    Depop_BlinkManager()
	{
		iter = 0;
		schema = "(Id,BlinkSwitch_Pos) ";
	}
    ~Depop_BlinkManager()
	{

	}
	virtual int DepopToDb(sqlite3_stmt *res) {
		if (res == NULL)
			cout << "res error" << endl;

		sqlite3_bind_int(res, 1, iter);
		sqlite3_bind_int(res, 2, BlinkerManager_Suction.BlinkSwitch_Pos);
		return 0;
	}
	virtual int Depop_FormQuery(string *psql) {
		psql->append(schema);
		psql->append("values(?1, ?2);");
		return 0;
	}
	virtual void CollectFromCmp(int RowId) {
		BlinkerManager_Suction = BlinkerManager_DumpCollector();
		iter = RowId;
	}
};
//#endif

