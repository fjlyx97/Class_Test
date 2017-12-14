#include <iostream>
#include <algorithm>
using namespace std;
int book[31][20001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int V , n;
    int value[31];
    cin >> V >> n;
    for (int i = 1 ; i <= n ; i++ )
    {
        cin >> value[i];
    }
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= V ; j++)
        {
            if ( j >= value[i])
            {
                book[i][j] = max(book[i-1][j],book[i-1][j-value[i]]+value[i]);
            }
            else
            {
                book[i][j] = book[i-1][j];
            }
        }
    }
    cout << V-book[n][V] << endl;
    system("pause");
    return 0;
}