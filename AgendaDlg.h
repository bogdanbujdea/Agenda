
// AgendaDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "InfoDlg.h"
#include "afxwin.h"
#include "PbManager.h"

// CAgendaDlg dialog
class CAgendaDlg : public CDialogEx
{

// Construction
public:
	CAgendaDlg(CWnd* pParent = NULL);	// standard constructor
	~CAgendaDlg();
// Dialog Data
	enum { IDD = IDD_AGENDAPH_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	void InitTree();
	void InitList();
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:


	CTreeCtrl TreeCtrl;
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl listCtrl;
	afx_msg void SearchContact();
	void OpenPb();
	InfoDlg *info;
	PbManager *manager;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedMfcbutton1();
	CButton bSearch;
	CButton bEdit;
	CButton bDelete;
	CButton bNew;
	void ShowControls(bool show);
	void LoadList(char *type, deque<Contact> list);
	afx_msg LRESULT OnShowWnd(UINT wParam, LONG lParam);
	afx_msg LRESULT Search(UINT wParam, LONG lParam);
	afx_msg void DeleteContact();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void ClosePhoneBook();
	CButton bClosePb;
	CButton bSavePb;
	int GetSelectedContact();
	CButton bDeletePb;
	HTREEITEM Agenda;
	HTREEITEM Acq;
	HTREEITEM Col;
	HTREEITEM Fr;
	virtual BOOL DestroyWindow();
	CButton bDetails;
	afx_msg void OnBnClickedButton8();
	afx_msg void AddNewContact();
	afx_msg void EditContact();
	afx_msg void OnFileNewphonebook();
	afx_msg void OnFileNewcontact32798();
	afx_msg void OnFileExit32795();
	afx_msg void DeletePhoneBook();
	afx_msg void OnClose();
	afx_msg void OnEditDeletecontact();
	afx_msg void OnEditContact();
};
