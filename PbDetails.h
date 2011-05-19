#pragma once
#include "afxwin.h"
#include <iostream>
#include "CPictureCtrl/PictureCtrl.h"
#include "Phonebook/IniFile.h"
#include "Phonebook/Phonebook.h"

using namespace std;

// PbDetails dialog

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
	IniFile ini;
	CButton bCancel;
	afx_msg void OnBnClickedButton4();
	bool show;
	CEdit eFirstName;
	CEdit eLastName;
	CEdit ePhoneNumber;
	CEdit eOccupation;
	CEdit eAge;
	CEdit eHomeAddress;
	CEdit eEmail;
	CString picName;
	string photoDir;
	string photoName;
	int save, add;
	string PbSection;
	string OpenedPb;
	CEdit eBirthDate;
	void ViewContact();
	void AddContact();
	bool contactView, contactAdd;
	afx_msg void OnBnClickedButton2();
	Phonebook *p;
	int contact;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void SaveContact();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	CEdit ePbName;
	afx_msg void OnEnChangeEdit9();
	string chPb[1000];
	bool viewOnly;
	virtual INT_PTR DoModal();
};
