#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    int T;
    scanf("%d",&T);
    int num[27];
    memset(num,0,sizeof(num));
    int i;
    int max;
    int index;
    while (T--)
    {
        char* str = (char*)malloc(sizeof(char) * 101);
        scanf("%s",str);
        memset(num,0,sizeof(num));
        max = 0;
        for ( i = 0 ; str[i] != '\0' ; i++)
        {
            num[str[i]-96]++;
        }
        for ( i = 1 ; i < 27 ; i++)
        {
            if (num[i] > max )
            {
                max = num[i];
                index = i;
            }
        }
        printf("%c\n",index+96);
        free(str);
    }
    system("pause");
    return 0;
}