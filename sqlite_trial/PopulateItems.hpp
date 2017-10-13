#ifndef POPULATE_ITEMS_H
#define POPULATE_ITEMS_H

#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include "sqlite3.h"
#include "tablegui_if.h"

using namespace std;

class PopulateItems{
public:
	virtual int PopulateFromDb(sqlite3_stmt *res) = 0;
	virtual int FeedToCmp(int Iter) = 0;
    virtual int FeedToCmpFromGui(DataFromGui_t dataFromGui, string colName) = 0;
};

#endif
