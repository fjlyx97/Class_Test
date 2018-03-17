#include <iostream>
using namespace std;
int num[100001] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N , K;
    int ans = 0;
    int K_mul;
    cin >> N >> K;
    for (int i = 1 ; i <= N ; i++)
    {
        cin >> num[i];
        num[i] = num[i] + num[i-1];
    }
    for (int i = 0 ; i <= N ; i++)
    {
        for (int j = i+1 ; j <= N ;)
        {
            K_mul = num[j] - num[i];
            if (K_mul % K == 0)
            {
                ans++;
                j = j+(j-i);
            }
            else
            {
                j++;
            }
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}