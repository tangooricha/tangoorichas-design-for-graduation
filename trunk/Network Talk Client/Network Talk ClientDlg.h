// Network Talk ClientDlg.h : header file
//

#if !defined(AFX_NETWORKTALKCLIENTDLG_H__0492A266_B84B_4493_9D77_94A577ED3386__INCLUDED_)
#define AFX_NETWORKTALKCLIENTDLG_H__0492A266_B84B_4493_9D77_94A577ED3386__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNetworkTalkClientDlg dialog

class CNetworkTalkClientDlg : public CDialog
{
// Construction
public:
	static UINT ThreadListenToServer(LPVOID pParam);
	CNetworkTalkClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNetworkTalkClientDlg)
	enum { IDD = IDD_NETWORKTALKCLIENT_DIALOG };
	CEdit	m_Edit_Receive;
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
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETWORKTALKCLIENTDLG_H__0492A266_B84B_4493_9D77_94A577ED3386__INCLUDED_)
