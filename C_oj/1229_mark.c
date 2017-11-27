#include <stdio.h>
#include <stdlib.h>
int cal(int a, int b, int c)
{
    int ans = 1;
    int i;
    int k;
    a = a % c;
    if ( b % 2 == 1)
    {
        ans = (ans * a ) % c;
    }
    k = (a * a) % c;
    for ( i = 1 ; i <= b / 2 ; i++)
    {
        ans = (ans * k ) % c;
    }
    ans = ans % c;
    return ans;
}
int main(void)
{
    int a , b , c;
    scanf("%d %d %d",&a,&b,&c);
    int result = cal(a,b,c);
    printf("%d",result);

    system("pause");
    return 0;
}