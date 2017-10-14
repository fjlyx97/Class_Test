#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a , b , c; 
    scanf("%d %d %d", &a , &b , &c);
    int i = 0 , j = 0 , k = 0;
    int result = 0;
    for ( i = 0 ; i <= a ; i++)
    {
        for (j = 0 ; j <= b ; j++)
        {
            for ( k = 0 ; k <= c ; k++)
            {
                if ( i + j + k == 10)
                {
                    result += 1;
                }
            }
        }
    }
    printf("%d",result);

    system("pause");
    return 0;
}