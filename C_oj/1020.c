#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void judge(int* num , int N , int index = 0)
{
    int i = 0;
    int min1 = 201;
    int min2 = 201;
    int minary_index[2] = {index,index+1};
    for ( i = 0 ; i < N-1 ; i++)
    {
        if ( num[i+1] < num[i] && num[i+1] < min1)
        {
            min1 = num[i+1];
            minary_index[0] = i+1;
        }
    }
    num[minary_index[0]] = 201;
    for ( i = 0 ; i < N-1 ; i++)
    {
        if ( num[i+1] < num[i] && num[i+1] < min2)
        {
            min2 = num[i+1];
            minary_index[1] = i+1;
        }
    }
    num[minary_index[1]] = 201;
}
int main(void)
{
    int N;
    scanf("%d", &N);
    int num[N];
    int i = 0;
    int index = 0;
    for (i = 0 ; i < N ; i++)
    {
        scanf("%d",&num[i]);
    }
    judge(num,N,index);


    system("pause");
    return 0;
}