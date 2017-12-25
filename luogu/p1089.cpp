#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int mouth_money[13];
    int now_money = 0;
    int save_money = 0;
    for ( int i = 1 ; i <= 12 ; i++)
    {
        cin >> mouth_money[i];
    }
    for ( int i = 1 ; i <= 12 ; i++)
    {
        now_money += 300;
        now_money -= mouth_money[i];
        if (now_money < 0)
        {
            cout << "-" << i << endl;
            return 0;
        }
        if (now_money >= 100)
        {
            save_money += (now_money / 100) * 100;
            now_money -= (now_money / 100) * 100;
        }
    }
    now_money += save_money * 1.2;
    cout << now_money << endl;

    system("pause");
    return 0;
}