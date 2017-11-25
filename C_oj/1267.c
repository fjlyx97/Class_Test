#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void dfs(int N , int M ,char (*map)[1001], int startx , int starty , int p , int q , int step , int (*next)[2] , int (*book)[1001] , int* min)
{
    if (startx == p && starty == q)
    {
        if (step < *min )
        {
            *min = step;
        }
        return;
    }
    int k = 0;
    int tx = startx, ty = starty;
    for (k = 0 ; k <= 3 ; k++)
    {
        tx = startx + next[k][0];
        ty = starty + next[k][1];
        if ( tx < 0 || tx >= N || ty < 0 || ty >= M)
        {
            continue;
        }
        if ( map[tx][ty] == '.' && book[tx][ty] == 0)
        {
            book[tx][ty] = 1;
            dfs(N,M,map,startx,starty,p,q,step+1,next,book,min);
            book[tx][ty] = 0;
        }
    }
    return;
}
int main(void)
{
    int N , M;
    scanf("%d %d",&N,&M);
    getchar();
    char map[N][1001];
    int book[N][1001];
    memset(book,0,sizeof(book));
    int i , j;
    int startx , starty , overx , overy;
    int min = 0;
    int next[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    for ( i = 0 ; i < N ; i++)
    {
        for ( j = 0 ; j < M ; j++)
        {
            scanf("%c",&map[i][j]);
            if (map[i][j] == 'B')
            {
                startx = i;
                starty = j;
            }
            else if (map[i][j] == 'A')
            {
                overx = i;
                overy = j;
            }
        }
        getchar();
    }

    dfs(N,M,map,startx,starty,overx,overy,0,next,book,&min);

    printf("%d",min);

    system("pause");
    return 0;
}