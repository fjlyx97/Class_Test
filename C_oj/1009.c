#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    float x;
    float result;
    scanf("%f",&x);
    if (x >= 0)
    {
        result = sqrt(x);
    }
    else
    {
        result = pow(x+1.0,2) + 2*x + 1.0/x;
    }
    printf("%.2f",result);
    system("pause");
    return 0;
}