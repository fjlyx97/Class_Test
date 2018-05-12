#include <iostream>
#include <algorithm>
using namespace std;
struct mfriend
{
    int id;
    int w;
}mp[20001];
int e[11] = {0};
bool cmp(mfriend m1 , mfriend m2)
{
    if (m1.w > m2.w)
    {
        return true;
    }
    if (m1.w == m2.w)
    {
        return m1.id < m2.id;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , k;
    cin >> n >> k;
    for (int i = 1 ; i <= 10 ; i++)
    {
        cin >> e[i];
    }
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> mp[i].w;
        mp[i].id = i;
    }
    sort(mp+1,mp+n+1,cmp);
    for (int i = 1 ; i <= n ; i++)
    {
        mp[i].w += e[(i-1) % 10 + 1];
    }
    sort(mp+1,mp+n+1,cmp);
    for (int i = 1 ; i <= k ; i++)
    {
        cout << mp[i].id << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}