// WebBrowserView.h : interface of the CWebBrowserView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WEBBROWSERVIEW_H__06488E66_D224_442B_BF22_8BED062A18A5__INCLUDED_)
#define AFX_WEBBROWSERVIEW_H__06488E66_D224_442B_BF22_8BED062A18A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "RefreshDlg.h"


class CWebBrowserView : public CHtmlView
{
protected: // create from serialization only
	CWebBrowserView();
	DECLARE_DYNCREATE(CWebBrowserView)

// Attributes
public:
	CWebBrowserDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWebBrowserView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	RefreshDlg refreshDlg;
	TCHAR URLString[1024];
	virtual ~CWebBrowserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWebBrowserView)
	afx_msg void OnMenuRefresh();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in WebBrowserView.cpp
inline CWebBrowserDoc* CWebBrowserView::GetDocument()
   { return (CWebBrowserDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEBBROWSERVIEW_H__06488E66_D224_442B_BF22_8BED062A18A5__INCLUDED_)
