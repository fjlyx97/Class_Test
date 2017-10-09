#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%d", &N);
    char *str[N];
    int i ;
    for ( i = 0 ; i < N ; i++)
    {
        str[i] = (char*)malloc(sizeof(char) * 32);
        scanf("%s",str[i]);
    }
    int j , k = 0 , l = 7,  temp = 0;
    for (j = 0 ; j < 8 ; j++)
    {
        for (k = 0 ; k < N ; k++)
        {
            if (str[j][k] == 0)
            {
                l--;
                continue;
            }
            else if (str[j][k] == 1)
            {
                temp += 1 * pow(2,l);
                l--;
            }
            else
            {
                temp += 2 * pow(2,l);
                l--
            }
        }
        l = 8;
        temp = 0;
    }


    system("pause");
    return 0;
}