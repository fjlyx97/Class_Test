/*
删除对象后无法保存
书本总数有误
删除书目并添加新书后登录号有误

查找还未调试
排序需要写
*/


#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#define I 2

FILE *fp;

/****************************函数清单*****************************/

void HideCursor();//---隐藏光标---

void goto_xy(int x, int y);//---定位光标位置到指定坐标---

/*--------------------------------------------------------------*/

void homepage();//---主页---

void setin();//---录入---

void list(struct book *p);//---输出---

void show(struct book *p);//---打印---

void serch();//---查找---

void serch_num();//登录号查找

void serch_name();//书名查找

void serch_author();//作者查找

void serch_dirive();//分类号查找

void serch_publish();//出版社查找

void serch_date();//出版日期查找

void serch_price();//价格查找

void serch_indistinct();//模糊查找

void serch_fail();//查找失败
/*
void sort(struct book b[],int n);//---排序---

void sort_n_down(struct book b[],int n);//登录号高-低排序

void sort_name_up(struct book b[],int n);//书名低-高排序

void sort_a_up(struct book b[],int n);//作者低-高排序

void sort_dirive_up(struct book b[],int n);//分类号低-高排序

void sort_publish_house(struct book b[],int n);//出版单位低-高排序

void sort_date_late(struct book b[],int n);//出版时间晚-早排序

void sort_date_early(struct book b[],int n);//出版时间早-晚排序
*/
void delet();//---删除---

void change();//---修改---

void save(struct book *p);//---数据保存---

void read();//---文件打开---

void establish();//新建链表

void ending();//---退出---

/*************************窗口操作函数***************************************/

void HideCursor()     //隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void toxy(int x, int y)      //将光标移动到X,Y坐标处
{
	COORD pos = { x , y };
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos); 
}

/***************************结构体******************************************/

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
/****************************功能函数*****************************************/

void homepage()//主页
{
	char t;
	HideCursor();
	while(1)
	{
		system("cls");
		printf(" ========================== \n");
		printf("| 厦门理工学院图书管理系统 |\n");
		printf("|==========================|\n");
		printf("|       1、新书录入        |\n");
		printf("|       2、浏览书目        |\n");
		printf("|       3、书目查询        |\n");
		printf("|       4、书目排序        |\n");
		printf("|       5、删除书目        |\n");
		printf("|       6、数据修改        |\n");
		printf("|==========================|\n");
		printf("| 输入数字1-6选择，按0退出 |\n");
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
						printf("书库暂时没有书哦~赶快去添加几本吧^_^(按任意键返回)");
						getch();
						homepage();
					}
					else
					{
						list(head);
						printf("   ==========================\n");
						printf("     按0退出,按1返回目录 \n");
						printf("   ==========================\n");
						while(1)
							{
								t=getch();
								switch (t)
								{
								case '1':homepage();break;
								case '0':ending();break;
								default:system("cls");printf("\n       系统出错！");Sleep(1000);homepage();break;
								}
							}
						break;
					}
				}
			case '3':serch();break;
			case '4':printf("查找");break;//sort();break;
			case '5':delet();break;
			case '6':change();break;
			case '0':ending();break;
			default:system("cls");printf("\n       系统出错！");Sleep(1000);break;
			}
		}
	}
}

