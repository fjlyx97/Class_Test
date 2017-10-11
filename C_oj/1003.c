#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    char *str[N];
    char *str_insert[N];
    int num[N+1];
    int z;
    for ( z = 0 ; z < N+1 ; z++)
    {
        num[z] = 0;
    }
    int i , j = 0;
    for ( i = 0 ; i < N ; i++)
    {
        str[i] = (char*)malloc(sizeof(char) * 16);
        str_insert[i] = (char*)malloc(sizeof(char) * 16);
    }
    for (i = 0 ; i < N ; i++)
    {
        scanf("%s",str[i]);
    }
    int index = 0;
    for ( index = 0 ; index < N ; index++)
    {
        for ( i = index+1 ; i < N ; i++)
        {
            //if (str[i] == "over")
            //{
            //    break;
            //}
            if (strcmp(str[index],str[i]) == 0)
            {
                strcpy(str_insert[index],str[i]);
                str[i] = "over";
                num[index] += 1;
            }
        }
    }
    int max_num = num[0];
    int max_index = 0;
    for (i = 0 ; i < N ; i++)
    {
        if (num[i] < num[i+1] && num[i+1] > max_num)
        {
            max_num = num[i+1];
            max_index = i+1;
        }
    }
    if ( N == 1)
    {
        printf("%s",str[0]);
    }
    else
    {
        printf("%s",str_insert[max_index]);
    }
    system("pause");
    return 0;
}