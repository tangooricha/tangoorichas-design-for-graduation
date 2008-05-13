// WebBrowserView.cpp : implementation of the CWebBrowserView class
//

#include "stdafx.h"
#include "WebBrowser.h"

#include "WebBrowserDoc.h"
#include "WebBrowserView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWebBrowserView

IMPLEMENT_DYNCREATE(CWebBrowserView, CHtmlView)

BEGIN_MESSAGE_MAP(CWebBrowserView, CHtmlView)
	//{{AFX_MSG_MAP(CWebBrowserView)
	ON_COMMAND(IDM_MENU_REFRESH, OnMenuRefresh)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWebBrowserView construction/destruction

CWebBrowserView::CWebBrowserView()
{
	// TODO: add construction code here

}

CWebBrowserView::~CWebBrowserView()
{
}

BOOL CWebBrowserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWebBrowserView drawing

void CWebBrowserView::OnDraw(CDC* pDC)
{
	CWebBrowserDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CWebBrowserView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	// TODO: This code navigates to a popular spot on the web.
	//  change the code to go where you'd like.
	Navigate2(_T("http://www.google.cn/"),NULL,NULL);
}

/////////////////////////////////////////////////////////////////////////////
// CWebBrowserView diagnostics

#ifdef _DEBUG
void CWebBrowserView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CWebBrowserView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CWebBrowserDoc* CWebBrowserView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWebBrowserDoc)));
	return (CWebBrowserDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWebBrowserView message handlers

void CWebBrowserView::OnMenuRefresh() 
{
	// TODO: Add your command handler code here
	if(refreshDlg.DoModal()==IDOK)
	{
		lstrcpy(URLString,refreshDlg.m_edit);
		Navigate(URLString);
	}
	
}
