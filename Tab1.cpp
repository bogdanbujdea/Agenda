// Tab1.cpp : implementation file
//

#include "stdafx.h"
#include "AgendaPH.h"
#include "Tab1.h"
#include "afxdialogex.h"


// Tab1 dialog

IMPLEMENT_DYNAMIC(Tab1, CDialogEx)

Tab1::Tab1(CWnd* pParent /*=NULL*/)
	: CDialogEx(Tab1::IDD, pParent)
{

}

Tab1::~Tab1()
{
}

void Tab1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, TreeCtrl);
}


BEGIN_MESSAGE_MAP(Tab1, CDialogEx)
END_MESSAGE_MAP()


// Tab1 message handlers
