#include <iostream>
using namespace std;
struct stu
{
    int id;
    bool isleft;
    stu* next;
    stu* back;
}student[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N , M;
    int k , p;
    cin >> N;
    student[1].id = 1;
    student[1].next = NULL;
    student[1].back = NULL;
    student[1].isleft = false;
    for (int i = 2 ; i <= N ; i++)
    {
        cin >> k >> p;
        student[i].id = i;
        student[i].next = NULL;
        student[i].back = NULL;
        student[i].isleft = false;
        if (p == 0)
        {
            student[i].next = &student[k];
            student[i].back = student[k].back;
            if (student[k].back != NULL)
            {
                student[k].back->next = &student[i];
            }
            student[k].back = &student[i];
        }
        else
        {
            student[i].back = &student[k];
            student[i].next = student[k].next;
            if (student[k].next != NULL)
            {
                student[k].next->back = &student[i];
            }
            student[k].next = &student[i];
        }
    }
    int num;
    cin >> M;
    for (int i = 1 ; i <= M ; i++)
    {
        cin >> num;
        if (student[num].isleft == false)
        {
            student[num].back = student[num].next;
            student[num].next = student[num].back;
            student[num].isleft = true;
        }
    }
    stu* pHead;
    for (int i = 1 ; i <= N ; i++)
    {
        if (student[i].back == NULL && student[i].isleft == false)
        {
            pHead = &student[i];
        }
    }
    
    while (pHead)
    {
        if (pHead->isleft == false)
            cout << pHead->id << " ";
        pHead = pHead->next;
    }
    cout << endl;
    system("pause");
    return 0;
}