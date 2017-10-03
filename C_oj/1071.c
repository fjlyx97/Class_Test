#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    float x , y;
    scanf("%f",&x);
    if ( x > 3)
    {
        y = cos(x+3);
    }
    else if ( x < 1)
    {
        y = x + 1;
    }
    else
    {
        y = 2 * sqrt(x) - 1;
    }
    printf("%.2f",y);

    system("pause");
    return 0;
}