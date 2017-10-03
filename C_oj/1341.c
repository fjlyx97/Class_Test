#include <stdio.h>
#include <stdlib.h>
int Judge(int,int,int);
int main(void)
{
    int num[4];
    long int i , j , k;
    for ( i = 0 ; i < 4; i++)
    {
        scanf("%d",&num[i]);
    }

    for (i = 0 ; i < 4 ; i++)
    {
        for (j = i+1 ; j < 4 ; j++)
        {
            for (k = j+1 ; k < 4 ; k++)
            {
                if (Judge(num[i],num[j],num[k]))
                {
                    printf("YES");
                    system("pause");
                    return 0;
                }
            }
        }
    }
    printf("NO");

    system("pause");
    return 0;
}
int Judge(int a,int b, int c)
{
    if (a + b > c && a + c > b && b + c > a)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}