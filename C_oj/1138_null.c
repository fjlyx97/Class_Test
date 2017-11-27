#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    int n , k , m , x;
    int i;
    int index;
    int j;
    int result;
    while (1)
    {
        scanf("%d %d %d %d",&n,&k,&m,&x);
        if ( 0 == n && 0 == m && 0 == x && 0 == k)
        {
            break;
        }
        int* num = (int*)malloc(sizeof(int)*n+1);
        for ( i = 1 ; i <= n ; i++)
        {
            num[i] = i;
        }
        num[m] = 0;
        j = n-1;
        index = m;
        for ( i = 1 ; i < j ; i++)
        {
            index += k; 
            if (index > n)
            {
               index = index % n; 
            }
            num[index] = 0;
        }
        for ( i = 1 ; i < n+1 ; i++)
        {
            if (num[i] != 0)
            {
                result = num[i];
            }
        }
        if (result == x)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        free(num);
    }

    system("pause");
    return 0;
}