#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    float x;
    scanf("%f",&x);
    float result;
    if ( x < 1)
    {
        result = x;
    }
    else if ( 1 <= x && x < 10)
    {
        result = 2*x-1;
    }
    else
    {
        result = x*x-11;
    }
    printf("%.2f",result);


    system("pause");
    return 0;
}