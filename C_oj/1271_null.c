#include <stdio.h>
#include <stdlib.h>
void judge(const int* , int );
int main(void)
{
    int N;
    scanf("%d",&N);
    int num[N];
    int i = 0;
    for (i = 0 ; i < N ; i++)
    {
        scanf("%d",&num[i]);
    }
    for (i = 0 ; i < N ; i++)
    {
        judge(num,i);
    }

    system("pause");
    return 0;
}
void judge(const int* num , int day_index)
{
    int i = 0 ;
    int days = 0;
    for (i = day_index-1 ; i > 0 ; i-- )
    {
        if ( num[day_index] > num[i])
        {
            days++;
        }
        else
        {
            break;
        }
    }
    days++;
    printf("%d ",days);
}