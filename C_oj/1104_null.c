#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    scanf("%d",&N);
    int num[N][N];
    int result = 0;
    int i = 0 , j = 0;
    for ( i = 0 ; i < N ; i++)
    {
        for ( j = 0 ; j < N ; j++)
        {
            num[i][j] = -1;
        }
    }
    for ( i = 0 ; i < N ; i++)
    {
        for ( j = 0 ; j <= i ; j++)
        {
            scanf("%d",&num[i][j]);         
        }
    }
    int k = 0;
    for ( i = 0 ; i < N ; i++)
    {
        result += num[i][0];
        for ( j = i+1 ; j < N ; j++)
        {
            if ( num[j][k] > num[j][k+1] )
            {
                result += num[j][k+1];
                k = k+1;
            }
            else
            {
                result += num[j][k];
            }
        }
        break;
    }
    printf("%d",result);
    system("pause");
    return 0;
}