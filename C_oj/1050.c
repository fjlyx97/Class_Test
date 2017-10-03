#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int m;
    scanf("%d",&m);
    double result = 1.0;
    int i;
    for (i = 1 ; i < m+1; i++)
    {
        result += 1.0 / ( 2*i);
    }
    printf("%.2f",result);


    system("pause");
    return 0;
}