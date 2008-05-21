// NetworkTalkServer.h : main header file for the NETWORKTALKSERVER application
//

#if !defined(AFX_NETWORKTALKSERVER_H__E7EC3DAC_245D_45F4_A8F4_0E5F01AEC2A9__INCLUDED_)
#define AFX_NETWORKTALKSERVER_H__E7EC3DAC_245D_45F4_A8F4_0E5F01AEC2A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNetworkTalkServerApp:
// See NetworkTalkServer.cpp for the implementation of this class
//

class CNetworkTalkServerApp : public CWinApp
{
public:
	CNetworkTalkServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetworkTalkServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNetworkTalkServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETWORKTALKSERVER_H__E7EC3DAC_245D_45F4_A8F4_0E5F01AEC2A9__INCLUDED_)
