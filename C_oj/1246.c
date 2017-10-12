#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    float N;
    scanf("%f",&N);
    int days = 0;
    float sell_num = 0;
    if ( N == 1)
    {
        printf("%d",1);
        return 0;
    }
    N = N / 2;
    if ( (int)N < N )
    {
        sell_num = (int)N + 1;
    }
    else
    {
        sell_num = N;
    }
    days++;
    N = (int)N;
    while (1)
    {
        if ( (int)(sell_num / 2) < sell_num / 2)
        {
            sell_num = (int)(sell_num / 2) + 1;
            N -= sell_num;
            days++;
        }
        else
        {
            sell_num = sell_num / 2;
            N -= sell_num;
            days++;
        }
        if ( N <= 0 )
        {
            break;
        }
    }
    printf("%d",days);
    system("pause");
    return 0;
}