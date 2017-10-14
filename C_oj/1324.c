#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void insert_find(char* str , int index)
{
    int i = 0;
    int len = strlen(str);
    char temp;
    for ( i = len+3 ; i > index+4 ; i--)
    {
        str[i] = str[i-4];
    }
    str[index+1] = 'f';
    str[index+2] = 'i';
    str[index+3] = 'n';
    str[index+4] = 'd';
    str[len+4] = '\0';
}
void add_ary(int* num_index,  int index)
{
    int i = 0;
    for ( i = index ;  ;  i++)
    {
        if (num_index[i] == -5)
        {
            break;
        }
        num_index[i] += 4;
    } 
}
int main(void)
{
    char str[1024];
    gets(str);
    int i;
    int max_ch = str[0];
    for ( i = 0 ; ; i++)
    {
        if (str[i] == '\0')
        {
            break;
        }
        if (str[i] < str[i+1] && str[i+1] > max_ch)
        {
            max_ch = str[i+1];
        }
    }
    int num_index[51];
    for (i = 0 ; i < 51 ; i++)
    {
        num_index[i] = -5;
    }
    int j = 0;
    for ( i = 0 ; ; i++)
    {
        if (str[i] == '\0')
        {
            break;
        }
        if (str[i] ==  max_ch)
        {
            num_index[j] = i;
            j++;
        }
    }
    for (i = 0 ; ; i++)
    {
        if ( num_index[i] < 0)
        {
            break;
        } 
        insert_find(str,num_index[i]);
        add_ary(num_index,i+1);
    }

    printf("%s",str);

    system("pause");
    return 0;
}