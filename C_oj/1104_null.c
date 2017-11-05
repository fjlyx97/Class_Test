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
    result += num[0][0];
    j = 0;
    for ( i = 1 ; i < N ; i++)
    {
        if ( num[i][j] > num[i][j+1])
        {
            result += num[i][j+1];
            j = j + 1;
        }
        else
        {
            result += num[i][j];
        }
    }
    printf("%d",result);
    system("pause");
    return 0;
}