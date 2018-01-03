#include <iostream>
#include <cstdio>
using namespace std;
int cal(int num)
{
    int ans = 1;
    for ( int i = 1 ; i <= num ; i++)
    {
        ans *= i;
    }
    return ans;
}
int main()
{
    int m , n;
    float res = 0;
    scanf("%d,%d",&m,&n);    
    if ( m > n )
    {
        float a = cal(m);
        float b = cal(n)*cal(m-n);
        res = a / b;
    }
    else
    {
        res = 0;
    }
    printf("%.2f",res);
    system("pause");
    return 0;
}