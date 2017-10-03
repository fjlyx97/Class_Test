#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    int x;
    scanf("%d",&x);
    int num;
    num = x*x;
    if ( num % 10 ==  x)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }

    system("pause");
    return 0;
}