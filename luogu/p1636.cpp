#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;
int e[1005][1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , m;
    int a , b;
    cin >> n >> m;
    for (int i = 1; i <= n ; i++)
    {
        for (int j =1 ; j <= n ; j++)
        {
            if (i == j)
                e[i][j] = 0;
            else
                e[i][j] = INF;
        }
    }
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> a >> b;
        e[a][b] = 1;
    }
    for (int k = 1 ; k <= n ; k++)
    {
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = 1 ; j <= n ; j++)
            {
                if (e[i][k] < INF && e[k][j] < INF && e[i][j] > e[i][k]+e[k][j])
                {
                    e[i][j] = e[i][k]+e[k][j];
                }
            }
        }
    }
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j =1 ; j <= n ; j++)
        {
            cout << e[i][j] << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}