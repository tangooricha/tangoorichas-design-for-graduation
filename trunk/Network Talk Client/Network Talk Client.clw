; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNetworkTalkClientDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Network Talk Client.h"

ClassCount=3
Class1=CNetworkTalkClientApp
Class2=CNetworkTalkClientDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_NETWORKTALKCLIENT_DIALOG

[CLS:CNetworkTalkClientApp]
Type=0
HeaderFile=Network Talk Client.h
ImplementationFile=Network Talk Client.cpp
Filter=N

[CLS:CNetworkTalkClientDlg]
Type=0
HeaderFile=Network Talk ClientDlg.h
ImplementationFile=Network Talk ClientDlg.cpp
Filter=D
LastObject=CNetworkTalkClientDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=Network Talk ClientDlg.h
ImplementationFile=Network Talk ClientDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_NETWORKTALKCLIENT_DIALOG]
Type=1
Class=CNetworkTalkClientDlg
ControlCount=10
Control1=IDC_STATIC,button,1342177287
Control2=IDC_IPADDRESS2,SysIPAddress32,1342242816
Control3=IDC_BTN_CONNECT,button,1342242816
Control4=ID_APP_EXIT,button,1342242816
Control5=IDC_STATIC,button,1342177287
Control6=IDC_EDIT_RECEIVE,edit,1350633604
Control7=IDC_STATIC,button,1342177287
Control8=IDC_EDIT_SEND,edit,1350631556
Control9=IDC_BTN_SEND,button,1342242816
Control10=IDC_STATIC,static,1342308352

