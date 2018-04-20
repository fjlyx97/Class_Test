#include <iostream>
#include <cstdio>
using namespace std;
long long map[25][25] = {0};
int book[25][25] = {0};
int main()
{
    int n , m , mx , my;
    cin >> n >> m >> mx >> my;
    book[mx][my] = -1;
    if (mx+1 <= n && my-2 <= m)
        book[mx+1][my-2] = -1;
    if (mx+2 <= n && my-1 <= m)
        book[mx+2][my-1] = -1;
    if (mx+2 <= n && my+1 <= m)
        book[mx+2][my+1] = -1;
    if (mx+1 <= n && my+2 <= m)
        book[mx+1][my+2] = -1;
    if (mx-1 <= n && my-2 <= m)
        book[mx-1][my-2] = -1;
    if (mx-2 <= n && my-1 <= m)
        book[mx-2][my-1] = -1;
    if (mx-2 <= n && my+1 <= m)
        book[mx-2][my+1] = -1;
    if (mx-1 <= n && my+2 <= m)
        book[mx-1][my+2] = -1;

    map[0][0] = 1;
    for (int i = 0 ; i <= m ; i++)
    {
        map[0][i] = 1;
    }
    for (int i = 0 ; i <= n ; i++)
    {
        map[i][0] = 1;
    }
    for (int i = 0 ; i <= n ; i++)
    {
        if (book[i][0] == -1)
        {
            for (int j = i ; j <= n ; j++)
            {
                map[j][0] = 0;
            }
            break;
        }
    }
    for (int i = 0 ; i <= m ; i++)
    {
        if (book[0][i] == -1)
        {
            for (int j = i ; j <= m ; j++)
            {
                map[0][j] = 0;
            }
            break;
        }
    }
    for (int i = 0 ; i <= n ; i++)
    {
        for (int j = 0 ; j <= m ; j++)
        {
            if (i == 0 || j == 0)
            {
                if (book[i][j] == -1)
                    map[i][j] = 0;
                continue;
            }
            if (book[i][j] == -1)
            {
                map[i][j] = 0;
                continue;
            }
            map[i][j] = map[i][j-1] + map[i-1][j];
        }
    }
    for (int i = 0 ; i <= n ; i++)
    {
        for (int j = 0 ; j <= m ; j++)
        {
            printf("%5lld " , map[i][j]);
        }
        printf("\n");
    }
    printf("%lld",map[n][m]);
    system("pause");
    return 0;
}