#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N , K;
    scanf("%d %d",&N , &K);
    //int *oil_add = (int*)malloc(sizeof(int) * K+1);
    int oil_add[K+1];
    int i = 0;
    for (i = 0 ; i < K+1 ; i++)
    {
        scanf("%d", &oil_add[i]);
    }
    int surplus_oil = N;
    int add_num = 0;
    for (i = 0 ; i < K ;i++)
    {
        if (N < oil_add[i])
        {
            printf("No Solution");
            system("pause");
            return 0;
        }
        surplus_oil -= oil_add[i];
        if (surplus_oil - oil_add[i+1] < 0)
        {
            add_num++;
            surplus_oil = N;
        }
    }
    if (surplus_oil < oil_add[K])
    {
        printf("No Solution");
    }
    else
    {
        printf("%d",add_num);
    }
    system("pause");
    return 0;
}