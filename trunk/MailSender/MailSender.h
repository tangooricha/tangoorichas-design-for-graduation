// MailSender.h : main header file for the MAILSENDER application
//

#if !defined(AFX_MAILSENDER_H__BC134BB5_E674_448F_AFA3_719D1322048F__INCLUDED_)
#define AFX_MAILSENDER_H__BC134BB5_E674_448F_AFA3_719D1322048F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMailSenderApp:
// See MailSender.cpp for the implementation of this class
//

class CMailSenderApp : public CWinApp
{
public:
	CMailSenderApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMailSenderApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMailSenderApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAILSENDER_H__BC134BB5_E674_448F_AFA3_719D1322048F__INCLUDED_)
