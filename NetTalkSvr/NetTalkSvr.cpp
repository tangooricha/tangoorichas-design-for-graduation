// NetTalkSvr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NetTalkSvr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
		CString tmpBuffer;
		SOCKET server,client[8];
		sockaddr_in serverAddr,clientAddr[8];
		int serverAddrLenth=sizeof(serverAddr);
		int clientCounter=0;
		WSADATA wsaData;

		if(WSAStartup(MAKEWORD( 2, 2 ),&wsaData)!=0)
			return 0;

		serverAddr.sin_addr.s_addr=INADDR_ANY;
		serverAddr.sin_family=AF_INET;
		serverAddr.sin_port=htons(8000);

		if((server=socket(AF_INET,SOCK_STREAM,0))==INVALID_SOCKET)
			return 0;

		if(bind(server,(sockaddr*)&serverAddr,sizeof(serverAddr))!=0)
			return 0;

		if(listen(server,10)!=0)
			return 0;

	}

	return nRetCode;
}


