#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a , b;
    cin >> a >> b;
    b += a*10;
    cout << b/19 << endl;

    system("pause");
    return 0;
}