#include <stdio.h>
#include <stdlib.h>
typedef int Position;
typedef int ElementType;
typedef struct LNode *List;
#define MAXSIZE 10
#define NotFound 0
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last;
};
Position BinarySearch(List L , ElementType X);
int main()
{
    List L = (List)malloc(sizeof(struct LNode));
    ElementType X;
    Position P;
    int i = 0;
    int num;
    scanf("%d",&num);
    for (i = 1 ; i <= num ; i++)
    {
        scanf("%d",&L->Data[i]);
        L->Last = i;
    }
    scanf("%d",&X);
    P = BinarySearch(L,X);
    printf("%d\n",P);
    system("pause");
    return 0;
}
Position BinarySearch(List L , ElementType X)
{
    int left = 1;
    int right = L->Last;
    int mid;
    while (left <= right)
    {
        mid = (left+right)/2;
        if (L->Data[mid] == X)
        {
            return mid;
        }
        else if (L->Data[mid] > X)
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }
    return NotFound;
}