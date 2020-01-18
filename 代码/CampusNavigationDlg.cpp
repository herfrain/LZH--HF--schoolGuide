// CampusNavigationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CampusNavigation.h"
#include "CampusNavigationDlg.h"
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int check=1;
int countt=0;
int MAX=5;
bool onb2=false;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCampusNavigationDlg dialog

CCampusNavigationDlg::CCampusNavigationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCampusNavigationDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCampusNavigationDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32

	//初始化起点和终点
	start=0;
	end=0;
	//水平滚动条显现范围
	//m_result.SetHorizontalExtent(100);

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CCampusNavigationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCampusNavigationDlg)
	DDX_Control(pDX, IDC_COMBOright, m_ComBoR);
	DDX_Control(pDX, IDC_COMBOleft, m_ComBoL);
	DDX_Control(pDX, IDC_LIST2, m_result);
	DDX_Control(pDX, IDC_LIST1, m_listboxsearchall);
	DDX_Control(pDX, IDC_BUTTON1, m_b1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCampusNavigationDlg, CDialog)
	//{{AFX_MSG_MAP(CCampusNavigationDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//ON_BN_CLICKED(IDC_B25lou, OnB25lou)
	/*ON_BN_CLICKED(IDC_Bcanting, OnBcanting)
	ON_BN_CLICKED(IDC_Bguangchang, OnBguangchang)
	ON_BN_CLICKED(IDC_Bhoumen, OnBhoumen)
	ON_BN_CLICKED(IDC_Bjiaoshigongyu, OnBjiaoshigongyu)
	ON_BN_CLICKED(IDC_BjiaoxuelouA, OnBjiaoxuelouA)
	ON_BN_CLICKED(IDC_BjiaoxuelouB, OnBjiaoxuelouB)
	ON_BN_CLICKED(IDC_BjiaoxuelouC, OnBjiaoxuelouC)
	ON_BN_CLICKED(IDC_Blanqiuchang, OnBlanqiuchang)
	ON_BN_CLICKED(IDC_Bshangyejie, OnBshangyejie)*/
	//ON_BN_CLICKED(IDC_Bshiyanlou, OnBshiyanlou)
	/*ON_BN_CLICKED(IDC_Btingchechang, OnBtingchechang)
	ON_BN_CLICKED(IDC_Btiyuguan, OnBtiyuguan)
	ON_BN_CLICKED(IDC_Btushuguan, OnBtushuguan)
	ON_BN_CLICKED(IDC_Bxingxizhongxing, OnBxingxizhongxing)
	ON_BN_CLICKED(IDC_Bxingzhenglou, OnBxingzhenglou)
	ON_BN_CLICKED(IDC_Bxuehuo, OnBxuehuo)
	ON_BN_CLICKED(IDC_BxueshensusheA, OnBxueshensusheA)
	ON_BN_CLICKED(IDC_BxueshensusheB, OnBxueshensusheB)
	ON_BN_CLICKED(IDC_Byundongchang, OnByundongchang)
	ON_BN_CLICKED(IDC_Bzhaodaisuo, OnBzhaodaisuo)*/
	//ON_BN_CLICKED(IDC_Bzhengmen, OnBzhengmen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCampusNavigationDlg message handlers

