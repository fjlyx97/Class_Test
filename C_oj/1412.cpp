#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    double a , b;
    int n;
    int ans;
    while (T--)
    {
        cin >> n;
        a = n * log10(n*1.0) - (long long)(n*log10(n*1.0));
        //cout << a << endl;
        b = pow((double)10,a);
        //cout << b << endl;
        ans = (int)b;
        cout << ans << endl;
    }

    system("pause");
    return 0;
}