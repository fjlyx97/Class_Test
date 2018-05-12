#include <iostream>
#include <algorithm>
using namespace std;
struct student
{
    int chinese_score;
    int math_score;
    int english_score;
    int total_score;
    int id;
}stu[301];
bool cmp(student s1 , student s2)
{
    if (s1.total_score > s2.total_score)
    {
        return true;
    }
    else if (s1.total_score == s2.total_score)
    {
        if (s1.chinese_score > s2.chinese_score)
        {
            return true;
        }
        else if (s1.chinese_score == s2.chinese_score)
        {
            if (s1.id < s2.id)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        stu[i].id = i;
        cin >> stu[i].chinese_score >> stu[i].math_score >> stu[i].english_score;
        stu[i].total_score = stu[i].chinese_score + stu[i].english_score + stu[i].math_score;
    }
    sort(stu+1,stu+n+1,cmp);
    for (int i = 1 ; i <= 5 ; i++)
    {
        cout << stu[i].id << ' ' << stu[i].total_score << endl;
    }

    system("pause");
    return 0;
}