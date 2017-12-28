#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    float s , x;
    cin >> s >> x;
    float begin = 7;
    float ans = 0;
    while(1)
    {
        if (s-x <= ans)
        {
            ans += begin;
            begin *= 0.98;
            if (ans <= s+x)
            {
                cout << 'y' << endl;
            }
            else
            {
                cout << 'n' << endl;
            }
            return 0;
        }
        ans += begin;
        begin *= 0.98;
    }

    system("pause");
    return 0;
}