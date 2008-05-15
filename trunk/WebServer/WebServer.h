// WebServer.h : main header file for the WEBSERVER application
//

#if !defined(AFX_WEBSERVER_H__7E75F5C5_5C1C_4E06_AF40_64E6C60B43EF__INCLUDED_)
#define AFX_WEBSERVER_H__7E75F5C5_5C1C_4E06_AF40_64E6C60B43EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWebServerApp:
// See WebServer.cpp for the implementation of this class
//

class CWebServerApp : public CWinApp
{
public:
	CWebServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWebServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWebServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEBSERVER_H__7E75F5C5_5C1C_4E06_AF40_64E6C60B43EF__INCLUDED_)