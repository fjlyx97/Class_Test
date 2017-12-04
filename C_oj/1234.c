#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n , k;
    scanf("%d %d",&n,&k);
    int num[8] = {0};
    int i , j , l;
    for ( i = 1 ; i <= n ; i++)
    {
        scanf("%d",&num[i]);
    }
    int add = 0 , temp = 0 , del = 0;
    for ( i = 0 ; i < k ; i++)
    {
        add = 0;
        del = 0;
        for ( j = 1 ; j <= n ; j++)
        {
            num[j] -= 1;
            if (num[j] != 0)
            {
                add++;
            }
            if (num[j] == 0)
            {
                del++;
            }
        }
        for ( j = 1 ; j <= n-1 ; j++)
        {
            for (l = 1 ; l <= n-j ; l++)
            {
                if (num[l+1] > num[l])
                {
                    temp = num[l+1];
                    num[l+1] = num[l];
                    num[l] = temp;
                }
            }
        }
        temp = n+add;
        if (temp > 7)
        {
            temp = 7;
        }
        for ( l = n-del+1 ; l <= temp-del ; l++)
        {
            num[l] = 3;
        }
        n = temp - del;
    }
    printf("%d",n);
    system("pause");
    return 0;
}