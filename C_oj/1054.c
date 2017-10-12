#include <stdio.h>
#include <stdlib.h>
int judge(int); //判断是否为素数。
int main(void)
{
    int n;
    scanf("%d",&n);

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