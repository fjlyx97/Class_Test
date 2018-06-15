#include <iostream>
#include <algorithm>
using namespace std;
long long e[1005][1005];
long long dis[1005];
bool book[1005];
#define INF 0x3f3f3f3f
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long n , m;
    int x , y , z;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            if (i == j)
                e[i][j] = 0;
            else
                e[i][j] = INF;
        }
    }
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> x >> y >> z;
        e[x][y] = z;
    }
    for (int i = 1 ; i <= n ; i++)
    {
        dis[i] = e[1][i];
    }
    book[1] = 1;
    dis[1] = 0;
    int min_index;
    int min_num;
    for (int i = 1 ; i <= n ; i++)
    {
        min_num = INF;
        for (int j = 1 ; j <= n ; j++)
        {
            if (book[j] == 0 && dis[j] < min_num)
            {
                min_num = dis[j];
                min_index = j;
            }
        }
        book[min_index] = 1;
        for (int j = 1 ; j <= n ; j++)
        {
            if (e[min_index][j] < INF && e[min_index][j] != 0) 
            {
                if (dis[j] > dis[min_index]*e[min_index][j])
                {
                    dis[j] = dis[min_index]*e[min_index][j];
                }
            }
        }
    }
    //for (int i = 1 ; i <= n ; i++)
    //{
    //    cout << dis[i] << " ";
    //}
    cout << dis[n] % 9987;
    cout << endl;
    system("pause");
    return 0;
}