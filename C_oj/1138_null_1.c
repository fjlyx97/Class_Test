#include <stdio.h>
#include <stdlib.h>
void judge(int n, int k, int m, int x)
{
    int* num = (int*)malloc(sizeof(int)*n+1);
    int* num_list = (int*)malloc(sizeof(int)*n+1);
    int i , index;
    for ( i = 1 ; i <= n ; i++)
    {
        num[i] = i;
        if ( i != n)
        {
            num_list[i] = i+1;
        }
        else
        {
            num_list[i] = 1;
        }
    }

    num_list[m-1] = num_list[m];
    index = m-1;
    n--;
    
    while(n != 1)
    {
        for (i = 1 ; i < k ; i++)
        {
            index = num_list[index];
        }
        num_list[index] = num_list[num_list[index]];
        n--;
    }
    if ( x == num[index])
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}
int main(void)
{
    int n , k , m , x;
    int i;
    while (1)
    {
        scanf("%d %d %d %d",&n,&k,&m,&x);
        if (n == 0 && k == 0 && m == 0 && x ==0)
        {
            break;
        }
        judge(n,k,m,x);
    }

    system("pause");
    return 0;
}