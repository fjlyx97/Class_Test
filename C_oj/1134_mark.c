#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double cal(double);
int main(void)
{
    double x;
    scanf("%lf",&x);
    double result = 1;;
    int i = 0;
    for (i = 1 ; ; i++)
    {
        result += pow(x,i) / cal(i);
        if ( fabs(pow(x,i) / cal(i)) < pow(10,-5))
        {
            break;
        }
    }
    printf("%.3lf",result);


    system("pause");
    return 0;
}
double cal(double num)
{
    double i = 0;
    double result = 1;
    for ( i = num ; i > 0 ; i--)
    {
        result *= i;
    }
    return result;
}