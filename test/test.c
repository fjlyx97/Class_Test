#include <stdio.h>
#include <stdlib.h>
//��һ�����������У�����һ��������������������ȷ��λ�ã�ʹ�ò�����������Ȼ����
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
	printf("�������������еĸ���");
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
struct number *insert(struct number *head,struct number *stud)//С��������� 
{
	struct number *p0;
    struct number *p1;
	struct number *p2;
	p1=head;
	p0=stud;
	if(head == NULL)//���ǲ����ǲ��ǿձ� 
	{
		head=p0;
		p0->next=NULL;
	} 
	else
	{ 
	    while((p1->num != p0->num) && (p1->next != NULL)) //�����Ƿ�����ͬ������ 
		{
		   p1=p1->next;
		}
		if(p1->next!=NULL)//����ͬ���֣��Ͳ��뵽��ͬ���ֺ��� 
		{
		   p0->next=p1->next;
		   p1->next=p0; 
		}
		else//û����ͬ���ִ�������� 
		{
			p1=head;
		    while((p0->num > p1->num)&&(p1->next!=NULL))//�������м�λ�ã���������ָպô��ڵ�ǰ�Ǹ����� 
			{
				p2=p1;
				p1=p1->next;
			}

		if(p0->num < p1->num)//���������С�ڵ�ǰ���� 
		{
			if(head == p1) //�����������־�С�ڵ�һ������ 
			{head =p0;} 
			else 
			{p2->next=p0;} 
			
			p0->next=p1;
		}
		else//�������һ��λ�ã� 
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
	
	stud=(struct number *)malloc(sizeof(struct number));//�����½ڵ� 
	head=creat(head);
	printf("��������Ҫ���������:");
	scanf("%d",&stud->num);//��������
	stud->next=NULL;
	head=insert(head,stud);
	printf("������������������:");
	print(head);	

	system("pause");
	return 0;
}