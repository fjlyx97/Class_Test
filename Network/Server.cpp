#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <cstdio>

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
    WORD ver = MAKEWORD(2,2);
    WSADATA wsaData;  
    if(WSAStartup(ver, &wsaData)!=0)  
    {  
        return 0;  
    }  
    //创建套接字  
    SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  
    if(slisten == INVALID_SOCKET)  
    {  
        printf("socket error !");  
        return 0;  
    }  
    //绑定IP和端口  
    sockaddr_in sin;  
    sin.sin_family = AF_INET;  
    sin.sin_port = htons(8888);  
    sin.sin_addr.S_un.S_addr = INADDR_ANY;   
    if(bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)  
    {  
        printf("bind error !");  
    }  
    
    //开始监听  
    if(listen(slisten, 5) == SOCKET_ERROR)  
    {  
        printf("listen error !");  
        return 0;  
    }  
    
    //循环接收数据  
    SOCKET sClient;  
    sockaddr_in remoteAddr;  
    int nAddrlen = sizeof(remoteAddr);  
    char revData[255];   
    while (true)  
    {  
        printf("Waitting a client...\n");  
        sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);  
        if(sClient == INVALID_SOCKET)  
        {  
            printf("accept error !");  
            continue;  
        }  
        printf("accept a client : %s \r\n", inet_ntoa(remoteAddr.sin_addr));  

        fd_set fdRead;
        fd_set fdWrite;
        fd_set fdExp;
        FD_ZERO(&fdRead);
        FD_ZERO(&fdWrite);
        FD_ZERO(&fdExp);
        FD_SET(slisten,&fdRead);
        FD_SET(slisten,&fdWrite);
        FD_SET(slisten,&fdExp);
        int ret = select(0,&fdRead,&fdWrite,&fdExp,NULL);
        if (ret < 0)
        {

        }
        
        //接收数据  
        //int ret = recv(sClient, revData, 255, 0);         
        //if(ret > 0)  
        //{  
        //    revData[ret] = 0x00;  
        //    printf(revData);  
        //}  
        //发送数据  
        DataHeader newHeader = {sizeof(DataPack),1};
        send(sClient, (const char*)&newHeader, sizeof(DataHeader),0);
        DataPack db = {80,"Yi Lai"};
        send(sClient, (const char*)&db, sizeof(DataPack) , 0);  
        closesocket(sClient);  
    }  
    closesocket(slisten);  
    WSACleanup();  
    return 0;  
}