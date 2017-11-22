#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    int num[10] = {0};
    int i = 0 , j;
    int one = n / 10;
    int two = n % 10;
    for ( i = 1 ; i <= one ; i++)
    {
        for ( j = 0 ; j < 10 ; j++)
        {
            num[j]++;
        }
    }
    for ( j = 1 ; j < one ; j++)
    {
        num[j] += 10;
    }
    for ( i = 0 ; i <= two ; i++)
    {
        if (one != 0)
        {
            num[one]++;
        }
        num[i]++;
    }

    num[0]--;
    if (n == 100)
    {
        num[0]++;
        num[1]++;
    }
    for (i = 0 ; i < 10 ; i++)
    {
        printf("%d\n",num[i]);
    }
    


    system("pause");
    return 0;
}