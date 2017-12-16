#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int map[401][401];
int book[401][401];
int next[8][2] = {{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
struct myhorse
{
    int x;
    int y;
    int step;
}horse[102400];
int main()
{
    int n , m , startx , starty;
    int head = 1 , tail = 1;
    cin >> n >> m >> startx >> starty;
    memset(map,-1,sizeof(map));

    map[startx][starty] = 0;
    book[startx][starty] = 1;
    horse[tail].x = startx;
    horse[tail].y = starty;
    horse[tail].step = 0;
    tail++;
    
    int tx , ty;
    while (head < tail)
    {
        for ( int i = 0 ; i < 8 ; i++)
        {
            tx = horse[head].x + next[i][0];
            ty = horse[head].y + next[i][1];
            if (tx < 1 || ty < 1 || tx > n || ty > m)
            {
                continue;
            }
            if (book[tx][ty] == 0)
            {
                book[tx][ty] = 1;
                horse[tail].x = tx;
                horse[tail].y = ty;
                horse[tail].step = horse[head].step+1;
                map[tx][ty] = horse[tail].step;
                tail++;
            }
        }
        head++;
    }
    for ( int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            printf("%-5d",map[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}