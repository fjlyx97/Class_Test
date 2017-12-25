#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    float num;
    float begin = 2;
    float res = 0;
    int ans = 0;
    cin >> num;
    while (res < num)
    {
        res += begin;
        begin *= 0.98;
        ans++;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}