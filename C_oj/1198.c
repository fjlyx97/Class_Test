#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    char str[81];
    gets(str);
    int len = strlen(str);
    char word;
    scanf("%c",&word);
    int i;
    for (i = 0 ; i < len ; i++)
    {
        if (str[i] == word)
        {
            str[i] = '\0';
        }
    }
    for (i = 0 ; i < len ; i++)
    {
        if (str[i] == '\0')
        {
            continue;
        }
        printf("%c",str[i]);
    }



    system("pause");
    return 0;
}