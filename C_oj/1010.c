#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    float a , b , c;
    float x1 , x2;
    scanf("%f %f %f", &a , &b, &c);
    float temp = b*b - 4*a*c;
    if ( temp >= 0)
    {
        x1 = (-b + sqrt(temp)) / (2*a);
        x2 = (-b - sqrt(temp)) / (2*a);
    }
    printf("x1=%.2f x2=%.2f",x1,x2);


    system("pause");
    return 0;
}