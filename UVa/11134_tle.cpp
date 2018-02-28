#include <iostream>
#include <algorithm>
using namespace std;
struct rook
{
    int xl , xr , yl , yr;
}rooks[5001];
int rows[5001] = {0};
int cols[5001] = {0};
int res[5001][2] = {0};
int n;
int index = 1;
int flag = 0;

bool cmp(rook a , rook b)
{
    if ( (a.yl-a.xl)*(a.yr-a.xr) < (b.yl-b.xl)*(b.yr-b.xr) )
    {
        return true;
    }
    return false;
}

void dfs(int step)
{
    if (flag)
    {
        return;
    }
    if (step == n+1)
    {
        for (int i = 1 ; i < index ; i++)
        {
            cout << res[i][0] << " " << res[i][1] << endl;
        }
        flag = 1;
        return;
    }
    for (int i = rooks[step].xl ; i <= rooks[step].yl ; i++)
    {
        for (int j = rooks[step].xr ; j <= rooks[step].yr ; j++)
        {
            if (rows[i] == 0 && cols[j] == 0)
            {
                rows[i] = 1;
                cols[j] = 1;
                res[index][0] = i;
                res[index][1] = j;
                index++;
                dfs(step+1);
                index--;
                res[index][0] = 0;
                res[index][1] = 0;
                rows[i] = 0;
                cols[j] = 0;
            }
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n)
    {
        flag = 0;
        index = 1;
        if (n == 0)
        {
            break;
        }
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> rooks[i].xl >> rooks[i].xr >> rooks[i].yl >> rooks[i].yr;
        }
        sort(rooks+1,rooks+n+1,cmp);
        dfs(1);
        if (!flag)
        {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    system("pause");
    return 0;
}