// PbManager.cpp : implementation file
//

#include "stdafx.h"
#include "AgendaPH.h"
#include "PbManager.h"
#include "afxdialogex.h"


// PbManager dialog

IMPLEMENT_DYNAMIC(PbManager, CDialogEx)

PbManager::PbManager(CWnd* pParent /*=NULL*/)
	: CDialogEx(PbManager::IDD, pParent)
{
	OpenedPb = new char[1024];
	detailsDlg = new PbDetails();
	Hide = 1;
}

PbManager::~PbManager()
{
	delete[] OpenedPb;
}

void PbManager::InitCbList()
{
	int Pb = 0;
	cbList.ResetContent();
	vector<vector<string>> retVal;
	try
	{
		if(PbApp.db->openDB())
		{
			retVal = PbApp.db->query("SELECT COUNT(*) FROM Phonebooks;");
			
		}
		else MessageBox("Can't Open Phone Book Database", "ERROR", 0); 
	}
	catch(string error)
	{
		cout<<"\nError:"<<error<<endl;
	}
	cout<<"\ncount returned:"<<retVal.at(0).at(0)<<endl;
	Pb = atoi(retVal.at(0).at(0).c_str());
	//Pb = detailsDlg->ini.GetIntValue("Settings", "PbNo");
	cout<<"\nNumber of phonebooks="<<Pb<<endl;
	PbApp.PbNumber = Pb;
	if(Pb)
	{
		try
		{
			retVal = PbApp.db->query("SELECT PbName FROM Phonebooks;");
			PbApp.db->close();
		}
		catch(string error)
		{
			MessageBox(error.c_str(), "ERROR initCbList()", 0);
			cout<<"\ncaught error in initCbList:"<<error<<endl;
		}
		/*string tmp;
		char ch[256];
		int pbLoaded = 0;
		detailsDlg->chPb->clear();*/
		vector<vector<string>>::iterator it;
		it = retVal.begin();
		for(int i = 0; i < Pb; i++, it++)
		{
			
			//_itoa_s(i, ch, 10);
			//tmp = detailsDlg->ini.GetStringValue(ch, "Phone Book Name", "error");
			cbList.AddString(it->at(0).c_str());
			detailsDlg->chPb[i] = it->at(0).c_str();
			cout<<"\npb "<<i<<"="<<it->at(0)<<endl;
			//pbLoaded++;
			/*if(pbLoaded == Pb)
				break;*/
		}
	}
}

void PbManager::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, bAddPb);
	DDX_Control(pDX, IDC_BUTTON2, bOpenPb);
	//DDX_Control(pDX, IDC_BUTTON3, bClosePb);
	DDX_Control(pDX, IDC_BUTTON4, bDeletePb);
	DDX_Control(pDX, IDC_COMBO1, cbList);
	DDX_Control(pDX, IDC_BUTTON5, bDetails);
}


BEGIN_MESSAGE_MAP(PbManager, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &PbManager::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON2, &PbManager::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &PbManager::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &PbManager::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &PbManager::OnBnClickedButton5)
END_MESSAGE_MAP()


// PbManager message handlers


void PbManager::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
}


void PbManager::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	int sel = 0;
	sel = cbList.GetCurSel();
	if(sel == CB_ERR) {
		MessageBox("Please choose again", "Error", MB_OK);
	}
	else
	{	
	//	OpenedPb = NULL;
		cbList.GetLBText(sel, OpenedPb);
		this->ShowWindow(0);
		CWnd *cwnd = this->GetOwner();
		cwnd->SendMessage(SHOW_WINDOW, 0, 0);
		Hide = 0;
	}
}


void PbManager::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	detailsDlg->mode = ADD_PHONEBOOK;
	if (detailsDlg->DoModal() == IDOK)
		InitCbList();
}


void PbManager::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	CDialogEx::OnOK();
}


BOOL PbManager::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if((pMsg->message == WM_KEYDOWN) && 
    (pMsg->wParam == VK_RETURN) || (pMsg->wParam == VK_ESCAPE))
	{
	   // Enter key was hit -> do whatever you want
	   return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void PbManager::OnBnClickedButton4() //Delete Phone Book
{
	// TODO: Add your control notification handler code here
	int sel = cbList.GetCurSel();
	if(sel == CB_ERR) {
			MessageBox("Please choose again", "Error", MB_OK);
		}
	else
	{
		char s[100];
		cbList.GetLBText(sel, s);
		if(PbApp.db->openDB())
		{
			if(MessageBox("Are you sure you want to delete this phone book?", "", MB_ICONQUESTION | MB_YESNO | MB_DEFBUTTON2 | MB_APPLMODAL) == IDYES)
			{	
				char Query[256];
				try
				{
					sprintf(Query, "DELETE FROM Phonebooks WHERE PbName='%s';", s);
					PbApp.db->query(Query);
				}
				catch(string error)
				{
					char err[1024];
					strcpy(err, error.c_str());
					PbApp.sp.SpeakText(err);
				}
				InitCbList();
				string dbPath = PbApp.getFolderPath();
				dbPath += "\\";
				dbPath += s;
				dbPath += ".txt";
				if(!DeleteFile(dbPath.c_str()))
				{
					MessageBox("Can't delete database file", PbApp.sp.IntToChar(GetLastError()), 0);
					PbApp.sp.SpeakText(PbApp.sp.GetStringError(GetLastError()));
				}
				else
					MessageBox("Phone Book Deleted",0,0);
				PbApp.db->close();
			}
		}
		else PbApp.sp.SpeakText("Can't open database!");
	}
}


void PbManager::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	int sel = cbList.GetCurSel();
	if(sel == CB_ERR) {
			MessageBox("Please choose again", "Error", MB_OK);
		}
	else
	{
		char pb[256], section[20];
		detailsDlg->OpenedPb = cbList.GetLBText(sel, pb);
		for(int i = 0; i < 100; i++)
		{
			_itoa_s(i, section, 10);
			string str = detailsDlg->ini.GetStringValue(section, "Phone Book Name", "");
			if(_stricmp(pb, str.c_str()) == 0)
			{
				_itoa_s(i, pb, 10);
				detailsDlg->PbSection = pb;
			break;
			}
		}
		detailsDlg->mode = VIEW_PHONEBOOK;
		detailsDlg->DoModal();
	}
}


BOOL PbManager::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	HICON hDetails = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON10));
	HICON hOpen = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON11));
	HICON hDelete = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON8));
	HICON hCreate = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON2));

	bDetails.SetIcon(hDetails);
	bOpenPb.SetIcon(hOpen);
	bAddPb.SetIcon(hCreate);
	bDeletePb.SetIcon(hDelete);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
