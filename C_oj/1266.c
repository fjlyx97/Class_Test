#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    int num[N][2];
    int i = 0 , j = 0;
    for (i = 0 ; i < N ; i++)
    {
        for (j = 0 ; j < 2 ; j++)
        {
            scanf("%d",&num[i][j]);
        }
    }
    int index[300] = {0};
    int max_problem = num[0][0];
    for (i = 0 ; i < N-1 ; i++)
    {
        if (num[i][0] < num[i+1][0] && num[i+1][0] > max_problem)
        {
            max_problem = num[i+1][0];
        }
    }
    j = 0;
    for (i = 0 ; i < N ; i++)
    {
        if ( max_problem == num[i][0])
        {
            index[j] = i; 
            j++;
        }
    }
    int min_time = num[index[0]][1];
    if ( j == 1)
    {
        printf("%d %d",num[index[0]][0],num[index[0]][1]);
    }
    else
    {
        for ( i = 0 ; i < j-1 ; i++)
        {
            if (num[index[i]][1] > num[index[i+1]][1] && num[index[i+1]][1] < min_time)
            {
                min_time = num[index[i+1]][1];
            }
        }
        printf("%d %d",max_problem,min_time);
    }
    system("pause");
    return 0;
}