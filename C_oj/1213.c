#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char str[71];
    scanf("%s",str);
    int begin , over;
    scanf("%d %d", &begin , &over);
    if (begin <= 1)
    {
        begin = 1;
    }
    int i;
    if (str[over] = '\0')
    {
        for ( i = begin ; i <= over ; i++ )
        {
            if (str[i] == '\0')
            {
                break;
            }
            printf("%c",str[i-1]);
        }
    }
    else
    {
        for ( i = begin ; i <= over ; i++ )
        {
            printf("%c",str[i-1]);
        }
    }
    system("pause");
    return 0;
}