#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
void cal(float x1 , float y1 , float x2 , float y2 , float k)
{
    float angle = (k / 180) * PI;
    angle = -angle;
    float result_x , result_y;
    result_x = (x1-x2)*cos(angle)-(y1-y2)*sin(angle)+x2;
    result_y = (y1-y2)*cos(angle)+(x1-x2)*sin(angle)+y2;
    printf("%.2f %.2f\n",result_x,result_y);
}
int main(void)
{
    int T;
    scanf("%d",&T);
    float x1 , y1 , x2 , y2 , k;
    while (T--)
    {
        scanf("%f %f %f %f %f",&x1,&y1,&x2,&y2,&k);
        cal(x1,y1,x2,y2,k);
    }

    system("pause");
    return 0;
}