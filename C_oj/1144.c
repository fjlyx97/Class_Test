#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    int T;
    scanf("%d",&T);
    getchar();
    char str[1024];
    int i = 0;
    int len = 0;
    int status = 0;
    while (T--)
    {
        gets(str);
        len = strlen(str);
        if ( len > 22)
        {
            for ( i = 2 ; i < 22 ; i++)
            {
                if (str[i] != '9')
                {
                    status = 1;
                    break;
                }
                status = 0;
            }
            if (status == 0)
            {
                status = 1;
                for ( i = 22 ; i < len ; i++)
                {
                    if ( str[i] != '0' )
                    {
                        status = 0;
                    }
                }
            }
            if ( status == 0)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
        else
        {
            printf("No\n");
        }
    }

    system("pause");
    return 0;
}