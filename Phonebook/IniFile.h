#include "../stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

class IniFile
{
private:
	string filepath, DefSection, mDirectory;
public:
	ofstream ini, Ini2;
	IniFile() {}
	IniFile(string FilePath,string Section);
	void SetFilePath( string path ) { filepath = path; }
	int GetIntValue(string section, string key);
	string GetStringValue(string Section, string Key, string DefaultValue);
	void WriteValue(string Section, string Key, string Value);
	int DeleteSection(string Section);
	void CreateSection(string Section);
	bool FileExists(string file);
	string GetIniPath() { return filepath; }
	~IniFile()
	{
		ini.close();
	}

};
