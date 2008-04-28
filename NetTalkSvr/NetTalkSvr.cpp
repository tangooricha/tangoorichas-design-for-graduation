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
		char tmpBuffer[65536];
		SOCKET server,client[8],clientTmp;
		sockaddr_in serverAddr,clientAddr[8],clientAddrTmp;
		int clientAddrLenth=sizeof(clientAddrTmp);
		int clientCounter=0;
		int indexI;
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

		while(true)
		{
			int sameClient=0;
			clientTmp=accept(server,(struct sockaddr *)&clientAddrTmp,&clientAddrLenth);
			for(indexI=0;indexI<clientCounter;indexI++)
			{
				if(clientTmp==client[indexI])
					sameClient=1;
			}
			if(sameClient==0)
			{
				client[clientCounter]=clientTmp;
				memcpy(&clientAddr[clientCounter],&clientAddrTmp,sizeof(clientAddrTmp));
			}
			clientCounter++;
			recv(server,tmpBuffer,65535,0);
			for(indexI=0;indexI<=clientCounter;indexI++)
				send(client[indexI],tmpBuffer,strlen(tmpBuffer),0);
		}

	}

	return nRetCode;
}


