#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    long long n , a;
    long long temp;
    long long b , c;
    cin >> T;
    while(T--)
    {
        cin >> n >> a;
        if (n > 2 || n == 0)
        {
            cout << -1 << " " << -1 << endl;
        }
        if (n == 2)
        {
            if (a % 2 == 1)
            {
                temp = (a-1) / 2;
                c = temp*temp+(temp+1)*(temp+1);
                b = c-1;
            }
            else
            {
                temp = (a-2) / 2;
                c = 1+(temp-1)*(temp-1);
                b = c-2;
            }
            cout << b << " " << c << endl;
        }
        if (n == 1)
        {
            b = a+1;
            c = a+b;
            cout << b << " " << c << endl;
        }
    }

    system("pause");
    return 0;
}