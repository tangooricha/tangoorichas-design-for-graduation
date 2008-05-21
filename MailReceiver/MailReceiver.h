// MailReceiver.h : main header file for the MAILRECEIVER application
//

#if !defined(AFX_MAILRECEIVER_H__D333BC0F_E28E_486C_A1F3_446A03F93C08__INCLUDED_)
#define AFX_MAILRECEIVER_H__D333BC0F_E28E_486C_A1F3_446A03F93C08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMailReceiverApp:
// See MailReceiver.cpp for the implementation of this class
//

class CMailReceiverApp : public CWinApp
{
public:
	CMailReceiverApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMailReceiverApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMailReceiverApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAILRECEIVER_H__D333BC0F_E28E_486C_A1F3_446A03F93C08__INCLUDED_)
