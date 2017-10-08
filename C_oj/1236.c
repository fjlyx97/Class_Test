#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    float x;
    scanf("%f",&x);
    float result;
    if ( x >= 3)
    {
        result = sqrt(x);
    }
    else if ( -3 < x && x < 3)
    {
        result = pow(x,2);
    }
    else
    {
        result = 4 / x;
    }
    printf("%.3f",result);

    system("pause");
    return 0;
}