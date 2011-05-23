
#include "IniFile.h"


IniFile::IniFile(string FilePath, string Section)
	:filepath(FilePath)
{
	char dir[1000];
	ifstream tmp(filepath.c_str());
	char *filename[100];
	filename[0] = new char[100];
	if(!tmp)
	{
		ofstream ini(filepath.c_str(),ios::app);
		if(ini.fail())
		{
			MessageBox(0,"Error creating ini file.You should try \r\n another file path","ERROR",0);
		}
		ini.close();
		GetFullPathName(filepath.c_str(), 1000, dir, filename);
		filepath = dir;
		WritePrivateProfileSection(Section.c_str(),"",filepath.c_str());
		IniFile::WriteValue(Section, "PbNo", "0");
	}
	else	
	{
		GetFullPathName(filepath.c_str(), 1000, dir, filename);
		filepath = dir;
		tmp.close();
	}
}

int IniFile::GetIntValue(string Section,string Key)
{
	return (int)GetPrivateProfileInt(Section.c_str(), Key.c_str(),-1, filepath.c_str());
}

int IniFile::DeleteSection(string Section) 
{
	cout<<"deleting:"<<Section<<endl;
   if(WritePrivateProfileSection(Section.c_str(), NULL, filepath.c_str()))
		return 0;
   else return GetLastError();
}

string IniFile::GetStringValue(string Section,string Key,string DefaultValue)
{
	char b[500];
	GetPrivateProfileString(Section.c_str(), Key.c_str(), DefaultValue.c_str(), b, 500, filepath.c_str());
	string buffer(b);
	return buffer;
}

void IniFile::WriteValue(string Section,string Key,string Value)
{
	WritePrivateProfileString(Section.c_str(),Key.c_str(),Value.c_str(),filepath.c_str());
}

void IniFile::CreateSection(string Section)
{
	WritePrivateProfileSection(Section.c_str(),"",filepath.c_str());
}