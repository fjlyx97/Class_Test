#include <iostream>
using namespace std;
#define INF 0x3f3f3f3f
struct mpep
{
    int a;
    int b;
    int money;
}pep[1001];
void mswap(mpep* m1 , mpep* m2)
{
    mpep m3 = *m1;
    *m1 = *m2;
    *m2 = m3;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int temp_money;
    int max_money = -INF;
    int max_money_index;
    int min_max_money;
    cin >> pep[1].a >> pep[1].b;
    pep[1].money = 0;
    temp_money = pep[1].a;
    for (int i = 2; i <= n+1 ; i++)
    {
        cin >> pep[i].a >> pep[i].b;
        pep[i].money = temp_money / pep[i].b;
        max_money = pep[i].money > max_money ? pep[i].money : max_money;
        max_money_index = i;
        temp_money *= pep[i].a;
    }
    min_max_money = max_money;
    int cal = n;
    while(cal--)
    {
        mswap(&pep[2],&pep[max_money_index]);          
        temp_money = pep[1].a;
        for (int i = 2 ; i <= max_money_index ; i++)
        {
            pep[i].money = temp_money / pep[i].b;
            max_money = pep[i].money > max_money ? pep[i].money : max_money;
            max_money_index = i;
            temp_money *= pep[i].a;
        }
        min_max_money = min_max_money < max_money ? min_max_money : max_money;
    }
    cout << min_max_money << endl;
    system("pause");
    return 0;
}