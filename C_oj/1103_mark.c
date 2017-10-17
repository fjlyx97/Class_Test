#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void change_min(int* num , int N , int index_int)
{
    int i = 0;
    int j = 0;
    int index = index_int;
    int temp = 0;
    int min_num = num[index_int];
    for ( i = index_int ; i < N-1 ; i++)
    {
        for ( j = i ; j < N-1 ; j++)
        {
            if (num[j+1] < num[j] && num[j+1] < min_num)
            {
                min_num = num[j+1];
                index = j+1;
            }
        }
        temp = num[i];
        num[i] = num[index];
        num[index] = temp;
        min_num = num[i+1];
        index = i+1;
    }
}
int main(void)
{
    int N;
    scanf("%d", &N);
    int num[N];
    int all_time = 0;
    int i = 0;
    int index_int = 0;
    for (i = 0 ; i < N ; i++)
    {
        scanf("%d",&num[i]);
    }
    for ( i = 0; i < N ; i++)
    {
        if ( i == N -1)
        {
            break;
        }
        change_min(num,N,index_int);
        all_time += num[i] + num[i+1];
        num[i+1] = num[i] + num[i+1];
        num[i] = 0;
        index_int++;
    }
    printf("%d",all_time);

    system("pause");
    return 0;
}