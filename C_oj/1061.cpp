#include <iostream>
using namespace std;
int dp[1001][1001] = {0};
#define MAX(a,b) a>b?a:b
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , m;
    int num[205] = {0};
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> num[i];
    }
    for (int i = 1 ; i <= n ; i++)
    {
        dp[i][1] = dp[i-1][1] + num[i];
    }
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 2 ; j <= m ; j++)
        {
            int min_value = 0x3f3f3f3f;
            for (int k = 1 ; k < i ; k++)
            {
                int temp = MAX(dp[i][1]-dp[k][1],dp[k][j-1]);
                if (temp < min_value)
                    min_value = temp;
            }
            dp[i][j] = min_value;
        }
    }
    cout << dp[n][m] << endl;



    system("pause");
    return 0;
}