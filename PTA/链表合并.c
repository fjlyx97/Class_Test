#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read() /* 细节在此不表 */
{
  int len = 0;
  int num = 0;
  PtrToNode h = NULL;
  PtrToNode last = NULL;

  scanf( "%d",&len );
  if(  len == 0  )
    return NULL;

  h = ( PtrToNode )malloc( sizeof( struct Node ) );//建立头结点
  h->Next = NULL;
  last = h;
  while(  len ){
    scanf( "%d",&num );
    PtrToNode node = ( PtrToNode )malloc( sizeof( struct Node ) );
    node->Data = num;
    node->Next = NULL;
    last->Next = node;
    last = node;
    len--;
  }
  return h;
}
void Print( List L )  
{  
    if(L->Next==NULL){
      printf("NULL\n"); 
        return;
    }  
    L=L->Next;
    while(L!=NULL){  
        printf("%d ",L->Data);  
        L=L->Next;  
    }  
    putchar('\n');  
}  
List Merge( List L1, List L2 );
int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}
List Merge(List L1 , List L2)
{
    List L = (List)malloc(sizeof(struct Node));
    L->Next = (List)malloc(sizeof(struct Node));
    List t = L->Next;
    List L1t = L1;
    List L2t = L2;
    if (L1 == NULL && L2 == NULL)
    {
        L->Next = NULL;
        L1->Next = NULL;
        L2->Next = NULL;
        return L;
    }
    L1 = L1->Next;
    L2 = L2->Next;
    while (1)
    {
        if (L1 == NULL)
        {
            while (L2 != NULL)
            {
                t->Data = L2->Data;
                L2 = L2->Next;
                if (L2 == NULL)
                {
                    t->Next = NULL;
                    break;
                }
                t->Next = (List)malloc(sizeof(struct Node));
                t = t->Next;
            }
            L1t->Next = NULL;
            L2t->Next = NULL;
            return L;
        }
        else if (L2 == NULL)
        {
            while (L1 != NULL)
            {
                t->Data = L1->Data;
                L1 = L1->Next;
                if (L1 == NULL)
                {
                    t->Next = NULL;
                    break;
                }
                t->Next = (List)malloc(sizeof(struct Node));
                t = t->Next;
            }
            L1t->Next = NULL;
            L2t->Next = NULL;
            return L;
        }

        if (L1->Data <= L2->Data)
        {
            t->Data = L1->Data;
            L1 = L1->Next;
        }
        else
        {
            t->Data = L2->Data;
            L2 = L2->Next;
        }
        t->Next = (List)malloc(sizeof(struct Node));
        t = t->Next;
    }
}
//List Merge( List L1, List L2 ){
//    List r;
//    //建立头结点而不能使用L1或L2的头结点是因为后边要将L1，L2置为NULL
//    PtrToNode L = ( PtrToNode )malloc( sizeof( struct Node ) );
//    List p=L1->Next;
//    List q=L2->Next;
//    r=L;
//    L->Next=NULL;
//    while(p!=NULL&&q!=NULL){
//        if(p->Data<q->Data){
//            r->Next=p;
//            p=p->Next;
//            r=r->Next;
//
//        }
//        else{
//            r->Next=q;
//            q=q->Next;
//            r=r->Next;
//        }
//
//    }
//    r->Next=NULL;
//    if(p!=NULL)    r->Next=p;
//    if(q!=NULL)    r->Next=q;
//    L1->Next=NULL;
//    L2->Next=NULL;
//    return L;
//}
