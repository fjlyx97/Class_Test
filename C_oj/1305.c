#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    char str[101];
    scanf("%s",str);
    int len = strlen(str);
    int i = 0 , j = len-1;
    int result = 0;
    if (len % 2 == 0)
    {
        for (i = 0 ; i < len / 2 ; i++,j--)
        {
            if (str[i] == str[j])
            {
                result = 1;
                continue;
            }
            else
            {
                result = 0;
                break;
            }
        }
    }
    else
    {
        for (i = 0 ; i <= len / 2 ; i++,j--)
        {
            if (str[i] == str[j])
            {
                result = 1;
                continue;
            }
            else
            {
                result = 0;
                break;
            }
        }
    }
    if ( 1 == result)
    {
        printf("Yes");
    }
    else if ( 0 == result)
    {
        printf("No");
    }

    system("pause");
    return 0;
}