#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num[7][2];
    for ( int i = 0 ; i < 7 ; i++)
    {
        cin >> num[i][0] >> num[i][1];
    }
    int index = 0;
    int max_index = 0;
    for (int i = 0 ; i < 7 ; i++)
    {
        if (num[i][0] + num[i][1] >= 8 && num[i][0] + num[i][1] > max_index)
        {
            max_index = num[i][0] + num[i][1];
            index = i;
        }
    }
    cout << index+1 << endl;
    system("pause");
    return 0;
}