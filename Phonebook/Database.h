#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3/sqlite3.h>
#include <vector>
#include <iostream>
#include <string>
#include <map>

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
	string GetValueById(int ID, string TableName, string Column);
	string GetValue(string TableName, string Column, string Options);
	void UpdateValueById(int ID, string TableName, string Column, string Value);
	void UpdateValue(string TableName, string Column, string Options);
	void InsertValues(map<string,string> phb, string TableName);
	vector<vector<string>> query(string Query);
	void close();

};
#endif