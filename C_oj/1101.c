#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N , my_round = 0;
    scanf("%d",&N);
    if (N == 1)
    {
        my_round = 1;
    }
    while ( N != 1)
    {
        if (N % 2 == 1)
        {
            N -= 1;
            N = N / 2;
            my_round += 1;
            N++;
        }
        else
        {
            N = N / 2;
            my_round += 1;
        }
    }
    printf("%d",my_round);

    system("pause");
    return 0;
}