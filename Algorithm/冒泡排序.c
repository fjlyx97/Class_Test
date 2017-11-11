#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    printf("please input a num:");
    int n;
    scanf("%d",&n);
    float num[n];
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 0 ; i < n ; i++)
    {
        scanf("%f",&num[i]);
    }
    for ( i = 1 ; i <= n-1 ; i++ )
    {
        for ( j = 0 ; j < n-i ; j++)
        {
            if (num[j] < num[j+1])
            {
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }
    for (i = 0 ; i < n ; i++)
    {
        printf("%.2f ",num[i]);
    }

    system("pause");
    return 0;
}