/* File Name: streams.c */   
#include <winsock.h>   
#include <stdio.h>   
#define TRUE 1   
/* 这个程序建立一个套接字，然后开始无限循环；每当它通过循环接收到一个连接，则打印出一个信息。 
当连接断开，或接收到终止信息，则此连接结束，程序再接收一个新的连接。命令行的格式是：streams */  
   
  
int main(void)   
{   
    int sock, length;   
    struct sockaddr_in server;   
    struct sockaddr tcpaddr;   
    int msgsock;   
    char buf[1024];   
    int rval, len;   
    
    /* 建立套接字 */   
    sock = socket(AF_INET, SOCK_STREAM, 0);   
    return 0;
}   