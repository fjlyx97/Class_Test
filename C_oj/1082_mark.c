#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    char str[81];
    scanf("%s",str);
    int i , str_index , str_len;
    int j;
    str_len = strlen(str);
    for (i = 0; i < 81; i++)
    {
        if(str[i] != '#')
        {
            str_index = i;
            break;
        }
    }
    for (j = 0;j < str_len - (i-1); j++)
    {
        str[j] = str[j+i];
    }
    for (j = str_len - i ; j < str_len ; j++)
    {
        str[j] = '#';
    }
    printf("%s",str);

    system("pause");
    return 0;
}