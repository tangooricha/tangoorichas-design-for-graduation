// MailReceiverDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MailReceiver.h"
#include "MailReceiverDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMailReceiverDlg dialog

CMailReceiverDlg::CMailReceiverDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMailReceiverDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMailReceiverDlg)
	m_from = _T("");
	m_mailContent = _T("");
	m_subject = _T("");
	m_to = _T("");
	m_serverIPAddress = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMailReceiverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMailReceiverDlg)
	DDX_Text(pDX, IDC_EDIT_FROM, m_from);
	DDX_Text(pDX, IDC_EDIT_MAIL, m_mailContent);
	DDX_Text(pDX, IDC_EDIT_SUBJECT, m_subject);
	DDX_Text(pDX, IDC_EDIT_TO, m_to);
	DDX_Text(pDX, IDC_EDIT_IP, m_serverIPAddress);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMailReceiverDlg, CDialog)
	//{{AFX_MSG_MAP(CMailReceiverDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_RECV, OnBtnRecv)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMailReceiverDlg message handlers

BOOL CMailReceiverDlg::OnInitDialog()
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

void CMailReceiverDlg::OnPaint() 
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
HCURSOR CMailReceiverDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMailReceiverDlg::OnBtnRecv() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CSocket sockClient;
	CString clientIPAddress,statusCode,clientData,fromName,toName,theEMail;
	UINT clientPort;
	int indexI,fromLength,toLength,recvBufferLength,stringLength,subjectLength;
	TCHAR recvBuffer[65536];

	sockClient.Create();
	sockClient.Connect((LPCTSTR) m_serverIPAddress,110);

	sockClient.GetSockName(clientIPAddress,clientPort);


	for(indexI=0;indexI<65536;indexI++)
	{
		recvBuffer[indexI]='\0';
	}
	sockClient.Receive(recvBuffer,65536);

	recvBuffer[3]='\0';
	statusCode=recvBuffer;
	if(statusCode!="+OK")
		return;


	clientData="STAT\t\n";
	sockClient.Send(clientData,clientData.GetLength());

	for(indexI=0;indexI<65536;indexI++)
	{
		recvBuffer[indexI]='\0';
	}
	sockClient.Receive(recvBuffer,65536);

	recvBuffer[3]='\0';
	statusCode=recvBuffer;
	if(statusCode!="+OK")
		return;


	clientData="LIST\t\n";
	sockClient.Send(clientData,clientData.GetLength());

	for(indexI=0;indexI<65536;indexI++)
	{
		recvBuffer[indexI]='\0';
	}
	sockClient.Receive(recvBuffer,65536);

	recvBuffer[3]='\0';
	statusCode=recvBuffer;
	if(statusCode!="+OK")
		return;


	clientData="RETR 1\t\n";
	sockClient.Send(clientData,clientData.GetLength());

	for(indexI=0;indexI<65536;indexI++)
	{
		recvBuffer[indexI]='\0';
	}
	sockClient.Receive(recvBuffer,65536);

	statusCode=recvBuffer;
	theEMail=recvBuffer;
	recvBufferLength=theEMail.GetLength();
	statusCode.Delete(3,recvBufferLength-3);
	theEMail.Delete(0,4);
	if(statusCode!="+OK")
		return;

	m_from=theEMail;
	stringLength=m_from.Find("From: ");
	m_from.Delete(0,stringLength);
	fromLength=m_from.GetLength();
	stringLength=m_from.Find("\t\n");
	m_from.Delete(stringLength,fromLength-stringLength);

	m_to=theEMail;
	stringLength=m_to.Find("To: ");
	m_to.Delete(0,stringLength);
	toLength=m_to.GetLength();
	stringLength=m_to.Find("\t\n");
	m_to.Delete(stringLength,toLength-stringLength);

	m_subject=theEMail;
	stringLength=m_subject.Find("Subject: ");
	m_subject.Delete(0,stringLength);
	subjectLength=m_subject.GetLength();
	stringLength=m_subject.Find("\t\n");
	m_subject.Delete(stringLength,subjectLength-stringLength);

	m_mailContent=theEMail.Replace("\t\n","\n");

	UpdateData(false);


	clientData="DELE 1\t\n";
	sockClient.Send(clientData,clientData.GetLength());

	for(indexI=0;indexI<2048;indexI++)
	{
		recvBuffer[indexI]='\0';
	}
	sockClient.Receive(recvBuffer,2048);

	recvBuffer[3]='\0';
	statusCode=recvBuffer;
	if(statusCode!="+OK")
		return;


	clientData="QUIT\t\n";
	sockClient.Send(clientData,clientData.GetLength());

	sockClient.Close();
	
}
