// PbDetails.cpp : implementation file
//

#include "stdafx.h"
#include "AgendaPH.h"
#include "PbDetails.h"
#include "afxdialogex.h"


// PbDetails dialog

IMPLEMENT_DYNAMIC(PbDetails, CDialogEx)

PbDetails::PbDetails(CWnd* pParent /*=NULL*/)
	: CDialogEx(PbDetails::IDD, pParent), ini("Settings.ini", "Settings")
{
	CString temp = (LPCTSTR) ini.GetIniPath().c_str(); // Force CString to make a copy
	cout<<"ini path="<<ini.GetIniPath()<<endl;
	char path[2048];
	picLoaded = 0;
	::GetCurrentDirectoryA(sizeof(path) - 1, path);
	photoDir = path;
	cout<<"photo dir="<<photoDir<<endl;
	p = &Phonebook::getInstance();
	mode = ADD_PHONEBOOK;
}

PbDetails::~PbDetails()
{
}

void PbDetails::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON3, bBrowse);
	DDX_Control(pDX, IDC_PICTURE, mPic);
	DDX_Control(pDX, IDC_BUTTON2, bSave);
	DDX_Control(pDX, IDC_BUTTON1, bClear);
	DDX_Control(pDX, IDC_BUTTON4, bCancel);
	DDX_Control(pDX, IDC_EDIT1, eFirstName);
	DDX_Control(pDX, IDC_EDIT2, eLastName);
	DDX_Control(pDX, IDC_EDIT3, ePhoneNumber);
	DDX_Control(pDX, IDC_EDIT4, eOccupation);
	DDX_Control(pDX, IDC_EDIT5, eAge);
	DDX_Control(pDX, IDC_EDIT6, eHomeAddress);
	DDX_Control(pDX, IDC_EDIT7, eEmail);
	DDX_Control(pDX, IDC_EDIT8, eBirthDate);
	DDX_Control(pDX, IDC_EDIT9, ePbName);
	DDX_Control(pDX, IDC_COMBO1, cbType);
}


BEGIN_MESSAGE_MAP(PbDetails, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &PbDetails::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &PbDetails::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &PbDetails::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &PbDetails::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &PbDetails::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &PbDetails::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT9, &PbDetails::OnEnChangeEdit9)
END_MESSAGE_MAP()


// PbDetails message handlers


//browse
void PbDetails::OnBnClickedButton3() 
{
	// TODO: Add your control notification handler code here
	CString name;
	char fileName[1024];
	char Filter[] = { "BMP Files (*.bmp)|*.bmp|PNG Files (*.png)|*.png|JPG Files (*.jpg)|*.jpg||" };
	CFileDialog FileDlg(TRUE, ".txt", NULL, 0, Filter, 0, 0, 1);
	if(FileDlg.DoModal() == IDOK)
	{
		name = FileDlg.GetFileName();
		cout<<"\nsizeof filename="<<sizeof(fileName)<<endl;
		strcpy_s(fileName, name.GetBuffer());
		photoName = name.GetBuffer();
		name = FileDlg.GetFolderPath();
		name.Append("\\");
		name.Append(fileName);
	}
	strcpy_s(fileName,  name.GetBuffer());	
	if(mPic.LoadFromFile(name) == 0)
	{
		MessageBox("Can't open this photo", "ERROR", MB_ICONERROR);
		photoName = "";
	}
	else
		picName = name;
	picLoaded = 1;

} //browse

void PbDetails::EditContact()
{}

void PbDetails::AddPhonebook()
{
	bSave.ShowWindow(1);
	bClear.ShowWindow(1);
	bBrowse.ShowWindow(1);
	bCancel.SetWindowTextA("Cancel");
	eFirstName.SetReadOnly(0);
	eLastName.SetReadOnly(0);
	ePbName.SetReadOnly(0);
	ePhoneNumber.SetReadOnly(0);
	eOccupation.SetReadOnly(0);
	eAge.SetReadOnly(0);
	eHomeAddress.SetReadOnly(0);
	eEmail.SetReadOnly(0);
	eBirthDate.SetReadOnly(0);
	::ShowWindow(PbName, 1);
	::SetWindowTextA(PbName, "Phone Book Name:");
}

