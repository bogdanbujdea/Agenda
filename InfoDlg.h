#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "AgendaPh.h"
#include <string>

using namespace std;

// InfoDlg dialog

class InfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(InfoDlg)

public:
	InfoDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~InfoDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };
	bool Show;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEdit eFirstName;
	CEdit eLastName;
	CEdit ePhoneNumber;
	CEdit eOccupation;
	CEdit eAge;
	CEdit eAddress;
	CEdit eEmail;
	void UpdateEdit();
	CEdit *edit[10];
	char text[1024];
	string attribute;
	afx_msg void OnNMReleasedcaptureSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl tSlider;
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClose();
	CButton bClear;
//	afx_msg void OnTRBNThumbPosChangingSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedRadio1();
	int rOption;
	int rLastOption;
	afx_msg void OnBnClickedRadio9();
	CButton rFirstName;
	afx_msg void OnBnClickedRadio10();
	CButton rFirst;
	CButton rLast;
	CButton rPhone;
	CButton rAge;
	CButton rOccupation;
	CButton rAddress;
	CButton rEmail;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRadio11();
	afx_msg void OnBnClickedRadio12();
	afx_msg void OnBnClickedRadio13();
	afx_msg void OnBnClickedRadio14();
	afx_msg void OnBnClickedRadio15();
	afx_msg void OnBnClickedButton2();
};
