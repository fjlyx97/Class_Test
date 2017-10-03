#include <stdio.h>
#include <stdlib.h>

int mul(int);
int main(void)
{
    int T;
    scanf("%d",&T);
    int num[T];
    long long result[T];
    int i , temp;
    for (i = 0; i < T; i++)
    {
        scanf("%d",&num[i]);
        result[i] = mul(num[i]);
    }
    int j;
    for (j = 0; j < T; j++)
    {
        printf("%d\n",result[j]);
    }
    system("pause");
    return 0;
}
int mul(int num)
{
    int i;
    long long result = 1;
    for (i = 1; i < num ; i++)
    {
        result += result * i;
    }
    return result;
}