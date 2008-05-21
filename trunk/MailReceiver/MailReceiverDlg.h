// MailReceiverDlg.h : header file
//

#if !defined(AFX_MAILRECEIVERDLG_H__F23C34B3_B527_46FA_BDF7_71C647E1ECBF__INCLUDED_)
#define AFX_MAILRECEIVERDLG_H__F23C34B3_B527_46FA_BDF7_71C647E1ECBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMailReceiverDlg dialog

class CMailReceiverDlg : public CDialog
{
// Construction
public:
	CMailReceiverDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMailReceiverDlg)
	enum { IDD = IDD_MAILRECEIVER_DIALOG };
	CString	m_from;
	CString	m_mailContent;
	CString	m_subject;
	CString	m_to;
	CString	m_serverIPAddress;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMailReceiverDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMailReceiverDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnRecv();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAILRECEIVERDLG_H__F23C34B3_B527_46FA_BDF7_71C647E1ECBF__INCLUDED_)
