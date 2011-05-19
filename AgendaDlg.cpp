
// AgendaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AgendaPH.h"
#include "AgendaDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About
CAgendaDlg::~CAgendaDlg()
{

}
void CAgendaDlg::ShowControls(bool show)
{
	TreeCtrl.ShowWindow(show);
	listCtrl.ShowWindow(show);
	bSearch.ShowWindow(show);
	bEdit.ShowWindow(show);
	bDelete.ShowWindow(show);
	bNew.ShowWindow(show);
	bClosePb.ShowWindow(show);
	bDeletePb.ShowWindow(show);
	bSavePb.ShowWindow(show);
	//bDetails.ShowWindow(show);
}

void CAgendaDlg::InitTree()
{
	TVINSERTSTRUCT agenda;
	agenda.hParent = NULL;
	agenda.hInsertAfter = NULL;
	agenda.item.mask = TVIF_TEXT;
	
	agenda.item.pszText = _T("Agenda");
	TreeCtrl.EditLabel(Agenda);
	Agenda = TreeCtrl.InsertItem(&agenda);
	Acq = TreeCtrl.InsertItem(TVIF_TEXT, "Acquaintances", 0, 0, 0, 0, 0, Agenda, NULL);
	Col = TreeCtrl.InsertItem(TVIF_TEXT, "Colleagues", 0, 0, 0, 0, 0, Agenda, NULL);
	Fr = TreeCtrl.InsertItem(TVIF_TEXT, "Friends", 0, 0, 0, 0, 0, Agenda, NULL);
	char ch = 'A', *c;
	c = new char[2];
	//for(int i = 0; i < 26; i++)
	//{
	//	c[0] = ch;
	//	c[1] = '\0';
	//	TreeCtrl.InsertItem(c, acq, TVI_SORT);
	//	TreeCtrl.InsertItem(c, col, TVI_SORT);
	//	TreeCtrl.InsertItem(c, fr, TVI_SORT);
	//	ch++;
	//}
}

void CAgendaDlg::InitList()
{
	LVCOLUMN col;
	col.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	col.fmt = LVCFMT_LEFT;
	col.cx = 120;
	col.pszText = "Nume";
	listCtrl.InsertColumn(0, &col);
	col.pszText = "Prenume";
	listCtrl.InsertColumn(1, &col);
	col.pszText = "Numar Telefon";
	listCtrl.InsertColumn(2, &col);
	col.pszText = "Ocupatie";
	listCtrl.InsertColumn(3, &col);
	col.pszText = "Varsta";
	listCtrl.InsertColumn(4, &col);
	col.pszText = "Adresa";
	listCtrl.InsertColumn(5, &col);
	col.pszText = "Email";
	listCtrl.InsertColumn(6, &col);
	listCtrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
}

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAgendaDlg dialog




CAgendaDlg::CAgendaDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAgendaDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//p = &Phonebook::getInstance();
}

void CAgendaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, TreeCtrl);
	DDX_Control(pDX, IDC_LIST1, listCtrl);
	DDX_Control(pDX, IDC_BUTTON1, bSearch);
	DDX_Control(pDX, IDC_BUTTON4, bEdit);
	DDX_Control(pDX, IDC_BUTTON3, bDelete);
	DDX_Control(pDX, IDC_BUTTON2, bNew);
	DDX_Control(pDX, IDC_BUTTON5, bClosePb);
	DDX_Control(pDX, IDC_BUTTON6, bSavePb);
	DDX_Control(pDX, IDC_BUTTON7, bDeletePb);
	//DDX_Control(pDX, IDC_BUTTON8, bDetails);
}

BEGIN_MESSAGE_MAP(CAgendaDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CAgendaDlg::OnTcnSelchangeTab1)
//	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB2, &CAgendaDlg::OnTcnSelchangeTab2)
ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CAgendaDlg::OnTvnSelchangedTree1)
ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CAgendaDlg::OnLvnItemchangedList1)
ON_BN_CLICKED(IDC_BUTTON1, &CAgendaDlg::OnBnClickedButton1)
ON_MESSAGE(SHOW_WINDOW, &CAgendaDlg::OnShowWnd)
ON_MESSAGE(SEARCH, &CAgendaDlg::Search)
ON_BN_CLICKED(IDC_BUTTON3, &CAgendaDlg::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON5, &CAgendaDlg::OnBnClickedButton5)
ON_BN_CLICKED(IDC_BUTTON8, &CAgendaDlg::OnBnClickedButton8)
ON_BN_CLICKED(IDC_BUTTON2, &CAgendaDlg::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON4, &CAgendaDlg::OnBnClickedButton4)
END_MESSAGE_MAP()

