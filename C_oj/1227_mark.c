#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int T;
    scanf("%d",&T);
    double num[T][6];
    int i = 0;
    int j = 0;
    double hp1_over = 0;
    double hp2_over = 0;
    for (j = 0 ; j < T ; j++)
    {
        for (i = 0 ; i < 6 ; i++)
        {
            scanf("%lf",&num[j][i]);
        }
    }
    for (j = 0 ; j < T ; j++)
    {
        //hp1_over = num[j][0] / num[j][4] * num[j][5]; 
        //hp2_over = num[j][3] / num[j][1] * num[j][2];
        //if (hp1_over > hp2_over)
        //{
        //    printf("Yes\n");
        //}
        //else
        //{
        //    printf("No\n");
        //}
        //第二种解法目前允许，第一种解法目前错误未知。
        while (num[j][0] > 0)
        {
            num[j][0] -= num[j][4];
            hp1_over += num[j][5];
        }
        while (num[j][3] > 0)
        {
            num[j][3] -= num[j][1];
            hp2_over += num[j][2];
        }
        if (hp1_over > hp2_over)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        hp1_over = 0;
        hp2_over = 0;
    }
    system("pause");
    return 0;
}
