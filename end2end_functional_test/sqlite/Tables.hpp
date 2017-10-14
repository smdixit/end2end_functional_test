using namespace std;

class Tables : public ComponentFactory{
private:
		sqlite3 *db;
		char *err_msg;
		sqlite3_stmt *res_copy;
				
		char OutTableName[100];	
		char InTableName[100];

public:
		sqlite3_stmt *res;
		PopulateItems* pPopulateItems;
		DumpFromProgram *pDumpFromProgram;
		string StrInTableName; //If many tables are to tested in sequence, this needs modification.

		int GetNumOfRowsOfInTable(int Handle) {
			/*
			 * Need to create SELECT Count(*) FROM <<tblName>>
             */
            Handle = Handle;
			int count = 0;
			char *sql = (char *)malloc(100 * sizeof(char) );
			strcpy(sql, "SELECT Count(*) FROM ");
			strncat(sql, InTableName, strlen(InTableName)); //Strip '\0', we are forming a query.
			strcat(sql, ";");
			int rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);    
			if (rc != SQLITE_OK ) {        
				fprintf(stderr, "SQL error: %s\n", err_msg);        
				sqlite3_free(err_msg);    
				sqlite3_close(db);
				sqlite3_finalize(res);
				free(sql);
				return -1;
			}
			int step = sqlite3_step(res);
            res_copy = (sqlite3_stmt *) malloc(200);
			if ( (step == SQLITE_ROW) || (step == SQLITE_DONE) ) { 
				count = strtol( (const char *)sqlite3_column_text(res, 0), NULL, 10);
			}
			sqlite3_finalize(res);
			free(sql);
			free(res_copy);
			return count;
		}

		int GetARowFromInTable(int RowId)
		{
			char *sql = (char *)malloc(1000 * sizeof(char) );
			strcpy(sql, "SELECT * FROM ");
			strncat(sql, InTableName, strlen(InTableName) ); //Strip '\0', we are forming a query.
			strcat(sql, " WHERE Id = ?"); //Column Name Id is the same in all Tables. Note the WHTITESPACE before WHERE.
			strcat(sql, ";");
			int rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);    
			if (rc != SQLITE_OK ) {        
				fprintf(stderr, "SQL error: %s\n", err_msg);        
				sqlite3_free(err_msg);    
				sqlite3_close(db);
				sqlite3_finalize(res);
				free(sql);
				return -1;
			}
			sqlite3_bind_int(res, 1, RowId);
			int step = sqlite3_step(res);
			if ( (step == SQLITE_ROW) || (step == SQLITE_DONE) ) { 
				pPopulateItems->PopulateFromDb(res);
			}
			else{
				fprintf(stderr, "Failed to execute statement %d", __LINE__);
				return -1;
			}
			sqlite3_finalize(res);
			free(sql);
			return 0;
		}

		int PutARowToTable(int RowId) //Now, RowId is not used.
		{
			//char *sql = (char *)malloc(100 * sizeof(char) );
			string sql;
			char *csql = (char *)malloc(1000 * sizeof(char));
            sql.append("INSERT INTO ");
            sql.append(InTableName, 0, strlen(InTableName) ); //Strip '\0', we are forming a query.
			sql.append(" ");
			pDumpFromProgram->CollectFromCmp(RowId);
			pDumpFromProgram->Depop_FormQuery(&sql);
			strcpy(csql, sql.c_str());
			int rc = sqlite3_prepare_v2(db, (const char *)csql, -1, &res, 0);
			if (rc != SQLITE_OK ) {        
				fprintf(stderr, "SQL error: %s\n", err_msg);        
				sqlite3_free(err_msg);    
				sqlite3_close(db);
				sqlite3_finalize(res);
				return -1;
			}
			pDumpFromProgram->DepopToDb(res);
			int step = sqlite3_step(res);
			if ( (step == SQLITE_ROW) || (step == SQLITE_DONE) ) { 
				cout << "execuated query " << sql << "successfully" << endl;
			}
			else{
				fprintf(stderr, "Failed to execute statement %d", __LINE__);
				return -1;
			}
			sqlite3_finalize(res);
			free(csql);
			return 0;
		}

        //Tables::Tables(string pThisTableName, string ComponentName, sqlite3* inComingDb) {
        Tables(string pThisTableName, string ComponentName, sqlite3* inComingDb) {
			int i  = 0;
			StrInTableName = pThisTableName;
			
			if (-1 != StrInTableName.find("In", 0, 2)) {
				pPopulateItems = CreateComponent(ComponentName, pPopulateItems);
			}
			else if (-1 != StrInTableName.find("Out", 0, 3))
				pDumpFromProgram = CreateComponent(ComponentName, pDumpFromProgram);
			else
				cout << "Table name " << StrInTableName << " does not contain In or Out as starting string." << endl;
			for(auto it = StrInTableName.begin(); it != StrInTableName.end(); ++it, i++) {
				InTableName[i] = *it;
			}
			InTableName[i] = '\0';
			db = inComingDb;
			cout << "create Tables constructor" << endl;
		}
		void LoadInstance(int Iter){
			pPopulateItems->FeedToCmp(Iter);
		}

        int ClearTable(void)
        {
            char *sql = (char *)malloc(1000 * sizeof(char) );
            strcpy(sql, "DELETE FROM ");
            strncat(sql, InTableName, strlen(InTableName) ); //Strip '\0', we are forming a query.
            strcat(sql, ";");
            int rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
            if (rc != SQLITE_OK ) {
                fprintf(stderr, "SQL error: %s\n", err_msg);
                sqlite3_free(err_msg);
                sqlite3_close(db);
                sqlite3_finalize(res);
                free(sql);
                return -1;
            }
            int step = sqlite3_step(res);
            if ( (step == SQLITE_ROW) || (step == SQLITE_DONE) ) {
                // Success
            }else{
                cout << __FUNCTION__ << " Failed" << __LINE__ << endl;
            }
            sqlite3_finalize(res);
            free(sql);
        }

		//Default:
       // Tables::Tables(void)
        Tables(void)
		{
			pPopulateItems = NULL;
			cout << "default Tables constructor" << endl;
		}
        ~Tables()
		{
			if(NULL != pPopulateItems){
				delete pPopulateItems;
			//	pPopulateItems = NULL;
			}
			cout << "default Tables destructor" << endl;
		}
};
