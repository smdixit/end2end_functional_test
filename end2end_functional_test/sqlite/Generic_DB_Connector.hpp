#include <string>
using namespace std;

class GenericDbConnector : public Tables
{
	private:
		int DbNameLength;
		char *pDbName;
		int hTableConnection;
		sqlite3 *db;
		char *err_msg;
		vector<Tables*> vTables;
		Tables *tempTables;
		int GetNumOfRowsOfThisInTable(int Handle) {
			int count = vTables.at(Handle)->GetNumOfRowsOfInTable(Handle);
			return count;
		}

		int GetARowFromThisInTable(int Handle, int RowId) {
			int Ret = vTables.at(Handle)->GetARowFromInTable(RowId);
			return Ret;
		}

	public:		
		int SetDbName(const char * pThisDbName) {
			DbNameLength = strlen(pThisDbName);
			if(NULL != pDbName)
			{
				fprintf(stderr, "Database name already set: %s\n", pDbName);
				return -1;
			}
			pDbName = (char *)malloc( 100 * sizeof(char) );
			strcpy(pDbName, pThisDbName);
			return 0;
		}
		int OpenConnection(void) {
			    int rc = sqlite3_open(pDbName, &db);    
				if (rc != SQLITE_OK) {     
					fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
					sqlite3_close(db);        
					return 1;
				}
				return 0;
		}	
		int CreateTable(string TableName, string CmpName){
			if(NULL == db)
				cout << "db null" << endl;
			tempTables = new Tables(TableName, CmpName, db);
			if(NULL != tempTables){
				vTables.push_back(tempTables);
				hTableConnection++;
				return hTableConnection;
			}
			return -1;
		}
#if 0
		int PutARowToThisOutTable(int Handle, int RowId) {
			int Ret = vTables.at(Handle)->PutARowToTable(RowId);
			return Ret;
		}
#endif
		int LoadTableFullyFromDb(int hTable) {
			int NumRows, it_NumRows;
			NumRows = GetNumOfRowsOfThisInTable(hTable);
			for (it_NumRows = 1; it_NumRows <= NumRows; it_NumRows++) {
				GetARowFromThisInTable(hTable, it_NumRows);
			}
			return 0;
		}
		void LoadThisInstance(int Iter, string TableName) {
			auto vTables_it = vTables.begin();
			for (; vTables_it != vTables.end(); ++vTables_it) {
				if(0 == (*vTables_it)->StrInTableName.compare(TableName) ){
					break;
				}
			}
			(*vTables_it)->LoadInstance(Iter);
		}
		void DumpThisInstance(int Iter, string TableName) {
			auto vTables_it = vTables.begin();
			for (; vTables_it != vTables.end(); ++vTables_it) {
				if (0 == (*vTables_it)->StrInTableName.compare(TableName)) {
					break;
				}
			}
			(*vTables_it)->PutARowToTable(Iter);
		}
        void ClearThisTable(string TableName)
        {
            auto vTables_it = vTables.begin();
            for (; vTables_it != vTables.end(); ++vTables_it) {
                if (0 == (*vTables_it)->StrInTableName.compare(TableName)) {
                    break;
                }
            }
            cout << TableName << endl;
            (*vTables_it)->ClearTable();
        }
        Tables * tableInstanceByName(string TableName )
        {
            auto vTables_it = vTables.begin();
            for (; vTables_it != vTables.end(); ++vTables_it) {
                if (0 == (*vTables_it)->StrInTableName.compare(TableName)) {
                    break;
                }
            }
            return  (*vTables_it);
        }

		GenericDbConnector();
		~GenericDbConnector();
};

GenericDbConnector::GenericDbConnector(void)
{		
	cout << "Calling GenericDbConnector constructor " << endl;
	DbNameLength = 0;
	hTableConnection = -1;
	pDbName = NULL;
	db = NULL;
	err_msg = NULL;
	res = NULL;
}

GenericDbConnector::~GenericDbConnector(void)
{		
	Tables tempTable;
	cout << "Calling GenericDbConnector destructor" << endl;
	free(pDbName);
#if 0
	while( vTables.empty()){
		vTables.pop_back(); //vTables is vector objects themselves, not pointers. So, this will destroy all Table instances.
	}
#endif
//	delete pPopulateItems;
}


