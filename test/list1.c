#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE   10
#define LISTINCREMENT   5

typedef int ElemType;
typedef struct{
    ElemType *elem;
    int length ;
    int ListSize;
}sqlist;

int InitList_sq(sqlist *l)  /*initial the list l*/
{
    l->elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if (!l->elem)
    {
        printf("无法分配空间！");
        return 1;
    }
    else
    {
        l->length=0;
        l->ListSize=LIST_INIT_SIZE;
        printf("ok\n");
        return 0;
    }
}

int insertList(sqlist *l)
{
    if (l->length >= l->ListSize)
    {
        printf("空间已满");
        return -1;
    }
    else
    {
        printf("Please insert num :");
        scanf("%d",(l->elem+l->length));
        printf("Insert num is :%d\n",*(l->elem+l->length));
        l->length++;
        return 1;
    }
}

int delList(sqlist *l)
{
    if (l->length <= 0)
    {
        printf("None num\n");
        return -1;
    }
    else
    {
        l->length--;
        return 1;
    }
}

int searchList(sqlist *l)
{
    if (l->length <= 0)
    {
        printf("None num\n");
        return -1;
    }
    else
    {
        int i;
        ElemType searchNum;
        printf("Please input search num:");
        scanf("%d",&searchNum);
        for (i = 0 ; i < l->length ; i++)
        {
            if (*(l->elem+i) == searchNum)
            {
                printf("Found num , index is : %d\n",i);
                return 1;
            }
        }
        printf("Cannot find num\n");
        return -1;
    }
}

int main()
{
   sqlist L;
   InitList_sq(&L);
   insertList(&L);
   insertList(&L);
   insertList(&L);
   insertList(&L);
   insertList(&L);
   delList(&L);
   searchList(&L);
   system("pause");
   return 0;
}
