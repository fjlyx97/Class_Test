#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    float result = 0;
    float i = 1, j = 2;
    float temp = 0;
    while (n--)
    {
        temp = j;
        result += j / i;
        j = j + i;
        i = temp;
    }
    printf("%.2f",result);
    system("pause");
    return 0;
}