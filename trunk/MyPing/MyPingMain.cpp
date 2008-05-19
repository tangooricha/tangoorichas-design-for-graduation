#include <windows.h>
#include <stdio.h>
#include <memory.h>

typedef struct icmp_hdr
{
	unsigned char icmp_type;
	unsigned char icmp_code;
	unsigned short icmp_checksum;

	unsigned short icmp_id;
	unsigned short icmp_sequence;
	unsigned long icmp_timestamp;
}ICMP_HDR,*PICMP_HDR;

typedef struct _IpHeader     
{   
	unsigned int HeaderLength:4;
	unsigned int Version:4;
	unsigned char TypeOfService;
	unsigned short TotalLength;
	unsigned short Identification;
	unsigned short FragmentationFlags;
	unsigned char TTL;
	unsigned char Protocol;
	unsigned short CheckSum;
    
	unsigned int sourceIPAddress;
	unsigned int destIPAddress;    
}IpHeader;

USHORT checksum(USHORT *buff,int size)
{
	unsigned long cksum=0;
	while(size>1)
	{
		cksum+=*buff++;
		size-=sizeof(USHORT);
	}
	if(size)
	{
		cksum+=*(UCHAR*)buff;
	}
	cksum=(cksum>>16)+(cksum&0xffff);
	cksum+=(cksum>>16);
	return (USHORT)(~cksum);
}

void main(int argc, char* argv[])
{
	WSADATA wsaData;
	::WSAStartup(MAKEWORD(2,2),&wsaData);

	char *szDestIp;
	szDestIp=argv[1];
	SOCKET sRaw=::socket(AF_INET,SOCK_RAW,IPPROTO_ICMP);

	int timeout=3000;
	setsockopt(sRaw,IPPROTO_TCP,SO_SNDTIMEO,(char*)&timeout,sizeof(struct timeval));

	SOCKADDR_IN dest;
	dest.sin_family=AF_INET;
	dest.sin_port=htons(0);
	dest.sin_addr.S_un.S_addr=inet_addr(szDestIp);

	char buff[sizeof(ICMP_HDR)+32];
	ICMP_HDR *pIcmp=(ICMP_HDR *)buff;

	pIcmp->icmp_type=8;
	pIcmp->icmp_code=0;
	pIcmp->icmp_id=(USHORT)::GetCurrentProcessId();
	pIcmp->icmp_checksum=0;
	pIcmp->icmp_sequence=0;

	memset(&buff[sizeof(ICMP_HDR)],0,32);

	USHORT nSeq=0;
	char recvBuff[1024];
	SOCKADDR_IN from;
	int nLen=sizeof(from);
	int nRet;

	pIcmp->icmp_checksum=0;
	pIcmp->icmp_timestamp=::GetTickCount();
	pIcmp->icmp_sequence=nSeq++;
	pIcmp->icmp_checksum=checksum((USHORT *)buff,sizeof(ICMP_HDR)+32);
	nRet=::sendto(sRaw,buff,sizeof(ICMP_HDR)+32,0,(SOCKADDR *)&dest,sizeof(dest));
	nRet=::recvfrom(sRaw,recvBuff,1024,0,(sockaddr *)&from,&nLen);
	ICMP_HDR *pRecvIcmp=(ICMP_HDR *)(recvBuff+sizeof(IpHeader));
	int nTick=::GetTickCount();
	printf("Respond in %dms\n",nTick-pIcmp->icmp_timestamp);
	::WSACleanup();
}