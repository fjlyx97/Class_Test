#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

#define ATTRIBUTES 4
//学生信息节点
struct Student
{
    char name[20];
    char sex;   // M F
    int age;
    char id[101];
    struct Student* next;
};

// 学生链表
struct StudentList
{
    struct Student* head;
    struct Student* next;
};

// 欢迎界面
void printHello();

// 初始化程序
struct StudentList* initStudentManagement();

// 读取文件
void readData(struct StudentList* stuHead);

// 写入文件
void writeData();

// 查询所有学生的数据
void showStudentData(struct StudentList* stuHead);

// 清屏函数
void clsScreen();


int main()
{
    //输出欢迎界面
    printHello();
    //初始化程序
    struct StudentList* stuHead = initStudentManagement();
    int choice;

    while (true)
    {
        printf("请输入操作序号：");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5: 
                showStudentData(stuHead);
                break;
            case 6:
                exit(0);
                break;
            default:
                clsScreen();
                printHello();
                printf("输入错误，请重新输入序号.\n");
                break;
        }
    }
    return 0;
}

void printHello()
{

    printf("                         *************************************\n");
    printf("                         *          学生信息管理系统         *\n");
    printf("                         *                                   *\n");
    printf("                         *          1:输入学生数据           *\n");
    printf("                         *          2:修改学生数据           *\n");
    printf("                         *          3:删除学生数据           *\n");
    printf("                         *          4:查询学生数据           *\n");
    printf("                         *          5:输出所有学生数据       *\n");
    printf("                         *          6:退出系统               *\n");
    printf("                         *                                   *\n");
    printf("                         *                                   *\n");
    printf("                         *************************************\n");
}

struct StudentList* initStudentManagement()
{
    struct StudentList* stuHead = (struct StudentList*)malloc(sizeof(struct StudentList));
    stuHead->head = NULL;
    stuHead->next = NULL;
    //读取文件
    readData(stuHead);

    return stuHead;
}

void readData(struct StudentList* stuHead)
{
    FILE* fb;
    char lineContent[1024];
    char tempContent[1024];
    char readContentData[ATTRIBUTES][1024];
    struct Student* pstu = stuHead->next;
    int i , j , index;

    printf("读取数据中.....\n");
    if ((fb = fopen("stu.dat","r")) != NULL)
    {
        printf("数据读取成功....\n");
        while (!feof(fb))
        {
            fgets(lineContent,1024,fb);
            index = 0;
            j = 0;
            for (i = 0 ; i <= strlen(lineContent) ; i++)
            {
                if (lineContent[i] != ' ' && lineContent[i] != '\0')
                {
                    tempContent[j++] = lineContent[i];
                }
                else
                {
                    tempContent[j] = '\0';
                    strcpy(readContentData[index++],tempContent);
                    j = 0;
                }
            }
            struct Student* newStu = (struct Student*)malloc(sizeof(struct Student));
            strcpy(newStu->name,readContentData[0]);
            newStu->sex = readContentData[1][0];
            newStu->age = atoi(readContentData[2]);
            strcpy(newStu->id,readContentData[3]);
            newStu->next = NULL;

            if (stuHead->head == NULL)
            {
                stuHead->head = newStu;
                stuHead->next = newStu;
                pstu = stuHead->next;
            }
            else
            {
                pstu->next = newStu;
                pstu = pstu->next;
            }
            //printf("%s\n",lineContent);
            /*
            for (i = 0 ; i < ATTRIBUTES ; i++)
            {
                printf("%s\n",readContentData[i]);
            }
            */
        }
    }
    else
    {
        printf("数据未找到....\n");
        fb = fopen("stu.dat","w");
    }
}

void showStudentData(struct StudentList* stuHead)
{
    struct Student* pstu = stuHead->next;
    while(pstu != NULL)
    {
        printf("%s %c %d %s\n",pstu->name,pstu->sex,pstu->age,pstu->id);
        pstu = pstu->next;
    }
}

void clsScreen()
{
    #ifdef WIN32
        system("cls");
    #else
        system("clear");
    #endif
}