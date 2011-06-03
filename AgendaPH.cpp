
// AgendaPH.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "AgendaPH.h"
#include "AgendaDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAgenda

BEGIN_MESSAGE_MAP(CAgenda, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CAgenda construction
bool CAgenda::CreateDatabase()
{
	bool success = true;
	
	if(db->openDB())
	{
		success = true;
		db->query("CREATE TABLE IF NOT EXISTS Phonebooks(id INTEGER, PbName VARCHAR(50), OwnerFName VARCHAR(50), OwnerLName VARCHAR(50),  OwnerAddress VARCHAR(100), OwnerPhoneNo VARCHAR(20), OwnerEmail VARCHAR(50), OwnerAge INTEGER, OwnerOccupation VARCHAR(50) , OwnerBirthDate DATE, Directory VARCHAR(500), OwnerPhotoPath VARCHAR(500));");
		db->close();
	}
	else
		success = false;
	return success;
}

bool CAgenda::LoadSettings()
{
	return true;
}

bool CAgenda::InitiateProgram()
{
	char* dir;
	dir = new char[1024];
	db = new Database("PhoneBookDb.db");
	bool bExists = false;
	DWORD size = 1024;
	GetCurrentDirectory(size, dir);
	string sDir = dir;
	folderPath = sDir;
	sDir += "\\";
	filePath = sDir + "AgendaPH.exe";
	sDir += "PhoneBookDb.db";
	cout<<"\n\nCurrent directory:"<<folderPath<<endl;
	cout<<"\nFile Path: "<<filePath<<endl;
	cout<<"\nDatabase path: "<<sDir<<endl;
	HANDLE hDB = CreateFile(sDir.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	long errorCode = GetLastError();
	if( errorCode == (DWORD) ERROR_FILE_NOT_FOUND)
	{
		bExists = false;
		cout<<"\nDatabase doesn't exist, getlasterror="<<errorCode<<endl;
		cout<<"path="<<sDir<<endl;
	}
	else
	{
		cout<<"\nDatabase exists\n";
		CloseHandle(hDB);
		bExists = true;
	}
	if(!bExists)
	{
		CreateDatabase();
		LoadSettings();
	}
	else
	LoadSettings();
	return true;
}
CAgenda::CAgenda() : PbNumber(0), folderPath(""), filePath(""), sp(0, 2, 100)
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
	AllocConsole();
	AttachConsole( GetCurrentProcessId() ) ;
	freopen( "CON", "w", stdout ) ;
	//PbApp.sp.SpeakText("Hi! Welcome to my Phone Book program !!");
	InitiateProgram();
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CAgenda object

CAgenda PbApp;

// CAgenda initialization

BOOL CAgenda::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CAgendaDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
		MessageBox(0, "OK", 0, 0);
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Delete the shell manager created above.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}
	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	m_hAccelTable = LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDD_ACCELERATOR));
	return FALSE;
}



BOOL CAgenda::ProcessMessageFilter(int code, LPMSG lpMsg)
{
  if (code >= 0 && m_pMainWnd && m_hAccelTable)
  {
    if (::TranslateAccelerator(m_pMainWnd->m_hWnd, m_hAccelTable, lpMsg))
      return TRUE;
  }
	return CWinApp::ProcessMessageFilter(code, lpMsg);
}
