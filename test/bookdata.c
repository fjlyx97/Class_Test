/*
ɾ��������޷�����
�鱾��������
ɾ����Ŀ�����������¼������

���һ�δ����
������Ҫд
*/


#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#define I 2

FILE *fp;

/****************************�����嵥*****************************/

void HideCursor();//---���ع��---

void goto_xy(int x, int y);//---��λ���λ�õ�ָ������---

/*--------------------------------------------------------------*/

void homepage();//---��ҳ---

void setin();//---¼��---

void list(struct book *p);//---���---

void show(struct book *p);//---��ӡ---

void serch();//---����---

void serch_num();//��¼�Ų���

void serch_name();//��������

void serch_author();//���߲���

void serch_dirive();//����Ų���

void serch_publish();//���������

void serch_date();//�������ڲ���

void serch_price();//�۸����

void serch_indistinct();//ģ������

void serch_fail();//����ʧ��
/*
void sort(struct book b[],int n);//---����---

void sort_n_down(struct book b[],int n);//��¼�Ÿ�-������

void sort_name_up(struct book b[],int n);//������-������

void sort_a_up(struct book b[],int n);//���ߵ�-������

void sort_dirive_up(struct book b[],int n);//����ŵ�-������

void sort_publish_house(struct book b[],int n);//���浥λ��-������

void sort_date_late(struct book b[],int n);//����ʱ����-������

void sort_date_early(struct book b[],int n);//����ʱ����-������
*/
void delet();//---ɾ��---

void change();//---�޸�---

void save(struct book *p);//---���ݱ���---

void read();//---�ļ���---

void establish();//�½�����

void ending();//---�˳�---

/*************************���ڲ�������***************************************/

void HideCursor()     //���ع��
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void toxy(int x, int y)      //������ƶ���X,Y���괦
{
	COORD pos = { x , y };
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos); 
}

/***************************�ṹ��******************************************/

struct date
{
	int year;
	int month;
	int day;
};
struct book
{
	char num[10];
	char name[20];
	char author[10];
	char dirive[10];
	char publish_house[40];
	struct date printdate;
	float ptice;

	struct book *next;
};
struct book *head=NULL;
struct book *tail=NULL;
int n=0;
#define LEN sizeof(struct book)
/****************************���ܺ���*****************************************/

void homepage()//��ҳ
{
	char t;
	HideCursor();
	while(1)
	{
		system("cls");
		printf(" ========================== \n");
		printf("| ������ѧԺͼ�����ϵͳ |\n");
		printf("|==========================|\n");
		printf("|       1������¼��        |\n");
		printf("|       2�������Ŀ        |\n");
		printf("|       3����Ŀ��ѯ        |\n");
		printf("|       4����Ŀ����        |\n");
		printf("|       5��ɾ����Ŀ        |\n");
		printf("|       6�������޸�        |\n");
		printf("|==========================|\n");
		printf("| ��������1-6ѡ�񣬰�0�˳� |\n");
		printf(" ==========================\n");
		while(1)
		{
			t=getch();
			switch (t)
			{
			case '1':setin();break;
			case '2':
				{
					if(head==NULL)
					{
						system("cls");
						printf("�����ʱû����Ŷ~�Ͽ�ȥ��Ӽ�����^_^(�����������)");
						getch();
						homepage();
					}
					else
					{
						list(head);
						printf("   ==========================\n");
						printf("     ��0�˳�,��1����Ŀ¼ \n");
						printf("   ==========================\n");
						while(1)
							{
								t=getch();
								switch (t)
								{
								case '1':homepage();break;
								case '0':ending();break;
								default:system("cls");printf("\n       ϵͳ����");Sleep(1000);homepage();break;
								}
							}
						break;
					}
				}
			case '3':serch();break;
			case '4':printf("����");break;//sort();break;
			case '5':delet();break;
			case '6':change();break;
			case '0':ending();break;
			default:system("cls");printf("\n       ϵͳ����");Sleep(1000);break;
			}
		}
	}
}

