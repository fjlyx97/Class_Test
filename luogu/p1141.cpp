#include <iostream>
#include <cstring>
using namespace std;
int map[1001][1001] = {0};
bool book[1001][1001];
int map_book[1001][1001] = {0};
int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
struct queue
{
    int x;
    int y;
}queue[5002001],book_queue[5002001];
int num;
void bfs(int i , int j , int n)
{
    if (map_book[i][j] != 0)
    {
        num = map_book[i][j];
        return;
    }
    int head = 1 , tail = 1;
    int book_head = 1 , book_tail = 1;
    int tx , ty;
    queue[tail].x = i;
    queue[tail].y = j;
    book[i][j] = 1;
    num++;
    book_queue[book_tail].x = i;
    book_queue[book_tail].y = j;
    book_tail++;
    tail++;
    while (head < tail )
    {
        if (map[queue[head].x][queue[head].y] == 1)
        {
            for (int k = 0 ; k <= 3 ; k++)
            {
                tx = queue[head].x + next[k][0];
                ty = queue[head].y + next[k][1];
                if ( tx < 1 || ty < 1 || tx > n || ty > n)
                {
                    continue;
                }
                if (book[tx][ty] == 0 && map[tx][ty] == 0)
                {
                    queue[tail].x = tx;
                    queue[tail].y = ty;
                    book_queue[book_tail].x = tx;
                    book_queue[book_tail].y = ty;
                    book[tx][ty] = 1;
                    num++;
                    tail++;
                    book_tail++;
                }
            }
        }
        else
        {
            for (int k = 0 ; k <= 3 ; k++)
            {
                tx = queue[head].x + next[k][0];
                ty = queue[head].y + next[k][1];
                if ( tx < 1 || ty < 1 || tx > n || ty > n)
                {
                    continue;
                }
                if (book[tx][ty] == 0 && map[tx][ty] == 1)
                {
                    queue[tail].x = tx;
                    queue[tail].y = ty;
                    book_queue[book_tail].x = tx;
                    book_queue[book_tail].y = ty;
                    book[tx][ty] = 1;
                    num++;
                    tail++;
                    book_tail++;
                }
            }
        }
        head++;
    }
    while (book_head < book_tail)
    {
        map_book[book_queue[book_head].x][book_queue[book_head].y] = num;
        book_head++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , m;
    cin >> n >> m;
    char temp;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            cin >> temp;
            map[i][j] = temp-48;
        }
    }
    int i , j;
    int index = 0;
    while (m--)
    {
        cin >> i >> j;
        num = 0;
        bfs(i,j,n);
        cout << num << endl;
    }
    system("pause");
    return 0;
}