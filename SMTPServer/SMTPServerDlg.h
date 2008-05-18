// SMTPServerDlg.h : header file
//

#if !defined(AFX_SMTPSERVERDLG_H__E4A290D2_C5F4_4869_BC8C_5C2C8840557E__INCLUDED_)
#define AFX_SMTPSERVERDLG_H__E4A290D2_C5F4_4869_BC8C_5C2C8840557E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSMTPServerDlg dialog

class CSMTPServerDlg : public CDialog
{
// Construction
public:
	CSMTPServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSMTPServerDlg)
	enum { IDD = IDD_SMTPSERVER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSMTPServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSMTPServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnStrat();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SMTPSERVERDLG_H__E4A290D2_C5F4_4869_BC8C_5C2C8840557E__INCLUDED_)
