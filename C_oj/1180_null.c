#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void del_string(char*,char*);
int main(void)
{
    char str[100001];
    scanf("%s",str);
    int N;
    scanf("%d",&N);
    char *del_str[N];
    int i = 0;
    for ( i = 0 ; i < N ; i++)
    {
        del_str[i] = (char*)malloc(sizeof(char) * 101);
        scanf("%s",del_str[i]);
    }
    for ( i = 0 ; i < N ; i++)
    {
        del_string( str , del_str[i]);
    }
    printf("%s",str);
    system("pause");
    return 0;
}
void del_string(char* str , char* del_str)
{
    int i = 0 , j = 0 , k = 0;
    int result = 0;
    int len = strlen(del_str);
    for ( i = 0 ; ; i++)
    {
        if (str[i] == '\0')
        {
            break;
        }
        if ( str[i] == del_str[j])
        {
            while (1)
            {
                for ( k = i+1 ; ; k++)
                {
                    j++;
                    if (str[k] == del_str[j])
                    {
                        result = 1;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                if (result == 1)
                {
                    for ( k = i ; k < i+len ; k++)
                    {
                        str[k] = 't';
                    }
                    break;
                }
            }
        }
    }
}