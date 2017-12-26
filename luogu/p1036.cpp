#include <iostream>
using namespace std;
int num[21];
int book[21] = {0};
int n , k;
int res = 0;
void dp(int step , int ans , int begin)
{
    if (step == k+1)
    {
        int flag = 1;
        for ( int i = 2 ; i < ans ; i++)
        {
            if (ans % i == 0)
            {
                flag = 0;
                break;
            }
        }
        if (ans == 2)
        {
            flag = 0;
            res++;
        }
        if (flag)
        {
            res++;
        }
        return;
    }
    for ( int i = begin ; i <= n ; i++)
    {
        if (book[i] == 0)
        {
            book[i] = 1;
            ans += num[i];
            dp(step+1 , ans , i);
            ans -= num[i];
            book[i] = 0;
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for ( int i = 1 ; i <= n ; i++)
    {
        cin >> num[i];
    }
    dp(1,0,1);
    cout << res << endl;
    system("pause");
    return 0;
}