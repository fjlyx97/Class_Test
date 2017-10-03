#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    unsigned int N;
    scanf("%d",&N);
    unsigned int num[N][6];
    unsigned int i , j;
    for ( i = 0; i < N ; i++)
    {
        for ( j = 0; j < 6 ; j++)
        {
            scanf("%d",&num[i][j]);
        }
    }
    unsigned int result = 0;
    unsigned int temp_result = 0;
    unsigned int temp1_result = 0;
    for ( i = 0; i < N ; i++)
    {
        for ( j = 0; j < 6 ; j++)
        {
            result += num[i][j] * (j+1);
        }
        if (result % 2 == 0)
        {
            for ( i = 0; i < N ; i++)
            {
                for ( j = 0; j < 6 ; j++)
                {
                    temp_result += num[i][j] * (j+1);
                    temp1_result = temp_result;
                    if (temp_result > result / 2)
                    {
                        temp_result = temp1_result;
                    }
                    else if (temp_result == result / 2) 
                    {
                        printf("YES");
                    }
                }
                if (temp_result != result / 2)
                {
                    printf("NO");
                }
                 
                temp_result = 0;
                temp1_result = 0;
            }
        }
        else
        {
            printf("NO\n");
        }
        result = 0;
    }

    system("pause");
    return 0;
}