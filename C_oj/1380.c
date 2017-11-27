#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    int T;
    scanf("%d",&T);
    int result = 0;
    int num1 , num2;
    int len1 , len2;
    int i = 0;
    while(T--)
    {
        num1 = 0;
        num2 = 0;
        char* str1 = (char*)malloc(sizeof(char*) * 7);
        char* str2 = (char*)malloc(sizeof(char*) * 7);
        scanf("%s",str1);
        scanf("%s",str2);
        len1 = strlen(str1);
        len2 = strlen(str2);
        for ( i = 0 ; str1[i] != '\0' ; i++)
        {
            if ( 'A' <= str1[i] && str1[i] <= 'F' )
            {
                num1 += (str1[i]-55) * pow(16,len1-1);  
            }
            else if ('0' <= str1[i] && str1[i] <= '9')
            {
                num1 += (str1[i]-48) * pow(16,len1-1);
            }
            len1--;
        }
        for ( i = 0 ; str2[i] != '\0' ; i++)
        {
            if ( 'A' <= str2[i] && str2[i] <= 'F' )
            {
                num2 += (str2[i]-55) * pow(16,len2-1);  
            }
            else if ('0' <= str2[i] && str2[i] <= '9')
            {
                num2 += (str2[i]-48) * pow(16,len2-1);
            }
            len2--;
        }
        printf("%d\n",num1+num2);

        free(str1);
        free(str2);
    }

    system("pause");
    return 0;
}