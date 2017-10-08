#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    char str1[1001];
    char str2[1001];
    char str3[1001];
    char str4[1001];
    gets(str1);
    gets(str2);
    gets(str3);
    gets(str4);
    int num[4];
    num[0] = strlen(str1);
    num[1] = strlen(str2);
    num[2] = strlen(str3);
    num[3] = strlen(str4);
    int i , j , temp , max;
    max = num[0];
    j = 0;
    for (i = 0 ; i < 4 ; i++)
    {
        for (j = 0; j <4 ; j++)
        {
            if (num[i] > num[j])
            {
                if (num[i] > max)
                {
                    max = num[i];
                    temp = i;
                }
            }
        }
    }
    if (temp == 0)
    {
        printf("A");
    }
    else if (temp == 1)
    {
        printf("B");
    }
    else if (temp == 2)
    {
        printf("C");
    }
    else if (temp == 3)
    {
        printf("D");
    }


    system("pause");
    return 0;
}