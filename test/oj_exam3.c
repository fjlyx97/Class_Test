#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a , b ,c;
    scanf("%d %d %d",&a,&b,&c);
    int i = 0 , j = 0 , k = 0;
    int result = 0;
    for ( i = 1 ; i < 34 ; i++)
    {
        for ( j = 1 ; j < 21 ; j++)
        {
            for ( k = 1 ; k < 15 ; k++)
            {
                if ( 3 * i + a == 5 * j + b && 3 * i + a == 7 * k + c )
                {
                    result = 3 * i + a;
                }
            }
        }
    }
    printf("%d\n",result);
    system("pause");
    return 0;
}