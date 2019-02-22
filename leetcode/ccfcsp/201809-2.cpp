#include <iostream>
using namespace std;
int ans[1000001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int ans1 = 0;
    int a , b;
    int max_num = 0;
    cin >> n;
    for (int i = 0; i < n ; i++)
    {
        cin >> a >> b;
        max_num = b > max_num ? b : max_num;
        for (int j = a ; j < b ; j++)
        {
            ans[j]++;
        }
    }
    for (int i = 0; i < n ; i++)
    {
        cin >> a >> b;
        max_num = b > max_num ? b : max_num;
        for (int j = a ; j < b ; j++)
        {
            ans[j]++;
        }
    }
    for (int i = 0 ; i <= max_num ; i++)
    {
        if (ans[i] == 2)
            ans1++;
    }
    cout << ans1++ << endl;

    system("pause");
    return 0;
}