#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i , j ;
    float k;
    for (i = 0; i < 15 ; i++)
    {
        for (j = 0 ; j < 23 ; j++)
        {
            for (k = 0; k < 45 ; k++)
            {
                if ( (3*i + 2*j + k / 2) == 45 && (i+j+k) == 45)
                {
                    printf("men=%d women=%d child=%.f\n",i,j,k);
                }
            }
        }
    }
    system("pause");
    return 0;
}