#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    int num[3][2];
    int i = 0 , j = 0 ;
    for ( i = 0 ; i < 3 ; i++)
    {
        for ( j = 0 ; j < 2 ; j++)
        {
            scanf("%d",&num[i][j]);
        }
    }
    int result = 0;
    int k = 0;
    for ( i = num[0][0] ; i <= num[0][1] ; i++)
    {
        for ( j = i ; j <= N-i ; j++)
        {
            for ( k = j ; k <= N-j-i ; k++)
            {
                if ( i + j > k && i + k > j && j + k > i && i + j + k == N)
                {
                    result++;
                }
            }
        }
    }
    printf("%d",result);
    system("pause");
    return 0;
}