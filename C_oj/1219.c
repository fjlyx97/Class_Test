#include <stdio.h>
#include <stdlib.h>
void fun()
{
    int N;
    scanf("%d",&N);
    int num[N];
    int i = 0 , j = 0;
    for (i = 0 ; i < N ; i++)
    {
        scanf("%d",&num[i]);
    }
    for ( i = 0 ; i < N ; i++)
    {
        for ( j = i ; j < N ; j++)
        {
            if (!(num[i] ^= num[j]) && i != j)
            {
                num[i] = -1;
                num[j] = -1;
                break;
            }
        }
        
    }
}
int main(void)
{
    int T;
    scanf("%d",&T);
    while ( T > 0)
    {
        fun();
        T--;
    }
    
    system("pause");
    return 0;
}