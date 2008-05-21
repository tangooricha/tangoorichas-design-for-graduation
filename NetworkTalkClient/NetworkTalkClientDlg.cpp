// NetworkTalkClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetworkTalkClient.h"
#include "NetworkTalkClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CNetworkTalkClientDlg dialog


CString g_serverIPAddress="";
CString g_serverData;
HWND g_hwnd;

UINT ServerConnect(LPVOID lpParameter)
{
	CSocket socksockClientSrv,sockConnect;
	CString serverIPAddress,serverData;
	UINT serverPort;
	int indexI;
	TCHAR recvBuffer[65536];
	HWND l_hwnd;

	socksockClientSrv.Create(4000);
	socksockClientSrv.Listen();
	while(true)
	{
		socksockClientSrv.Accept(sockConnect);
		sockConnect.GetPeerName(serverIPAddress,serverPort);
		if(serverIPAddress!=g_serverIPAddress)
		{
			sockConnect.Close();
		}
		for(indexI=0;indexI<65536;indexI++)
		{
			recvBuffer[indexI]='\0';
		}
		sockConnect.Receive(recvBuffer,65536);
		serverData=recvBuffer;
		g_serverData=serverData;
		l_hwnd=g_hwnd;
		::PostMessage(l_hwnd,WM_RECVDATA,0,0);
	}
	return 0;
}


CNetworkTalkClientDlg::CNetworkTalkClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNetworkTalkClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNetworkTalkClientDlg)
	m_serverIPAddress = _T("");
	m_recvText = _T("");
	m_sendText = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNetworkTalkClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNetworkTalkClientDlg)
	DDX_Text(pDX, IDC_EDIT_IP, m_serverIPAddress);
	DDX_Text(pDX, IDC_EDIT_RECV, m_recvText);
	DDX_Text(pDX, IDC_EDIT_SEND, m_sendText);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNetworkTalkClientDlg, CDialog)
	//{{AFX_MSG_MAP(CNetworkTalkClientDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SEND, OnBtnSend)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_RECVDATA,OnRecvData)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetworkTalkClientDlg message handlers

BOOL CNetworkTalkClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	g_hwnd=m_hWnd;
	LPVOID pParam=NULL;
	AfxBeginThread((AFX_THREADPROC)ServerConnect,pParam);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNetworkTalkClientDlg::OnPaint() 
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
HCURSOR CNetworkTalkClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CNetworkTalkClientDlg::OnBtnSend() 
{
	// TODO: Add your control notification handler code here
	CSocket sockClient;
	sockClient.Create();
	sockClient.Connect(m_serverIPAddress,8000);
	g_serverIPAddress=m_serverIPAddress;
	sockClient.Send(m_sendText,m_sendText.GetLength());
	sockClient.Close();
	
}

LRESULT CNetworkTalkClientDlg::OnRecvData(WPARAM wParam,LPARAM lParam)
{
	CString recvData;
	recvData=g_serverData+"\n";
	m_recvText+=recvData;
	UpdateData(false);
	return 0;
}
