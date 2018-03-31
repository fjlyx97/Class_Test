#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int delChar(char *str,char ch)
{
    int count = 0;
    int len = strlen(str);
    int i;
    printf("%s\n",str);
    for (i = 0 ; i < len ; i++)
    {
        if (str[i] == ch)
        {
            str[i] = '\0';
            count++;
        }
    }
    for ( i = 0 ; i < len ; i++)
    {
        if (str[i] == '\0')
        {
            continue;
        }
        printf("%c",str[i]);
    }
    printf("\n");
    return count;
}
int main(int argc , char* argv[])
{
    char str[80];
    char del_ch;
    int count = 0;
    strcpy(str,argv[1]);
    del_ch = argv[2][0];
    count = delChar(str,del_ch);
    printf("del : %d" , count);
    return 0;
}

