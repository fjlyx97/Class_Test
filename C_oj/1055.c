#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    int num[n];
    int i = 0;
    for (i = 0 ; i < n ;i++)
    {
        scanf("%d", &num[i]);
    }
    int j = 0;
    int result = -1;
    for (i = n-1 ; i >= 0 ; i--)
    {
        for ( j = i - 1 ; j >= 0 ; j--)
        {
            if (num[i] == num[j])
            {
                num[j] = -999;
                result = 1;
            }
        }
        if (result == 1)
        {
            num[i] = -999;
            result = 0;
        }
    }
    for ( i = 0 ; i < n ; i++)
    {
        if (num[i] == -999)
        {
            continue;
        }
        else
        {
            printf("%d",num[i]);
            break;
        }
    }
    system("pause");
    return 0;
}