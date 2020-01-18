; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCampusNavigationDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CampusNavigation.h"

ClassCount=5
Class1=CCampusNavigationApp
Class2=CCampusNavigationDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=All
Class4=Shortest
Resource3=IDD_CAMPUSNAVIGATION_DIALOG

[CLS:CCampusNavigationApp]
Type=0
HeaderFile=CampusNavigation.h
ImplementationFile=CampusNavigation.cpp
Filter=N

[CLS:CCampusNavigationDlg]
Type=0
HeaderFile=CampusNavigationDlg.h
ImplementationFile=CampusNavigationDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST1

[CLS:CAboutDlg]
Type=0
HeaderFile=CampusNavigationDlg.h
ImplementationFile=CampusNavigationDlg.cpp
Filter=D
LastObject=IDOK

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CAMPUSNAVIGATION_DIALOG]
Type=1
Class=CCampusNavigationDlg
ControlCount=14
Control1=IDC_STATIC,static,1342308865
Control2=IDC_BUTTON1,button,1342242816
Control3=IDC_BUTTON2,button,1342242816
Control4=IDC_STATIC,static,1342308865
Control5=IDC_Map,static,1342177294
Control6=IDC_LIST1,listbox,1353797891
Control7=IDC_LIST2,listbox,1485897993
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_COMBOleft,combobox,1344339970
Control14=IDC_COMBOright,combobox,1344339970

[CLS:Shortest]
Type=0
HeaderFile=Shortest.h
ImplementationFile=Shortest.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:All]
Type=0
HeaderFile=All.h
ImplementationFile=All.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_COMBO1

