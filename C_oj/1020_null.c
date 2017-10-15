#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void change_min(int* num , int N , int* my_index)
{
    int temp_num[N];
    memcpy(temp_num,num,sizeof(int) * N);
    int i = 0;
    int j = 0;
    int temp;
    int index = 0;
    int min_num = num[0];
    int k = 0;
    for ( i = 0 ; i < N-1 ; i++)
    {
        for ( j = i ; j < N-1 ; j++)
        {
            if (temp_num[j+1] < temp_num[j] && temp_num[j+1] < min_num)
            {
                min_num = temp_num[j+1];
                index = j+1;
            }
        }
        my_index[i] = j+1;
        temp_num[j+1] = 999;
    }
}
int main(void)
{
    int N;
    scanf("%d", &N);
    int num[N];
    int i = 0;
    for (i = 0 ; i < N ; i++)
    {
        scanf("%d",&num[i]);
    }
    int result = 0;
    int j = 0;
    int index[N];
    //for (i = 1 ; i <= N-1 ; i++)
    //{
    //    result += num[0] + num[1];
    //    num[0] = num[0] + num[1];
    //    num[1] = 999;
    change_min(num,N,index);
    //}
    printf("%d",result);
    system("pause");
    return 0;
}