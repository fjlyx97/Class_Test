#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    char *str[N];
    int i , j;
    for (i = 0 ; i < N ; i++)
    {
        str[i] = (char*)malloc(sizeof(char) * 1000000);
        scanf("%s",str[i]);
    }
    int circle = 0;
    for (i = 0 ; i < N ; i++)
    {
        for (j = 0 ; ; j++)
        {
            if (str[i][j] == '\0')
            {
                break;
            }
            else if (str[i][j] == 48 || str[i][j] == 52 || str[i][j] == 54 || str[i][j] == 57)
            {
                circle++;
            } 
            else if (str[i][j] == 56)
            {
                circle += 2;
            }
        }
        printf("%d\n",circle);
        circle = 0;
    }
    for (i = 0 ; i < N ; i++)
    {
        free(str[i]);
    }
    system("pause");
    return 0;
}