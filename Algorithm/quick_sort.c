#include <stdio.h>
#include <stdlib.h>
void quick_sort(int left , int right , int *num)
{
    if (left > right)
    {
        return;
    }
    int i = left;
    int j = right;
    int temp;
    int t = num[left];
    int k;
    while ( i != j)
    {
        for ( ; j > i ; j--)
        {
            if (num[j] < num[left] )
            {
                break;
            }
        }
        for ( ; i < j ; i++)
        {
            if (num[i] > num[left])
            {
                break;
            }
        }
        if ( i < j )
        {
            temp = num[i];
            num[i] = num[j];
            num[j] = temp;
        }
    }
    num[left] = num[i];
    num[i] = t;
    quick_sort(left,i-1,num);
    quick_sort(i+1,right,num);
}
int main(void)
{
    int n;
    scanf("%d",&n);
    //int num[n];
    int *num = (int*)malloc(sizeof(int) * n);
    int i = 0;
    for ( i = 0 ; i < n ; i++)
    {
        scanf("%d",&num[i]);
    }
    quick_sort(0,n-1,num);
    for ( i = 0 ; i < n ; i++)
    {
        printf("%d ",num[i]);
    }
    system("pause");
    return 0;
}