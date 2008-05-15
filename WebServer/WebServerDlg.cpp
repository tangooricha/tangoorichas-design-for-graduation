// WebServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WebServer.h"
#include "WebServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWebServerDlg dialog

CWebServerDlg::CWebServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWebServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWebServerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWebServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWebServerDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWebServerDlg, CDialog)
	//{{AFX_MSG_MAP(CWebServerDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_START, OnBtnStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWebServerDlg message handlers

BOOL CWebServerDlg::OnInitDialog()
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

void CWebServerDlg::OnPaint() 
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
HCURSOR CWebServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWebServerDlg::OnBtnStart() 
{
	// TODO: Add your control notification handler code here
	CSocket sockSrv,sockConnect;
	int indexI,recvByteCounterCurrent,requestDataLength,httpMethodLength,requestPagePathLength,httpVersionLength;
	TCHAR recvBufferTmp[2048],recvBuffer[2048],*pRecvByteTmp,*pRecvByte,*pRecvByteCurrent,webPageFileContent[65536];
	CString requestData,requestDataTmp,httpMethod,requestPagePath,httpVersion,webPage200,webPage404,sendData;
	CFileFind webPageFileFind;
	CFile webPageFile;
	DWORD webPageFileLength;

	pRecvByte=recvBuffer;
	pRecvByteCurrent=recvBuffer;

	sockSrv.Create(8080);
	sockSrv.Listen();
	sockSrv.Accept(sockConnect);

	for(indexI=0;indexI!=1;)
	{
		recvByteCounterCurrent=0;
		pRecvByteTmp=recvBufferTmp;
		recvByteCounterCurrent=sockConnect.Receive(recvBufferTmp,2048);
		pRecvByteCurrent+=recvByteCounterCurrent;
		for(;pRecvByte!=pRecvByteCurrent;pRecvByteTmp++,pRecvByte++)
		{
			*pRecvByte=*pRecvByteTmp;
			if(*pRecvByte=='\r')
			{
				indexI=1;
				break;
			}
		}
	}
	
	pRecvByte++;
	*pRecvByte='\0';

	requestData=recvBuffer;

	requestDataLength=requestData.GetLength();
	requestDataTmp=requestData;
	httpMethodLength=requestData.Find(' ');
	requestDataTmp.Delete(httpMethodLength,requestDataLength-httpMethodLength);
	httpMethod=requestDataTmp;
	requestData.Delete(0,httpMethodLength+1);

	requestDataLength=requestData.GetLength();
	requestDataTmp=requestData;
	requestPagePathLength=requestData.Find(' ');
	requestDataTmp.Delete(requestPagePathLength,requestDataLength-requestPagePathLength);
	requestPagePath=requestDataTmp;
	requestData.Delete(0,requestPagePathLength+1);

	requestDataLength=requestData.GetLength();
	requestDataTmp=requestData;
	httpVersionLength=8;
	requestDataTmp.Delete(httpVersionLength,requestDataLength-httpVersionLength);
	httpVersion=requestDataTmp;

	webPage200=httpVersion+" 200 OK\t\nContent-Type: text/html; charset=UTF-8\t\nServer: Earthquake Web Server\t\n\t\n";
	webPage404=httpVersion+" 404 Not Found";

	requestPagePath.Replace('/','\\');
	if(requestPagePath=='\\')
	{
		requestPagePath="\\index.html";
	}

	if(webPageFileFind.FindFile(requestPagePath))
	{
		webPageFile.Open(requestPagePath,CFile::modeRead|CFile::typeBinary);
		webPageFileLength=webPageFile.GetLength();
		webPageFile.Read(webPageFileContent,(UINT)webPageFileLength-1);
		sendData=webPage200+webPageFileContent;
	}
	else
	{
		sendData=webPage404;
	}
	sockConnect.Send(sendData,sendData.GetLength());
	
}