BOOL CCampusNavigationDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.
	/*OnButton=new bool[max+1];
	for(int qq=1;qq<=max;qq++){
		OnButton[qq]=false;
	}
	//初始化地点编号
	point=new int[max+1];
	for(int k=1;k<=max;k++){
		point[k]=k;
	}*/

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
		//int record[rec.vertexNum+1][rec.vertexNum+1];
	int *record=new int [CCampusNavigationApp::vertexNum+2];
	bool *exist=new bool [CCampusNavigationApp::vertexNum+1];
	for(int i=0;i<=CCampusNavigationApp::vertexNum;i++){
		record[i]=0;
		exist[i]=false;
	}
	record[CCampusNavigationApp::vertexNum+1]=0;
	record[1]=1;
	exist[record[1]]=true;
	record[CCampusNavigationApp::vertexNum+1]=1;
	SearchAll(2,CCampusNavigationApp::vertexNum,CCampusNavigationApp::vertexNum+1,exist,record);
	check=0;
	countt=0;
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCampusNavigationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCampusNavigationDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCampusNavigationDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCampusNavigationDlg::OnButton1() 
{

	if(onb2==true){
		m_result.ResetContent();
		onb2=false;
	}
		
	// TODO: Add your control notification handler code here
	int a=m_ComBoL.GetCurSel()+1;
	int b=m_ComBoR.GetCurSel()+1;

	if(a==0||b==0)
	{
		AfxMessageBox("选项不能为空！");
		return;
	}

	if(a==b)
	{
		AfxMessageBox("起点终点不能相同！");
		return;
	}
	
	if(CCampusNavigationApp::dist[a][b]==1000){
		AfxMessageBox("该两景点间不相通");
		return;
	}
	string num;
	stringstream s;
	s<<CCampusNavigationApp::dist[a][b];
	s>>num;

	string str=CCampusNavigationApp::path[a][b];
	str+="  路程为:";
	str+=num;
	CString cstr(str.data());
	m_result.AddString(cstr);
	
}



void CCampusNavigationDlg::OnButton2() 
{
	onb2=true;
	// TODO: Add your control notification handler code here
	m_result.ResetContent();

	start=m_ComBoL.GetCurSel()+1;
	end=m_ComBoR.GetCurSel()+1;
	if(start!=0&&end!=0){
		int *record=new int [CCampusNavigationApp::vertexNum+2];
		bool *used=new bool [CCampusNavigationApp::vertexNum+1];
		for(int i=0;i<=CCampusNavigationApp::vertexNum;i++){
			record[i]=0;
			used[i]=false;
		}
		record[CCampusNavigationApp::vertexNum+1]=0;
		if(start==end){
			record[1]=start;
			used[start]=true;
			record[CCampusNavigationApp::vertexNum+1]=end;
			used[end]=true;
			SearchAll(2,CCampusNavigationApp::vertexNum,CCampusNavigationApp::vertexNum+1,used,record);
		}
		else{
			record[1]=start;
			used[start]=true;
			record[CCampusNavigationApp::vertexNum]=end;
			used[end]=true;
			SearchAll(2,CCampusNavigationApp::vertexNum,CCampusNavigationApp::vertexNum,used,record);
		}
		start=0;
		end=0;
	}
	countt=0;
}



int maxx=1000;
void CCampusNavigationDlg::SearchAll(int origin,int destination,int recordEnd,bool used[],int record[])//回溯法
{

	int i=1;
	for(;i<=destination;i++)
	{
		int b=record[origin-1];
		if(used[i]==true||CCampusNavigationApp::arc[b][i]==maxx)
			continue;
		int e=record[recordEnd];
		if(origin+1==recordEnd)
		{
			if(CCampusNavigationApp::arc[i][e]!=maxx)
			{
				record[origin]=i;
				used[i]=true;
				show(recordEnd,record);
			}
			else
				continue;
		}
		if(countt<MAX){
			record[origin]=i;
			used[i]=1;
			SearchAll(origin+1,destination,recordEnd,used,record);
			record[origin]=0;
			used[i]=0;
		}
	}
}



void CCampusNavigationDlg::show(int end,int record[])
{


	string str;
	string num;
	int i=1;
	int sum=0;
	for(;i<=end;i++)
	{
		if(i<end){
			str+=CCampusNavigationApp::space[record[i]]+"-";
			sum+=CCampusNavigationApp::arc[record[i]][record[i+1]];
		}
		else if(i==end)
			str+=CCampusNavigationApp::space[record[i]];
	}
	str+="  路径长度为：";
	stringstream s;
	s<<sum;
	s>>num;
	str+=num;
	CString cstr(str.data());
	string k=" ";
	CString kong(k.data());
	if(check){
		countt++;
		m_listboxsearchall.AddString(cstr);
		//m_listboxsearchall.AddString(0);
	}
	else{
		countt++;
		m_result.AddString(cstr);
	}
	
}
