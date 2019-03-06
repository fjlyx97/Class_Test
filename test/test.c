#include <stdio.h>
#include <stdlib.h>
//在一个有序序列中，输入一个数，将该述插入在正确的位置，使得插入后的序列依然有序。
struct number
{
	int num;
	struct number *next;
	
}; 
struct number *creat(struct number *head)
{
	int n,i=0;
	struct number *p1,*p2;
	p1=p2=(struct number *)malloc(sizeof(struct number));
	p1->next=NULL;
	printf("请输入有序数列的个数");
	scanf("%d",&n);
	while(i < n)
	{
		if(head==NULL) head=p1;
		else
		{
			p2->next=p1;
			p2=p1;
		}
		p1=(struct number*)malloc(sizeof(struct number));
		scanf("%d",&p1->num);
		i++;
	}
	return head;	
} 
struct number *insert(struct number *head,struct number *stud)//小到大的序列 
{
	struct number *p0;
    struct number *p1;
	struct number *p2;
	p1=head;
	p0=stud;
	if(head == NULL)//考虑插入是不是空表 
	{
		head=p0;
		p0->next=NULL;
	} 
	else
	{ 
	    while((p1->num != p0->num) && (p1->next != NULL)) //查找是否有相同的数字 
		{
		   p1=p1->next;
		}
		if(p1->next!=NULL)//有相同数字，就插入到相同数字后面 
		{
		   p0->next=p1->next;
		   p1->next=p0; 
		}
		else//没有相同数字处理情况下 
		{
			p1=head;
		    while((p0->num > p1->num)&&(p1->next!=NULL))//插入是中间位置，插入的数字刚好大于当前那个数字 
			{
				p2=p1;
				p1=p1->next;
			}

		if(p0->num < p1->num)//插入的数字小于当前数字 
		{
			if(head == p1) //如果插入的数字就小于第一个数字 
			{head =p0;} 
			else 
			{p2->next=p0;} 
			
			p0->next=p1;
		}
		else//插入最后一个位置， 
		{
			p1->next=p0;
			p0->next=NULL;
		}
		
	}
	}
	return head;	
} 
void print(struct number *head)
{
	struct number *temp;
	temp=head;
	if(head!=NULL)
	{
		while(temp!=NULL)
		{
			printf("%d",temp->num);
			temp=temp->next;
		}
	}
	return;	
}
int main()
{
	struct number *head=NULL;
	struct number *stud;
	
	stud=(struct number *)malloc(sizeof(struct number));//申请新节点 
	head=creat(head);
	printf("请输入你要插入的数字:");
	scanf("%d",&stud->num);//插入数字
	stud->next=NULL;
	head=insert(head,stud);
	printf("插入后的有序数列如下:");
	print(head);	

	system("pause");
	return 0;
}