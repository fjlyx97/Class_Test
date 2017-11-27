#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int judge(int n , int m)
{
    int num[n+2][m+2];
    int i , j;
    int result = 0;
    memset(num,0,sizeof(num));
    int temp = 0;
    int index = 0;
    for ( i = 1 ; i < n+1 ; i++)
    {
        for ( j = 1 ; j < m+1 ; j++)
        {
            scanf("%d",&num[i][j]);
            if (num[i][j] != 0)
            {
                index++;
            }
        }
    }
    for ( i = 1 ; i < n+1 ; i++)
    {
        for ( j = 1 ; j < m+1 ; j++)
        {
            if (num[i][j] - num[i][j-1] > 0)
            {
                temp += num[i][j] - num[i][j-1];
            }
            if (num[i][j] - num[i][j+1] > 0)
            {
                temp += num[i][j] - num[i][j+1];
            }
            if (num[i][j] - num[i-1][j] > 0)
            {
                temp += num[i][j] - num[i-1][j];
            }
            if (num[i][j] - num[i+1][j] > 0)
            {
                temp += num[i][j] - num[i+1][j];
            }
        }
    }
    return temp + index;
}
int main(void)
{
    int T;
    int n , m;
    scanf("%d",&T);
    int result;
    while(T--)
    {
        scanf("%d %d",&n,&m);
        result = judge(n,m);
        printf("%d\n",result);
    }

    system("pause");
    return 0;
}