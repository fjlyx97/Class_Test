#include <iostream>
#include <string.h>
#include "Student.h"
using namespace std;
//��ʼ����
void Hello();
//���ѧ����Ϣ
void addStudent(int,char[],char[]);
//��������
void freeStudent();
//��ʾ����
void printStudent();
//����ѧ�Ų���ѧ����Ϣ
void searchStudent(int);
//��������ͷ��β
STU* pHead = NULL;
STU* pEnd = NULL;
int main()
{
    //��������
    int iChoose = -1;
    int Id = -1;
    char arrName[10];
    char arrBornDay[10]; 
    bool is_begin = true;
    //��������
    while(is_begin)
    {
        Hello();
        cin >> iChoose;
        switch (iChoose)
        {
            //���ѧ����Ϣ
            case 1:
                cout << "������ѧ��ѧ��:";
                cin >> Id;
                cout << "������ѧ������:";
                cin >> arrName;
                cout << "������ѧ����������:";
                cin >> arrBornDay;
                addStudent(Id,arrName,arrBornDay);
                cout << "�����ɡ�" << endl;
                break;
            case 2:
                cout << "������Ҫ���ҵ�ѧ��ѧ��:" ;
                cin >> Id;
                searchStudent(Id);
                break;
            case 3:
                break;
            case 8:
                printStudent();
                break;
            case 0:
                is_begin = false;
                break;
            default:
                cout << "��������д����������롣" << endl;
        }
    }
    freeStudent();
    system("pause");
    return 0;
}
void Hello()
{
    cout << "*************************ѧ����Ϣ����ϵͳ*************************" << endl;
    cout << "***                     ����1���ѧ����Ϣ                      ***" << endl;
    cout << "***                     ����2����ѧ����Ϣ                      ***" << endl;
    cout << "***                     ����3�޸�ѧ����Ϣ                      ***" << endl;
    cout << "***                     ����4����ѧ����Ϣ                      ***" << endl;
    cout << "***                     ����5��ȡѧ����Ϣ                      ***" << endl;
    cout << "***                     ����6ɾ��ѧ����Ϣ                      ***" << endl;
    cout << "***                     ����7�ָ�ѧ����Ϣ                      ***" << endl;
    cout << "***                     ����8��ʾѧ����Ϣ                      ***" << endl;
    cout << "***                     ����9���ѧ����Ϣ                      ***" << endl;
    cout << "***                     ����0�˳���Ϣϵͳ                      ***" << endl;
    cout << "******************************************************************" << endl;
    cout << "����������:" ;
}
void addStudent(int id,char arrName[10],char arrBornDay[10])
{
    if ( 0 == id || NULL == arrName || NULL == arrBornDay)
    {
        cout << "�����������������롣";
        return;
    }
    STU* pTemp = new STU;
    pTemp->Id = id;
    strcpy(pTemp->arrName,arrName);
    strcpy(pTemp->arrBornDay,arrBornDay);
    pTemp->pNext = NULL;
    if ( NULL == pHead)
    {
        pHead = pTemp;
    }
    else
    {
        pEnd->pNext = pTemp;
    }
    pEnd = pTemp;
}
void freeStudent()
{
    while (NULL != pHead)
    {
        STU* pTemp = pHead;
        pHead = pHead->pNext;
        delete pTemp;
    }
}
void printStudent()
{
    STU* pTemp = pHead;
    while (pTemp != NULL)
    {
        cout << "ѧ���������ǣ�" << pTemp->Id << '\t';
        cout << "ѧ���������ǣ�" << pTemp->arrName << '\t';
        cout << "ѧ���ĳ��������ǣ�" << pTemp->arrBornDay << endl;
        pTemp = pTemp->pNext;
    }
}
void searchStudent(int id)
{ 
    STU* pTemp = pHead;
    while (true)
    {
        if (NULL == pHead)
        {
            cout << "�޷����ҵ�����" << endl;
            break;
        }
        if (id == pTemp->Id)
        {
            cout << "���ҳɹ�" << endl;
            cout << "ѧ���������ǣ�" << pTemp->Id << '\t';
            cout << "ѧ���������ǣ�" << pTemp->arrName << '\t';
            cout << "ѧ���ĳ��������ǣ�" << pTemp->arrBornDay << endl;
            break;
        }
        if (NULL == pTemp->pNext)
        {
            cout << "�޷����ҵ�����" << endl;
            break;
        }
        pTemp = pTemp->pNext;
    }
}