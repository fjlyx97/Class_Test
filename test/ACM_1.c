#include <stdio.h>
#include <stdlib.h>
// 0 剪刀 1 石头 2 布 3 蜥蜴人 4 斯波克
void judge_result(int a, int b, int* pointa, int* pointb)
{
    if (a == b)
    {
        return;
    }
    else if ( a == 0 && b == 1)
    {
        (*pointb)++;
    }
    else if ( a == 1 && b == 0)
    {
        (*pointa)++;
    }
    else if ( a == 0 && b == 2)
    {
        (*pointa)++;
    }
    else if ( a == 2 && b == 0)
    {
        (*pointb)++;
    }
    else if ( a == 0 && b == 3)
    {
        (*pointa)++;
    }
    else if ( a == 3 && b == 0)
    {
        (*pointb)++;
    }
    else if ( a == 0 && b == 4)
    {
        (*pointb)++;
    }
    else if ( a == 4 && b == 0)
    {
        (*pointa)++;
    }
    else if ( a == 1 && b == 2)
    {
        (*pointb)++;
    }
    else if ( a == 2 && b == 1)
    {
        (*pointa)++;
    }
    else if ( a == 1 && b == 3)
    {
        (*pointa)++;
    }
    else if ( a == 3 && b == 1)
    {
        (*pointb)++;
    }
    else if ( a == 1 && b == 4)
    {
        (*pointb)++;
    }
    else if ( a == 4 && b == 1)
    {
        (*pointa)++;
    }
    else if ( a == 2 && b == 3)
    {
        (*pointb)++;
    }
    else if ( a == 3 && b == 2)
    {
        (*pointa)++;
    }
    else if ( a == 2 && b == 4)
    {
        (*pointa)++;
    }
    else if ( a == 4 && b == 2)
    {
        (*pointb)++;
    }
    else if ( a == 3 && b == 4)
    {
        (*pointa)++;
    }
    else if ( a == 4 && b == a)
    {
        (*pointb)++;
    }
}
int main(void)
{
    int N , NA , NB;
    scanf("%d %d %d", &N, &NA, &NB);
    int numA[NA] , numB[NB];
    int i = 0;
    for ( i = 0 ; i < NA ; i++)
    {
        scanf("%d",&numA[i]);
    }
    for ( i = 0 ; i < NB ; i++)
    {
        scanf("%d",&numB[i]);
    }
    int pointa = 0 , pointb = 0;
    int a = 0 , b = 0;
    for (i = 0 ; i < N ; i++)
    {
        judge_result(numA[a] , numB[b] , &pointa, &pointb);
        a++;
        b++;
        if ( a == NA)
        {
            a = 0;
        }
        if ( b == NB)
        {
            b = 0;
        }
    }
    printf("%d %d",pointa , pointb);
    system("pause");
    return 0;
}