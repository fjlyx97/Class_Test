#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    float x,y;
    scanf("%f",&x);
    if ( x < 1)
    {
        y = cos(x+2);
    }
    else
    {
        y = sqrt(x-1);
    }
    printf("%.2f",y);

    system("pause");
    return 0;
}