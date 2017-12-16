#include <stdio.h>
int main(void)
{
    float x;
    float y;
    scanf("%f",&x);
    if (  x <= 150 )
    {
        y = 0;
    }
    else if (150 < x && x <= 10000)
    {
        y = (1.0 / 3.0)*(x-150);
    }
    else
    {
        y = (10000 - 150) * (1.0/3.0) + (x-10000)*(3.0/5.0);
    }
    printf("%.2f",y);
    return 0;
}