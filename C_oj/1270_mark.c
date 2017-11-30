#include <stdio.h>
#include <stdlib.h>
void swap(int x,int y,int* num)
{
    int temp;
    temp = num[x];
    num[x] = num[y];
    num[y] = temp;
    return;
}
void siftdown(int i,int* num,int n)     //元素下滑
{
    int flag = 0;
    int temp;
    while (flag == 0 && i * 2 <= n)
    {
        if (num[i] > num[i*2])
        {
            temp = i * 2;
        }
        else
        {
            temp = i;
        }
        if ( i*2+1 <= n)
        {
            if (num[i*2+1] < num[temp])
            {
                temp = i*2+1;
            }
        }
        if ( temp != i)
        {
            swap(i,temp,num);
            i = temp;
        }
        else
        {
            flag = 1;
        }
    }
    return;
}
void create(int* num,int n)
{
    int i = n / 2;
    for ( i = n / 2 ; i >= 1 ; i--)
    {
        siftdown(i,num,n);
    }
}
int delete_min(int* num,int* n)
{
    int temp = num[1];
    num[1] = num[*n];
    *n -= 1;
    siftdown(1,num,*n);
    return temp; 
}
void siftup(int i , int* num , int n)
{
    int flag = 0;
    if (i == 1)
    {
        return;
    }
    while (i != 1 && flag == 0)
    {
        if (num[i/2] > num[i])
        {
            swap(i/2,i,num);
        }
        else
        {
            flag = 1;
        }
        i = i / 2;
    }
    return;
}
int main(void)
{
    int N;
    scanf("%d",&N);
    int *num = (int*)malloc(sizeof(int)*(N+1));
    //int num[N];
    int i;
    for ( i = 1 ; i <= N ; i++)
    {
        scanf("%d",&num[i]);
    }
    create(num,N);  //初始化堆
    int result = 0;
    int min_1 , min_2;
    while (1)
    {
        min_1 = delete_min(num,&N);
        min_2 = delete_min(num,&N);
        result += min_1+min_2;
        if (N == 0)
        {
            break;
        }
        N++;
        num[N] = min_1+min_2;
        siftup(N,num,N);
    }
    printf("%d",result);
    free(num);
    system("pause");
    return 0;
}