#include <iostream>
using namespace std;
int prices[205][205] = {0};
int book[205];
int dis[205];
#define INF 0x3f3f3f3f
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ;j <= n ; j++)
        {
            if (i == j)
                prices[i][j] = 0;
            else
                prices[i][j] = INF;
        }
    }
    for (int i = 1 ; i <= n-1 ; i++)
    {
        for (int j = i+1 ; j <= n ; j++)
        {
            cin >> prices[i][j];
        }
    }
    for (int i = 1 ; i <= n ; i++)
    {
        dis[i] = prices[1][i];
    }
    book[1] = 1;
    dis[1] = 0;
    int min_dis;
    int min_index;
    for (int i = 2 ; i <= n ; i++)
    {
        min_dis = INF;
        for (int j = 1 ; j <= n ; j++)
        {
            if (book[j] == 0 && dis[j] < min_dis)
            {
                min_dis = dis[j];
                min_index = j;
            }
        }
        book[min_index] = 1;
        for (int v = 1 ; v <= n ; v++)
        {
            if (prices[i][v] < INF)
            {
                if (dis[v] > dis[min_index]+prices[min_index][v])
                {
                    dis[v] = dis[min_index]+prices[min_index][v];
                }
            }
        }
    }
    cout << dis[n] << endl;
    system("pause");
    return 0;
}