#include <iostream>
#include <algorithm>
using namespace std;
int time_value[101][2];
int book[101][1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T , M;
    cin >> T >> M;
    for (int i = 1 ; i <= M ; i++)
    {
        cin >> time_value[i][0] >> time_value[i][1];
    }
    for (int i = 1 ; i <= M ; i++)
    {
        for (int j = T ; j >= 1 ; j--)
        {
            if ( j >= time_value[i][0] )
            {
                book[i][j] = max(book[i-1][j],book[i-1][j-time_value[i][0]]+time_value[i][1]);
            }
            else
            {
                book[i][j] = book[i-1][j];
            }
        }
    }
    cout << book[M][T] << endl;
    system("pause");
    return 0;
}