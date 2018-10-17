#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int num;
    struct Node* next;
};
struct List
{
    struct Node* Head;
};
void showReverseList(struct Node* pList , int index)
{
    if (index < 10)
    {
        showReverseList(pList->next,index+1);
    }
    printf("%d ",pList->num);
    return;
}
int main()
{
    struct List* mList; 
    struct Node* pList; 
    int i;
    mList = (struct List*)malloc(sizeof(struct List));
    mList->Head = (struct Node*)malloc(sizeof(struct Node));
    pList = mList->Head;
    for (i = 0 ; i < 10 ; i++)
    {
        scanf("%d",&(pList->num));
        pList->next = (struct Node*)malloc(sizeof(struct Node));
        pList = pList->next;
    }
    printf("Result:");
    showReverseList(mList->Head,1);

    system("pause");
    return 0;
}