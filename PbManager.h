#pragma once
#include "afxwin.h"

#include "PbDetails.h"

// PbManager dialog

class PbManager : public CDialogEx
{
	DECLARE_DYNAMIC(PbManager)

public:
	PbManager(CWnd* pParent = NULL);   // standard constructor
	virtual ~PbManager();
	char *OpenedPb;
// Dialog Data
	enum { IDD = IDD_MANAGEDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CButton bAddPb;
	CButton bOpenPb;
	CButton bClosePb;
	CButton bDeletePb;
	CComboBox cbList;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void Open();
	afx_msg void OnBnClickedButton1();
	void InitCbList();
	int Hide;
	PbDetails *detailsDlg;
	int contact;
	virtual void OnOK();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	virtual BOOL OnInitDialog();
	CButton bDetails;
};
