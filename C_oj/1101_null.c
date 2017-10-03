#include <stdio.h>
#include <stdlib.h>
void Judge(int num, int* temp , int* Com_round);
int main(void)
{
    int N;
    scanf("%d",&N);
    int Com_round = 0;
    int people_num = 0;
    if ( N % 2 == 1)
    {
        N--;
        people_num++;
    }
    while(true)
    {
        Judge(N,people_num,Com_round);
    }
    printf("%d",Com_round);

    system("pause");
    return 0;
}
void Judge(int num , int* temp ,int* Com_round)
{
    if (num % 2 == 0)
    {
        num = num / 2;
        *Com_round++;
    }
    else if ( num % 2 == 1)
    {
        num--;
        *temp++;
        Judge(num,temp,Com_round);
    }
}