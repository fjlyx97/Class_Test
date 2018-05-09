#include <stdio.h>
int main(void)
{
    int num[1000];
    int len = 0;
    int i , j;
    int flag;
    for (i = 2 ; i <= 1000 ; i++)
    {
        flag = 1;
        for (j = 2 ; j < i ; j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            num[len++] = i;
        }
    }
    for ( i = 0 ; i < len-1 ; i++)
    {
        if (num[i+1] - num[i] == 2)
        {
            printf("%d %d\n",num[i],num[i+1]);
        }
    }
    return 0;
}