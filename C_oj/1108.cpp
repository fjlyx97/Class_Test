#include <iostream>
using namespace std;
int value[51][51] = {0};
int N;
int min_money = 999999;
void dp(int id , int money)
{
    if (money > min_money)
    {
        return;
    }
    if (id == N)
    {
        if (money < min_money)
        {
            min_money = money;
            return;
        }
    }
    if (id > N)
    {
        return;
    }
    for ( int i = 1 ; i < N ; i++)
    {
        dp(id+i,money+value[id][id+i]);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for ( int i = 1 ; i <= N ; i++)
    {
        for ( int j = i+1 ; j <= N ; j++)
        {
            cin >> value[i][j];
        }
    }
    dp(1,0);
    cout << min_money << endl;
    system("pause");
    return 0;
}