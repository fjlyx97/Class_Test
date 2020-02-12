#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
using namespace std;
typedef struct Student
{
	char num[15];//ѧ��
	char name[10];//����
	char sex[5];//�Ա�
	char age[3];//����
	int score;//����

	struct Student *next;
    Student& operator= (const Student &t)
    {
        this->score = t.score;
        strcpy(this->name ,t.name);
        strcpy(this->sex ,t.sex);
        strcpy(this->age ,t.age);
        strcpy(this->num ,t.num);
    }
}Stu;

Student *head=NULL;
Student *tail=NULL;
int sum=0;
int scan(Student *now)//����һ��
{
	memset(now->num,0,sizeof(now->num));
	memset(now->name,0,sizeof(now->name));
	memset(now->sex,0,sizeof(now->sex));
	memset(now->age,0,sizeof(now->age));

	scanf("%s",now->num);
	if(strcmp(now->num,"0")==0)
		return 0;
	scanf("%s",now->name);
	scanf("%s",now->sex);
	scanf("%s",now->age);
	scanf("%d", &now->score);
	getchar();
	return 1;
}
void print(Student *now)//���һ��
{
	printf("#ѧ�ţ�%s ",now->num);
	printf("���֣�%s ",now->name);
	printf("�Ա�%s ",now->sex);
	printf("���䣺%s ",now->age);
	printf("������%d\n",now->score);
	return;
}
int add()//���
{
	//static int k=0;
	int flag=1;
	Student *now;
	if (sum == 0)
	{
		head =(Student*)malloc(sizeof(Student));
		head->next = NULL;
		//����
		flag=scan(head);
		//print(head);
		tail = head;
	}
	else
	{
		if (!(now =(Student*)malloc(sizeof(Student))))
		{
			printf("�洢�ռ�������");
			return 0;
		}
		//����
		tail->next = now;
		flag=scan(now);
		now->next = NULL;
		tail = now;
	}
	//print(tail);
	//gotoxy(20,k+2);
	if(flag)
		sum++;
	return flag;
}
void input()//����ȫ��
{
	Student *p;
	int num,i=0;
	while (1)
	{
		if(add()==0)
		{
			break;
		}
		i++;
	}
	return;
}
void output()
{
	int i;
	Student *p;
		for (i = 1; i <= sum; i++)
		{
			if (i == 1)
				p = head;
			else
				p = p->next;
			print(p);
		}
	return;
}
void sort()//����
{
	int i,j;
    bool isSwap;
	Student *pi,*pj,*t=(Student*)malloc(sizeof(Student)),*max;
    int maxScore;
	for(i=1;i<sum;i++)
	{
		if(i==1)
			pi=head;
		else
			pi=pi->next;
        isSwap = false;
 	 	maxScore=pi->score;
 	 	pj=pi->next;
		for(j=i+1;j<=sum;j++)
		{
			if(pj->score > maxScore)
			{
                isSwap = true;
                maxScore = pj->score;
				max=pj;
			}
			pj=pj->next;
		}
        if (isSwap)
        {
            *t=*pi;
            *pi=*max;
            *max=*t;
        }
		//max->next=pi->next;
		//pi->next=t->next;
 	}
 	output();
}
int main()
{
	input();
	sort();
	system("pause");

	return 0;
}