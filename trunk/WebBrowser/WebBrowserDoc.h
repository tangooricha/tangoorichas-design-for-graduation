// WebBrowserDoc.h : interface of the CWebBrowserDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WEBBROWSERDOC_H__BF63E288_7A20_4994_97CB_BD7648D96FD3__INCLUDED_)
#define AFX_WEBBROWSERDOC_H__BF63E288_7A20_4994_97CB_BD7648D96FD3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWebBrowserDoc : public CDocument
{
protected: // create from serialization only
	CWebBrowserDoc();
	DECLARE_DYNCREATE(CWebBrowserDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWebBrowserDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWebBrowserDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWebBrowserDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEBBROWSERDOC_H__BF63E288_7A20_4994_97CB_BD7648D96FD3__INCLUDED_)
