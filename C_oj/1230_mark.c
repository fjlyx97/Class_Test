#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    long long a , b , c;
    long long ans = 1;
    scanf("%I64d %I64d %I64d",&a,&b,&c);
    while ( b > 0 )
    {
        if ( b % 2 == 1)
        {
            ans = (ans * a ) % c;
        }
        b /= 2;
        a = (a * a) % c;
    }
    printf("%I64d",ans);
    system("pause");
    return 0;
}