// POPServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "POPServer.h"
#include "POPServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPOPServerDlg dialog

CPOPServerDlg::CPOPServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPOPServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPOPServerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPOPServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPOPServerDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPOPServerDlg, CDialog)
	//{{AFX_MSG_MAP(CPOPServerDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_START, OnBtnStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPOPServerDlg message handlers

BOOL CPOPServerDlg::OnInitDialog()
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

void CPOPServerDlg::OnPaint() 
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
HCURSOR CPOPServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPOPServerDlg::OnBtnStart() 
{
	// TODO: Add your control notification handler code here
	CSocket sockSrv,sockConnect;
	CString serverIPAddress,serverData,clientData,clientCommand,clientCommandData,clientHELOHost,mailFromAccount,mailToAccount,theEMail,eMailFileName,eMailFileNameTmp,stringFileNumberCount,stringFileByteCount;
	UINT serverPort;
	TCHAR recvBuffer[2048],mailContent[65536],charEMailFileName[256];
	int clientDataLength,clientDataTmp,clientCommandLength,theEMailLength,indexI;
	CFileFind finder;
	int fileNumberCount;
	DWORD fileByteCount=0;

	sockSrv.Create(110);
	sockSrv.Listen();
	sockSrv.Accept(sockConnect);

	sockConnect.GetSockName(serverIPAddress,serverPort);	

	serverData="+OK Earthquake pop3 server ready\t\n";
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

		if(clientCommand=="STAT")
		{
			fileNumberCount=0;
			BOOL bWorking = finder.FindFile("C:\\mailpool\\*.eml");
			while (bWorking)
			{
				bWorking = finder.FindNextFile();
				if (finder.IsDots())
					continue;
				fileNumberCount++;
				fileByteCount+=finder.GetLength();
			}
			finder.Close();
			stringFileNumberCount.Format("%d",fileNumberCount);
			stringFileByteCount.Format("%d",fileByteCount);
			serverData="+OK "+stringFileNumberCount+' '+stringFileByteCount;
			serverData+="\t\n";
			sockConnect.Send(serverData,serverData.GetLength());
		}
		else if(clientCommand=="LIST")
		{
			serverData="+OK\t\n";
			fileNumberCount=0;
			BOOL bWorking = finder.FindFile("C:\\mailpool\\*.eml");
			while (bWorking)
			{
				bWorking = finder.FindNextFile();
				if (finder.IsDots())
					continue;
				fileNumberCount++;
				fileByteCount=finder.GetLength();
				stringFileNumberCount.Format("%d",fileNumberCount);
				stringFileByteCount.Format("%d",fileByteCount);
				serverData+=stringFileNumberCount+' '+stringFileByteCount+"\t\n";
			}
			finder.Close();
			serverData+="\t\n.\t\n";
			sockConnect.Send(serverData,serverData.GetLength());
		}
		else if(clientCommand=="RETR")
		{
			finder.FindFile("C:\\mailpool\\*.eml");
			finder.FindNextFile();
			eMailFileName=finder.GetFilePath();
			for(indexI=0;indexI<256;indexI++)
			{
				charEMailFileName[indexI]='\0';
			}
			lstrcpy(charEMailFileName,eMailFileName);
			CFile eMailFile((LPCTSTR)charEMailFileName,CFile::modeReadWrite);
			for(indexI=0;indexI<65536;indexI++)
			{
				mailContent[indexI]='\0';
			}
			theEMailLength=eMailFile.GetLength();
			eMailFile.Read(mailContent,theEMailLength);
			eMailFile.Close();
			theEMail=mailContent;
			serverData="+OK \t\n"+theEMail+"\t\n.\t\n";
			sockConnect.Send(serverData,serverData.GetLength());
		}
		else if(clientCommand=="DELE")
		{
			serverData="+OK \t\n";
			sockConnect.Send(serverData,serverData.GetLength());
		}
		else if(clientCommand=="QUIT")
		{
			serverData="+OK \t\n";
			sockConnect.Send(serverData,serverData.GetLength());
		}

	}while(clientCommand!="QUIT");
	
}
