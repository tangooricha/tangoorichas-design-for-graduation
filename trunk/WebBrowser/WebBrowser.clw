; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=RefreshDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "WebBrowser.h"
LastPage=0

ClassCount=6
Class1=CWebBrowserApp
Class2=CWebBrowserDoc
Class3=CWebBrowserView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=RefreshDlg
Resource3=IDD_REFRESH_DIALOG

[CLS:CWebBrowserApp]
Type=0
HeaderFile=WebBrowser.h
ImplementationFile=WebBrowser.cpp
Filter=N

[CLS:CWebBrowserDoc]
Type=0
HeaderFile=WebBrowserDoc.h
ImplementationFile=WebBrowserDoc.cpp
Filter=N

[CLS:CWebBrowserView]
Type=0
HeaderFile=WebBrowserView.h
ImplementationFile=WebBrowserView.cpp
Filter=C
LastObject=CWebBrowserView
BaseClass=CHtmlView
VirtualFilter=7VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_APP_EXIT




[CLS:CAboutDlg]
Type=0
HeaderFile=WebBrowser.cpp
ImplementationFile=WebBrowser.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=IDM_MENU_REFRESH
Command2=ID_APP_EXIT
Command3=ID_APP_ABOUT
CommandCount=3

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_REFRESH_DIALOG]
Type=1
Class=RefreshDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT,edit,1350631556

[CLS:RefreshDlg]
Type=0
HeaderFile=RefreshDlg.h
ImplementationFile=RefreshDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_APP_ABOUT
VirtualFilter=dWC

