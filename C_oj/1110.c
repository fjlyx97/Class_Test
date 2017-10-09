#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    int x;
    scanf("%d",&x);
    float result = 0;
    if ( 1 < x && x < 100)
    {
        if (x % 2 == 0)
        {
            result = sin(x+2);
        }
    }
    else if ( x > 100)
    {
        result = 2 * sqrt(x-1);
    }
    else
    {
        result = x;
    }
    printf("%.2f",result);
    system("pause");
    return 0;
}