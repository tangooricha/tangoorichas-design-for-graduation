// NetworkTalkServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetworkTalkServer.h"
#include "NetworkTalkServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNetworkTalkServerDlg dialog

CNetworkTalkServerDlg::CNetworkTalkServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNetworkTalkServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNetworkTalkServerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNetworkTalkServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNetworkTalkServerDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNetworkTalkServerDlg, CDialog)
	//{{AFX_MSG_MAP(CNetworkTalkServerDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_START, OnBtnStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetworkTalkServerDlg message handlers

BOOL CNetworkTalkServerDlg::OnInitDialog()
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

void CNetworkTalkServerDlg::OnPaint() 
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
HCURSOR CNetworkTalkServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CNetworkTalkServerDlg::OnBtnStart() 
{
	// TODO: Add your control notification handler code here
	CSocket sockSrv,sockConnect,sockClient1,sockClient2;
	CString clientIPAddress,clientData;
	UINT clientPort;
	int bClientUse[2]={0};
	char charClientIPAddress1[16]={0};
	char charClientIPAddress2[16]={0};
	int indexI;
	char recvBuffer[65536];

	sockSrv.Create(8000);
	sockSrv.Listen();
	while(true)
	{
		sockSrv.Accept(sockConnect);
		sockConnect.GetPeerName(clientIPAddress,clientPort);
		if(bClientUse[0]==0&&bClientUse[1]==0)
		{
			lstrcpy(charClientIPAddress1,clientIPAddress);
			bClientUse[0]=1;
		}
		else if(bClientUse[0]==1&&bClientUse[1]==0)
		{
			if(clientIPAddress!=charClientIPAddress1)
			{
				lstrcpy(charClientIPAddress2,clientIPAddress);
				bClientUse[1]=1;
			}
		}
		else if(bClientUse[1]==1&&bClientUse[1]==0)
		{
			if((clientIPAddress!=charClientIPAddress1)&&(clientIPAddress!=charClientIPAddress2))
			{
				sockConnect.Close();
			}
		}
		for(indexI=0;indexI<65536;indexI++)
		{
			recvBuffer[indexI]='\0';
		}
		sockConnect.Receive(recvBuffer,65536);
		clientData=recvBuffer;
		if(bClientUse[0]==1)
		{
			sockClient1.Create();
			clientIPAddress=charClientIPAddress1;
			sockClient1.Connect(clientIPAddress,4000);
			sockClient1.Send(clientData,clientData.GetLength());
			sockClient1.Close();
		}
		if(bClientUse[1]==1)
		{
			sockClient2.Create();
			clientIPAddress=charClientIPAddress2;
			sockClient1.Connect(clientIPAddress,4000);
			sockClient2.Send(clientData,clientData.GetLength());
			sockClient2.Close();
		}
	}
	
}
