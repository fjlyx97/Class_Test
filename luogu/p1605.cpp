#include <iostream>
#include <cstring>
using namespace std;
int map[6][6];
int book[6][6];
int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int ans = 0;
void dfs(int x , int y, int N , int M , int overx ,int overy)
{
    if ( x == overx && y == overy)
    {
        ans++;
        return;
    }
    int tx , ty;
    for (int i = 0 ; i < 4 ; i++)
    {
        tx = x+next[i][0];
        ty = y+next[i][1];
        if (tx <= 0 || ty <= 0 || tx > N || ty > M)
        {
            continue;
        }
        if (book[tx][ty] == 0 && map[tx][ty] != -1)
        {
            book[tx][ty] = 1;
            dfs(tx,ty,N,M,overx,overy);
            book[tx][ty] = 0;
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N , M , T;
    int startx , starty , overx , overy;
    int thingx , thingy;
    memset(map,0,sizeof(map));
    memset(book,0,sizeof(book));
    cin >> N >> M >> T;
    cin >> startx >> starty >> overx >> overy; 
    map[startx][starty] = 1;
    map[overx][overy] = 2;
    while (T--)
    {
        cin >> thingx >> thingy;
        map[thingx][thingy] = -1;
    }
    book[startx][starty] = 1;
    dfs(startx,starty,N,M,overx,overy);
    cout << ans << endl;
    system("pause");
    return 0;
}