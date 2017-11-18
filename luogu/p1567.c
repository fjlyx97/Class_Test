#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    int num[N];
    int i = 0;
    for ( i = 0 ; i < N ; i++)
    {
        scanf("%d",&num[i]);
    }
    int max = 0;
    int temp = 0;
    for ( i = 0 ; i < N-1 ; i++)
    {
        if (num[i+1] > num[i])
        {
            temp++;
            if ( temp > max )
            {
                max = temp;
            }
        }
        else
        {
            temp = 0;
        }
    }
    printf("%d",max+1);

    system("pause");
    return 0;
}