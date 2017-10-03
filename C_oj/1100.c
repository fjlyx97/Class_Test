#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    float x;
    scanf("%f",&x);
    float result = 1.0;
    int i;
    for (i = 1 ; i < 100 ; i++)
    {
        if (i % 2 == 1)
        {
            result += x / (i+1);
        }
        else
        {
            result -= x / (i+1);
        }
    }
    printf("%.2f",result);
    system("pause");
    return 0;
}