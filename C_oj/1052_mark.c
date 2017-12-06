#include <stdio.h>
#include <stdlib.h>
struct queue    //使用队列保存排队
{
    int server_time[101];
    int head;
    int tail;
};
int main(void)
{
    int n , s;
    scanf("%d %d",&n,&s);
    int server_time[n];     //保存队列
    int i , j , temp , index = 0;
    for (i = 0 ; i < n ; i++)
    {
        scanf("%d",&server_time[i]);
    }
    for (i = 0 ; i < n-1 ; i++)     //给队列进行从小到大排序
    {
        for (j = 0 ; j < n- i- 1 ; j++)
        {
            if (server_time[j] > server_time[j+1])
            {
                temp = server_time[j];
                server_time[j] = server_time[j+1];
                server_time[j+1] = temp;
            }
        }
    }
    struct queue server_queue[s];       //申明服务队列
    for (i = 0 ; i < s ; i++)           //初始化
    {
        server_queue[i].head = 0;
        server_queue[i].tail = 0;
    }
    int choice = 0;
    while (index != n)          //将队列按顺序添加
    {
        for (i = 0 ; i < s ; i++)
        {
            server_queue[i].server_time[server_queue[i].tail] = server_time[index];
            server_queue[i].tail += 1;
            index++;
            if (index == n) break;
        }
    }
    float result = 0;
    for (i = 0 ; i < s ; i++)
    {
        temp = server_queue[i].tail;
        for (j = 0 ; j < server_queue[i].tail ; j++)
        {
            result += server_queue[i].server_time[server_queue[i].head] * temp; 
            server_queue[i].head++;
            temp--;
        }
    }
    printf("%.2f", result/n);
    system("pause");
    return 0;
}