#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3/sqlite3.h>
#include <vector>
using namespace std;

class Database
{
private:
	sqlite3 *database;
	string mDbName;
public:
	Database(string DbName);
	int openDB();
	string getDbName();
	vector<vector<string>> query(string Query);
	void close();

};
#endif