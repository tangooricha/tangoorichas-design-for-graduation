// RefreshDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WebBrowser.h"
#include "RefreshDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RefreshDlg dialog


RefreshDlg::RefreshDlg(CWnd* pParent /*=NULL*/)
	: CDialog(RefreshDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(RefreshDlg)
	m_edit = _T("");
	//}}AFX_DATA_INIT
}


void RefreshDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(RefreshDlg)
	DDX_Text(pDX, IDC_EDIT, m_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(RefreshDlg, CDialog)
	//{{AFX_MSG_MAP(RefreshDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// RefreshDlg message handlers
