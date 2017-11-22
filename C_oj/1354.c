#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    int i , j , k;
    int blank = N*2-3;
    for ( i = 1 ; i < N ; i++)
    {
        for (j = 1 ; j <= i ; j++)
        {
            printf("*");
        }
        for (j = 1 ; j <= blank ; j++)
        {
            printf(" ");
        }
        for ( j = 1 ; j <= i ; j++)
        {
            printf("*");
        }
        blank -= 2;
        printf("\n");
    }
    for ( i = 1 ; i <= N * 2 -1 ; i++)
    {
        printf("*");
    }
    printf("\n");
    blank = 1;
    int temp = N;
    for ( i = 1 ; i < temp ; i++)
    {
        for (j = 1 ; j <= N-1 ; j++)
        {
            printf("*");
        }
        for (j = 1 ; j <= blank ; j++)
        {
            printf(" ");
        }
        for ( j = 1 ; j <= N-1 ; j++)
        {
            printf("*");
        }
        N--;
        blank += 2;
        printf("\n");
    }

    system("pause");
    return 0;
}