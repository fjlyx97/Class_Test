#include <iostream>
using namespace std;
int main()
{
    int N;
    int num[11];
    int ans = 0;
    cin >> N;
    for (int i = 1 ; i <= N ; i++)
    {
        cin >> num[i];
    }
    for (int i = 1 ; i <= N ; i++)
    {
        ans ^= num[i];
    }
    if (ans == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    system("pause");
    return 0;
}