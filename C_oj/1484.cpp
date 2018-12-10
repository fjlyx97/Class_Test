#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Y;
    cin >> Y;
    if (abs(Y-2022) % 12 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    system("pause");
    return 0;
}