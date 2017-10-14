#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    int num[n][2];
    int i = 0 , j = 0;
    for (i = 0 ; i < n ; i++)
    {
        for (j = 0 ; j < 2 ; j++)
        {
            scanf("%d",&num[i][j]);
        }
    }
    int result = 1;
    for ( i = 0 ; i < n ; i++)
    {
        for ( j = 1 ; j < n ; j++)
        {
            if (num[i][1] < num[j][0])
            {
                result += 1;
                i = j;
            }
        }
    }
    printf("%d",result);
    system("pause");
    return 0;
}