#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct stu
{
    string name;
    int ave_score;
    int class_score;
    char isOfficer;
    char isWest;
    int essay;
    int id;
    int money;
}student[101];
bool cmp(stu s1 , stu s2)
{
    return s1.money < s2.money;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    int total_money = 0;
    int id = 1;
    cin >> N;
    for (int i = 1 ; i <= N ; i++)
    {
        cin >> student[i].name;
        cin >> student[i].ave_score;
        cin >> student[i].class_score;
        cin >> student[i].isOfficer;
        cin >> student[i].isWest;
        cin >> student[i].essay;
        student[i].id = i;
        student[i].money = 0;
        if (student[i].ave_score > 80 && student[i].essay >= 1)
        {
            student[i].money += 8000;
        }
        if (student[i].ave_score > 85 && student[i].class_score > 80)
        {
            student[i].money += 4000;
        }
        if (student[i].ave_score > 90)
        {
            student[i].money += 2000;
        }
        if (student[i].ave_score > 85 && student[i].isWest == 'Y')
        {
            student[i].money += 1000;
        }
        if (student[i].class_score > 80 && student[i].isOfficer == 'Y')
        {
            student[i].money += 850;
        }
        total_money += student[i].money;
        if (student[i].money > student[id].money)
        {
            id = i;
        }
    }
    //sort(student,student+N+1,cmp);
    cout << student[id].name << endl;
    cout << student[id].money << endl;
    cout << total_money << endl;

    system("pause");
    return 0;
}