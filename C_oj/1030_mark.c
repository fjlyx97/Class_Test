#include <stdio.h>
#include <stdlib.h>
void judge(int num[][7] , int N)
{
    int value = 0;
    int i , j;
    for ( i = 0 ; i < N ; i++)
    {
        for ( j = 1 ; j <= 6 ; j++)
        {
            if (num[i][j] != 0)
            {
                value += j * num[i][j];
            } 
        }
        if (value % 2 == 1)
        {
            printf("NO\n");
            return;
        }
        else
        {
            for ( j = 1 ; j <= 6 ; j++)
            {
                if ( 0 == num[i][j] )
                {
                    continue;
                }
                if ( num[i][j] % 2 == 0)
                {
                    num[i][j] = 0;
                }
                else
                {
                    num[i][j] = 1;
                }
            }
            value = 0;
            for ( j = 1 ; j <= 6 ; j++)
            {
                if (num[i][j] != 0)
                {
                    value += j;
                }
            }
            if ( value % 2 != 0)
            {
                printf("NO");
                return;
            }
            else
            {
                
            }
        }
    }
}
int main(void)
{
    int N;
    scanf("%d",&N);
    int num[N][7] = {0};
    int i , j;
    for ( i = 0 ; i < N ; i++)
    {
        for ( j = 1 ;  j <= 6 ; j++)
        {
            scanf("%d",&num[i][j]);
        }
    }
    for ( i = 0 ; i < N ; i++)
    {
        judge(num , N);
    }

    system("pause");
    return 0;
}