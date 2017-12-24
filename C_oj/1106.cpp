#include <iostream>
using namespace std;
int boy_advantage[101][101] = {0};
int girl_advantage[101][101] = {0};
int boy_book[101] = {0};
int girl_book[101] = {0};
int N;
int max_advantage = 0;
void dp(int id , int advantage)
{
    if (id > N+1)
    {
        return;
    }
    if (id == N+1)
    {
        if (advantage > max_advantage)
        {
            max_advantage = advantage;
            return;
        }
    }
    for ( int i = 1 ; i <= N ; i++)
    {
        if (boy_book[id] == 0 && girl_book[i] == 0)
        {
            boy_book[id] = 1;
            girl_book[i] = 1;
            dp(id+1,advantage+(boy_advantage[id][i]*girl_advantage[i][id]));
            boy_book[id] = 0;
            girl_book[i] = 0;
        }
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
        for ( int j = 1 ; j <= N ; j++)
        {
            cin >> boy_advantage[i][j];
        }
    }
    for ( int i = 1 ; i <= N ; i++)
    {
        for ( int j = 1 ; j <= N ; j++)
        {
            cin >> girl_advantage[i][j];
        }
    }
    dp(1,0);
    cout << max_advantage << endl;
    system("pause");
    return 0;
}