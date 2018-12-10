#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    double N , X;
    double height = 0;
    int ans = 0;
    cin >> N >> X;
    while(true)
    {
        height += X;
        X *= 0.95;
        ans++;
        if (height >= N)
        {
            break;
        }
        height -= 2;
        if (X <= 2)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;

    system("pause");
    return 0;
}