#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char map[11][11];

typedef struct
{
    int x;
    int y;
    int step;
}queue;

int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

queue two_bfs[50];
int two_bfs_head = 1;
int two_bfs_tail = 1;
int index = 0;

void bfs(int startx , int starty , int step)
{
    int book[11][11];
    memset(book,0,sizeof(book));


    /* 初始化队列 */
    int head = 1;
    int tail = 1;
    queue map_queue[101];
    map_queue[tail].x = startx;
    map_queue[tail].y = starty;
    map_queue[tail].step = step;
    book[startx][starty] = 1;
    tail++;
    /* 结束初始化 */
    int tx , ty;
    int i , j;
    while (head < tail)
    {
        for ( i = 0 ; i < 4 ; i++)
        {
            tx = map_queue[head].x + next[i][0];
            ty = map_queue[head].y + next[i][1];
            if (tx < 1 || ty < 1 || tx > 10 || ty > 10)
            {
                continue;
            }
            if ( ('1' <= map[tx][ty] && map[tx][ty] <= '6') && book[tx][ty] == 0)
            {
                book[tx][ty] = 1;
                two_bfs[two_bfs_tail].x = tx;
                two_bfs[two_bfs_tail].y = ty;
                two_bfs[two_bfs_tail].step = map_queue[head].step + 1;
                index += 1;
                two_bfs_tail++;
            }
            if ( book[tx][ty] == 0 && map[tx][ty] == '.')
            {
                map_queue[tail].x = tx;
                map_queue[tail].y = ty;
                map_queue[tail].step = map_queue[head].step + 1;
                book[tx][ty] = 1;
                tail++; 
            }
        }
        head++;
    }
    return;
}
int main(void)
{
    int T;
    int i , j;
    int startx , starty;
    //freopen("11.txt","r",stdin);  
    scanf("%d",&T);
    getchar();
    int min;
    while (T--)
    {
        two_bfs_head = 1;
        two_bfs_tail = 1;
        index = 0;
        min = 99999;
        for ( i = 1 ; i < 11 ; i++)
        {
            for ( j = 1 ; j < 11 ; j++)
            {
                map[i][j] = getchar();
                if (map[i][j] == 'A')
                {
                    startx = i;
                    starty = j;
                }
            }
            getchar();
        }
        bfs(startx , starty , 0);
        int temp = index;
        two_bfs_head = 1;
        index = 0;
        two_bfs_tail = temp+1;
        for ( i = 1 ; i <= temp ; i++)
        {
            bfs(two_bfs[i].x,two_bfs[i].y,two_bfs[i].step);
        }
        for ( i = temp+1 ; i <= index+temp ; i++)
        {
            if (two_bfs[i].step < min)
            {
                min = two_bfs[i].step;
            }
        }
        printf("%d\n",min);
        getchar();
    }
    system("pause");
    return 0;
}