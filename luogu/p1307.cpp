#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int tempN = N;
    int wei = 0;
    while (tempN)
    {
        wei++;
        tempN /= 10;
    }
    int ans = 0;
    for ( int i = wei-1 ; i >= 0 ; i--)
    {
        ans += pow(10,i)* (N%10);
        N /= 10;
    }
    cout << ans << endl;

    system("pause");
    return 0;
}