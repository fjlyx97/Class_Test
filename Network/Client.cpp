#include <WINSOCK2.H>
#include <stdio.h>
#include <iostream>
using namespace std;
#pragma comment(lib, "ws2_32.lib")

struct DataHeader
{
    int length;
    int cmd;
};

struct DataPack
{
    int age;
    char name[32];
};

int main()
{
    WORD sockVersion = MAKEWORD(2, 2);
    WSADATA data;
    if (WSAStartup(sockVersion, &data) != 0)
    {
        return 0;
    }
    while (true)
    {
        SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (sclient == INVALID_SOCKET)
        {
            printf("invalid socket!");
            return 0;
        }

        sockaddr_in serAddr;
        serAddr.sin_family = AF_INET;
        serAddr.sin_port = htons(8888);
        serAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
        if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
        { //连接失败
            printf("connect error !");
            closesocket(sclient);
            return 0;
        }

        //DataPack sendData = {20,"Yuxin Liang"};
        //send(sclient, (const char*)&sendData, sizeof(DataPack), 0);


        DataHeader newHeader;
        int ret = recv(sclient, (char*)&newHeader, sizeof(DataHeader), 0);
        DataPack* newPack;
        char buf[64];
        int ret1 = recv(sclient, buf , newHeader.length, 0);
        if (ret1 > 0)
        {
            newPack = (DataPack*)buf;
            std::cout << newPack->age << std::endl;
            std::cout << newPack->name << std::endl;
        }
        closesocket(sclient);
        break;
    }

    WSACleanup();
    return 0;
}