#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    scanf("%d",&n);
    int i = 0 , j = 0;
    for ( i = 1 ; i <= n ; i++)
    {
        for ( j = 1 ; j <= i ; j++ )   
        {
            printf("%d*%d=%d ",j,i,i*j);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}