void PbDetails::ViewPhonebook()
{
	bSave.ShowWindow(0);
	bClear.ShowWindow(0);
	bBrowse.ShowWindow(0);
	bCancel.SetWindowTextA("Close");
	eFirstName.SetReadOnly(1);
	eLastName.SetReadOnly(1);
	ePbName.SetReadOnly(1);
	ePhoneNumber.SetReadOnly(1);
	eOccupation.SetReadOnly(1);
	eAge.SetReadOnly(1);
	eHomeAddress.SetReadOnly(1);
	eEmail.SetReadOnly(1);
	eBirthDate.SetReadOnly(1);
	string tmp[256];
	eFirstName.SetWindowTextA(ini.GetStringValue(PbSection, "Owner First Name", "").c_str());
	eLastName.SetWindowTextA(ini.GetStringValue(PbSection, "Owner Last Name", "").c_str());
	ePbName.SetWindowTextA(ini.GetStringValue(PbSection, "Phone Book Name", "").c_str());
	ePhoneNumber.SetWindowTextA(ini.GetStringValue(PbSection, "Owner Phone Number", "").c_str());
	eOccupation.SetWindowTextA(ini.GetStringValue(PbSection, "Owner Occupation", "").c_str());
	eAge.SetWindowTextA(ini.GetStringValue(PbSection, "Owner Age", "").c_str());
	eHomeAddress.SetWindowTextA(ini.GetStringValue(PbSection, "Owner Home Address", "").c_str());
	eEmail.SetWindowTextA(ini.GetStringValue(PbSection, "Owner Email Address", "").c_str());
	eBirthDate.SetWindowTextA(ini.GetStringValue(PbSection, "Owner Birth Date", "").c_str());
	CString str = ini.GetStringValue(PbSection, "Owner Photo", "").c_str();
	::ShowWindow(PbName, 1);
	mPic.LoadFromFile(str);
	::SetWindowTextA(PbName, "Phone Book Name:");
}

void PbDetails::EditPhonebook()
{
	bSave.ShowWindow(0);
	bClear.ShowWindow(0);
	bBrowse.ShowWindow(0);
	bCancel.SetWindowTextA("Close");
	eFirstName.SetReadOnly(1);
	eLastName.SetReadOnly(1);
	ePbName.SetReadOnly(1);
	ePhoneNumber.SetReadOnly(1);
	eOccupation.SetReadOnly(1);
	eAge.SetReadOnly(1);
	eHomeAddress.SetReadOnly(1);
	eEmail.SetReadOnly(1);
	eBirthDate.SetReadOnly(1);
	string tmp[256];
	eFirstName.SetWindowTextA(ini.GetStringValue(PbSection, "Owner First Name", "").c_str());
	eLastName.SetWindowTextA(ini.GetStringValue(PbSection, "Owner Last Name", "").c_str());
	ePbName.SetWindowTextA(ini.GetStringValue(PbSection, "Phone Book Name", "").c_str());
	ePhoneNumber.SetWindowTextA(ini.GetStringValue(PbSection, "Owner Phone Number", "").c_str());
	eOccupation.SetWindowTextA(ini.GetStringValue(PbSection, "Owner Occupation", "").c_str());
	eAge.SetWindowTextA(ini.GetStringValue(PbSection, "Owner Age", "").c_str());
	eHomeAddress.SetWindowTextA(ini.GetStringValue(PbSection, "Owner Home Address", "").c_str());
	eEmail.SetWindowTextA(ini.GetStringValue(PbSection, "Owner Email Address", "").c_str());
	eBirthDate.SetWindowTextA(ini.GetStringValue(PbSection, "Owner Birth Date", "").c_str());
	CString str = ini.GetStringValue(PbSection, "Owner Photo", "").c_str();
	::ShowWindow(PbName, 1);
	::SetWindowTextA(PbName, "Phone Book Name:");
	mPic.LoadFromFile(str);
}

BOOL PbDetails::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	picLoaded = 0;
	this->OnBnClickedButton1();
	mPic.FreeData();
	cbType.AddString("Acquaintance");
	cbType.AddString("Colleague");
	cbType.AddString("Friend");
	cbType.SetCurSel(0);
	PbName = ::GetDlgItem(this->m_hWnd, IDC_STATICPBNAME);
	MessageBox("InitDialog",0,0);
	switch(mode)
	{
	case ADD_PHONEBOOK:
		AddPhonebook();
		break;
	case EDIT_PHONEBOOK:
		EditPhonebook();
		break;
	case VIEW_PHONEBOOK:
		ViewPhonebook();
		break;
	case ADD_CONTACT:
		AddContact();
		break;
	case EDIT_CONTACT:
		EditContact();
		break;
	case VIEW_CONTACT:
		ViewContact();
		break;
	}


	// TODO:  Add extra initialization here
	HICON hSave = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON6));
	HICON hClear = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON5));

	
	//DWORD error = GetLastError();
	bSave.SetIcon(hSave);
	bClear.SetIcon(hClear);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void PbDetails::ViewContact()
{
	this->SetWindowTextA("Contact Details");
	eFirstName.SetWindowTextA(p->ContactList[contact].getFirstName().c_str());
	eLastName.SetWindowTextA(p->ContactList[contact].getLastName().c_str());
	ePhoneNumber.SetWindowTextA(p->ContactList[contact].getPhoneNumber().c_str());
	eOccupation.SetWindowTextA(p->ContactList[contact].getOccupation().c_str());
	int age = p->ContactList[contact].getAge();
	char tmp[10]; 
	_itoa_s(age, tmp, 10);
	eAge.SetWindowTextA(tmp);
	eHomeAddress.SetWindowTextA(p->ContactList[contact].getHomeAddress().c_str());
	eEmail.SetWindowTextA(p->ContactList[contact].getEmailAddress().c_str());
	eBirthDate.SetWindowTextA(p->ContactList[contact].getBirthDate().toString().c_str());
	::SetWindowTextA(PbName, "Contact Name:");
}

