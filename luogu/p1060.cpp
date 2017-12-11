#include <iostream>
#include <algorithm>
using namespace std;
int value[26][2];
int dp(int money , int id , int m)
{
    if (id == m )
    {
        if (money >= value[id][0])
        {
            return value[id][0]*value[id][1];
        }
        else
        {
            return  0;
        }
    }
    if ( money < value[id][0])
    {
        return dp(money,id+1,m);
    }
    return max(dp(money-value[id][0],id+1,m)+value[id][0]*value[id][1] ,dp(money,id+1,m));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N , m;
    cin >> N >> m;
    for ( int i = 1 ; i <= m ; i++)
    {
        cin >> value[i][0] >> value[i][1];
    }
    int result = dp(N,1,m);
    cout << result << endl;

    system("pause");
    return 0;
}