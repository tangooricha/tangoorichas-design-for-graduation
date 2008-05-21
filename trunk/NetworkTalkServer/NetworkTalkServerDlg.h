// NetworkTalkServerDlg.h : header file
//

#if !defined(AFX_NETWORKTALKSERVERDLG_H__EB889A66_F63D_447C_8DF7_9319E76A4708__INCLUDED_)
#define AFX_NETWORKTALKSERVERDLG_H__EB889A66_F63D_447C_8DF7_9319E76A4708__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNetworkTalkServerDlg dialog

class CNetworkTalkServerDlg : public CDialog
{
// Construction
public:
	CNetworkTalkServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNetworkTalkServerDlg)
	enum { IDD = IDD_NETWORKTALKSERVER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetworkTalkServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNetworkTalkServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETWORKTALKSERVERDLG_H__EB889A66_F63D_447C_8DF7_9319E76A4708__INCLUDED_)
