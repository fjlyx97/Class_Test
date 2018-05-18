#include <iostream>
#include <cstdio>
#define INF 0x3f3f3f3f
using namespace std;
int map[105][105] = {0};
bool book[105][105] = {0};
int save_ans[105][105] = {0};
int R , C;
void read(int& num)
{
    char c;
    num = 0;
    while (c = getchar(),c > '9' || c < '0');
    while (c >= '0' && c <= '9')
    {
        num = num*10 + c-'0';
        c = getchar();
    }
}
int max_ans = -INF;
int dfs(int i,int j ,int step)
{
    if ( i > R || j > C || i < 1 || j < 1)
    {
        return;
    }
    max_ans = step > max_ans ? step : max_ans;

    if (map[i][j+1] < map[i][j] && !book[i][j+1])
    {
        book[i][j+1] = 1;
        dfs(i,j+1,step+1);
        book[i][j+1] = 0;
    }
    if (map[i+1][j] < map[i][j] && !book[i+1][j])
    {
        book[i+1][j] = 1;
        dfs(i+1,j,step+1);
        book[i+1][j] = 0;
    }
    if (map[i][j-1] < map[i][j] && !book[i][j-1])
    {
        book[i][j-1] = 1;
        dfs(i,j-1,step+1);
        book[i][j-1] = 0;
    }
    if (map[i-1][j] < map[i][j] && !book[i-1][j])
    {
        book[i-1][j] = 1;
        dfs(i-1,j,step+1);
        book[i-1][j] = 0;
    }

    return;
}
int main()
{
    scanf("%d %d",&R,&C);
    for (int i = 1 ; i <= R ; i++)
    {
        for (int j = 1 ; j <= C ; j++)
        {
            read(map[i][j]);
        }
    }
    for (int i = 1 ; i <= R ; i++)
    {
        for (int j = 1 ; j <= C ; j++)
        {
            dfs(i,j,1);
        }
    }
    printf("%d\n",max_ans);
    system("pause");
    return 0;
}