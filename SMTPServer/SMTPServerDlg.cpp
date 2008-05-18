// SMTPServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SMTPServer.h"
#include "SMTPServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSMTPServerDlg dialog

CSMTPServerDlg::CSMTPServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSMTPServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSMTPServerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSMTPServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSMTPServerDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSMTPServerDlg, CDialog)
	//{{AFX_MSG_MAP(CSMTPServerDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_STRAT, OnBtnStrat)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSMTPServerDlg message handlers

BOOL CSMTPServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSMTPServerDlg::OnPaint() 
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
HCURSOR CSMTPServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSMTPServerDlg::OnBtnStrat() 
{
	// TODO: Add your control notification handler code here
	CSocket sockSrv,sockConnect;
	CString serverIPAddress,serverData,clientData,clientCommand,clientCommandData,clientHELOHost,mailFromAccount,mailToAccount,theEMail,eMailFileName,eMailFileNameTmp;
	UINT serverPort;
	TCHAR recvBuffer[2048],mailContent[65536],charEMailFileName[256];
	int clientDataLength,clientDataTmp,clientCommandLength,theEMailLength,mailContentLength,indexI;

	sockSrv.Create(25);
	sockSrv.Listen();
	sockSrv.Accept(sockConnect);

	sockConnect.GetSockName(serverIPAddress,serverPort);	

	serverData="220 "+serverIPAddress+" Earthquake SMTP Server\t\n";
	sockConnect.Send(serverData,serverData.GetLength());

	do
	{
		sockConnect.Receive(recvBuffer,2048);
		clientData=recvBuffer;
		clientDataLength=clientData.Find('\t');
		clientDataTmp=clientData.GetLength();
		clientData.Delete(clientDataLength,clientDataTmp-clientDataLength);

		clientCommand=clientData;
		clientCommandData=clientData;
		clientCommandLength=clientData.Find(' ');
		if(clientCommandLength==-1)
		{
			clientCommandLength=clientCommand.GetLength();
			clientCommandData="";
		}
		else
		{
			clientCommand.Delete(clientCommandLength,clientDataLength-clientCommandLength);
			clientCommandData.Delete(0,clientCommandLength+1);
		}

		if(clientCommand=="HELO")
		{
			clientHELOHost=clientCommandData;
			serverData="250-"+serverIPAddress+"\t\n";
			sockConnect.Send(serverData,serverData.GetLength());
		}
		else if(clientCommand=="MAIL")
		{
			mailFromAccount=clientCommandData;
			serverData="250 OK\t\n";
			sockConnect.Send(serverData,serverData.GetLength());
		}
		else if(clientCommand=="RCPT")
		{
			mailToAccount=clientCommandData;
			serverData="250 OK\t\n";
			sockConnect.Send(serverData,serverData.GetLength());
		}
		else if(clientCommand=="Data")
		{
			serverData="354 End data with <CR><LF>.<CR><LF>\t\n";
			sockConnect.Send(serverData,serverData.GetLength());
			sockConnect.Receive(mailContent,65536);
			theEMail=mailContent;
			theEMailLength=theEMail.Find("\t\n.\t\n");
			mailContentLength=theEMail.GetLength();
			theEMail.Delete(theEMailLength,mailContentLength-theEMailLength);

			CTime eMailFileTime=CTime::GetCurrentTime();
			eMailFileName=eMailFileTime.Format("%A,%B%d,%Y,%H%M%S");
			eMailFileName+=".eml";
			eMailFileName="C:\\mailpool\\"+eMailFileName;
			for(indexI=0;indexI<256;indexI++)
			{
				charEMailFileName[indexI]='\0';
			}
			lstrcpy(charEMailFileName,eMailFileName);

			CFile eMailFile((LPCTSTR)charEMailFileName,CFile::modeCreate|CFile::modeReadWrite/*|CFile::shareExclusive|CFile::typeBinary*/);
			for(indexI=0;indexI<65536;indexI++)
			{
				mailContent[indexI]='\0';
			}
			lstrcpy(mailContent,theEMail);
			theEMailLength=theEMail.GetLength();
			eMailFile.Write(mailContent,theEMailLength);
			eMailFile.Close();
			serverData="250 OK\t\n";
			sockConnect.Send(serverData,serverData.GetLength());

		}
		else if(clientCommand=="QUIT")
		{
			serverData="221 Bye\t\n";
			sockConnect.Send(serverData,serverData.GetLength());
		}

	}while(clientCommand!="QUIT");
	
}
