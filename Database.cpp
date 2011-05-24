#include "Database.h"

Database::Database(string DbName) : mDbName(DbName)
{}

int Database::openDB()
{	
	if(sqlite3_open(mDbName.c_str(), &database) == SQLITE_OK)
		return 1;
	else return 0;
}

vector<vector<string>> Database::query(string Query)
{
	sqlite3_stmt *statement;
	vector<vector<string>> results;

	if(sqlite3_prepare_v2(database, Query.c_str(), -1, &statement, 0) == SQLITE_OK)
	{
		int cols = sqlite3_column_count(statement);
		int result = 0;
		while(true)
		{
			result = sqlite3_step(statement);
			
			if(result == SQLITE_ROW)
			{
				vector<string> row;
				for(int col = 0; col < cols; col++)
				{
					row.push_back((char*)sqlite3_column_text(statement, col));
				}
				results.push_back(row);
			}
			else
			{
				break;   
			}
		}
	   
		sqlite3_finalize(statement);
	}
	string error = sqlite3_errmsg(database);
	Query += ":";
	Query += error;
	if(error.compare("not an error"))
		throw(Query);
	else return results;
}

string Database::getDbName()
{
	return mDbName;
}

void Database::close()
{
	sqlite3_close(database);
}