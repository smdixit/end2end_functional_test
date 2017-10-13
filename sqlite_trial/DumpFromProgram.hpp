
#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include "sqlite3.h"

using namespace std;

class DumpFromProgram {
public:
	virtual int DepopToDb(sqlite3_stmt *res) = 0;
	virtual int Depop_FormQuery(string *psql) = 0;
	virtual void CollectFromCmp(int RowId) = 0;
};



