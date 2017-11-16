#include <stdio.h>
#include <stdlib.h>
struct queue    //初始化队列
{
    int data[1000];
    int head;
    int tail;
};

struct stack    //初始化栈
{
    int data[10];
    int top;
};
int main(void)
{
    struct queue q1 , q2;   //设q1小明，q2小红
    struct stack s;               //初始化栈
    q1.head = 1 , q1.tail = 1;
    q2.head = 1 , q2.tail = 1;
    s.top = 0;

    int i = 0;

    /*进行发牌*/

    for ( i = 1 ; i <= 6 ; i++)
    {
        scanf("%d",&q1.data[q1.tail]);
        q1.tail++;
    }
    for ( i = 1 ; i <= 6 ; i++)
    {
        scanf("%d",&q2.data[q2.tail]);
        q2.tail++;
    }
    
    /*初始化第一张出的牌*/
    int t;
    while (q1.head < q1.tail && q2.head < q2.tail)
    {
        t = q1.data[q1.head];

        /*观察是否桌面上牌有相同的*/
        int flag = 0;
        for ( i = 0 ; i <= s.top ; i++)
        {
            if (t == s.data[i])
            {
                flag = 1;
                break;
            }
        }
        if ( 0 == flag )
        {
            q1.head++;
            s.top++;
            s.data[s.top] = t;
        }
        else if ( 1 == flag )
        {
            q1.head++;
            q1.data[q1.tail] = t;
            q1.tail++;
            while (s.data[s.top] != t)
            {
                q1.data[q1.tail] = s.data[s.top];
                q1.tail++;
                s.top--;
            }
        }

        /*判断胜负*/
        if (q2.head == q2.tail)
        {
            printf("q2 win");
        }
    }
    system("pause");
    return 0;
}