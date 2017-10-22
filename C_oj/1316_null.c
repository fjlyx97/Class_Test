#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    int num[N][3];
    int i = 0;
    int j = 0;
    int rooms = 0;
    for ( i = 0 ; i < N ; i++)
    {
        for ( j = 0 ; j < 3 ; j++)
        {
            scanf("%d",&num[i][j]);
        }
    }
    int min_day = num[0][1];
    int temp[3];
    j = 0;
    for ( i = 0 ; i < N ; i++)
    {
        for ( j = 0 ; j < N-i-1 ; j++)
        {
            if (num[i][1] > num[i+1][1] )
            {
                memcpy(temp,&num[i+1],sizeof(int) * 3);
                memcpy(&num[i+1] , &num[i] , sizeof(int) * 3);
                memcpy(&num[i] , temp , sizeof(int) * 3);
            }
        }
    }


    system("pause");
    return 0;
}