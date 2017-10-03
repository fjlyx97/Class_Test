#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int mul(int); //计算阶乘
int main(void)
{
    unsigned int M; 
    scanf("%d",&M);
    int num[M];
    int i;
    for ( i = 0; i < M; i++ )
    {
        scanf("%d",&num[i]); //循环输入数字
    }
    int j; //for循环
    int z; //for循环
    int result = 0; //申明答案
    int result_temp; //临时储存答案，已达到回调的目的
    for (j = 0; j < M; j++ )
    {
        for (z = 8; z > 0 ; z--)
        {
            result_temp = result;
            result += mul(z);
            if (result > num[j])
            {
                result = result_temp;
            }
        }
        if (result == num[j])
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        result = 0;
        result_temp = 0;
    }
    system("pause");
    return 0;
}
int mul(int num) //定义一个阶乘
{
    int result = 1;
    int i;
    for (i = 1; i < num ; i++)
    {
       result += result * i;
    }
    return result;
}