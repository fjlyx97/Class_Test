#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct mnum
{
    string num;
    int first;
}num[21];
bool cmp(mnum m1 , mnum m2)
{
    if (m1.first > m2.first)
        return m1.first > m2.first;
    else if (m1.first == m2.first)
        return m1.num > m2.num;
    return false;
}
bool cmp1(mnum m1 , mnum m2)
{
    return m1.num+m2.num > m2.num+m1.num;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> num[i].num;
        num[i].first = num[i].num[0]-48;
    }
    sort(num+1,num+n+1,cmp1);
    for (int i = 1 ; i <= n ; i++)
    {
        cout << num[i].num;
    }
    cout << endl;

    system("pause");
    return 0;
}