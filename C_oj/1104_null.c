#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    int num[N][N] = {{0}};
    int i = 0 , j = 0;
    for (i = 0 ; i < N ; i++)
    {
        for (j = 0 ; j < i+1 ; j++)
        {
            scanf("%d",&num[i][j]);
        }
    }
    for (i = 0 ; i < N ; i++)
    {
        for (j = 0 ; j < N ; j++)
        {
            printf("%d ",num[i][j]);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}