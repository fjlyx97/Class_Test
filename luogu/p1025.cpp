#include <iostream>
using namespace std;
int n , k;
int ans = 0;
int book[7] = {0};
void dfs(int step)
{
    int temp = 0;
    for (int t = 1 ; t < step ; t++)
    {
        temp += book[t];
    }
    if (step == k+1)
    {
        if (temp == n)
        {
            //for (int t = 1 ; t < step ; t++)
            //{
            //    cout << book[t] << " ";
            //}
            //cout << endl;
            ans++;
        }
        return;
    }
    for (int i = 0 ; i <= n-temp ; i++)
    {
        book[step] += i;
        dfs(step+1);
        book[step] -= i;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    int t = 1;
    for (int i = 1 ; i <= k ; i++)
    {
        t *= i;
    }
    dfs(1);
    cout << ans / t - (k-1)<< endl;

    system("pause");
    return 0;
}