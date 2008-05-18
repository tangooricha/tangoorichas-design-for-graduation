// MailSenderDlg.h : header file
//

#if !defined(AFX_MAILSENDERDLG_H__AAA5B744_3C78_4B74_95AD_92E4A44403FB__INCLUDED_)
#define AFX_MAILSENDERDLG_H__AAA5B744_3C78_4B74_95AD_92E4A44403FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMailSenderDlg dialog

class CMailSenderDlg : public CDialog
{
// Construction
public:
	CMailSenderDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMailSenderDlg)
	enum { IDD = IDD_MAILSENDER_DIALOG };
	CString	m_from;
	CString	m_serverIPAddress;
	CString	m_mailContent;
	CString	m_subject;
	CString	m_to;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMailSenderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMailSenderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAILSENDERDLG_H__AAA5B744_3C78_4B74_95AD_92E4A44403FB__INCLUDED_)
