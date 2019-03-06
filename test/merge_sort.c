#include <stdio.h>
#include <stdlib.h>
void merge(int* num , int l , int r, int m)
{
    //printf("l: %d r %d mid %d\n",l,r,m);
    int leftSize = m-l;
    int rightSize = r-m+1;
    int leftNum[leftSize];
    int rightNum[rightSize];
    int i = 0 , j = 0, index = l;
    for (i = l ; i < m ; i++)
        leftNum[i-l] = num[i];
    for (i = m ; i <= r ; i++)
        rightNum[i-m] = num[i];
    i = 0 , j = 0;
    index = l;
    while (i < leftSize && j < rightSize)
    {
        if (leftNum[i] < rightNum[j])
            num[index++] = leftNum[i++];
        else
            num[index++] = rightNum[j++];
    }
    while(i < leftSize)
        num[index++] = leftNum[i++];
    while(j < rightSize)
        num[index++] = rightNum[j++];
}
void merge_sort(int* num , int l , int r)
{
    if (l >= r)
        return;
    int mid = (l+r)/2;
    merge_sort(num,l,mid);
    merge_sort(num,mid+1,r);
    //printf("l: %d r %d mid %d\n",l,r,mid+1);
    merge(num,l,r,mid+1);
}
int main()
{
    int n;
    int i;
    int* num;
    scanf("%d",&n);
    num = (int*)malloc(sizeof(int)*n);
    for (i = 0 ; i < n ;i++)
    {
        scanf("%d",&num[i]);
    }
    merge_sort(num,0,n-1);
    //merge(num,0,5,3);
    for (i = 0 ; i < n ; i++)
    {
        printf("%d ",num[i]);
    }
    free(num);
	system("pause");
	return 0;
}
