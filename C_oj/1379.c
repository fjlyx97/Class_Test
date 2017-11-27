#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int T;
    scanf("%d",&T);
    float num[3][2];
    int i , j;
    float result[2];
    float k1 , k2;
    float save[2][3];
    float temp[3];
    while (T--)
    {
        for ( i = 0 ; i < 3 ; i++)
        {
            for ( j = 0 ; j < 2 ; j++)
            {
                scanf("%f",&num[i][j]);
            }
        }
        if (!(num[1][0] - num[0][0]))
        {
            k2 = 0;
            result[0] = num[0][0];
            result[1] = num[2][1];
            printf("%.2f %.2f\n",result[0],result[1]);
        }
        else
        {
            k1 = (num[1][1] - num[0][1]) / (num[1][0] - num[0][0]);
            k2 = -1 / k1;
            save[0][0] = k1;
            save[0][1] = -1;
            save[0][2] = -(k1 * num[0][0] - num[0][1]);
            save[1][0] = k2;
            save[1][1] = -1;
            save[1][2] = -(k2 * num[2][0] - num[2][1]);

            temp[0] = save[0][0] - save[1][0];
            temp[1] = save[0][1] - save[1][1];
            temp[2] = save[0][2] - save[1][2];
            result[0] = (-temp[2]) / temp[0];
            result[1] = k1 * result[0] + save[0][2];
            printf("%.2f %.2f\n",result[0],result[1]);
        }
    }

    system("pause");
    return 0;
}