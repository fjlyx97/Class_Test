#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char str[102];
    char str1[102];
    scanf("%s",str);
    int i = 0 , j = 0 , index;
    for (j = 0 ; j < 51 ; j++)
    {
        if (str[j] == '\0')
        {
            index = j-1;
            break;
        }
        str1[j] = str[j];
    }
    j = index + 1;
    for ( i = index ; i >= 0 ; i--)
    {
        str1[j] = str[i]; 
        j++;
    }
    str1[j] = '\0';
    printf("%s",str1);
    system("pause");
    return 0;
}