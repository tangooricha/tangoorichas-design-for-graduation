#if !defined(AFX_REFRESHDLG_H__C15D375C_2D8B_427B_ABBB_F7F42ACAFCD5__INCLUDED_)
#define AFX_REFRESHDLG_H__C15D375C_2D8B_427B_ABBB_F7F42ACAFCD5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RefreshDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RefreshDlg dialog

class RefreshDlg : public CDialog
{
// Construction
public:
	RefreshDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(RefreshDlg)
	enum { IDD = IDD_REFRESH_DIALOG };
	CString	m_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RefreshDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(RefreshDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REFRESHDLG_H__C15D375C_2D8B_427B_ABBB_F7F42ACAFCD5__INCLUDED_)
