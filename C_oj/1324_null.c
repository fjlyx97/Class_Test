#include <stdio.h>
#include <string.h>
void search_max(char*,int,int);
#include <stdlib.h>
int main(void)
{
    char str[204];
    scanf("%s",str);
    int len = strlen(str);
    int i;
    int max_ch = str[0];
    for ( i = 0 ; i < len-1 ; i++)
    {
        if (str[i] < str[i+1] && str[i+1] > max_ch)
        {
            max_ch = str[i+1];
        }
    }
    int index[50] = {0};
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
    for ( i = 0 ; i < num ; i++)
    {
        search_max(str , index[i], len);
        index[i+1] += 4;
        len = strlen(str);
    }
    str[len-1] = '\0';
    printf("%s",str);
    system("pause");
    return 0;
}
void search_max(char* str , int index , int len)
{
    int i = 0;
    int j = 1;
    int temp = 0;
    for ( i = len+4 ; i > index+3; i--)
    {
        str[i] = str[i-5];
    }
    str[index+1] = 'f';
    str[index+2] = 'i';
    str[index+3] = 'n';
    str[index+4] = 'd';
    printf("%s",str);
    //for ( i = index+1 ; i < len+4 ; i++)
    //{
    //    temp = str[i+1];
    //    str[i+1] = str[i];
    //    if ( j == 1)
    //    {
    //        str[i] = 'f';
    //        j++;
    //    }
    //    else if ( j == 2)
    //    {
    //        str[i] = 'i';
    //        j++;
    //    }
    //    else if ( j == 3)
    //    {
    //        str[i] = 'n';
    //        j++;
    //    }
    //    else if ( j == 4)
    //    {
    //        str[i] = 'd';
    //        j++;
    //    }
    //}
}