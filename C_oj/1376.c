#include <stdio.h>
#include <stdlib.h>
void judge(int n , int k)
{
    int num[n];
    int i = 0;
    int total = 0;
    int result = 0;
    int del = 0;
    for ( i = 0 ; i < n ; i++)
    {
        scanf("%d",&num[i]);
        total += num[i];
    }
    if (total % k != 0)
    {
        printf("-1\n");
        return;
    }
    else
    {
        if ( n > k )
        {
            del = n - k;
        }
    }
}
int main(void)
{
    int T;
    scanf("%d",&T);
    int n , k;
    while (T--)
    {
        scanf("%d %d",&n,&k);
    }

    system("pause");
    return 0;
}