//录入
void setin()
{
	struct book *p;
	while(1)
	{
		p=(struct book *)malloc(LEN);
		n++;
		system("cls");
		printf("请输入图书登录号(小于10位数)：");    
		scanf("%s",p->num);getchar();
		printf("请输入书名(小于10位数)：");
		scanf("%s",p->name);getchar();
		printf("请输入作者名(小于5个汉字)：");
		scanf("%s",p->author);getchar();
		printf("请输入分类号(小于10位数)：");
		scanf("%s",p->dirive);getchar();
		printf("请输入图书出版单位(小于20个汉字)：");
		scanf("%s",p->publish_house);getchar();
		printf("请输入图书出版时间(年.月.日)：");
		scanf("%d.%d.%d",&(p->printdate.year),&(p->printdate.month),&(p->printdate.day));getchar();
		printf("请输入图书价格：");
		scanf("%f",&p->ptice);getchar();
		save(p);
	}
}
//输出
void list(struct book *p)
{
	struct book *p1;
	system("cls");
	printf("   ------------------------------------------------------------------------------------------------------\n");
	printf("\t登录号\t书名\t作者名\t分类号\t出版单位\t出版时间\t价格（元）\n");
	printf("   ------------------------------------------------------------------------------------------------------\n");
	for(p1=p;p1!=NULL;p1=p1->next)
		show(p1);
}
//打印
void show(struct book *p)
{
	printf("\t%s\t%s\t%s\t%s\t%s\t\t%d.%d.%d\t%.2f\n",p->num,p->name,p->author,p->dirive,p->publish_house,p->printdate.year,p->printdate.month,p->printdate.day,p->ptice);
}
//查找
void serch()
{
	char t;
	system("cls");
	HideCursor();
	printf(" ============================ \n");
	printf("|      请选择查找方式:       |\n");
	printf("|============================|\n");
	printf("|     1、按登 录 号查找      |\n");
	printf("|     2、按书    名查找      |\n");
	printf("|     3、按作    者查找      |\n");
	printf("|     4、按分 类 号查找      |\n");
	printf("|     5、按出 版 社查找      |\n");
	printf("|     6、按出版日期查找      |\n");
	printf("|     7、按价    格查找      |\n");
	printf("|     8、  模  糊  查找      |\n");
	printf("|============================|\n");
	printf("|  输入数字1-8选择，按0返回  |\n");
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
		default:printf("系统出错！");Sleep(1000);break;
		}
	}
}
void serch_fail()//查找失败
{
	char t;
	system("cls");
	printf(" ================================ \n");
	printf("| 未找到数据，是否继续进行操作？ |\n");
	printf("|      1、是       2、否         |\n");
	printf(" ================================ \n");
	while(1)
	{
		t=getch();
		switch (t)
		{
		case '1':serch();break;
		case '2':homepage(); break;
		default:printf("\n        系统出错！");Sleep(1000);break;
		}
	}
}
void serch_num()  //登录号查找
{
	struct book *p;
	char dlh[10];
	int flag=0;
	system("cls");
	printf("========================================\n");
	printf("      请输入要查找的登录号：\n");
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
void serch_name()  //书名查找
{
	struct book *p;
	int flag=0;
	char sm[100];
	system("cls");
	printf("========================================\n");
	printf("      请输入要查找的书名：\n");
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
void serch_author()  //作者查找
{
	struct book *p;
	char s[20];
	int flag=0;
	system("cls");
	printf("========================================\n");
	printf("      请输入要查找的作者：\n");
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
void serch_dirive()  //分类号查找
{
	struct book *p;
	char s[10];
	int flag=0;
	system("cls");
	printf("========================================\n");
	printf("      请输入要查找的分类号：\n");
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
void serch_publish()  //出版社查找
{
	struct book *p;
	char s[50];
	int flag=0;
	system("cls");
	printf("========================================\n");
	printf("      请输入要查找的出版社：\n");
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
void serch_date()  //出版日期查找
{
	struct book *p;
	int y,m,d;
	int flag=0;
	system("cls");
	printf("========================================\n");
	printf("      请输入要查找的日期：\n");
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
void serch_price()  //价格查找
{
	struct book *p;
	int pri;
	int flag=0;
	system("cls");
	printf("========================================\n");
	printf("      请输入要查找的价格：\n");
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
void serch_indistinct()//模糊查询
{
	struct book *p;
	char information[100];
	int flag=0;
	
	system("cls");
	printf("========================================\n");
	printf("      请输入要查找的信息：\n");
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
void sort()  //排序
{
	char t;
	system("cls");
	HideCursor();
	printf(" =================================\n");
	printf("|         请选择排序方式:         |\n");
	printf("|=================================|\n");
	printf("|     1、按登 录 号高-低排序      |\n");
	printf("|     2、按出版时间晚-早排序      |\n");
	printf("|     3、按出版时间早-晚排序      |\n");
	printf("|     4、按价    格高-低排序      |\n");
	printf("|     5、按价    格低-高排序      |\n");
	printf("|=================================|\n");
	printf("|  输入数字1-5选择，按0返回主页面 |\n");
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
		default:printf("系统出错！");Sleep(1000);break;
	}
}
//登录号高-低排序
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
//出版时间晚-早排序
struct book *sort_date_late()
{
	struct book *pfirst;      //排列后有序链的表头指针  
    struct book *ptail;       //排列后有序链的表尾指针 
    struct book *pminBefore;  //保留键值更小的节点的前驱节点的指针 
    struct book *pmin;        // 存储最小节点   
    struct book *p;           // 当前比较的节点 
   
    pfirst = NULL;  
    while (head != NULL)
    {  
        for (p=head->next,pmin=head;p->next!=NULL;p=p->next) 
        {  
            if (p->printdate.year<pmin->printdate.year||p->printdate.year==pmin->printdate.year&&p->printdate.month<pmin->printdate.month||p->printdate.year==pmin->printdate.year&&p->printdate.month==pmin->printdate.month&&p->printdate.day<pmin->printdate.day) //找到一个比当前min小的节点。
            {  
                pminBefore=p;           //保存找到节点的前驱节点：显然p->next的前驱节点是p  
                pmin=p->next;     //保存键值更小的节点。*******************************************************
            }  
        }  
    
    //上面for语句结束后，就要做两件事；一是把它放入有序链表中；二是根据相应的条件判断，安排它离开原来的链表。 
      
        //第一件事
        if (pfirst == NULL)
        {  
            pfirst = pmin;      // 第一次找到键值最小的节点。 
            ptail  = pmin;      //注意：尾指针让它指向最后的一个节点。   
        }  
        else                   //有序链表中已经有节点                       
        {  
            ptail->next = pmin; //把刚找到的最小节点放到最后，即让尾指针的next指向它。 
            ptail = pmin;       //尾指针也要指向它。                               
        }  
  
        //第二件事
        if (pmin == head)        // 如果找到的最小节点就是第一个节点                 
        {  
            head = head->next;   // 显然让head指向原head->next,即第二个节点，就OK  
        }  
        else //如果不是第一个节点
        {  
            pminBefore->next = pmin->next; //前次最小节点的next指向当前pmin的next,这样就让pmin离开了原链表。 
        }  
    }  
  
    if (pfirst != NULL)     //循环结束得到有序链表first       
    {  
        ptail->next = NULL; //单向链表的最后一个节点的next应该指向NULL 
    }  
    head = pfirst;  
return pfirst;
}
//出版时间早-晚排序
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
//价格高-低排序
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
//价格低-高排序
void sort_p_up(struct book b[],int n)
{
	
}
*/
//删除
void delet()
{
	char x[10];
	struct book *p1,*p2;
	char t;
	int flag=0;
	system("cls");
	list(head);
	printf("======================================================\n");
	printf("  请输入要删除的书本的登录号：\n");
	printf("======================================================\n");
	toxy(30,4);
	scanf("%s",x);
	for(p1=head;p1->num>0&&p1!=NULL;p1=p1->next)//按顺序查找
	{
		p2=p1;
		if(strcmp(p1->num,x)==0)//找到对应数据
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
			printf("|  删除成功，是否继续进行操作？  |\n");
			printf("|      1、是       2、否         |\n");
			printf(" ================================ \n");
			while(1)
			{
				t=getch();
				switch (t)
				{
				case '1':delet();break;
				case '2':homepage(); break;
				default:printf("\n        系统出错！");Sleep(1000);break;
				}
			}
		}
	}
	if(flag==0)
	{
		system("cls");
		printf(" ================================ \n");
		printf("| 未找到数据，是否继续进行操作？ |\n");
		printf("|      1、是       2、否         |\n");
		printf(" ================================ \n");
		while(1)
		{
			t=getch();
			switch (t)
			{
			case '1':delet();break;
			case '2':homepage(); break;
			default:printf("\n        系统出错！");Sleep(1000);break;
			}
		}
	}
	
}
//修改
void change()
{
	char t;
	struct book *p1,*p2; 
	char dlh[10];
	int flag=0;
	system("cls");
	printf("========================================\n");
	printf("  请输入要修改的书本的登录号：");
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
	printf("      按s开始输入，按b返回，按e结束输入\n");
	printf("====================================================\n");
	printf("请输入修改后的数据：");	
	printf("------------------------------------------------------------------------------------------------------\n");
	printf("   登录号        书名        作者名     分类号        出版单位        出版时间：年.月.日    价格（元）\n");
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
//数据保存
void save(struct book *p)
{
	char t;
	system("cls");
	printf(" ================================ \n");
	printf("|         是否保存数据？         |\n");
	printf("|      1、是       2、否         |\n");
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
				printf("\n            正在保存……\n");
				Sleep(1000);
				if(fp==NULL)
				{
	  				system("cls");
					printf(" ================================\n");
					printf("|文件打开失败，是否继续进行操作？|\n");
					printf("|      1、是       2、否         |\n");
					printf(" ================================ \n");
					while(1)
					{
						t=getch();
						switch (t)
						{
						case '1':save(p);break;
						case '2':homepage();break;
						default:system("cls");printf("\n        系统出错！");Sleep(1000);homepage();break;
						}
					}
				}
				if(fwrite(p,LEN,1,fp)!=1)
				{
					system("cls");
					printf(" ================================\n");
					printf("|文件写入失败，是否继续进行操作？|\n");
					printf("|      1、是       2、否         |\n");
					printf(" ================================ \n");
					while(1)
					{
						t=getch();
						switch (t)
						{
						case '1':save(p);break;
						case '2':homepage(); break;
						default:system("cls");printf("\n        系统出错！");Sleep(1000);save(p);break;
						}
					}
				}
				system("cls");
				printf("\n   ================================\n");
				printf("  |            保存成功            |\n");
				printf("   ================================ \n");
				fclose(fp);
				Sleep(1000);
				homepage();
				break;
			}
		case '2':homepage();break;
		default:printf("\n        系统出错！");Sleep(1000);homepage();break;
		}
	}

}
void read()//文件信息读取
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
		printf("|文件打开失败，是否继续进行操作？|\n");
		printf("|      1、是       2、否         |\n");
		printf(" ================================ \n");
		while(1)
		{
			t=getch();
			switch (t)
			{
			case '1':read();break;
			case '2':ending();break;
			default:system("cls");printf("\n        系统出错！");Sleep(1000);homepage();break;
			}
		}
	}
	fseek(fp,0,0);
	while(!feof(fp))        //判断文件位置标志是否移动到文件末尾 
	{
		n++;
		p=(struct book *)malloc(LEN); //向内存申请一段空间 
		fread(p,LEN,1,fp);     //将fp所指向的文件中的内容赋给p 
		if(n==1)
		{
			head=p;
			p2=p;
		}
		else             //创建链表 
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
	fclose(fp);    //关闭文件 
}
//退出
void ending()
{
	char t;
	system("cls");
	printf(" ==============================\n");
	printf("|        是否确定退出？        |\n");
	printf("|        1、是   2、否         |\n");
	printf(" ==============================\n");
	while(1)
	{
		t=getch();
		switch (t)
		{
		case '1':
			system("cls");
			printf("\n       正在退出中，请稍后....\n\n");
			Sleep(1000);
			exit(0);
			break;
		case '2':homepage();break;
		default:printf("\n        系统出错！");Sleep(1000);homepage();break;
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









