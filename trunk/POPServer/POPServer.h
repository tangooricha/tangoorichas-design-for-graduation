// POPServer.h : main header file for the POPSERVER application
//

#if !defined(AFX_POPSERVER_H__4823E82D_F139_47FA_9756_F8D2F7F4ED62__INCLUDED_)
#define AFX_POPSERVER_H__4823E82D_F139_47FA_9756_F8D2F7F4ED62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPOPServerApp:
// See POPServer.cpp for the implementation of this class
//

class CPOPServerApp : public CWinApp
{
public:
	CPOPServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPOPServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPOPServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPSERVER_H__4823E82D_F139_47FA_9756_F8D2F7F4ED62__INCLUDED_)
