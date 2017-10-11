#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    float result = 1;
    int i;
    for (i = 1 ; i < N ; i++)
    {
        if (i % 2 == 0)
        {
            result -= 1.0 / (i+1);
        }
        else if (i % 2 == 1)
        {
            result += 1.0 / (i+1);
        }
    }
    printf("%.2f",result);


    system("pause");
    return 0;
}