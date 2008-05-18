// SMTPServer.h : main header file for the SMTPSERVER application
//

#if !defined(AFX_SMTPSERVER_H__629D5682_2A00_43D6_9356_C140A933410D__INCLUDED_)
#define AFX_SMTPSERVER_H__629D5682_2A00_43D6_9356_C140A933410D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSMTPServerApp:
// See SMTPServer.cpp for the implementation of this class
//

class CSMTPServerApp : public CWinApp
{
public:
	CSMTPServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSMTPServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSMTPServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SMTPSERVER_H__629D5682_2A00_43D6_9356_C140A933410D__INCLUDED_)
