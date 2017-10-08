#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    float profit;
    float money = 0;
    scanf("%f",&profit);
    if (profit <= 1000)
    {
        money = 500;
    }
    else if ( 1000 < profit && profit <= 5000)
    {
        money = 500 + profit * 0.25;
    }
    else
    {
        money = 500 + profit * 0.5;
    }
    printf("%.2f",money);

    system("pause");
    return 0;
}