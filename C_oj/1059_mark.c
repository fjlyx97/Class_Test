#include <stdio.h>
#include <stdlib.h>
int judge(float , float , float , float , float , float , float ,float );
int choice_num(int , int , int*);
int main(void)
{
    float num[4][2];
    int i , j;
    for (i = 0 ; i < 4 ; i++)
    {
        for (j = 0 ; j < 2 ; j++)
        {
            scanf("%f",&num[i][j]);
        }
    }
    int k = 0 , l = 0;
    int *p = &l;
    int result = 0;

    for (i = 0 ; i < 4 ; i++)
    {
        for (j = i+1 ; j < 4 ; j++)
        {
            k = choice_num(i,j,p);
            result = judge(num[i][0],num[i][1],num[j][0],num[j][1],num[k][0],num[k][1],num[l][0],num[l][1]);
            if ( result == 1)
            {
                printf("YES");
                system("pause");
                return 0;
            }
            j++;
        }
    }
    printf("NO");
    system("pause");
    return 0;
}
int judge(float x1, float y1 , float x2 , float y2 , float x3 , float y3 , float x4 , float y4)
{
    float k1 , k2;
    k1 =  (y2 - y1) / (x2 - x1);
    k2 =  (y4 - y3) / (x4 - x3);
    if (x4 - x3 == 0)
    {
        k2 = 0;
    }
    if (x2 - x1 == 0)
    {
        k1 = 0;
    }
    if (k1 == 0 && k2 == 0)
    {
        if ( y2 - y1 == 0 && x4 - x3 == 0 )
        {
            return 1;
        }
        if ( y4 - y3 == 0 && x2 - x1 == 0 )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if ( k1 * k2 == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int choice_num(int num1 ,  int num2 , int* num3)
{
    int num[4] = {0,1,2,3};
    int i = 0;
    for (i = 0 ; i < 4 ; i++)
    {
        if ( num[i] == num1 || num[i] == num2 )
        {
            continue;
        }
        *num3 = i;
    }
    for (i = 0 ; i < 4 ; i++)
    {
        if ( num[i] == num1 || num[i] == num2 || num[i] == *num3)
        {
            continue;
        }
        return i;
    }
}