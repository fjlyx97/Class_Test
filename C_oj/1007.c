#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n; //输入整数
    float result = 1.0;
    scanf("%d",&n);
    int i;
    for(i = 1 ; i < n ; i++ )
    {
        if (i % 2 == 0)
        {
            result = result + 1.0 / (3*i+1);
        }
        if (i % 2 == 1)
        {
            result = result - 1.0 / (3*i+1);
        }
    }
    printf("%.3f",result);

    system("pause");
    return 0;
}