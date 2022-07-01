#include<stdio.h> 
#include <WinSock2.h>
#pragma comment(lib, "WS2_32.lib")
#pragma warning(disable : 4996)
int main() {
	int WSAAPI connect(SOCKET s, const sockaddr *name, int namelen);
	WORD wVersionRequested;
	wVersionRequested = MAKEWORD(2, 2);
	int WSAAPI WSAStartup(WORD wVersionRequested, LPWSADATA lpWSAData);
	WSADATA wsaData;
	WSAStartup(wVersionRequested, &wsaData);
	SOCKET gsocket;
	gsocket = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN addrserv;
	addrserv.sin_family = AF_INET;
	addrserv.sin_port = htons(111);
	//addrserv.sin_addr.s_addr = inet_addr("59.47.73.40");
	//connect(gsocket, (struct sockaddr *)&addrserv, sizeof(addrserv));
	addrserv.sin_addr.S_un.S_addr = ADDR_ANY;
	int ret1 = bind(gsocket, (sockaddr*)&addrserv, sizeof(sockaddr));
	listen(gsocket, 2);
	while (1) {

		sockaddr_in cliAddr;

		int addLen = sizeof(cliAddr);

		SOCKET clientSock = accept(gsocket, (sockaddr*)&cliAddr, &addLen);
		char a[16]="welocme connect";
		char *buff = a;

		int ret2 = send(clientSock, buff, strlen(buff), 0);


	}

	return 0;



}
