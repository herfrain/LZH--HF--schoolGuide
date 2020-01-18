// CampusNavigationDlg.h : header file
//

#if !defined(AFX_CAMPUSNAVIGATIONDLG_H__20839383_43FA_4C48_9CF1_533C2745D8A7__INCLUDED_)
#define AFX_CAMPUSNAVIGATIONDLG_H__20839383_43FA_4C48_9CF1_533C2745D8A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCampusNavigationDlg dialog

class CCampusNavigationDlg : public CDialog
{
// Construction

public:
	CCampusNavigationDlg(CWnd* pParent = NULL);	// standard constructor
	int start;//Æðµã
	int end;//ÖÕµã

	void SearchAll(int origin,int destination,int recordEnd,bool used[],int record[]);
	void show(int end,int record[]);
// Dialog Data
	//{{AFX_DATA(CCampusNavigationDlg)
	enum { IDD = IDD_CAMPUSNAVIGATION_DIALOG };
	CComboBox	m_ComBoR;
	CComboBox	m_ComBoL;
	CListBox	m_result;
	CListBox	m_listboxsearchall;
	CButton	m_b1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCampusNavigationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCampusNavigationDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAMPUSNAVIGATIONDLG_H__20839383_43FA_4C48_9CF1_533C2745D8A7__INCLUDED_)

