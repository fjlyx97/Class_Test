#include <iostream>
using namespace std;
int a[100005];
int main()
{
    int T;
    int n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> a[i];
        }
    }
    system("pause");
    return 0;
}