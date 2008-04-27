// Network Talk Client.h : main header file for the NETWORK TALK CLIENT application
//

#if !defined(AFX_NETWORKTALKCLIENT_H__E8C51A56_2DA0_4E6F_AE34_977DAB9F0929__INCLUDED_)
#define AFX_NETWORKTALKCLIENT_H__E8C51A56_2DA0_4E6F_AE34_977DAB9F0929__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNetworkTalkClientApp:
// See Network Talk Client.cpp for the implementation of this class
//

class CNetworkTalkClientApp : public CWinApp
{
public:
	CNetworkTalkClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetworkTalkClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNetworkTalkClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETWORKTALKCLIENT_H__E8C51A56_2DA0_4E6F_AE34_977DAB9F0929__INCLUDED_)
