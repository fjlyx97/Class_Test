#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void cal(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4,float x0,float y0)
{
    float k1 , k2;
    if ( x2 - x1 == 0 || x3 - x2 == 0)
    {
        if (x0 < x1 && x4 < x0 && y0 < y2 && y1 < y0 )
        {
            printf("T\n");
        }
        else
        {
            printf("F\n");
        }
    }
    else
    {
        k1 = (y2-y1) / (x2-x1);
        k2 = (y3-y2) / (x3-x2);
        float num[4][3];
        num[0][0] = k1;
        num[0][1] = -1;
        num[0][2] = -(k1*x1-y1);

        num[1][0] = k2;
        num[1][1] = -1;
        num[1][2] = -(k2*x2-y2);

        num[2][0] = k1;
        num[2][1] = -1;
        num[2][2] = -(k1*x3-y3);

        num[3][0] = k2;
        num[3][1] = -1;
        num[3][2] = -(k2*x4-y4);

        float distance[4];
        distance[0] = fabs(num[0][0] * x0 - y0 + num[0][2]) / sqrt(pow(num[0][0],2)+pow(num[0][1],2));
        distance[1] = fabs(num[1][0] * x0 - y0 + num[1][2]) / sqrt(pow(num[1][0],2)+pow(num[1][1],2));
        distance[2] = fabs(num[2][0] * x0 - y0 + num[2][2]) / sqrt(pow(num[2][0],2)+pow(num[2][1],2));
        distance[3] = fabs(num[3][0] * x0 - y0 + num[3][2]) / sqrt(pow(num[3][0],2)+pow(num[3][1],2));

        float len1 , len2;
        len1 = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
        len2 = sqrt(pow((x3-x2),2) + pow((y3-y2),2));

        if (distance[0] <= len2 && distance[2] <= len2 && distance[1] <= len1 && distance[3] <= len1)
        {
            printf("T\n");
        }
        else
        {
            printf("F\n");
        }
    }
}
int main(void)
{
    int T;
    scanf("%d",&T);
    getchar();
    float x1,y1,x2,y2,x3,y3,x4,y4,x0,y0;
    int i = 0;
    while (T--)
    {
        scanf("%f %f %f %f %f %f %f %f %f %f",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4,&x0,&y0);
        cal(x1,y1,x2,y2,x3,y3,x4,y4,x0,y0);
    }

    system("pause");
    return 0;
}