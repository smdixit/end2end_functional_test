#ifndef TABLEGUI_IF_H
#define TABLEGUI_IF_H
#include <string>
using namespace std;

struct DataFromGui_t{
    int intData;
    string strData;
    string requestedInputMethod;
};

#if 0
void Update_KL15_Status(struct DataFromGui_t dataFromGui, int Id);
void Update_DoorLockFromOutside_Status(struct DataFromGui_t dataFromGui, int Id);
#endif

struct StaticTables_t{
    int Id;
    string tableName;
    string colName;    
};

void thisFeeder(struct DataFromGui_t dataFromGui, StaticTables_t mStaticTables);


#endif // TABLEGUI_IF_H
