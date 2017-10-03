#include <iostream>
#include <string.h>
#include "Student.h"
using namespace std;
//开始界面
void Hello();
//添加学生信息
void addStudent(int,char[],char[]);
//清理链表
void freeStudent();
//显示链表
void printStudent();
//根据学号查找学生信息
void searchStudent(int);
//声明链表头和尾
STU* pHead = NULL;
STU* pEnd = NULL;
int main()
{
    //声明变量
    int iChoose = -1;
    int Id = -1;
    char arrName[10];
    char arrBornDay[10]; 
    bool is_begin = true;
    //声明变量
    while(is_begin)
    {
        Hello();
        cin >> iChoose;
        switch (iChoose)
        {
            //添加学生信息
            case 1:
                cout << "请输入学生学号:";
                cin >> Id;
                cout << "请输入学生姓名:";
                cin >> arrName;
                cout << "请输入学生出生年月:";
                cin >> arrBornDay;
                addStudent(Id,arrName,arrBornDay);
                cout << "添加完成。" << endl;
                break;
            case 2:
                cout << "请输入要查找的学生学号:" ;
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
                cout << "你的输入有错，请重新输入。" << endl;
        }
    }
    freeStudent();
    system("pause");
    return 0;
}
void Hello()
{
    cout << "*************************学生信息管理系统*************************" << endl;
    cout << "***                     输入1添加学生信息                      ***" << endl;
    cout << "***                     输入2查找学生信息                      ***" << endl;
    cout << "***                     输入3修改学生信息                      ***" << endl;
    cout << "***                     输入4保存学生信息                      ***" << endl;
    cout << "***                     输入5读取学生信息                      ***" << endl;
    cout << "***                     输入6删除学生信息                      ***" << endl;
    cout << "***                     输入7恢复学生信息                      ***" << endl;
    cout << "***                     输入8显示学生信息                      ***" << endl;
    cout << "***                     输入9添加学生信息                      ***" << endl;
    cout << "***                     输入0退出信息系统                      ***" << endl;
    cout << "******************************************************************" << endl;
    cout << "请输入数字:" ;
}
void addStudent(int id,char arrName[10],char arrBornDay[10])
{
    if ( 0 == id || NULL == arrName || NULL == arrBornDay)
    {
        cout << "输入有误，请重新输入。";
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
        cout << "学生的座号是：" << pTemp->Id << '\t';
        cout << "学生的姓名是：" << pTemp->arrName << '\t';
        cout << "学生的出生日期是：" << pTemp->arrBornDay << endl;
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
            cout << "无法查找到此人" << endl;
            break;
        }
        if (id == pTemp->Id)
        {
            cout << "查找成功" << endl;
            cout << "学生的座号是：" << pTemp->Id << '\t';
            cout << "学生的姓名是：" << pTemp->arrName << '\t';
            cout << "学生的出生日期是：" << pTemp->arrBornDay << endl;
            break;
        }
        if (NULL == pTemp->pNext)
        {
            cout << "无法查找到此人" << endl;
            break;
        }
        pTemp = pTemp->pNext;
    }
}