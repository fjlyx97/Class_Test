#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int X;
    scanf("%d",&X);
    int num[X][4];
    int i , j;
    int result[X];
    for (i = 0 ; i < X ; i++)
    {
        for (j = 0 ; j < 4 ; j++)
        {
            scanf("%d",&num[i][j]);
        }
    }
    for (i = 0 ; i < X ; i++)
    {
        result[i] = num[i][1] - num[i][0] - num[i][2];
        result[i] = -result[i];
    }
    for (i = 0 ; i < X ; i++)
    {
        printf("%d\n",result[i]);
    }

    system("pause");
    return 0;
}