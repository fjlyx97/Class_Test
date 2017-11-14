#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    int num[N][N];
    int i = 2;
    int j = 0 , k = 0;
    int temp;
    int status = 0;
    for ( i = 0 ; i < N ; i++)
    {
        for ( j = 0 ; j < N ; j++)
        {
            num[i][j] = 0;
        }
    }
    num[0][N/2] = 1;
    for ( i = 2 ; i <= N*N ; i++)
    {
        status = 0;
        temp = i-1;
        for ( j = 0 ; j < N ; j++)
        {
            for ( k = 0 ; k < N ; k++)
            {
                if (temp == num[j][k])
                {
                    status = 1;
                    break;
                }
            }
            if ( 1 == status )
            {
                break;
            }
        }
        if ( j == 0 && k != N-1)
        {
            num[N-1][k+1] = i;
        }
        else if ( k == N-1 && j != 0)
        {
            num[j-1][0] = i;
        }
        else if ( j == 0 && k == N-1)
        {
            num[j+1][k] = i;
        }
        else if ( j != 0 && k != N-1)
        {
            if ( num[j-1][k+1] == 0)
            {
                num[j-1][k+1] = i;
            }
            else
            {
                num[j+1][k] = i;
            }
        }
    }
    for ( i = 0 ; i < N ; i++)
    {
        for ( j = 0 ; j < N ; j++)
        {
            printf("%d ",num[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}