//¼��
void setin()
{
	struct book *p;
	while(1)
	{
		p=(struct book *)malloc(LEN);
		n++;
		system("cls");
		printf("������ͼ���¼��(С��10λ��)��");    
		scanf("%s",p->num);getchar();
		printf("����������(С��10λ��)��");
		scanf("%s",p->name);getchar();
		printf("������������(С��5������)��");
		scanf("%s",p->author);getchar();
		printf("����������(С��10λ��)��");
		scanf("%s",p->dirive);getchar();
		printf("������ͼ����浥λ(С��20������)��");
		scanf("%s",p->publish_house);getchar();
		printf("������ͼ�����ʱ��(��.��.��)��");
		scanf("%d.%d.%d",&(p->printdate.year),&(p->printdate.month),&(p->printdate.day));getchar();
		printf("������ͼ��۸�");
		scanf("%f",&p->ptice);getchar();
		save(p);
	}
}
//���
void list(struct book *p)
{
	struct book *p1;
	system("cls");
	printf("   ------------------------------------------------------------------------------------------------------\n");
	printf("\t��¼��\t����\t������\t�����\t���浥λ\t����ʱ��\t�۸�Ԫ��\n");
	printf("   ------------------------------------------------------------------------------------------------------\n");
	for(p1=p;p1!=NULL;p1=p1->next)
		show(p1);
}
//��ӡ
void show(struct book *p)
{
	printf("\t%s\t%s\t%s\t%s\t%s\t\t%d.%d.%d\t%.2f\n",p->num,p->name,p->author,p->dirive,p->publish_house,p->printdate.year,p->printdate.month,p->printdate.day,p->ptice);
}
//����
void serch()
{
	char t;
	system("cls");
	HideCursor();
	printf(" ============================ \n");
	printf("|      ��ѡ����ҷ�ʽ:       |\n");
	printf("|============================|\n");
	printf("|     1������ ¼ �Ų���      |\n");
	printf("|     2������    ������      |\n");
	printf("|     3������    �߲���      |\n");
	printf("|     4������ �� �Ų���      |\n");
	printf("|     5������ �� �����      |\n");
	printf("|     6�����������ڲ���      |\n");
	printf("|     7������    �����      |\n");
	printf("|     8��  ģ  ��  ����      |\n");
	printf("|============================|\n");
	printf("|  ��������1-8ѡ�񣬰�0����  |\n");
	printf(" ============================ \n");
	while(1)
	{
		t=getch();
		switch (t)
		{
		case '1':serch_num();
		case '2':serch_name();
		case '3':serch_author();
		case '4':serch_dirive();
		case '5':serch_publish();
		case '6':serch_date();
		case '7':serch_price();
		case '8':;
		case '0':homepage();break;
		default:printf("ϵͳ����");Sleep(1000);break;
		}
	}
}
void serch_fail()//����ʧ��
{
	char t;
	system("cls");
	printf(" ================================ \n");
	printf("| δ�ҵ����ݣ��Ƿ�������в����� |\n");
	printf("|      1����       2����         |\n");
	printf(" ================================ \n");
	while(1)
	{
		t=getch();
		switch (t)
		{
		case '1':serch();break;
		case '2':homepage(); break;
		default:printf("\n        ϵͳ����");Sleep(1000);break;
		}
	}
}
void serch_num()  //��¼�Ų���
{
	struct book *p;
	char dlh[10];
	int flag=0;
	system("cls");
	printf("========================================\n");
	printf("      ������Ҫ���ҵĵ�¼�ţ�\n");
	printf("========================================\n");
	toxy(28,1);
	scanf("%s",dlh);
	for(p=head;p->num>0;p=p->next)
		if(strcmp(p->author,dlh)==0)
		{
			flag=1;
			show(p);
		}
	if(flag==0)
		serch_fail();
}
void serch_name()  //��������
{
	struct book *p;
	int flag=0;
	char sm[100];
	system("cls");
	printf("========================================\n");
	printf("      ������Ҫ���ҵ�������\n");
	printf("========================================\n");
	toxy(26,1);
	scanf("%s",sm);
	for(p=head;p->num>0&&p!=NULL;p=p->next)
		if(strcmp(p->name,sm)==0)
		{
			flag=1;
			show(p);
		}
	if(flag==0)
		serch_fail();
}
void serch_author()  //���߲���
{
	struct book *p;
	char s[20];
	int flag=0;
	system("cls");
	printf("========================================\n");
	printf("      ������Ҫ���ҵ����ߣ�\n");
	printf("========================================\n");
	toxy(26,1);
	scanf("%s",s);
	
	for(p=head;p->num>0&&p!=NULL;p=p->next)
		if(strcmp(p->author,s)==0)
		{
			flag=1;
			show(p);
		}
	if(flag==0)
		serch_fail();
}
void serch_dirive()  //����Ų���
{
	struct book *p;
	char s[10];
	int flag=0;
	system("cls");
	printf("========================================\n");
	printf("      ������Ҫ���ҵķ���ţ�\n");
	printf("========================================\n");
	toxy(28,1);
	scanf("%s",s);
	
	for(p=head;p->num>0&&p!=NULL;p=p->next)
		if(strcmp(p->dirive,s)==0)
		{
			flag=1;
			show(p);
		}
	if(flag==0)
		serch_fail();
}
void serch_publish()  //���������
{
	struct book *p;
	char s[50];
	int flag=0;
	system("cls");
	printf("========================================\n");
	printf("      ������Ҫ���ҵĳ����磺\n");
	printf("========================================\n");
	toxy(28,1);
	scanf("%s",s);
	
	for(p=head;p->num>0&&p!=NULL;p=p->next)
		if(strcmp(p->publish_house,s)==0)
		{
			flag=1;
			show(p);
		}
	if(flag==0)
		serch_fail();
}
void serch_date()  //�������ڲ���
{
	struct book *p;
	int y,m,d;
	int flag=0;
	system("cls");
	printf("========================================\n");
	printf("      ������Ҫ���ҵ����ڣ�\n");
	printf("========================================\n");
	toxy(26,1);
	scanf("%d.%d.%d",&y,&m,&d);
	
	for(p=head;p->num>0&&p!=NULL;p=p->next)
		if(p->printdate.year==y&&p->printdate.month==m&&p->printdate.day==d)
		{
			flag=1;
			show(p);
		}
	if(flag==0)
		serch_fail();
}
void serch_price()  //�۸����
{
	struct book *p;
	int pri;
	int flag=0;
	system("cls");
	printf("========================================\n");
	printf("      ������Ҫ���ҵļ۸�\n");
	printf("========================================\n");
	toxy(26,1);
	scanf("%d",&pri);
	for(p=head;p->num>0&&p!=NULL;p=p->next)
		if(p->ptice==pri)
		{
			flag=1;
			show(p);
		}
	if(flag==0)
		serch_fail();
}
void serch_indistinct()//ģ����ѯ
{
	struct book *p;
	char information[100];
	int flag=0;
	
	system("cls");
	printf("========================================\n");
	printf("      ������Ҫ���ҵ���Ϣ��\n");
	printf("========================================\n");
	toxy(26,1);
	scanf("%s",information);
	for(p=head;p->num>0&&p!=NULL;p=p->next)
	{
		if(p!=NULL&&(strcmp(p->name,information)==0||strcmp(p->dirive,information)==0||strcmp(p->publish_house,information)==0||strcmp(p->author,information)==0))
		{
			flag=1;
			show(p);
		}
		p=p->next;
	}
	if(flag==0)
		serch_fail();
	
}
/*
void sort()  //����
{
	char t;
	system("cls");
	HideCursor();
	printf(" =================================\n");
	printf("|         ��ѡ������ʽ:         |\n");
	printf("|=================================|\n");
	printf("|     1������ ¼ �Ÿ�-������      |\n");
	printf("|     2��������ʱ����-������      |\n");
	printf("|     3��������ʱ����-������      |\n");
	printf("|     4������    ���-������      |\n");
	printf("|     5������    ���-������      |\n");
	printf("|=================================|\n");
	printf("|  ��������1-5ѡ�񣬰�0������ҳ�� |\n");
	printf(" =================================\n");
	t=getch();
	switch (t)
	{
		case '1':list(sort_n_down());
		case '2':list(sort_n_down());
		case '3':list(sort_n_down());
		case '4':list(sort_n_down());
		case '5':list(sort_n_down());
		case '0':homepage();break;
		default:printf("ϵͳ����");Sleep(1000);break;
	}
}
//��¼�Ÿ�-������
void sort_n_down()
{
	int i,j;
	struct book temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(b[j+1].num>b[j].num)
			{
				temp=b[j+1];
				b[j+1]=b[j];
				b[j]=temp;
			}
		}
	}
}
//����ʱ����-������
struct book *sort_date_late()
{
	struct book *pfirst;      //���к��������ı�ͷָ��  
    struct book *ptail;       //���к��������ı�βָ�� 
    struct book *pminBefore;  //������ֵ��С�Ľڵ��ǰ���ڵ��ָ�� 
    struct book *pmin;        // �洢��С�ڵ�   
    struct book *p;           // ��ǰ�ȽϵĽڵ� 
   
    pfirst = NULL;  
    while (head != NULL)
    {  
        for (p=head->next,pmin=head;p->next!=NULL;p=p->next) 
        {  
            if (p->printdate.year<pmin->printdate.year||p->printdate.year==pmin->printdate.year&&p->printdate.month<pmin->printdate.month||p->printdate.year==pmin->printdate.year&&p->printdate.month==pmin->printdate.month&&p->printdate.day<pmin->printdate.day) //�ҵ�һ���ȵ�ǰminС�Ľڵ㡣
            {  
                pminBefore=p;           //�����ҵ��ڵ��ǰ���ڵ㣺��Ȼp->next��ǰ���ڵ���p  
                pmin=p->next;     //�����ֵ��С�Ľڵ㡣*******************************************************
            }  
        }  
    
    //����for�������󣬾�Ҫ�������£�һ�ǰ����������������У����Ǹ�����Ӧ�������жϣ��������뿪ԭ�������� 
      
        //��һ����
        if (pfirst == NULL)
        {  
            pfirst = pmin;      // ��һ���ҵ���ֵ��С�Ľڵ㡣 
            ptail  = pmin;      //ע�⣺βָ������ָ������һ���ڵ㡣   
        }  
        else                   //�����������Ѿ��нڵ�                       
        {  
            ptail->next = pmin; //�Ѹ��ҵ�����С�ڵ�ŵ���󣬼���βָ���nextָ������ 
            ptail = pmin;       //βָ��ҲҪָ������                               
        }  
  
        //�ڶ�����
        if (pmin == head)        // ����ҵ�����С�ڵ���ǵ�һ���ڵ�                 
        {  
            head = head->next;   // ��Ȼ��headָ��ԭhead->next,���ڶ����ڵ㣬��OK  
        }  
        else //������ǵ�һ���ڵ�
        {  
            pminBefore->next = pmin->next; //ǰ����С�ڵ��nextָ��ǰpmin��next,��������pmin�뿪��ԭ���� 
        }  
    }  
  
    if (pfirst != NULL)     //ѭ�������õ���������first       
    {  
        ptail->next = NULL; //������������һ���ڵ��nextӦ��ָ��NULL 
    }  
    head = pfirst;  
return pfirst;
}
//����ʱ����-������
void sort_date_early(struct book b[],int n)
{
	int i,j;
	struct book temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(b[j+1].printdate.year<b[j].printdate.year||b[j+1].printdate.year==b[j].printdate.year&&b[j+1].printdate.month<b[j].printdate.month||b[j+1].printdate.year==b[j].printdate.year&&b[j+1].printdate.month==b[j].printdate.month&&b[j+1].printdate.day<b[j].printdate.day)
			{
				temp=b[j+1];
				b[j+1]=b[j];
				b[j]=temp;
			}
		}
	}
}
//�۸��-������
void sort_p_down(struct book b[],int n)
{
	int i,j;
	struct book temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(b[j+1].ptice>b[j].ptice)
			{
				temp=b[j+1];
				b[j+1]=b[j];
				b[j]=temp;
			}
		}
	}
}
//�۸��-������
void sort_p_up(struct book b[],int n)
{
	
}
*/
//ɾ��
void delet()
{
	char x[10];
	struct book *p1,*p2;
	char t;
	int flag=0;
	system("cls");
	list(head);
	printf("======================================================\n");
	printf("  ������Ҫɾ�����鱾�ĵ�¼�ţ�\n");
	printf("======================================================\n");
	toxy(30,4);
	scanf("%s",x);
	for(p1=head;p1->num>0&&p1!=NULL;p1=p1->next)//��˳�����
	{
		p2=p1;
		if(strcmp(p1->num,x)==0)//�ҵ���Ӧ����
		{
			flag=1;
			if(p1==head)
				head=p1->next;
			else
				p2->next=p1->next;
			n--;
			free(p1);
			system("cls");
			printf(" ================================\n");
			printf("|  ɾ���ɹ����Ƿ�������в�����  |\n");
			printf("|      1����       2����         |\n");
			printf(" ================================ \n");
			while(1)
			{
				t=getch();
				switch (t)
				{
				case '1':delet();break;
				case '2':homepage(); break;
				default:printf("\n        ϵͳ����");Sleep(1000);break;
				}
			}
		}
	}
	if(flag==0)
	{
		system("cls");
		printf(" ================================ \n");
		printf("| δ�ҵ����ݣ��Ƿ�������в����� |\n");
		printf("|      1����       2����         |\n");
		printf(" ================================ \n");
		while(1)
		{
			t=getch();
			switch (t)
			{
			case '1':delet();break;
			case '2':homepage(); break;
			default:printf("\n        ϵͳ����");Sleep(1000);break;
			}
		}
	}
	
}
//�޸�
void change()
{
	char t;
	struct book *p1,*p2; 
	char dlh[10];
	int flag=0;
	system("cls");
	printf("========================================\n");
	printf("  ������Ҫ�޸ĵ��鱾�ĵ�¼�ţ�");
	printf("========================================\n");
	toxy(5,30);
	scanf("%s",dlh);
	if(strcmp(dlh,"0")==0)
		homepage();
	else
	{
		for(p1=head;p1->num>0&&p1!=NULL;p1=p1->next)
		{
			p2=p1;
			p1=p1->next;
			if(p1==head)
				head=p1->next;
			else
				p2->next=p1->next;
		}
	}
	system("cls");
	printf("====================================================\n");
	printf("      ��s��ʼ���룬��b���أ���e��������\n");
	printf("====================================================\n");
	printf("�������޸ĺ�����ݣ�");	
	printf("------------------------------------------------------------------------------------------------------\n");
	printf("   ��¼��        ����        ������     �����        ���浥λ        ����ʱ�䣺��.��.��    �۸�Ԫ��\n");
	printf("------------------------------------------------------------------------------------------------------\n");
	while(1)
	{
		t=getch();
		if(t=='b')
			homepage();
		if(t=='s')
		{
			scanf("%s%s%s%s%s%d.%d.%d%f",p1->num,p1->name,p1->author,&p1->dirive,p1->publish_house,&p1->printdate.year,&p1->printdate.month,&p1->printdate.day,&p1->ptice);
			p1->next=p2->next;
			p2->next=p1;
		}
		if(t=='e')
			break;
	}
	for(p1=head;p1->num>0&&p1!=NULL;p1=p1->next)
		if(strcmp(p1->author,dlh)==0)
		{
			flag=1;
			show(p1);
		}
	if(flag==0)
		serch_fail();
	list(head);
	save(p1);
}
//���ݱ���
void save(struct book *p)
{
	char t;
	system("cls");
	printf(" ================================ \n");
	printf("|         �Ƿ񱣴����ݣ�         |\n");
	printf("|      1����       2����         |\n");
	printf(" ================================ \n");
	fp=fopen("bookdata","ab+");
	while(1)
	{
		t=getch();
		switch (t)
		{
		case '1':
			{
				system("cls");
				printf("\n            ���ڱ��桭��\n");
				Sleep(1000);
				if(fp==NULL)
				{
	  				system("cls");
					printf(" ================================\n");
					printf("|�ļ���ʧ�ܣ��Ƿ�������в�����|\n");
					printf("|      1����       2����         |\n");
					printf(" ================================ \n");
					while(1)
					{
						t=getch();
						switch (t)
						{
						case '1':save(p);break;
						case '2':homepage();break;
						default:system("cls");printf("\n        ϵͳ����");Sleep(1000);homepage();break;
						}
					}
				}
				if(fwrite(p,LEN,1,fp)!=1)
				{
					system("cls");
					printf(" ================================\n");
					printf("|�ļ�д��ʧ�ܣ��Ƿ�������в�����|\n");
					printf("|      1����       2����         |\n");
					printf(" ================================ \n");
					while(1)
					{
						t=getch();
						switch (t)
						{
						case '1':save(p);break;
						case '2':homepage(); break;
						default:system("cls");printf("\n        ϵͳ����");Sleep(1000);save(p);break;
						}
					}
				}
				system("cls");
				printf("\n   ================================\n");
				printf("  |            ����ɹ�            |\n");
				printf("   ================================ \n");
				fclose(fp);
				Sleep(1000);
				homepage();
				break;
			}
		case '2':homepage();break;
		default:printf("\n        ϵͳ����");Sleep(1000);homepage();break;
		}
	}

}
void read()//�ļ���Ϣ��ȡ
{
	char t;
	struct book *p,*p2,*pr;
	fp=fopen("bookdata","rb+");
	if(fgetc(fp) ==EOF)
	{
		fseek(fp,0,0);
		homepage();
	}
	if(fp==NULL)
	{
	  	system("cls");
		printf(" ================================\n");
		printf("|�ļ���ʧ�ܣ��Ƿ�������в�����|\n");
		printf("|      1����       2����         |\n");
		printf(" ================================ \n");
		while(1)
		{
			t=getch();
			switch (t)
			{
			case '1':read();break;
			case '2':ending();break;
			default:system("cls");printf("\n        ϵͳ����");Sleep(1000);homepage();break;
			}
		}
	}
	fseek(fp,0,0);
	while(!feof(fp))        //�ж��ļ�λ�ñ�־�Ƿ��ƶ����ļ�ĩβ 
	{
		n++;
		p=(struct book *)malloc(LEN); //���ڴ�����һ�οռ� 
		fread(p,LEN,1,fp);     //��fp��ָ����ļ��е����ݸ���p 
		if(n==1)
		{
			head=p;
			p2=p;
		}
		else             //�������� 
		{
			pr=p2;
	    	p2->next=p;
	    	p2=p;
		}
    }
	if(pr!=NULL)
       pr->next=NULL;
    else
       head=NULL;
	tail=pr;
	fclose(fp);    //�ر��ļ� 
}
//�˳�
void ending()
{
	char t;
	system("cls");
	printf(" ==============================\n");
	printf("|        �Ƿ�ȷ���˳���        |\n");
	printf("|        1����   2����         |\n");
	printf(" ==============================\n");
	while(1)
	{
		t=getch();
		switch (t)
		{
		case '1':
			system("cls");
			printf("\n       �����˳��У����Ժ�....\n\n");
			Sleep(1000);
			exit(0);
			break;
		case '2':homepage();break;
		default:printf("\n        ϵͳ����");Sleep(1000);homepage();break;
		}
	}
	fclose(fp);	
}
int main()
{
	
	read();
	homepage();
	return 0;
}









