// CampusNavigation.h : main header file for the CAMPUSNAVIGATION application
//

#if !defined(AFX_CAMPUSNAVIGATION_H__251FDAB0_CECD_487F_95EA_9A3602CEB990__INCLUDED_)
#define AFX_CAMPUSNAVIGATION_H__251FDAB0_CECD_487F_95EA_9A3602CEB990__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include <string>
using namespace std;
/////////////////////////////////////////////////////////////////////////////
// CCampusNavigationApp:
// See CampusNavigation.cpp for the implementation of this class
//


class CCampusNavigationApp : public CWinApp
{
public:
	CCampusNavigationApp();
	void Make();//导航图的初始化
	~CCampusNavigationApp(){}//析构申请的内存；
	static string path[30][30];//对于景点与景点之间路线的标记
	static string space[30];//记录景点的名字
	static int vertexNum;//记录景点数
	static int arcNum;//记录路径的数
	static int **arc;//记录景点与景点之间的路径
	static int **dist;//辅助数组，记录景点与景点之间的最短距离
	static int **kkmin;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCampusNavigationApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCampusNavigationApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAMPUSNAVIGATION_H__251FDAB0_CECD_487F_95EA_9A3602CEB990__INCLUDED_)
