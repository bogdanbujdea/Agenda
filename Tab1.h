#pragma once
#include "afxcmn.h"


// Tab1 dialog

class Tab1 : public CDialogEx
{
	DECLARE_DYNAMIC(Tab1)

public:
	Tab1(CWnd* pParent = NULL);   // standard constructor
	virtual ~Tab1();
	
// Dialog Data
	enum { IDD = IDC_TAB1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
