#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
int main(void)
{
    float x , y , z;
    float a , r;
    scanf("%f %f %f", &x , &y , &z);
    a = sqrt(pow(x,2)+pow(y,2));
    r = sqrt(pow(a,2)+pow(z,2));
    float v;
    v = (4.0 / 3) * PI * pow(r,3);
    printf("%.2f",v);


    system("pause");
    return 0;
}