LRESULT CAgendaDlg::Search(UINT wParam, LONG lParam)
{
	LRESULT x = NULL;
	LoadList("this", manager->detailsDlg->p->search(info->attribute, info->text, "all"));
	return x;
}

LRESULT CAgendaDlg::OnShowWnd(UINT wParam, LONG lParam)
{
	LRESULT x = NULL;
	ShowControls(0);
	ShowControls(1);
	manager->Hide = 1;
	OpenPb();
	TVINSERTSTRUCT agenda;
	agenda.hParent = NULL;
	agenda.hInsertAfter = NULL;
	agenda.item.mask = TVIF_TEXT;
	agenda.item.pszText = manager->OpenedPb;
	List list;
	LoadList("all", list);
	//MessageBox(manager->OpenedPb, "pb name", 0);
	TreeCtrl.SetItemText(Agenda, manager->OpenedPb);
	return x;
}
// CAgendaDlg message handlers

BOOL CAgendaDlg::OnInitDialog()
{
	AllocConsole();
	AttachConsole( GetCurrentProcessId() ) ;
	freopen( "CON", "w", stdout ) ;
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	InitTree();
	InitList();
	info = new InfoDlg();
	info->Create(IDD_DIALOG1, this);
	manager = new PbManager();
	manager->Create(IDD_MANAGEDIALOG, this);
	manager->ShowWindow(1);
	manager->InitCbList();
	info->ModifyStyleEx(0, WS_EX_LAYERED, 0);
	info->tSlider.SetRange(0, 255, 0);
	CMenu menu1;
//	menu1.LoadMenuA(IDR_MENU1);
	SetMenu(&menu1);
	HICON hSearch = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	HICON hEdit = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON2));
	HICON hDelete = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON3));
	HICON hNew = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON4));
	HICON hClear = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON5));
	HICON hClose = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON7));
	HICON hSave = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON8));
	HICON hDeletePb = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON9));
	
	DWORD error = GetLastError();
//	char err[100];
	//_itoa_s(error, err, 10);
	//MessageBox(err, err, 0);
	bClosePb.SetIcon(hClose);
	bSavePb.SetIcon(hSave);
	bDeletePb.SetIcon(hDeletePb);
	bSearch.SetIcon(hSearch);
	bEdit.SetIcon(hEdit);
	bDelete.SetIcon(hDelete);
	bNew.SetIcon(hNew);
	info->bClear.SetIcon(hClear);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAgendaDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAgendaDlg::OpenPb()
{
	//int item;
	string file;
	file = manager->OpenedPb;
	file += ".txt";
	Phonebook *p = &manager->detailsDlg->p->getInstance();
	p->setFile(file);
	p->loadPhonebook();

}

void CAgendaDlg::OnPaint()
{

	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAgendaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CAgendaDlg::LoadList(char *type, List list)
{
	int item = 0;
	Phonebook *p = manager->detailsDlg->p;
	if(!_stricmp(type, "this"))
		list = p->getContacts(p->ContactList, type);

	listCtrl.DeleteAllItems();
	for(int i = 0; i < list.getSize(); i++)
	{
		item = listCtrl.InsertItem(i, list[i].getFirstName().c_str());
		listCtrl.SetItemText(item, 1, list[i].getLastName().c_str());
		listCtrl.SetItemText(item, 2, list[i].getPhoneNumber().c_str());
		listCtrl.SetItemText(item, 3, list[i].getOccupation().c_str());
		int age =list[i].getAge();
		char a[3];
		_itoa_s(age, a, 10);
		if(age)
			listCtrl.SetItemText(item, 4, a);
		listCtrl.SetItemText(item, 5, list[i].getHomeAddress().c_str());
		listCtrl.SetItemText(item, 6, list[i].getEmailAddress().c_str());
	}

}

void CAgendaDlg::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	HTREEITEM h = TreeCtrl.GetSelectedItem();
	List list;
	if(h == Agenda)
		LoadList("all", list);
	else if(h == Acq)
		LoadList("acquaintance", list);
	else if(h == Col)
		LoadList("colleague", list);
	else if(h == Fr)
		LoadList("friend", list);
	*pResult = 0;
}


void CAgendaDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}


void CAgendaDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	info->Show = !info->Show;
	info->tSlider.SetPos(230);
	info->SetLayeredWindowAttributes(0xFF00FF,230, LWA_ALPHA);
	info->ShowWindow(info->Show);	
}


void CAgendaDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CAgendaDlg::OnBnClickedMfcbutton1()
{
	// TODO: Add your control notification handler code here
}


int CAgendaDlg::GetSelectedContact()
{
	int sel = listCtrl.GetSelectionMark();
	if(sel == -1)
		return -1;
	char data[1024];
	
	Phonebook *p = manager->detailsDlg->p;
	cout<<"sel="<<sel<<endl;
	string str[10];
	listCtrl.GetItemText(sel, 0, data, 1024); //first name
	str[0] = data;
	cout<<"sel name="<<data<<endl;
	listCtrl.GetItemText(sel, 1, data, 1024); //last name
	str[1] = data;
	listCtrl.GetItemText(sel, 2, data, 1024); //phone number
	str[2] = data;
	listCtrl.GetItemText(sel, 3, data, 1024); //occupation
	str[3] = data;
	listCtrl.GetItemText(sel, 4, data, 1024); //age
	str[4] = data;
	int age;
	age = atoi(data);
	listCtrl.GetItemText(sel, 5, data, 1024); //address
	str[5] = data;
	listCtrl.GetItemText(sel, 6, data, 1024); //email
	str[6] = data;
	listCtrl.GetItemText(sel, 7, data, 1024);
	str[7] = data;
	//cout<<"contact1 fn:"<<str[0]<<endl;
	for(int i = 0; i < p->ContactList.getSize(); i++)
	{
		if( p->ContactList[i].getFirstName().compare(str[0]) == 0 &&
			//p->ContactList[i].getContactType().compare((str[0]) == 0 &&
			p->ContactList[i].getLastName().compare(str[1]) == 0 &&
			//p->ContactList[i].getGender().compare(str[0]) == 0 &&
			//p->ContactList[i].getBirthDate().toString().compare(p->ContactList[sel].getBirthDate().toString()) == 0 &&
			p->ContactList[i].getAge() == age &&
			p->ContactList[i].getPhoneNumber().compare(str[2]) == 0 &&
			p->ContactList[i].getHomeAddress().compare(str[5]) == 0 &&
			p->ContactList[i].getEmailAddress().compare(str[6]) == 0
		)
		return i;
	}
	return -1;
}

void CAgendaDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	Phonebook *p = manager->detailsDlg->p;
	int sel = listCtrl.GetSelectionMark();
	int i = GetSelectedContact();
	p->ContactList.Delete(i);
	listCtrl.DeleteItem(sel);
}


BOOL CAgendaDlg::PreTranslateMessage(MSG* pMsg)
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


void CAgendaDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	manager->detailsDlg->p->savePhonebook(1);
	if(listCtrl.DeleteAllItems() == 0)
		MessageBox("Error deleting items", "ERROR", MB_ICONERROR);
	cout<<"deleted\n";
	ShowControls(0);
	manager->ShowWindow(1);
}


BOOL CAgendaDlg::DestroyWindow()
{
	// TODO: Add your specialized code here and/or call the base class
	/*if( MessageBox("Do you want to save the Phone Book?", "Save", MB_ICONQUESTION | MB_YESNO) == IDYES)
		manager->detailsDlg->p->savePhonebook(1);
	else manager->detailsDlg->p->savePhonebook(0);*/
	return CDialogEx::DestroyWindow();
}


void CAgendaDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	int i = this->GetSelectedContact();
	manager->detailsDlg->contact = i;
	manager->detailsDlg->mode = ADD_CONTACT;
	manager->detailsDlg->DoModal();
}


void CAgendaDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	manager->detailsDlg->mode = ADD_CONTACT;
	manager->detailsDlg->DoModal();
}


void CAgendaDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	
	int sel = GetSelectedContact();
	if(sel == -1)
		MessageBox("First select a contact!", "ERROR", MB_ICONWARNING);
	else
	{
		manager->detailsDlg->mode = EDIT_CONTACT;
		manager->detailsDlg->contact = sel;
		manager->detailsDlg->DoModal();
	}
}
