
// AgendaPH.h : main header file for the PROJECT_NAME application
//

#pragma once
//
#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <string>
#include "Phonebook/Phonebook.h"
#include "SpeechEngine/SpeechEngine.h"

using namespace std;
// CAgenda:
// See AgendaPH.cpp for the implementation of this class
//



class CAgenda : public CWinApp
{
private:
	string filePath, folderPath;
	
public:
	CAgenda();
	int PbNumber;
// Overrides
public:
	virtual BOOL InitInstance();
	Database *db;
	SpeechEngine sp;
	HACCEL m_hAccelTable;
// Implementation
	string getFilePath() { return filePath; }
	string getFolderPath() { return folderPath; }
	bool CreateDatabase();
	bool InitiateProgram();
	bool LoadSettings();
	void Notify();
	DECLARE_MESSAGE_MAP()
	virtual BOOL ProcessMessageFilter(int code, LPMSG lpMsg);
};

extern CAgenda PbApp;