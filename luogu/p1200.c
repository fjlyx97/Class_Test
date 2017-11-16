#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char str[8];
    char str1[8];
    gets(str);
    gets(str1);
    int a = 1, b = 1 , i;
    for ( i = 0 ; str[i] != '\0' ; i++)
    { 
        a *= str[i] - 64; 
    }
    for ( i = 0 ; str1[i] != '\0' ; i++)
    { 
        b *= str1[i] - 64; 
    }
    if ( a % 47 == b % 47 )
    {
        printf("GO");
    }
    else
    {
        printf("STAY");
    }

    system("pause");
    return 0;
}