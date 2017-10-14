#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a = 0 , b = 0 , c = 0 , d = 0 , e = 0 , f = 0;
    int result = 0 ;
    for ( a = 0 ; a <= 6 ; a++)
    {
        for ( b = 0 ; b <= 6 ; b++)
        {
            for ( c = 0 ; c <= 6 ; c++)
            {
                for ( d = 0 ; d <= 6 ; d++)
                {
                    for ( e = 0 ; e <= 6 ; e++)
                    {
                        for ( f = 0 ; f <= 6 ; f++)
                        {
                            if ( a+b+c+d+e+f == 6)
                            {
                                result += 1;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d",result);
    system("pause");
    return 0;
}