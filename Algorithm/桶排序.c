#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int num[11] = {0};
    int i = 0;
    int j = 0;
    int a;
    for (i = 0 ; i < 5 ; i++)
    {
        scanf("%d",&a);
        num[a]++;
    }
    for ( i = 0 ; i < 11 ; i++)
    {
        if (num[i] == 0)
        {
            continue;
        }
        for ( j = 0 ; j < num[i] ; j++)
        {
            printf("%d ",i);
        }
    }


    system("pause");
    return 0;
}