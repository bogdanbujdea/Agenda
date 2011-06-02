#pragma once
#include "afxwin.h"
#include <iostream>
#include "CPictureCtrl/PictureCtrl.h"
#include "AgendaPH.h"

#include <map>

using namespace std;

// PbDetails dialog
enum Mode
{
	ADD_CONTACT,
	EDIT_CONTACT,
	VIEW_CONTACT,
	ADD_PHONEBOOK,
	VIEW_PHONEBOOK,
	EDIT_PHONEBOOK
	
};

enum RetCode
{
	SUCCESS,
	PB_ALREADY_EXISTS,
	FILE_ERROR
};

class PbDetails : public CDialogEx
{
	DECLARE_DYNAMIC(PbDetails)

public:
	PbDetails(CWnd* pParent = NULL);   // standard constructor
	virtual ~PbDetails();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CButton bBrowse;
	afx_msg void OnBnClickedButton3();
	CPictureCtrl mPic;
	CButton bSave;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	CButton bClear;
//	IniFile ini;
	Mode mode;
	CButton bCancel;
	afx_msg void OnBnClickedButton4();
	bool show;
	int picLoaded;
	CEdit eFirstName;
	CEdit eLastName;
	CEdit ePhoneNumber;
	string RemotePhotoPath;
	CEdit eOccupation;
	CEdit eAge;
	CEdit eHomeAddress;
	CEdit eEmail;
	CString picName;
	string photoPath;
	string photoName;
	int save, add;
	string PbSection;
	string OpenedPb;
	CEdit eBirthDate;
	bool contactView, contactAdd;
	afx_msg void AddNewContact();
	Phonebook *p;
	int contact;
	HWND PbName;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	int SaveContact();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	CEdit ePbName;
	afx_msg void OnEnChangeEdit9();
	string chPb[1000];
	bool viewOnly;
	virtual INT_PTR DoModal();
	int ValidateInputData();
	void AddPhonebook();
	void EditPhonebook();
	void ViewPhonebook();
	void AddContact();
	void ViewContact();
	void EditContact();
	int ChangeContact();
	int ValidateData();
	void DisplayInfo();
	CComboBox cbType;
};
