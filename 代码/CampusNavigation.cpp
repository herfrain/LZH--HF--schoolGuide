// CampusNavigation.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "CampusNavigation.h"
#include "CampusNavigationDlg.h"
#include <string>
#include <fstream>
#include <sstream>

string CCampusNavigationApp::path[30][30];//对于景点与景点之间路线的标记
string CCampusNavigationApp::space[30];//记录景点的名字
int CCampusNavigationApp::vertexNum;//记录景点数
int CCampusNavigationApp::arcNum;//记录路径的数
int ** CCampusNavigationApp::arc;//记录景点与景点之间的路径
int ** CCampusNavigationApp::dist;//辅助数组，记录景点与景点之间的最短距离
int ** CCampusNavigationApp::kkmin;

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCampusNavigationApp

BEGIN_MESSAGE_MAP(CCampusNavigationApp, CWinApp)
	//{{AFX_MSG_MAP(CCampusNavigationApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCampusNavigationApp construction

CCampusNavigationApp::CCampusNavigationApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCampusNavigationApp object

CCampusNavigationApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CCampusNavigationApp initialization

BOOL CCampusNavigationApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	theApp.Make();
	CCampusNavigationDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

void CCampusNavigationApp::Make(){
	ifstream ifs("campus.txt");
	if(!ifs) 
	{
		AfxMessageBox("文件读取失败！");
		return ;
	}

	string line;//记录文件每一行的内容
	int num;//记录景点名字前面的序号
	vertexNum=0;
	arcNum=0;

	while(getline(ifs,line))//从文件输入景点编号以及其名称
	{
		if(line.find("end")!=string::npos)
			break;

		if(line.rfind("//",2)!=string::npos)
			continue;

		char temp[20];

		istringstream is(line);
		is>>num>>temp;
		space[num]=string(temp);
		vertexNum++;
	}

	arc=new int*[vertexNum+1];
	dist=new int*[vertexNum+1];
	kkmin=new int*[vertexNum+1];
	int r=0,c=0;
	int maxx=1000;
	for(;r<=vertexNum;r++)//初始化路径数组，假定景点与景点之间彼此无法到达
	{
		arc[r]=new int [vertexNum+1];
		dist[r]=new int [vertexNum+1];
		kkmin[r]=new int [vertexNum+1];
		for(c=0;c<=vertexNum;c++)
		{
			arc[r][c]=maxx;
			dist[r][c]=maxx;
			kkmin[r][r]=maxx;
			stringstream strStream;//初始化路径，标记起点和终点
			strStream<<(char)(64+r)<<(char)(64+c);//将每个景点的序号转化为大写英文字母，易于统计
			path[r][c]+=strStream.str();
		}
	}

	while(getline(ifs,line))//从文件输入景点间的路径
	{
		if(line.find("end")!=string::npos)
			break;

		if(line.rfind("//",2)!=string::npos)
			continue;

		int len;

		istringstream is(line);
		is>>r>>c>>len;
		arc[r][c]=len;
		dist[r][c]=len;
		arc[c][r]=len;
		dist[c][r]=len;
		arcNum++;
	}
	//Floyd算法
	int i=0;
	int j=0;
	int k=0;

	for(i=1;i<=vertexNum;i++)//初始化dist和path
		for(j=1;j<=vertexNum;j++){
			//dist[i][j]=arc[i][j];
			if(dist[i][j]!=maxx) path[i][j]=space[i]+"-"+space[j];
			else path[i][j]="";
		}

	{
		
		for(i=1;i<=vertexNum;i++){
		//	if(k==i) continue;
			for(j=1;j<=vertexNum;j++){
				for(k=1;k<=vertexNum;k++){
				//if(j==k||i==j) continue;	
				if(dist[i][k]+dist[k][j]<dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
					path[i][j]=path[i][k]+","+path[k][j];

					//比较i到k和k到j的距离，离的近的一边直接加上地点名
					//if(dist[i][k]<dist[k][j])
					/*if(dist[i][k]<kkmin[i][k]){
						kkmin[i][k]=dist[i][k];
						path[i][j]=space[i]+"-"+path[k][j];
					}*/
					//else
					//path[i][j]=path[i][k]+"-"+space[j];
				}
				}
			}
		}
	}
}

