//#ifndef POPULATE_DISPLAYS_POWER_H
//#define POPULATE_DISPLAYS_POWER_H

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include "BlinkManager_Mock.h"
#include "tablegui_if.h"

using namespace std;

class Pop_BlinkerManager : public PopulateItems{
public:
	sBlinkerManager_Feeder Feeder;
    sBlinkerManager_Feeder FedFromGui;
	list<sBlinkerManager_Feeder> Feeder_list;
	friend void BlinkerManager_LoadFeeder(sBlinkerManager_Feeder pBlinkerManager_Feeder);

    string requestedInputMethod;

	virtual int PopulateFromDb(sqlite3_stmt *res){
		if(res == NULL)
			cout << "res error" << endl;
		//Buses[iter].Id = (int)strtol( (const char *)sqlite3_column_text(res, 0), NULL, 10);
		const unsigned char * temp = sqlite3_column_text(res, 0);
		Feeder.IgnState = (uint8)strtol( (const char *)sqlite3_column_text(res, 1), NULL, 10);
		Feeder.DoorLockFromOutside = (uint8)strtol( (const char *)sqlite3_column_text(res, 2), NULL, 10);
		
		Feeder_list.push_back(Feeder);

		BlinkerManager_LoadFeeder(Feeder);
		return 0;
	}
	virtual int FeedToCmp(int Iter) {
		auto Iter_Feeder_list = Feeder_list.begin();
		advance(Iter_Feeder_list, Iter - 1);
        sBlinkerManager_Feeder Feeder = *Iter_Feeder_list;
        if( 0 == requestedInputMethod.compare("GUI"))
        {
            Feeder.IgnState = FedFromGui.IgnState;
            cout << "!!!!!!!!!!!!!!!!!!!!!" << endl;
           printf("FedFromGui.IgnState %d\n", FedFromGui.IgnState);
        }
		BlinkerManager_LoadFeeder(Feeder);
		return 0;
	}
    virtual int FeedToCmpFromGui(DataFromGui_t dataFromGui, string colName)
    {
        if(0 == colName.compare("IgnState") )
        {
            FedFromGui.IgnState = dataFromGui.intData;
            requestedInputMethod = dataFromGui.requestedInputMethod;
        }
        else if(0 == colName.compare("DoorLockFromOutside") )
        {
            FedFromGui.DoorLockFromOutside = dataFromGui.intData;
        }
        else{
            printf("%s unknown colName %s\n", "Pop_BlinkerManager", colName );
        }
        return 0;
    }

    Pop_BlinkerManager()
	{

	}
    ~Pop_BlinkerManager()
	{

	}
};
//#endif
