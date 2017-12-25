#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num[10];
    int max_height;
    int ans = 0;
    for ( int i = 0 ; i < 10 ; i++)
    {
        cin >> num[i];
    }
    cin >> max_height;
    for ( int i = 0 ; i < 10 ; i++)
    {
        if (max_height + 30 >= num[i])
        {
            ans++;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}