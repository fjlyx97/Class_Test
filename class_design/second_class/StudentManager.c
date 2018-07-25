#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//vscodeͨ�ö���
#define WIN32 1

#ifdef WIN32
	//vs2010�رվ���
	#pragma warning(disable:4996)
	//windows����conio.hͷ�ļ�
	#include <conio.h>
#endif

#define true 1
#define false 0
#define ATTRIBUTES 4

//ѧ����Ϣ�ڵ�
struct Student
{
    char name[20];
    char sex;   // M F
    int age;
    char id[101];
    struct Student* next;
};

// ѧ������
struct StudentList
{
    struct Student* head;
    struct Student* next;
};

// ��ӭ����
void printHello();

// ��ʼ������
struct StudentList* initStudentManagement();

// ��ȡ�ļ�
void readData(struct StudentList* stuHead);

// д���ļ�
void writeData(struct StudentList* stuHead);

// ��ѯ����ѧ��������
void showStudentData(struct StudentList* stuHead);

// ����ѧ���ڵ�
void addStudent(struct StudentList* stuHead);

// �޸�ѧ����Ϣ
void changeStudent(struct StudentList* stuHead);

// ɾ��ѧ����Ϣ
void delStudent(struct StudentList* stuHead);

// ��ѯ����ѧ����Ϣ
void searchStudent(struct StudentList* stuHead);

// ��������
void clsScreen();


int main()
{
    //��ʼ������
    struct StudentList* stuHead = initStudentManagement();
    int choice;

    while (true)
    {
        //�����ӭ����
        printHello();
        printf("�����������ţ�");
        scanf("%d",&choice);
        getchar();
        clsScreen();

        switch(choice)
        {
            case 1:
                addStudent(stuHead);
                break;
            case 2:
                changeStudent(stuHead);
                break;
            case 3:
                delStudent(stuHead);
                break;
            case 4:
				searchStudent(stuHead);
                break;
            case 5:
                showStudentData(stuHead);
                break;
            case 6:
                exit(0);
                break;
            default:
                printHello();
                printf("��������������������.\n");
                break;
        }
        writeData(stuHead);
        clsScreen();
    }
    return 0;
}

void printHello()
{

    printf("                         *************************************\n");
    printf("                         *          ѧ����Ϣ����ϵͳ         *\n");
    printf("                         *                                   *\n");
    printf("                         *          1:����ѧ������           *\n");
    printf("                         *          2:�޸�ѧ������           *\n");
    printf("                         *          3:ɾ��ѧ������           *\n");
    printf("                         *          4:��ѯѧ������           *\n");
    printf("                         *          5:�������ѧ������       *\n");
    printf("                         *          6:�˳�ϵͳ               *\n");
    printf("                         *                                   *\n");
    printf("                         *                                   *\n");
    printf("                         *************************************\n");
}

struct StudentList* initStudentManagement()
{
    struct StudentList* stuHead = (struct StudentList*)malloc(sizeof(struct StudentList));
    stuHead->head = NULL;
    stuHead->next = NULL;
    //��ȡ�ļ�
    readData(stuHead);

    return stuHead;
}

