#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    char str[N][50];
    int i = 0;
    for (i = 0 ; i < N ; i++)
    {
        scanf("%s",&str[i][0]);
    }
    int j = 0;
    int point_num = 0;
    int one , two , three , four;
    int index[50] = {0};

    for ( i = 0 ; i < N ; i++)
    {
        point_num = 0;
        for ( j = 0 ; str[i][j] != '\0' ; j++)
        {
            if (str[i][j] == '.')
            {
                index[point_num] = j; 
                point_num++;
            }
        }
        if ( 3 != point_num )
        {
            printf("NO\n");
        }
        else
        {
            one = atoi(&str[i][0]);
            two = atoi(&str[i][index[1]+1]);
            three = atoi(&str[i][index[2]+1]);
            four = atoi(&str[i][index[3]+1]);
            if (one > 255 || two > 255 || three > 255 || four > 255)
            {
                printf("NO\n");
            }
            else
            {
                printf("YES\n");
            }
        }
    }
    system("pause");
    return 0;
}