
#include <stdio.h>
#include <windows.h>
SERVICE_STATUS m_ServiceStatus;
SERVICE_STATUS_HANDLE m_ServiceStatusHandle;
BOOL bRunning=true;
void WINAPI ServiceMain(DWORD argc, LPTSTR *argv);
void WINAPI ServiceCtrlHandler(DWORD Opcode);
void WINAPI CmdStart(void);
BOOL InstallService();
BOOL DeleteService();

int main(int argc, char* argv[])
{
	printf("\twindows based service demo\n");
	printf("\tgxisone@hotmail.com\n");
    if(argc!=3)
	{
		printf("usage: %s -install[remove]",argv[0]);
		return 0;
	}
		if(strcmp(argv[1],"-install")==0)
		{
			if(InstallService())
				printf("\n\nService Installed Sucessfully\n");
			else
				printf("\n\nError Installing Service\n");
		}
	else if(strcmp(argv[1],"-remove")==0)
		{
			if(DeleteService())
				printf("\n\nService remove sucessfully\n");
			else
				printf("\n\nError removing Service\n");
		} 
		else
		{
			printf("\nusage: %s -install[remove]\n",argv[0]);
			return 0;
		}

	SERVICE_TABLE_ENTRY DispatchTable[]={{"NetTalkSvr",ServiceMain},{NULL,NULL}};

	StartServiceCtrlDispatcher(DispatchTable); 
	return 0;
}

void WINAPI ServiceMain(DWORD argc, LPTSTR *argv)
{
	m_ServiceStatus.dwServiceType = SERVICE_WIN32;
	m_ServiceStatus.dwCurrentState = SERVICE_START_PENDING; 
	m_ServiceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP;
	m_ServiceStatus.dwWin32ExitCode = 0; 
	m_ServiceStatus.dwServiceSpecificExitCode = 0; 
	m_ServiceStatus.dwCheckPoint = 0; 
	m_ServiceStatus.dwWaitHint = 0;
	m_ServiceStatusHandle = RegisterServiceCtrlHandler("NetTalkSvr",ServiceCtrlHandler);
	if (m_ServiceStatusHandle == (SERVICE_STATUS_HANDLE)0)return; 
	m_ServiceStatus.dwCurrentState = SERVICE_RUNNING;
	m_ServiceStatus.dwCheckPoint = 0; 
	m_ServiceStatus.dwWaitHint = 0; 

	SetServiceStatus (m_ServiceStatusHandle, &m_ServiceStatus);
 	bRunning=true;
	//*
    CmdStart();
	//*
	return; 
}

void WINAPI ServiceCtrlHandler(DWORD Opcode)
{
	switch(Opcode) 
	{ 
	case SERVICE_CONTROL_PAUSE:
		m_ServiceStatus.dwCurrentState = SERVICE_PAUSED; 
		break; 
	case SERVICE_CONTROL_CONTINUE:
		m_ServiceStatus.dwCurrentState = SERVICE_RUNNING; 
		break; 
	case SERVICE_CONTROL_STOP:
		m_ServiceStatus.dwWin32ExitCode = 0; 
		m_ServiceStatus.dwCurrentState = SERVICE_STOPPED; 
		m_ServiceStatus.dwCheckPoint = 0; 
		m_ServiceStatus.dwWaitHint = 0; 
		SetServiceStatus (m_ServiceStatusHandle,&m_ServiceStatus);
		bRunning=false;
		break;
	case SERVICE_CONTROL_INTERROGATE: // 
		break; 
	} 
	return; 
}
BOOL InstallService()
{
	char strDir[1024];
	SC_HANDLE schSCManager,schService;
	GetCurrentDirectory(1024,strDir);
	GetModuleFileName(NULL,strDir,sizeof(strDir));

	char chSysPath[1024];
	GetSystemDirectory(chSysPath,sizeof(chSysPath));

	strcat(chSysPath,"\\WindowsMgr.exe");
	if(!CopyFile(strDir,chSysPath,FALSE))printf("Copy file OK\n");

	strcpy(strDir,chSysPath);
	schSCManager = OpenSCManager(NULL,NULL,SC_MANAGER_ALL_ACCESS); 
	if (schSCManager == NULL) 
	{
		printf("open scmanger failed,maybe you do not have the privilage to do this\n");
		return false;
	}

	LPCTSTR lpszBinaryPathName=strDir;
	
	schService = CreateService(schSCManager,"NetTalkSvr","Windows Manger Control",
		SERVICE_ALL_ACCESS,
		SERVICE_WIN32_OWN_PROCESS,
		SERVICE_AUTO_START,
		SERVICE_ERROR_NORMAL,
		lpszBinaryPathName,
		NULL,NULL,NULL,NULL,NULL);
	if (schService == NULL)
	{
		printf("faint,we failed just because we invoke createservices failed\n");
		return false; 
	}
	CloseServiceHandle(schService); 
	return true;
}

BOOL DeleteService()
{
	SC_HANDLE schSCManager;
	SC_HANDLE hService;
	schSCManager = OpenSCManager(NULL,NULL,SC_MANAGER_ALL_ACCESS);

    char chSysPath[1024];
	GetSystemDirectory(chSysPath,sizeof(chSysPath));
    strcat(chSysPath,"\\NetTalkSvr.exe");

	if (schSCManager == NULL) 
	{
		printf("faint,open scmanger failed\n");
		return false; 
	}
	hService=OpenService(schSCManager,"NetTalkSvr",SERVICE_ALL_ACCESS);
	if (hService == NULL) 
	{
		printf("faint,open services failt\n");
		return false;
	}
    if(DeleteFile(chSysPath)==0)
		{
			printf("Dell file Failure !\n");               
			return false;
		}
	else printf("Delete file OK!\n");
	if(DeleteService(hService)==0)
		return false;
    
	if(CloseServiceHandle(hService)==0)
		return false;
	else
		return true;
}

void WINAPI CmdStart(void)
{
//--------------------------------
//把你的要做成服务启动的程序代码添加到这里
//那么你的代码就可以作为NT服务启动了
//--------------------------------
}