void readData(struct StudentList* stuHead)
{
    FILE* fb;
	char lineContent[1024] = {0};
    char tempContent[1024];
    char readContentData[ATTRIBUTES][1024];
    struct Student* pstu = stuHead->next;
    int i , j , index;

    //printf("��ȡ������.....\n");
    if ((fb = fopen("stu.dat","r")) != NULL)
    {
        //printf("���ݶ�ȡ�ɹ�....\n");
        while (!feof(fb))
        {
			memset(lineContent,0,sizeof(lineContent));
            fgets(lineContent,1024,fb);

			//��ֹ���ļ�����޷���ȡ
			if (lineContent[0] == '\0') return;

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
            for (i = 0 ; i < strlen(newStu->id) ; i++)
            {
                if (newStu->id[i] == '\n')
                {
                    newStu->id[i] = '\0';
                    break;
                }
            }
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
        //printf("����δ�ҵ�....\n");
        fb = fopen("stu.dat","w");
    }
    fclose(fb);
}

void showStudentData(struct StudentList* stuHead)
{
    struct Student* pstu = stuHead->next;
    printf("����˳��Ϊ�������Ա����䣬ѧ��\n");
    while(pstu != NULL)
    {
        printf("%s %c %d %s\n",pstu->name,pstu->sex,pstu->age,pstu->id);
        pstu = pstu->next;
    }
    printf("��ȡ��ϣ��밴�س�����....\n");
	#ifdef WIN32
		getche();
	#else
		getchar();
	#endif
}

void clsScreen()
{
    #ifdef WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void addStudent(struct StudentList* stuHead)
{
    struct Student* pstu = stuHead->next;
    struct Student* newStu = (struct Student*)malloc(sizeof(struct Student));
    char name[1024];
    char sex[2];
    char age[10];
    char id[1024];
    char choice;
    while (pstu != NULL && pstu->next != NULL)
    {
        pstu = pstu->next;
    }
    printf("������ѧ��������");
    gets(name);
    printf("������ѧ���Ա�M/F����");
    gets(sex);
    printf("������ѧ��ѧ�����䣺");
    gets(age);
    printf("������ѧ��ѧ�ţ�");
    gets(id);

    printf("\n������������ǣ�%s\n�Ա��ǣ�%s\n�����ǣ�%s\nѧ���ǣ�%s\nȷ�ϻ���ȡ����y/n����",name,sex,age,id);
    while(true)
    {
        scanf("%c",&choice);
        getchar();
        if (choice == 'y')
        {
            strcpy(newStu->name,name);
            newStu->sex = sex[0];
            newStu->age = atoi(age);
            strcpy(newStu->id,id);
            newStu->next = NULL;
			if (pstu == NULL)
			{
				pstu = newStu;
				stuHead->next = pstu;
				return;
			}
			else
			{
				pstu->next = newStu;
			}
            break;
        }
        else if (choice == 'n')
        {
            break;
        }
        else
        {
            printf("����������������룺");
        }
    }
}
void changeStudent(struct StudentList* stuHead)
{
    char changeId[1024];
    struct Student* pstu = stuHead->next;
    char tempId[1024];
	int flag = 0;
    printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
    gets(changeId);
    int i;
    while(pstu != NULL)
    {
        strcpy(tempId,pstu->id);
        for (i = 0 ; i < strlen(tempId) ; i++)
        {
            if (tempId[i] == '\n')
            {
                tempId[i] = '\0';
            }
        }
        if (strcmp(tempId,changeId) == 0)
        {
            printf("���ҵ���ѧ��....\n");
            char name[1024];
            char sex[2];
            char age[10];
            char id[1024];
            printf("���޸�ѧ��������");
            gets(name);
            printf("���޸�ѧ���Ա�M/F����");
            gets(sex);
            printf("���޸�ѧ�����䣺");
            gets(age);
            printf("���޸�ѧ��ѧ�ţ�");
            gets(id);
            strcpy(pstu->name,name);
            pstu->sex = sex[0];
            pstu->age = atoi(age);
            strcpy(pstu->id,id);
			flag = 1;
            printf("�޸ĳɹ����밴�س�����...\n");
			break;
        }
        pstu = pstu->next;
    }
	if (!flag)
		printf("�Ҳ�����ѧ�����밴�س�����...\n");

	#ifdef WIN32
		getche();
	#else
		getchar();
	#endif
}

void delStudent(struct StudentList* stuHead)
{
    struct Student* pstu = stuHead->next;
    struct Student* prestu = NULL;
    char delId[1024];
    printf("������Ҫɾ��ѧ����ѧ�ţ�");
    gets(delId);
    while (pstu != NULL)
    {
        if (strcmp(pstu->id,delId) == 0)
        {
            if (prestu == NULL)
            {
                stuHead->next = pstu->next;
            }
            else
            {
                prestu->next = pstu->next;
            }
            free(pstu);
            printf("��ɾ����ѧ��...\n");
            getchar();
            return;
        }
        prestu = pstu;
        pstu = pstu->next;
    }
    printf("�޷��ҵ�����ѧ��...\n");

	#ifdef WIN32
		getche();
	#else
		getchar();
	#endif

    return;
}

void writeData(struct StudentList* stuHead)
{
    FILE* fp;
    fp = fopen("stu.dat","w");
    char saveData[1024];
    struct Student* pstu = stuHead->next;
    while(pstu != NULL)
    {
        // Ԥ��������
        memset(saveData,0,sizeof(saveData));
        char tempAge[101];
        char tempSex[2];
        int tempNum = pstu->age;
        int index = 0;
        tempSex[0] = pstu->sex;
        tempSex[1] = '\0';
        while(tempNum)
        {
            tempAge[index++] = tempNum % 10 +'0';
            tempNum /= 10;
        }
		tempAge[index] = '\0';

        strcat(saveData,pstu->name);
        strcat(saveData," ");
        strcat(saveData,tempSex);
        strcat(saveData," ");
        strcat(saveData,tempAge);
        strcat(saveData," ");
        strcat(saveData,pstu->id);
        strcat(saveData,"\n");
        fputs(saveData,fp);
        pstu = pstu->next;
    }
    fclose(fp);
}

void searchStudent(struct StudentList* stuHead)
{
	struct Student* pstu = stuHead->next;
	char stuId[1024];
	printf("������Ҫ��ѯ��ѧ��ѧ�ţ�");
	gets(stuId);
	int flag = 0;

	while(pstu != NULL)
	{
		if (strcmp(pstu->id,stuId) == 0)
		{
			printf("������%s\n�Ա�%c\n���䣺%d\nѧ�ţ�%s\n",pstu->name,pstu->sex,pstu->age,pstu->id);
			flag = 1;
			break;
		}
		pstu = pstu->next;
	}
	if (!flag)
	{
		printf("δ���ҵ���ѧ��....\n");
	}
	printf("�밴�س�������.....\n");
	#ifdef WIN32
		getche();
	#else
		getchar();
	#endif
	return;
}
