#include <iostream>
#include <algorithm>
using namespace std;
struct itime
{
    int ai;
    int bi;
}mytime[100];
bool cmp(const struct itime& a1 , const struct itime& a2)
{
    if (a1.bi < a2.bi) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> mytime[i].ai >> mytime[i].bi;
    }
    sort(mytime+1,mytime+n+1,cmp);
    int ans = 0;
    int nowtime = 0;
    for ( int i = 1 ; i <= n ; i++)
    {
        if (mytime[i].ai >= nowtime)
        {
            ans++;
            nowtime = mytime[i].bi;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}