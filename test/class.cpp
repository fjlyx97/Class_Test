#include <WinSock2.h>
#include <iostream>
//#pragma comment(lib,"ws2_32.lib")
int main(void)
{
	WORD sockVersion = MAKEWORD(2, 2);		//�ƶ��汾��
	WSADATA wsaData;

	/*��ʼ��socket��*/
	if (WSAStartup(sockVersion, &wsaData)!=0)
	{
		return 0;
	}

	/*�����׽���*/
	/*��һ������ָ��IPv4���ڶ�������ָ����ʽ���䣬����tcp������������ָ��tcpЭ�飬����Ϊ0���Զ��ж�*/
	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	sockaddr_in sin;
	sin.sin_family = AF_INET;	//ָ��Э��
	sin.sin_port = htons(6000);	//��������������ݸ�ʽ��ʹ��htons����װ
	sin.sin_addr.S_un.S_addr = inet_addr("192.168.2.117");
	/*���а�*/
	if (bind(slisten, (SOCKADDR*)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		std::cout << "bind error ! " << std::endl;
	}

	/*5Ϊ�ȴ�������Ŀ*/
	if (listen(slisten, 5) == SOCKET_ERROR)
	{
		std::cout << "listen error" << std::endl;
	}
	
	/*��������*/
	SOCKET sClient;
	sockaddr_in remoteAddr;
	char revData[255];
	int nAddrlen = sizeof(remoteAddr);
	while (true)
	{
		std::cout << "�ȴ�����" << std::endl;
		sClient = accept(slisten, (SOCKADDR*)&remoteAddr, &nAddrlen);
		std::cout << "���ӳɹ�" << std::endl;
		send(sClient, "���ӳɹ�" , sizeof("���ӳɹ�"), 0);
		int ret = 1;
		while (ret > 0)
		{
			ret = recv(sClient, revData, 255, 0);
			std::cout << revData << std::endl;
		}
	}
	return 0;
}