#include "Database.h"


Database::Database(string DbName) : mDbName(DbName)
{}

int Database::openDB()
{	
	if(sqlite3_open(mDbName.c_str(), &database) == SQLITE_OK)
		return 1;
	else return 0;
}

string Database::GetValueById(int ID, string TableName, string Column)
{
	string Query;
	Query = "SELECT ";
	Query += Column;
	Query += " FROM ";
	Query += TableName;
	char id[10];
	_itoa_s(ID, id, 10);
	Query += " WHERE ID='";
	Query += id;
	Query += "';";
	cout<<"\nQuery = "<< Query<<endl;
	vector<vector<string>> retVal;
	try
	{
		retVal = query(Query);
	}
	catch(string error)
	{
		throw(error);
	}
	Query = retVal[0][0];
	return Query;
}

string Database::GetValue(string TableName, string Column, string Options)
{
	char  Query[500];
	sprintf(Query, "SELECT %s FROM %s %s;", Column.c_str(), TableName.c_str(), Options.c_str());
	cout<<"\nselect photo query="<<Query<<endl;
	vector<vector<string>> retVal;
	try
	{
		retVal = query(Query);
	}
	catch(string error)
	{
		throw(error);
	}
	strcpy(Query ,retVal[0][0].c_str());
	return Query;
}

void Database::UpdateValueById(int ID, string TableName, string Column, string Value)
{
	char Query[256];
	char id[10];
	_itoa_s(ID, id, 10);
	sprintf(Query, "Update %s SET %s='%s' WHERE ID=%s;", TableName.c_str(), Column.c_str(), Value.c_str(), id);
	cout<<"\n\nQuery = "<< Query << endl;
	try
	{
		query(Query);
	}
	catch(string error)
	{
		throw(error);
	}
}

void Database::InsertValues(map<string,string> phb, string TableName)
{
	string Query;
	string columns, values;
	//sprintf(Query, "INSERT INTO %s (%s) VALUES (%s);");
	map<string, string>::iterator it;
	columns = values = "(";
	for (it = phb.begin(); it != phb.end(); it++)
	{
		if(it->first.size() && it->second.size())
		{
			columns += it->first;
			columns += ",";
			values += it->second;
			values += ",";
		}
	}
	columns.resize(columns.size() - 1);
	columns += ")";
	values.resize(values.size() - 1);
	values += ")";
	Query = "INSERT INTO ";
	Query += TableName;
	Query += " ";
	Query += columns;
	Query += " VALUES ";
	Query += values;
	Query += ";";
	try
	{
		query(Query);
	}
	catch(string error)
	{
		throw(error);
	}
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
					char *x = (char*)sqlite3_column_text(statement, col);
					if(x)
						row.push_back(x);
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
	//else
	//	throw(sqlite3_errmsg(database));
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