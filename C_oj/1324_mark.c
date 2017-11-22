#include <stdio.h>
#include <string.h>
void search_max(char*,int,int);
#include <stdlib.h>
int main(void)
{
    char str[1024];
    gets(str);
    int len = strlen(str);
    int len_temp = len;
    int i;
    int max_ch = str[0];
    for ( i = 0 ; i < len-1 ; i++)
    {
        if (str[i] < str[i+1] && str[i+1] > max_ch)
        {
            max_ch = str[i+1];
        }
    }
    int index[1024] = {0};
    int j = 0;
    int num = 0;
    for (i = 0 ; i < len ; i++)
    {
        if ( max_ch == str[i])
        {
            index[j] = i;
            num++;
            j++;
        }
    }
    int k ;
    for ( i = 0 ; i < num ; i++)
    {
        search_max(str , index[i], len);
        for ( k = i+1 ; ; k++ )
        {
            if (index[k] == 0)
            {
                break;
            }
            index[k] += 4; 
        }
    }

    printf("%s",str);
    system("pause");
    return 0;
}
void search_max(char* str , int index , int len)
{
    int i = 0;
    int j = 1;
    int temp = 0;
    for ( i = len+3 ; i > index+4; i--)
    {
        str[i] = str[i-4];
    }
    str[index+1] = 'f';
    str[index+2] = 'i';
    str[index+3] = 'n';
    str[index+4] = 'd';
}