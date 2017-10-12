#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
double add_num(double);
int main(void)
{
    double x;
    scanf("%lf",&x);
    x = fmod(x,2 * PI);
    double result = x;
    int i;
    double temp = 0;
    for (i = 1 ; ; i++)
    {
        temp = pow(x,(i+1) * 2 - 1) / add_num((i+1) * 2 -1);
        if ( fabs(temp) < 10e-5)
        {
            break;
        }
        if (i % 2 == 0)
        {
            result += pow(x,(i+1) * 2 - 1) / add_num((i+1) * 2 -1);
        }
        else if ( i % 2 == 1)
        {
            result -= pow(x,(i+1) * 2 - 1) / add_num((i+1) * 2 -1);
        }
    }
    printf("%.3lf",result);

    system("pause");
    return 0;
}
double add_num(double num)
{
    int i;
    double result = 1;
    for (i = num ;i > 0 ; i--)
    {
        result = result * i; 
    }
    return result;
}