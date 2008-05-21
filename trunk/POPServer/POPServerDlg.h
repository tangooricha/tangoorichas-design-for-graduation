// POPServerDlg.h : header file
//

#if !defined(AFX_POPSERVERDLG_H__98D44060_4AE5_47C1_B2EB_A341213C9475__INCLUDED_)
#define AFX_POPSERVERDLG_H__98D44060_4AE5_47C1_B2EB_A341213C9475__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPOPServerDlg dialog

class CPOPServerDlg : public CDialog
{
// Construction
public:
	CPOPServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPOPServerDlg)
	enum { IDD = IDD_POPSERVER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPOPServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPOPServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPSERVERDLG_H__98D44060_4AE5_47C1_B2EB_A341213C9475__INCLUDED_)
