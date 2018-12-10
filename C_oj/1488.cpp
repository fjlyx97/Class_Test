#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    double M;
    double money = 100;
    int ans = 0;
    cin >> M;
    while (money >= 0)
    {
        if (money - M >= 0)
        {
            ans++;
            money -= M;
            double temp = M * 0.9;
            if (M <= 5)
                M = 5;
            else
                M = temp;
        }
        else
            break;
    }
    cout << ans << endl;



    system("pause");
    return 0;
}