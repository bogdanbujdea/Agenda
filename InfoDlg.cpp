// InfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AgendaPH.h"
#include "InfoDlg.h"
#include "afxdialogex.h"


// InfoDlg dialog

IMPLEMENT_DYNAMIC(InfoDlg, CDialogEx)

InfoDlg::InfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(InfoDlg::IDD, pParent)
	, rOption(0)
{
	Show = false;
}

InfoDlg::~InfoDlg()
{
	
}

void InfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, eFirstName);
	DDX_Control(pDX, IDC_EDIT2, eLastName);
	DDX_Control(pDX, IDC_EDIT3, ePhoneNumber);
	DDX_Control(pDX, IDC_EDIT4, eOccupation);
	DDX_Control(pDX, IDC_EDIT5, eAge);
	DDX_Control(pDX, IDC_EDIT6, eAddress);
	DDX_Control(pDX, IDC_EDIT7, eEmail);
	DDX_Control(pDX, IDC_SLIDER1, tSlider);
	DDX_Control(pDX, IDC_BTN_SEARCH, bClear);
	DDX_Control(pDX, IDC_RADIO10, rLast);
	DDX_Control(pDX, IDC_RADIO11, rPhone);
	DDX_Control(pDX, IDC_RADIO12, rOccupation);
	DDX_Control(pDX, IDC_RADIO13, rAge);
	DDX_Control(pDX, IDC_RADIO14, rAddress);
	DDX_Control(pDX, IDC_RADIO15, rEmail);
	DDX_Control(pDX, IDC_RADIO9, rFirst);
}


BEGIN_MESSAGE_MAP(InfoDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_SEARCH, &InfoDlg::OnBnClickedButton1)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, &InfoDlg::OnNMReleasedcaptureSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &InfoDlg::OnNMCustomdrawSlider1)
	ON_WM_CLOSE()
//	ON_NOTIFY(TRBN_THUMBPOSCHANGING, IDC_SLIDER1, &InfoDlg::OnTRBNThumbPosChangingSlider1)
ON_EN_CHANGE(IDC_EDIT1, &InfoDlg::OnEnChangeEdit1)
ON_BN_CLICKED(IDC_RADIO9, &InfoDlg::OnBnClickedRadio9)
ON_BN_CLICKED(IDC_RADIO10, &InfoDlg::OnBnClickedRadio10)
ON_BN_CLICKED(IDC_RADIO11, &InfoDlg::OnBnClickedRadio11)
ON_BN_CLICKED(IDC_RADIO12, &InfoDlg::OnBnClickedRadio12)
ON_BN_CLICKED(IDC_RADIO13, &InfoDlg::OnBnClickedRadio13)
ON_BN_CLICKED(IDC_RADIO14, &InfoDlg::OnBnClickedRadio14)
ON_BN_CLICKED(IDC_RADIO15, &InfoDlg::OnBnClickedRadio15)
ON_BN_CLICKED(IDC_NEWCONTACT, &InfoDlg::AddNewContact)
END_MESSAGE_MAP()


// InfoDlg message handlers


void InfoDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	eFirstName.SetWindowTextA("");
	eLastName.SetWindowTextA("");
	ePhoneNumber.SetWindowTextA("");
	eOccupation.SetWindowTextA("");
	eAge.SetWindowTextA("");
	eAddress.SetWindowTextA("");
	eEmail.SetWindowTextA("");

}


void InfoDlg::OnNMReleasedcaptureSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	
	
	*pResult = 0;
	

}


void InfoDlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	int pos = tSlider.GetPos();
	int col = 0xFF00FF;
	this->SetLayeredWindowAttributes(col, pos, LWA_ALPHA);
	*pResult = 0;
}


void InfoDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	Show = !Show;
	CDialogEx::OnClose();
}




BOOL InfoDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if((pMsg->message == WM_KEYDOWN) && 
    (pMsg->wParam == VK_RETURN) )
	{
	   // Enter key was hit -> do whatever you want
		this->Show = 0;
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void InfoDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void InfoDlg::UpdateEdit()
{
	edit[rOption]->EnableWindow(1);
	edit[rLastOption]->EnableWindow(0);
	edit[rLastOption]->SetWindowTextA("");
	rLastOption = rOption;
}


void InfoDlg::OnBnClickedRadio9()
{
	// TODO: Add your control notification handler code here
	rOption = 0;
	UpdateEdit();

}


void InfoDlg::OnBnClickedRadio10()
{
	// TODO: Add your control notification handler code here
	rOption = 1;
	UpdateEdit();
}


BOOL InfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	rFirst.SetCheck(BST_CHECKED);
	rLast.SetCheck(BST_UNCHECKED);
	rPhone.SetCheck(BST_UNCHECKED);
	rAge.SetCheck(BST_UNCHECKED);
	rOccupation.SetCheck(BST_UNCHECKED);
	rAddress.SetCheck(BST_UNCHECKED);
	rEmail.SetCheck(BST_UNCHECKED);
	rLastOption = 0;
	rOption = 0;
	for(int i =  0; i < 7; i++)
		edit[i] = new CEdit;

	edit[0] = &eFirstName;
	edit[0] = &eFirstName;
	edit[1] = &eLastName;
	edit[2] = &ePhoneNumber;
	edit[3] = &eOccupation;
	edit[4] = &eAge;
	edit[5] = &eAddress;
	edit[6] = &eEmail;
	for(int i = 0; i < 7; i++)
		edit[i]->EnableWindow(0);
	edit[0]->EnableWindow(1);
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void InfoDlg::OnBnClickedRadio11()
{
	// TODO: Add your control notification handler code here
	rOption = 2;
	UpdateEdit();
}


void InfoDlg::OnBnClickedRadio12()
{
	// TODO: Add your control notification handler code here
	rOption = 3;
	UpdateEdit();
}


void InfoDlg::OnBnClickedRadio13()
{
	// TODO: Add your control notification handler code here
	rOption = 4;
	UpdateEdit();
}


void InfoDlg::OnBnClickedRadio14()
{
	// TODO: Add your control notification handler code here
	rOption = 5;
	UpdateEdit();
}


void InfoDlg::OnBnClickedRadio15()
{
	// TODO: Add your control notification handler code here
	rOption = 6;
	UpdateEdit();
}


void InfoDlg::AddNewContact()
{
	// TODO: Add your control notification handler code here

	CWnd *cwnd = this->GetOwner();
	edit[rOption]->GetWindowTextA(text, 1023);
	switch(rOption)
	{
	case 0:
		attribute = "firstname";
		break;
	case 1:
		attribute = "lastname";
		break;
	case 2:
		attribute = "number";
		break;
	case 3:
		attribute = "occupation";
		break;
	case 4:
		attribute = "age";
		break;
	case 5:
		attribute = "address";
		break;
	case 6:
		attribute = "email";
		break;
	}
	cwnd->SendMessage(SEARCH, 0, 0);
}
