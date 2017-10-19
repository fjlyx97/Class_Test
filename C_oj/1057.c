#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    int num[10] = {0};
    int single = 0;
    single = n / 10;
    int two_single = 0;
    two_single = n % 10;
    int i = 0 , j = 0;
    if ( n <= 9)
    {
        printf("0\n");
        for ( i = 0 ; i < n ; i++)
        {
            printf("1\n");
        }
        for ( i = n ; i < 9 ; i++)
        {
            printf("0\n");
        }
        return 0;
    }
    for ( i = 0 ; i < single ; i++)
    {
        for ( j = 1 ; j < 10 ; j++)
        {
            num[j] += 1;
        }
        for ( i = 0 ; i < single ; i++)
        {
            for ( j = 1 ; j < single ; j++)
            {
                num[j] += 11;
            }
            for ( j = 0 ; j <= two_single ; j++)
            {
                num[j] += 1;
            }
       }
    }
    for ( i = 0 ; i < 10 ; i++)
    {
        printf("%d\n",num[i]);
    }
    system("pause");
    return 0;
}