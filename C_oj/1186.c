#include <stdio.h>
#include <stdlib.h>
/* 垃圾题目，题目不清晰 */
int main(void)
{
    int N , S;
    scanf("%d %d", &N , &S);
    int i = 0 , j = 0;;
    int boys = 0;
    int max = boys;
    for ( i = 0 ; i <= N ; i++)
    {
        for ( j = 0 ; j <= N ; j++)
        {
            if ( i * j == S && i + j < N )
            {
                boys = (N - (i + j)) / 2;
                if ( boys > max )
                {
                    max = boys;
                }
            }
        }
    }
    printf("%d",max);

    system("pause");
    return 0;
}