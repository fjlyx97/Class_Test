#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char str[81];
    char temp[81]; //储存变量
    gets(str);
    int i;
    int num = 0; //要替换数字个数
    int len = 0;
    for (i = 0 ; ; i++)
    {
        if (str[i] == '\0')
        {
            break;
        }
        len++;
    }
    for (i = 0 ; ; i++)
    {
        if ( 48 <= str[i] && str[i] <= 57 )
        {
            num += 1;
            temp[i] = str[i];
        }
        else
        {
            break;
        }
    }
    for (i = 0 ; i < len-1; i++)
    {
        str[i] = str[i+num];
    }
    int z = 0;
    for (i = len - num; i < len ; i++)
    {
        str[i] = temp[z];
        z++;
    }
    printf("%s",str);
    system("pause");
    return 0;
}