#include <iostream>
#include <cstdio>
using namespace std;
void cal(long long a , long long b , long long c)
{
    long long tempb = b;
    long long tempa = a;
    long long ans = 1;
    while ( b > 0)
    {
        if (b % 2 == 1 )
        {
            ans = (ans * a) % c;
        }
        b /= 2;
        a = (a * a) % c;
    }
    printf("%lld^%lld mod %lld=%lld",tempa,tempb,c,ans);
}
int main()
{
    long long b , p , k;
    cin >> b >> p >> k;
    cal(b,p,k);
    system("pause");
    return 0;
}
