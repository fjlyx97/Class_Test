#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    float num[N][4];
    int i = 0 , j = 0;
    for (i = 0 ; i < N ; i++)
    {
        for (j = 0 ; j < 4 ; j++)
        {
            scanf("%f",&num[i][j]);
        }
    }
    float time_x = 0;
    float time_y = 0;
    float height1 = 0 , height2 = 0;
    for ( i = 0 ; i < N ; i++)
    {
        time_x = num[i][0] / num[i][2]; 
        height1 = (num[i][3] * num[i][3]) / ( 2 * 10);
        if (height1 < num[i][1])
        {
            printf("F\n");
        }
        else
        {
            height2 = num[i][3] * time_x - 0.5 * 10 * time_x * time_x;
            if (height2 > num[i][1])
            {
                printf("P\n");
            }
            else
            {
                printf("F\n");
            }
        }
    }
    system("pause");
    return 0;
}