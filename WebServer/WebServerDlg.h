// WebServerDlg.h : header file
//

#if !defined(AFX_WEBSERVERDLG_H__417E853F_0BDC_4055_815F_F89169B2D019__INCLUDED_)
#define AFX_WEBSERVERDLG_H__417E853F_0BDC_4055_815F_F89169B2D019__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWebServerDlg dialog

class CWebServerDlg : public CDialog
{
// Construction
public:
	CWebServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWebServerDlg)
	enum { IDD = IDD_WEBSERVER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWebServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWebServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEBSERVERDLG_H__417E853F_0BDC_4055_815F_F89169B2D019__INCLUDED_)
