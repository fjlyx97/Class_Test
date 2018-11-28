#include <stdio.h>
#include <stdlib.h>
float add(int , float);
int main(void)
{
    int n;
    float result = 0;
    float result_temp = 0;
    scanf("%d",&n);
    int i;
    for (i = 1 ; i <= n; i++)
    {
        result += add(i+1 , result_temp) / add(i , result_temp );
    }
    printf("%.2f",result);
    system("pause");
    return 0;
}
float add(int num , float result)
{
    if (num == 1 )
    {
        return 1.0;
    }
    else if (num == 2)
    {
        return 2.0;
    }
    else if (num == 3)
    {
        return 3.0;
    }
    result += add(num-1 , result) + add(num-2 , result);
    return result;
}