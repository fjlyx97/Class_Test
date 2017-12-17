#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;
int num[30001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int w;
    int n;
    cin >> w >> n;
    for ( int i = 1 ; i <= n ; i++)
    {
        cin >> num[i];
    }
    sort(num+1,num+n+1,greater<int>());
    int ans = 0;
    int temp = 0;
    int j_temp = n;
    for (int i = 1 ; i <= n ; i++)
    {
        temp = num[i];
        for (int j = j_temp ; j > i ; j--)
        {
            temp += num[j];
            if (temp > w)
            {
                ans++;
                j_temp = j;
                break;
            }
        }
        if ( i == j_temp ) ans++;
    }
    cout << ans << endl;

    system("pause");
    return 0;
}