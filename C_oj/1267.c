#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int x;
    int y;
    int num;//步数
}my_node[1002001];
char map[1001][1001];
int book[1001][1001];

int main(void)
{
    int N , M;
    int i , j , k;
    scanf("%d %d",&N,&M);
    getchar();
    //char map[N+1][M+1]; //初始化地图

    //int book[N+1][M+1]; //初始化地图记录

    memset(book,0,sizeof(book));

    int startx , starty , overx , overy; //定义小光头以及小姑娘的位置

    /* 初始化队列 */
    //struct node my_node[N*M+1]; 
    int head = 1;
    int tail = 1;
    /*结束初始化*/

    for ( i = 1 ; i <= N ; i++)
    {
        for ( j = 1 ; j <= M ; j++)
        {
            map[i][j] = getchar();
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
    /*将第一个位置放入队列*/
    my_node[tail].x = startx;
    my_node[tail].y = starty;
    my_node[tail].num = 0;
    book[startx][starty] = 1;
    tail++;
    /*结束放入*/

    /*定义运动方向*/
    int next[4][2] = {{0,1}, //向右
                      {1,0}, //向下
                      {0,-1}, //向左
                      {-1,0}};   //向上
    /*结束定义*/

    int tx , ty;    //定义临时变量
    int min_num = 999999;

    int flag = 1;
    int go_in;
    while (head < tail)
    {
        for ( i = 0 ; i <= 3 ; i++)
        {
            go_in = 0;  //为下面循环设定条件
            tx = my_node[head].x + next[i][0]; 
            ty = my_node[head].y + next[i][1];
            if (tx > N || ty > M || tx < 1 || ty < 1)
            {
                continue;
            }
            if (book[tx][ty] == 0 && map[tx][ty] == '.')
            {
                book[tx][ty] = 1;
                my_node[tail].x = tx;
                my_node[tail].y = ty;
                my_node[tail].num = my_node[head].num+1;
                tail++;
                go_in = 1;
            }
            if ( tx == overx && go_in == 1)
            {
                flag = 1;
                if (ty > overy)
                {
                    for ( j = ty-1 ; j > overy ; j--)
                    {
                        if (map[tx][j] != '#')
                        {
                            flag = 1;
                        }
                        else
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
                else
                {
                    for ( j = ty+1 ; j < overy ; j++)
                    {
                        if (map[tx][j] != '#')
                        {
                            flag = 1;
                        }
                        else
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
                if (flag == 0)
                {
                    continue;
                }
                else
                {
                    if (my_node[tail-1].num < min_num)
                    {
                        min_num = my_node[tail-1].num;
                    }
                }
            }
            else if (ty == overy && go_in == 1)
            {
                flag = 1;
                if (tx > overx)
                {
                    for ( j = tx-1 ; j >= overx ; j--)
                    {
                        if (map[j][ty] != '#')
                        {
                            flag = 1;
                        }
                        else
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
                else
                {
                    for ( j = tx+1 ; j <= overx ; j++)
                    {
                        if (map[j][ty] != '#')
                        {
                            flag = 1;
                        }
                        else
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
                if (flag == 0)
                {
                    continue;
                }
                else
                {
                    if (my_node[tail-1].num < min_num)
                    {
                        min_num = my_node[tail-1].num;
                    }
                }
            }
        }
        head++;
    }
    if (min_num == 999999)
    {
        printf("No!!!");
    }
    else
    {
        printf("%d",min_num);
    }
    system("pause");
    return 0;
}