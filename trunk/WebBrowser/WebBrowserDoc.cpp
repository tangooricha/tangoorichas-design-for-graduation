// WebBrowserDoc.cpp : implementation of the CWebBrowserDoc class
//

#include "stdafx.h"
#include "WebBrowser.h"

#include "WebBrowserDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWebBrowserDoc

IMPLEMENT_DYNCREATE(CWebBrowserDoc, CDocument)

BEGIN_MESSAGE_MAP(CWebBrowserDoc, CDocument)
	//{{AFX_MSG_MAP(CWebBrowserDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWebBrowserDoc construction/destruction

CWebBrowserDoc::CWebBrowserDoc()
{
	// TODO: add one-time construction code here

}

CWebBrowserDoc::~CWebBrowserDoc()
{
}

BOOL CWebBrowserDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWebBrowserDoc serialization

void CWebBrowserDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWebBrowserDoc diagnostics

#ifdef _DEBUG
void CWebBrowserDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWebBrowserDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWebBrowserDoc commands
