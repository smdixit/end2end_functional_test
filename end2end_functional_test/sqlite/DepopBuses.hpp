//#indef DEPOP_BUSES_COPY_H
//#define DEPOP_BUSES_COPY_H

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;


typedef struct tBuses_copy{
	int Id;
	char Type[50];
	int cost;
}StBuses_copy;

class DepopBuses : public DumpFromProgram {
public:
	StBuses_copy Buses[10];
	list<StBuses_copy> Buses_list;
	int iter;
	string schema;

    DepopBuses()
	{
		iter = 0;
		schema = "(Id,Type,Cost) ";
	}
    ~DepopBuses()
	{

	}
	virtual int DepopToDb(sqlite3_stmt *res){
		if(res == NULL)
			cout << "res error" << endl;

		sqlite3_bind_int(res, 1, 2);
		sqlite3_bind_text(res, 2, "Volvo", -1, SQLITE_STATIC);
		sqlite3_bind_int(res, 3, 15000);
		return 0;
	}
	virtual int Depop_FormQuery(string *psql) {
		psql->append(schema);
		psql->append("values(?1, ?2, ?3);");
		return 0;
	}
	virtual void CollectFromCmp(int RowId) {

	}
};
//#endif
