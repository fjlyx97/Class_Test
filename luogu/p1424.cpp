#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x , n;
    cin >> x >> n;
    int ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        if (x == 6)
        {
            x++;
            continue;
        }
        else if ( x == 7)
        {
            x = 1;
            continue;
        }
        x++;
        ans += 250;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}