void PbDetails::AddContact()
{
		this->SetWindowTextA("Add Contact");
		::ShowWindow(PbName, 1);
		::SetWindowTextA(PbName, "Contact Type:");
		cbType.ShowWindow(1);
		ePbName.ShowWindow(0);
		
}
//clear edit boxes
void PbDetails::OnBnClickedButton1() //clear function
{
	// TODO: Add your control notification handler code here
	eFirstName.SetWindowTextA("");
	eFirstName.SetWindowTextA("");
	eLastName.SetWindowTextA("");
	ePbName.SetWindowTextA("");
	ePhoneNumber.SetWindowTextA("");
	eOccupation.SetWindowTextA("");
	eAge.SetWindowTextA("");
	eHomeAddress.SetWindowTextA("");
	eEmail.SetWindowTextA("");
	eBirthDate.SetWindowTextA("");
}
//cancel button
void PbDetails::OnBnClickedButton4() //cancel
{
	// TODO: Add your control notification handler code here
	this->EndDialog(IDCANCEL);
}

void PbDetails::SaveContact()
{
	char tmp[1024];
	string details[10];
	int sel = cbType.GetCurSel();
	if(sel == CB_ERR)
		MessageBox("Choose a contact type", "ERROR", MB_ICONWARNING);
	else cbType.GetLBText(sel, tmp);
	details[0] = tmp;
	eFirstName.GetWindowTextA(tmp, 256);
	details[1] = tmp;
	eLastName.GetWindowTextA(tmp, 256);
	details[2] = tmp;
	ePhoneNumber.GetWindowTextA(tmp, 256);
	details[3] = tmp;
	eAge.GetWindowTextA(tmp, 256);
	details[4] = "";
	details[5] = tmp;
	eEmail.GetWindowTextA(tmp, 256);
	details[6] = tmp;
	eOccupation.GetWindowTextA(tmp, 256);
	details[7] = tmp;
	eBirthDate.GetWindowTextA(tmp, 256);
	details[8] = tmp;
	eHomeAddress.GetWindowTextA(tmp, 256);
	details[9] = tmp;
	int err = 0;
	if(details[0].compare("Acquaintance") == 0)
		p->addAcquaintance(details);
	else
		if(details[0].compare("Colleague") == 0)
			p->addColleague(details);
		else if(details[0].compare("Friend") == 0)
			p->addFriend(details);
	else
		{
			details[0] += " is not a valid contact type!";
			MessageBox(details[0].c_str(), "ERROR", 0);
			err = 1;
		}
	if(!err)
		MessageBox("Contact saved", 0, 0);

	////ViewContact();
	//char tmp[1024];
	//string details[10];
	//ePbName.GetWindowTextA(tmp, 256);
	//details[0] = tmp;
	//eFirstName.GetWindowTextA(tmp, 256);
	//details[1] = tmp;
	//eLastName.GetWindowTextA(tmp, 256);
	//details[2] = tmp;
	//ePhoneNumber.GetWindowTextA(tmp, 256);
	//details[3] = tmp;
	//eAge.GetWindowTextA(tmp, 256);
	//details[4] = "";
	//details[5] = tmp;
	//eEmail.GetWindowTextA(tmp, 256);
	//details[6] = tmp;
	//eOccupation.GetWindowTextA(tmp, 256);
	//details[7] = tmp;
	//eBirthDate.GetWindowTextA(tmp, 256);
	//details[8] = tmp;
	//eHomeAddress.GetWindowTextA(tmp, 256);
	//details[9] = tmp;
	//p->ContactList[contact].setFirstName(details[1]);
	//p->ContactList[contact].setLastName(details[2]);
	//p->ContactList[contact].setEmailAddress(details[6]);
	//p->ContactList[contact].setHomeAddress(details[9]);
	//p->ContactList[contact].setPhoneNumber(details[3]);
	//p->ContactList[contact].setOccupation(details[7]);
	//int age = atoi(details[5].c_str());
	//p->ContactList[contact].setAge(age);
}
//save
void PbDetails::OnBnClickedButton2() //save
{
	// TODO: Add your control notification handler code here

	int Pb;
	Pb = ini.GetIntValue("Settings", "PbNo");
	char tmp[256], section[100];
	_itoa_s(Pb, section, 10);
	ini.CreateSection(section);
	string details, pbPath;
	ePbName.GetWindowTextA(tmp, 256);
	int err = 0;
	for(int i = 0; i < (int) chPb->size(); i++)
	{
		if(_stricmp(tmp, chPb[i].c_str()) == 0)
		{
			MessageBox("Enter a different phone book name, this one already exists", "ERROR", MB_ICONERROR);
			err = 1;
			break;
		}
	}
	
	if(!err)
	{	details = tmp;
		pbPath = details;
		ini.WriteValue(section, "Phone Book Name", details);
		eFirstName.GetWindowTextA(tmp, 256);
		details = tmp;
		ini.WriteValue(section, "Owner First Name", details);
		eLastName.GetWindowTextA(tmp, 256);
		details += tmp;
		p->setOwner(details);
		details = tmp;
		ini.WriteValue(section, "Owner Last Name", details);
		ePhoneNumber.GetWindowTextA(tmp, 256); details = tmp;
		ini.WriteValue(section, "Owner Phone Number", details);
		eOccupation.GetWindowTextA(tmp, 256); details = tmp;
		ini.WriteValue(section, "Owner Occupation", details);
		eAge.GetWindowTextA(tmp, 256); details = tmp;
		ini.WriteValue(section, "Owner Age", details);
		eHomeAddress.GetWindowTextA(tmp, 256); details = tmp;
		ini.WriteValue(section, "Owner Home Address", details);
		eEmail.GetWindowTextA(tmp, 256); details = tmp;
		ini.WriteValue(section, "Owner Email Address", details);
		eBirthDate.GetWindowTextA(tmp, 256); details = tmp;
		ini.WriteValue(section, "Owner Birth Date", details);
		details = picName.GetBuffer();
		ini.WriteValue(section, "Owner Photo", details);
		string photoPath = photoDir;
		if(picLoaded)
		{		
			photoPath += "\\";
			photoPath += photoName;
			if(CopyFile(details.c_str(), photoPath.c_str(), 0) == 0 && photoPath.size() != 0)
				MessageBox("Can't copy photo", "ERROR", MB_ICONERROR);
			cout<<"photo path="<<photoPath<<endl;
			picLoaded = 0;
		}
		Pb++;
		_itoa_s(Pb, tmp, 10);
		ini.WriteValue("Settings", "PbNo", tmp);
		
		photoPath = photoDir;
		photoPath += pbPath;
		photoPath += ".txt";
		ofstream f(photoPath.c_str());
		if(!f)
			MessageBox("Error creating phone book file", "ERROR", MB_ICONERROR);
		else
			MessageBox("New Phone Book Saved Succesfully!", "Saved", MB_ICONINFORMATION);
		PbSection = "";
		photoDir = "";
		photoPath = "";
		this->EndDialog(IDOK);
	}
}

