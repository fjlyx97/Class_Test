#include <iostream>
#include <cstring>
using namespace std;
#define max(a,b) a>b?a:b
int book[101][2] = {0};
int mark[101][1001] = {0};
int dp(int i , int mtime)
{
    if (i == 1 && mtime >= book[i][0])
    {
        mark[i][mtime] = book[i][1];
        return mark[i][mtime];
    }
    else if (i == 1 && mtime < book[i][0])
    {
        mark[i][mtime] = 0;
        return 0;
    }

    if (mtime >= book[i][0])
    {
        if (mark[i][mtime] != -1)
        {
            return mark[i][mtime];
        }
        int a = dp(i-1,mtime-book[i][0])+book[i][1];
        int b = dp(i-1,mtime);
        mark[i][mtime] = max(a,b);
        return mark[i][mtime];
    }
    else
    {
        if (mark[i][mtime] != -1)
        {
            return mark[i][mtime];
        }
        else
        {
          mark[i][mtime] = mark[i-1][mtime];
          return mark[i][mtime];
        }
    }
}
int main()
{
    memset(mark,-1,sizeof(mark));
    int T , M;
    cin >> T >> M;
    for (int i = 1 ; i <= M ; i++)
    {
        cin >> book[i][0] >> book[i][1];
    }
    cout << dp(M,T) << endl;
    system("pause");
    return 0;
}