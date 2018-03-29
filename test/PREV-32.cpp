#include <iostream>
using namespace std;
int num[101];
int temp_num[101];
int main()
{
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> num[i];
    }
    int flag;
    while(true)
    {
        flag = 1;
        for (int i = 1 ; i < n ; i++)
        {
            if (num[i] != num[i+1])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            break;
        }
        for (int i = 1 ; i < n ; i++)
        {
            temp_num[i] = num[i] / 2;
            num[i] += num[i+1] / 2;
        }
        temp_num[n] = num[n] / 2;
        num[n] += temp_num[1];
        for (int i = 1 ; i < n ; i++)
        {
            num[i] -= temp_num[i];
            if (num[i] % 2 == 1)
            {
                num[i]++;
                ans++;
            }
        }
        num[n] -= temp_num[n];
        if (num[n] % 2 == 1)
        {
            num[n]++;
            ans++;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}