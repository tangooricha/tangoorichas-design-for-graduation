; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSMTPServerDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SMTPServer.h"

ClassCount=4
Class1=CSMTPServerApp
Class2=CSMTPServerDlg

ResourceCount=3
Resource2=IDR_MAINFRAME
Resource3=IDD_SMTPSERVER_DIALOG

[CLS:CSMTPServerApp]
Type=0
HeaderFile=SMTPServer.h
ImplementationFile=SMTPServer.cpp
Filter=N

[CLS:CSMTPServerDlg]
Type=0
HeaderFile=SMTPServerDlg.h
ImplementationFile=SMTPServerDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_SMTPSERVER_DIALOG]
Type=1
Class=CSMTPServerDlg
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BTN_STRAT,button,1342242816

