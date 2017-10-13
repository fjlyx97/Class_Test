#include <stdio.h>
#include <stdlib.h>
int judge(int); //判断是否为素数。
int add_judge(int , int);
int main(void)
{
    int n;
    scanf("%d",&n);
    int i = 0;
    int save_num[][6];
    int index = 0;

    for ( i = 0 ; i < n ; i++)
    {
        if (judge(1+i))
        {
            save_num[]
        }
    }

    system("pause");
    return 0;
}
int judge(int num)
{
    int i;
    for (i = 2 ; i < num ; i++)
    {
        if ( num % i == 0 )
        {
            return 0; //出现结果
        }
    }
    return 1;
}