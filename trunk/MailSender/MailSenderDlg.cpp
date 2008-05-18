// MailSenderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MailSender.h"
#include "MailSenderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMailSenderDlg dialog

CMailSenderDlg::CMailSenderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMailSenderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMailSenderDlg)
	m_from = _T("");
	m_serverIPAddress = _T("");
	m_mailContent = _T("");
	m_subject = _T("");
	m_to = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMailSenderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMailSenderDlg)
	DDX_Text(pDX, IDC_EDIT_FROM, m_from);
	DDX_Text(pDX, IDC_EDIT_IP, m_serverIPAddress);
	DDX_Text(pDX, IDC_EDIT_MAIL, m_mailContent);
	DDX_Text(pDX, IDC_EDIT_SUBJECT, m_subject);
	DDX_Text(pDX, IDC_EDIT_TO, m_to);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMailSenderDlg, CDialog)
	//{{AFX_MSG_MAP(CMailSenderDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SEND, OnBtnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMailSenderDlg message handlers

BOOL CMailSenderDlg::OnInitDialog()
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

void CMailSenderDlg::OnPaint() 
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
HCURSOR CMailSenderDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMailSenderDlg::OnBtnSend() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CSocket sockClient;
	CString clientIPAddress,statusCode,clientData,fromName,toName;
	UINT clientPort;
	int indexI,fromLength,toLength,fromNameLength,toNameLength;
	TCHAR recvBuffer[2048];

	sockClient.Create();
	sockClient.Connect((LPCTSTR) m_serverIPAddress,25);

	sockClient.GetSockName(clientIPAddress,clientPort);


	for(indexI=0;indexI<2048;indexI++)
	{
		recvBuffer[indexI]='\0';
	}
	sockClient.Receive(recvBuffer,2048);

	recvBuffer[3]='\0';
	statusCode=recvBuffer;
	if(statusCode!="220")
		return;


	clientData="HELO "+clientIPAddress+"\t\n";
	sockClient.Send(clientData,clientData.GetLength());

	for(indexI=0;indexI<2048;indexI++)
	{
		recvBuffer[indexI]='\0';
	}
	sockClient.Receive(recvBuffer,2048);

	recvBuffer[3]='\0';
	statusCode=recvBuffer;
	if(statusCode!="250")
		return;


	clientData="MAIL FROM: <"+m_from+">\t\n";
	sockClient.Send(clientData,clientData.GetLength());

	for(indexI=0;indexI<2048;indexI++)
	{
		recvBuffer[indexI]='\0';
	}
	sockClient.Receive(recvBuffer,2048);

	recvBuffer[3]='\0';
	statusCode=recvBuffer;
	if(statusCode!="250")
		return;


	clientData="RCPT TO: <"+m_from+">\t\n";
	sockClient.Send(clientData,clientData.GetLength());

	for(indexI=0;indexI<2048;indexI++)
	{
		recvBuffer[indexI]='\0';
	}
	sockClient.Receive(recvBuffer,2048);

	recvBuffer[3]='\0';
	statusCode=recvBuffer;
	if(statusCode!="250")
		return;


	clientData="Data\t\n";
	sockClient.Send(clientData,clientData.GetLength());

	for(indexI=0;indexI<2048;indexI++)
	{
		recvBuffer[indexI]='\0';
	}
	sockClient.Receive(recvBuffer,2048);

	recvBuffer[3]='\0';
	statusCode=recvBuffer;
	if(statusCode!="354")
		return;

	
	fromLength=m_from.GetLength();
	toLength=m_to.GetLength();
	fromName=m_from;
	toName=m_to;
	fromNameLength=fromName.Find('@');
	toNameLength=toName.Find('@');
	fromName.Delete(fromNameLength,fromLength-fromNameLength);
	toName.Delete(toNameLength,toLength-toNameLength);

	clientData="From: \""+fromName+"\" <";
	clientData+=m_from+">\t\n";
	clientData+="To: \""+toName+"\" <";
	clientData+=m_to+">\t\n";
	clientData+="Subject: "+m_subject;
	clientData+="Mime-Version: 1.0\t\nContent-Type: text\\/plain;\t\n.charset=\"gb2312\"\t\nContent-Transfer-Encoding: 7bit\t\n\t\n";
	clientData+=m_mailContent;
	clientData+="\t\n.\t\n";

	sockClient.Send(clientData,clientData.GetLength());

	for(indexI=0;indexI<2048;indexI++)
	{
		recvBuffer[indexI]='\0';
	}
	sockClient.Receive(recvBuffer,2048);

	recvBuffer[3]='\0';
	statusCode=recvBuffer;
	if(statusCode!="250")
		return;

	clientData="QUIT\t\n";
	sockClient.Send(clientData,clientData.GetLength());

	sockClient.Close();
	
}
