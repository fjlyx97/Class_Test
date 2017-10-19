#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void obtain_num(char* str , char* num)
{
    int i = 0 , j = 0 , k = 0;
    int over = 1;
    for ( i = 0 ; i < 51 ; i++)
    {
        if ( 48 <= str[i] && str[i] <= 57 )
        {
            for ( k = i; ; k++)
            {
                if ( str[k] < 48 || str[k] > 57)
                {
                    over = 0;
                    break;
                }
                num[j] = str[k];
                str[k] = '#';
                j++;
            }
        }
        if (over == 0)
        {
            break;
        }
    }
}
int main(void)
{
    char str[51] = {'\0'};
    gets(str);
    char num[50][50] = {'\0'};

    int i = 0;
    for (i = 0 ; i < 50 ; i++)
    {
        obtain_num(str , &num[i][0]);
    }
    int result = 0;
    for (i = 0 ; i < 50 ; i++)
    {
        result += atoi(&num[i][0]);
    }
    printf("%d",result);
    system("pause");
    return 0;
}