#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N , X , Y , Z;
    scanf("%d %d %d %d", &N , &X , &Y , &Z);
    int begin , over;
    int money;
    for ( begin = 9 ; begin > 0 ; begin--)
    {
        for (over = 9 ; over >= 0 ; over--)
        {
            money = begin * 10000 + X * 1000 + Y * 100 + Z * 10 + over;
            if (money % N == 0)
            {
                printf("%d %d ",begin , over);
                printf("%d",money / N);
                return 0;
            }
        }
    }
    printf("0");

    system("pause");
    return 0;
}