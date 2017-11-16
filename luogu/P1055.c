#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char isbn[14];
    scanf("%s",isbn);
    int i = 0;
    int j = 1;
    int num = 0;
    for ( i = 0 ; i < 11 ; i++)
    {
        if ( 1 == i || 5 == i)
        {
            continue;
        }
        num += (isbn[i] - 48) * j;
        j++;
    }
    if (num % 11 == 10)
    {
        if ( 'X' == isbn[12] )
        {
            printf("Right");
            return 0;
        }
        else
        {
            isbn[12] = 'X';
            printf("%s",isbn);
            return 0;
        }
    }
    if (num % 11 == isbn[12]-48)
    {
        printf("Right");
    }
    else
    {
        isbn[12] = 48+num % 11;
        printf("%s",isbn);
    }
    system("pause");
    return 0;
}