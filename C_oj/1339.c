#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N , day_1 ,day_2;
    scanf("%d", &N);
    day_1 = N / 7 * 2;
    day_2 = N - (N / 7 * 7);
    if ( 6 == day_2)
    {
        day_1++;
    }
    else if (7 == day_2)
    {
        day_1 += 2;
    }

    printf("%d", day_1);
    


    system("pause");
    return 0;
}