#include <stdio.h>
#include <stdlib.h>
void judge(int n , int k)
{
    int num[n];
    int total = 0;
    int result = 0;
    int ave = 0;
    int i , j;
    int temp = 0;
    int sum = 0;
    for ( i = 0 ; i < n ; i++)
    {
        scanf("%d",&num[i]);
        total += num[i];
    }
    if (total % k != 0)
    {
        printf("-1\n");
        return;
    }
    else
    {
        ave = total / k;
        result = n-1+k-1;   //定义要拆掉再合成的板子数量
        for ( i = 0 ; i < k-1 ; i++)
        {
            temp += ave;
            for ( j = 0 ; j < n-1 ; j++)
            {
                sum += num[j];
                if (sum == temp)
                {
                    result -= 2; //如果板子已经存在，可以少两次操作次数
                }
            }
            sum = 0;
        }
    }
    printf("%d\n",result);
}
int main(void)
{
    int T;
    scanf("%d",&T);
    int n , k;
    while (T--)
    {
        scanf("%d %d",&n,&k);
        judge(n,k);
    }
    system("pause");
    return 0;
}