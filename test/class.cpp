#include <WinSock2.h>
#include <iostream>
//#pragma comment(lib,"ws2_32.lib")
int main(void)
{
	WORD sockVersion = MAKEWORD(2, 2);		//制定版本号
	WSADATA wsaData;

	/*初始化socket库*/
	if (WSAStartup(sockVersion, &wsaData)!=0)
	{
		return 0;
	}

	/*创建套接字*/
	/*第一个参数指定IPv4，第二个参数指定流式传输，适用tcp，第三个参数指定tcp协议，设置为0将自动判断*/
	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	sockaddr_in sin;
	sin.sin_family = AF_INET;	//指定协议
	sin.sin_port = htons(6000);	//必须采用网络数据格式，使用htons来包装
	sin.sin_addr.S_un.S_addr = inet_addr("192.168.2.117");
	/*进行绑定*/
	if (bind(slisten, (SOCKADDR*)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		std::cout << "bind error ! " << std::endl;
	}

	/*5为等待连接数目*/
	if (listen(slisten, 5) == SOCKET_ERROR)
	{
		std::cout << "listen error" << std::endl;
	}
	
	/*接受数据*/
	SOCKET sClient;
	sockaddr_in remoteAddr;
	char revData[255];
	int nAddrlen = sizeof(remoteAddr);
	while (true)
	{
		std::cout << "等待连接" << std::endl;
		sClient = accept(slisten, (SOCKADDR*)&remoteAddr, &nAddrlen);
		std::cout << "连接成功" << std::endl;
		send(sClient, "连接成功" , sizeof("连接成功"), 0);
		int ret = 1;
		while (ret > 0)
		{
			ret = recv(sClient, revData, 255, 0);
			std::cout << revData << std::endl;
		}
	}
	return 0;
}