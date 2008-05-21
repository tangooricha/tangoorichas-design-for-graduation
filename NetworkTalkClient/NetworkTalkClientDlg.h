// NetworkTalkClientDlg.h : header file
//

#if !defined(AFX_NETWORKTALKCLIENTDLG_H__FDD80709_1857_44BB_9B03_84FA9A797522__INCLUDED_)
#define AFX_NETWORKTALKCLIENTDLG_H__FDD80709_1857_44BB_9B03_84FA9A797522__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WM_RECVDATA WM_USER+1

/////////////////////////////////////////////////////////////////////////////
// CNetworkTalkClientDlg dialog

class CNetworkTalkClientDlg : public CDialog
{
// Construction
public:
	CNetworkTalkClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNetworkTalkClientDlg)
	enum { IDD = IDD_NETWORKTALKCLIENT_DIALOG };
	CString	m_serverIPAddress;
	CString	m_recvText;
	CString	m_sendText;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetworkTalkClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNetworkTalkClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnSend();
	//}}AFX_MSG
	afx_msg LRESULT OnRecvData(WPARAM,LPARAM);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETWORKTALKCLIENTDLG_H__FDD80709_1857_44BB_9B03_84FA9A797522__INCLUDED_)
