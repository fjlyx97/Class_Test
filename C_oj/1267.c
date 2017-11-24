#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N , M;
    scanf("%d %d",&N,&M);
    getchar();
    char map[N][M];
    int i , j;
    for ( i = 0 ; i < N ; i++)
    {
        for ( j = 0 ; j < M ; j++)
        {
            scanf("%c",&map[i][j]);
        }
        getchar();
    }


    system("pause");
    return 0;
}