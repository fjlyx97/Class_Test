#include<stdio.h>
#include<stdlib.h>
#include <stdlib.h>

typedef int DateType;
typedef struct Lnode
{
    DateType date;
    struct Lnode *link;
}Lnode,*Linklist;


void initList(Linklist* first)
{
    *first = (Lnode* ) malloc(sizeof(Lnode));
    if(!first){
        printf("error\n");
        exit(1);
    }
    (*first)->link=NULL;
}


int Insert(Linklist* first,int i,DateType x)
{
    if(!first||i==1){
        Lnode *newNode = (Lnode*)malloc(sizeof(Lnode));
        if(!newNode ){
            printf("error!\n");
            exit(1);
        }
        newNode->date = x;
        newNode->link = *first;
        *first= newNode;
    }
    else{
        Lnode *p = *first; int k =  1;
        while(p !=NULL && k<i-1){
            p = p->link;
            k++;
        }
        if( p == NULL && (*first) !=NULL){
            printf("error!\n");
            return 0;
        }
        else{
            Lnode *newNode = (Lnode*)malloc(sizeof(Lnode));
            if(! newNode ){
                printf("error!\n");
                exit(1);
            }
            newNode->date=x;
            newNode->link = p->link; p->link = newNode;
        }
    }
}


void printList(Lnode* first)
{
    //first = first->link;
    while((first->link )!= NULL ){
        printf("%d\n",first->date);
        first = first->link;
    }
    printf("\n");
}
int main()
{
    Linklist list1;
    //initList(&list1);
    Insert(&list1,1,2);
    Insert(&list1,2,3);
    Insert(&list1,3,4);
    printList(list1);
	system("pause");
    return 0;
}

