#include <iostream>
using namespace std;
#define INF 0x3f3f3f3f
int book_value[1001][1001] = {0};
int dp[1001][1001] = {0};
inline int max(const int& a , const int& b)
{
    if (a > b) return a;
    else return b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    int power[1001] = {0};
    cin >> N;
    for (int i = 1 ; i <= N ; i++)
    {
        cin >> power[i];
    }
    int max_power = -INF;
    int min_power = INF;
    for (int i = 1 ; i <= N ; i++)
    {
        max_power = -INF;
        min_power = INF;
        for (int j = i;  j <= N ; j++)
        {
            if (power[j] > max_power)
                max_power = power[j];
            if (power[j] < min_power)
                min_power = power[j];
            book_value[i][j] = (max_power-min_power)*(max_power-min_power);
        }
    }
    for (int i = 1 ; i <= N ; i++)
    {
        dp[1][i] = book_value[1][i];
    }
    for (int i = 2 ; i <= N ;i++)
    {
        for (int j = i ; j <= N ;j++)
        {
            for (int k = i-1 ; k < j ; k++)
            {
                dp[i][j] = max(dp[i][j],dp[i-1][k]+book_value[k+1][j]);
            }
        }
    }
    int ans = -INF;
    for (int i = 1 ; i <= N; i++)
    {
        ans = max(ans,dp[i][N]);
    }
    
    cout << ans << endl;



    system("pause");
    return 0;
}