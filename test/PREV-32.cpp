#include <iostream>
using namespace std;
int num[101];
int main()
{
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> num[i];
    }
    while(true)
    {
        for (int i = 1 ; i <= n ; i++)
        {

        }
        for (int i = 1 ; i < n ; i++)
        {
            num[i+1] += num[i] / 2;
            num[i] /= 2;
            if (num[i] % 2 == 1 && i != 1)
            {
                num[i]++;
                ans++;
            }
        }
        num[1] += num[n] / 2;
        num[n] /= 2;
        if (num[n] % 2 == 1)
        {
            num[n]++;
            ans++;
        }
        if (num[1] % 2 == 1)
        {
            num[1]++;
            ans++;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}