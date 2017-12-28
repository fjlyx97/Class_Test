#include <iostream>
#include <algorithm>
using namespace std;
struct myapple
{
    int height;
    int power;
}apple[5001];
bool cmp(struct myapple a1 , struct myapple a2)
{
    if (a1.power < a2.power)
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
    int n , s;
    int a , b;
    cin >> n >> s >> a >> b;
    for ( int i = 1 ; i <= n ; i++)
    {
        cin >> apple[i].height >> apple[i].power;
    }
    sort(apple+1,apple+n+1,cmp);
    int ans = 0;
    for ( int i = 1 ; i <= n ; i++)
    {
        if (s < apple[i].power)
        {
            break;
        }
        if ( a+b >= apple[i].height && s >= apple[i].power)
        {
            s -= apple[i].power;
            ans++;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}