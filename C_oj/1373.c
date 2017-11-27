#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int T;
    int m , k , x , y;
    int num , num1;
    float num_time , num_time1;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d %d %d %d",&m,&k,&x,&y);
        num = 800-(m+k);
        num_time = (float)num / x;
        num1= 800-m;
        num_time1 = (float)num1 / y;
        if (num_time > num_time1)
        {
            printf("T\n");
        }
        else
        {
            printf("F\n");
        }

    }
    system("pause");
    return 0;
}