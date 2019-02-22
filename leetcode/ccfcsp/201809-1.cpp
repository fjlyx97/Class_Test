#include <iostream>
using namespace std;
int num[1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> num[i];
    }
    for (int i = 0 ; i < n ; i++)
    {
        if (i == 0)
        {
            cout << int((num[i]+num[i+1]) / 2) << " ";
            continue;
        }
        if (i == n-1)
        {
            cout << int((num[i]+num[i-1]) / 2) << " ";
            continue;
        }
        cout << int((num[i]+num[i+1]+num[i-1])/3) << " ";
    }
    cout << endl;



    system("pause");
    return 0;
}