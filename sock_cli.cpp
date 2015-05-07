

#include "stdafx.h"

#include <windows.h>
#include <winsock.h>

#pragma comment(lib, "wsock32.lib")

int _tmain(int argc, _TCHAR* argv[])
{

	WORD version;
	WSADATA wsaData;
	int rVal=0;

	version = MAKEWORD(1,1);

	WSAStartup(version,(LPWSADATA)&wsaData);

	LPHOSTENT hostEntry;

	SOCKET theSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(theSocket == SOCKET_ERROR)
	{
		return -1;
	}


	SOCKADDR_IN serverInfo;

	serverInfo.sin_family = AF_INET;
	serverInfo.sin_addr.s_addr = inet_addr("192.168.11.139"); 

	serverInfo.sin_port = htons(5353);

	rVal=connect(theSocket,(LPSOCKADDR)&serverInfo, sizeof(serverInfo));
	if(rVal==SOCKET_ERROR)
	{
		return -1;
	}

	closesocket(theSocket);
	WSACleanup();

	return 0;
}


