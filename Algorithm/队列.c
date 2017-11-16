#include <stdio.h>
#include <stdlib.h>
struct queue    //队列模型
{
    int data[1000];
    int head;
    int tail;
};
int main(void)
{
    struct queue t;
    t.head = 1;
    t.tail = 1;
    int i = 0;
    for ( i = 1 ; i <= 9 ; i++)
    {
        scanf("%d",&t.data[t.tail]);
        t.tail++;
    }
    while(t.head < t.tail)
    {
        printf("%d ",t.data[t.head]);
        t.head++;

        t.data[t.tail] = t.data[t.head];
        t.tail++;

        t.head++;
    }

    system("pause");
    return 0;
}