BOOL PbDetails::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if((pMsg->message == WM_KEYDOWN) && 
    (pMsg->wParam == VK_RETURN) )
	{
	   // Enter key was hit -> do whatever you want
		if(bSave.EnableWindow(0) == 0)
			OnBnClickedButton2();
		else bSave.EnableWindow(0);
	   return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void PbDetails::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	int length;
	length = eFirstName.GetWindowTextLengthA();
	int lastname = eLastName.GetWindowTextLengthA();
	int pb = 1;
	if(mode >= 3)
		pb = ePbName.GetWindowTextLengthA();
	if((length > 0 && lastname > 0 && pb > 0) || save == 1)
		bSave.EnableWindow(1);
	else
		bSave.EnableWindow(0);
	// TODO:  Add your control notification handler code here
}


void PbDetails::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	int length;
	length = eFirstName.GetWindowTextLengthA();
	int lastname = eLastName.GetWindowTextLengthA();
	int pb = 1;
	if(mode >= 3)
		pb = ePbName.GetWindowTextLengthA();
	if((length > 0 && lastname > 0 && pb > 0) || save == 1)
		bSave.EnableWindow(1);
	else
		bSave.EnableWindow(0);
	// TODO:  Add your control notification handler code here
}


void PbDetails::OnEnChangeEdit9()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	int length;
	length = eFirstName.GetWindowTextLengthA();
	int lastname = eLastName.GetWindowTextLengthA();
	int pb = 1;
	if(mode >= 3)
		pb = ePbName.GetWindowTextLengthA();
	if((length > 0 && lastname > 0 && pb > 0) || save == 1)
		bSave.EnableWindow(1);
	else
		bSave.EnableWindow(0);
	// TODO:  Add your control notification handler code here
}


INT_PTR PbDetails::DoModal()
{
	// TODO: Add your specialized code here and/or call the base class

		
	return CDialogEx::DoModal();
}
